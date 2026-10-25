#!/usr/bin/env python3
"""从教程 Markdown 中提取带编号的完整 C 示例。

用法：
    python3 scripts/extract_examples.py          # 重新生成 examples/
    python3 scripts/extract_examples.py --check  # 检查 examples/ 是否与教程同步

约定：
- 小节中的完整示例，代码块第一行写成 `// 2.1.1 arithmetic.c`；
- 代码块后面用 `<!-- output: 2.1.1 -->` 标记输出，紧跟一个 text 代码块；
- 只有带编号的代码块会被抽取，片段和故意写错的代码不会收录；
- 每个示例都必须通过 `cc -std=c11 -Wall -Wextra -Werror -pedantic` 编译。

编号重复、输出缺失或编译失败都会直接报错，不再静默跳过。
"""

from __future__ import annotations

import argparse
import os
import re
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
EXAMPLES = ROOT / "examples"
SOURCE_PATTERNS = ("chapter*/sections/*.md",)

FENCE_RE = re.compile(r"^```c[ \t]*\n(.*?)^```[ \t]*$", re.M | re.S)
EXAMPLE_RE = re.compile(r"^//\s*(\d+\.\d+\.\d+)\s+(\S+\.c)\s*$")
OUTPUT_RE = re.compile(
    r"<!--\s*output:\s*(\d+\.\d+\.\d+)\s*-->\s*```text[ \t]*\n(.*?)^```[ \t]*$",
    re.M | re.S,
)
H1_RE = re.compile(r"^#\s+(.+)$", re.M)
HEADING_RE = re.compile(r"^(#{2,4})\s+(.+)$", re.M)

CHAPTER_NAMES = {
    "chapter0": "第 0 章：计算机基础",
    "chapter1": "第 1 章：认识 C 语言",
    "chapter2": "第 2 章：运算符、条件、循环与函数",
    "chapter3": "第 3 章：数组与字符串",
    "chapter4": "第 4 章：指针与结构体",
    "chapter5": "第 5 章：文件读写与实战",
    "chapter6": "第 6 章：动态内存与链表",
    "chapter7": "第 7 章：递归",
    "chapter8": "第 8 章：排序与查找",
    "chapter9": "第 9 章：数据结构入门",
    "chapter10": "第 10 章：C 语言收官",
}


@dataclass
class Example:
    source: Path
    source_rel: str
    number: str
    filename: str
    name: str
    code: str
    output: str
    title: str
    heading: str
    line: int

    @property
    def chapter(self) -> str:
        return f"chapter{self.number.split('.')[0]}"

    @property
    def output_file(self) -> str:
        return f"{self.number}_{self.name[:-2]}.c"


def strip_markdown(text: str) -> str:
    text = re.sub(r"<[^>]*>", "", text)
    text = re.sub(r"!\[[^\]]*\]\([^)]*\)", "", text)
    text = re.sub(r"\[([^\]]*)\]\([^)]*\)", r"\1", text)
    text = re.sub(r"[`*_>#]", "", text)
    return re.sub(r"\s+", " ", text).strip()


def document_title(text: str) -> str:
    match = H1_RE.search(text)
    return strip_markdown(match.group(1)) if match else ""


def nearest_heading(text: str, position: int) -> str:
    headings = list(HEADING_RE.finditer(text[:position]))
    return strip_markdown(headings[-1].group(2)) if headings else ""


def sanitize_comment(text: str) -> str:
    return text.replace("*/", "* /").replace("\r", " ")


def sanitize_heading(text: str) -> str:
    return sanitize_comment(text).strip()


def compile_error(code: str, workdir: Path, compiler: str) -> str | None:
    source = workdir / "candidate.c"
    binary = workdir / "candidate"
    source.write_text(code, encoding="utf-8")
    command = [
        compiler,
        "-std=c11",
        "-Wall",
        "-Wextra",
        "-Werror",
        "-pedantic",
        str(source),
        "-o",
        str(binary),
    ]
    try:
        result = subprocess.run(
            command, capture_output=True, text=True, timeout=30, check=False
        )
    except (OSError, subprocess.TimeoutExpired) as error:
        return str(error)
    if result.returncode == 0:
        return None
    return result.stderr.strip() or result.stdout.strip() or "编译失败"


def collect_examples() -> tuple[list[Example], list[str]]:
    compiler = os.environ.get("CC", "cc")
    examples: list[Example] = []
    problems: list[str] = []
    seen_numbers: dict[str, str] = {}

    with tempfile.TemporaryDirectory(prefix="learn-c-extract-") as temp:
        workdir = Path(temp)
        for pattern in SOURCE_PATTERNS:
            for source in sorted(ROOT.glob(pattern)):
                text = source.read_text(encoding="utf-8")
                source_rel = source.relative_to(ROOT).as_posix()
                outputs = {match.group(1): match.group(2) for match in OUTPUT_RE.finditer(text)}
                title = document_title(text)

                for block in FENCE_RE.finditer(text):
                    code = block.group(1)
                    first_line = code.splitlines()[0].strip() if code.splitlines() else ""
                    match = EXAMPLE_RE.match(first_line)
                    if not match:
                        continue

                    number, name = match.groups()
                    line = text.count("\n", 0, block.start()) + 1
                    location = f"{source_rel}:{line}"

                    if number in seen_numbers:
                        problems.append(
                            f"{location}: 示例编号 {number} 重复（另一处：{seen_numbers[number]}）"
                        )
                        continue
                    seen_numbers[number] = location

                    if "int main(" not in code:
                        problems.append(f"{location}: 示例 {number} 没有 main 函数")
                        continue

                    if number not in outputs:
                        problems.append(f"{location}: 示例 {number} 缺少 output 标记")
                        continue

                    error = compile_error(code, workdir, compiler)
                    if error:
                        problems.append(f"{location}: 示例 {number} 编译失败\n{error}")
                        continue

                    examples.append(
                        Example(
                            source=source,
                            source_rel=source_rel,
                            number=number,
                            filename=name,
                            name=name,
                            code=code.rstrip() + "\n",
                            output=outputs[number].rstrip() + "\n",
                            title=title,
                            heading=nearest_heading(text, block.start()),
                            line=line,
                        )
                    )

    examples.sort(key=lambda item: tuple(int(part) for part in item.number.split(".")))
    return examples, problems


def build_header(example: Example) -> str:
    lines = [
        "/*",
        f" * 教程来源：{example.source_rel}",
        f" * 示例编号：{example.number}",
        f" * 所在小节：{sanitize_heading(example.heading) or example.title or '（无标题）'}",
        " * 编译运行：cc -std=c11 -Wall -Wextra -pedantic "
        f"{example.output_file} -o demo",
        " *",
        " * 预期输出：",
    ]
    for line in example.output.rstrip("\n").splitlines():
        lines.append(f" *   {sanitize_comment(line)}")
    lines += [
        " *",
        " * 本文件由 scripts/extract_examples.py 自动生成。",
        " * 如需修改，请改教程原文后重新生成。",
        " */",
        "",
    ]
    return "\n".join(lines)


def escape_table_cell(text: str) -> str:
    return (
        text.replace("\\", "\\\\")
        .replace("|", r"\|")
        .replace("[", r"\[")
        .replace("]", r"\]")
    )


def build_index(examples: list[Example]) -> str:
    chapters: dict[str, list[Example]] = {}
    for example in examples:
        chapters.setdefault(example.chapter, []).append(example)

    lines = [
        "# 教程示例代码",
        "",
        "本目录由 [`scripts/extract_examples.py`](../scripts/extract_examples.py) 自动生成，",
        "收录教程中带编号、可以独立编译运行的完整 C 程序。",
        "",
        "## 怎么用",
        "",
        "```bash",
        "# 编译全部示例（输出到 examples/build/）",
        "make -C examples",
        "",
        "# 只编译某一章",
        "make -C examples build/chapter2/2.1.1_arithmetic",
        "",
        "# 运行某个示例",
        "./examples/build/chapter2/2.1.1_arithmetic",
        "",
        "# 编译并核对教程里写的输出",
        "python3 scripts/verify_examples.py",
        "",
        "# 清理编译产物",
        "make -C examples clean",
        "```",
        "",
        "每个 `.c` 文件顶部都有教程出处、示例编号、所在小节和预期输出。",
        "代码第一行的注释保留了示例编号和文件名。",
        "",
        "> 本目录是自动生成的。想改示例，请改教程原文，然后运行：",
        ">",
        "> ```bash",
        "> python3 scripts/extract_examples.py",
        "> ```",
        "",
        "## 示例总览",
        "",
        f"共 **{len(examples)}** 个示例，分布在 **{len(chapters)}** 个章节。",
        "",
        "| 章节 | 示例数 |",
        "|------|--------|",
    ]
    for chapter in sorted(chapters, key=lambda name: int(name.removeprefix("chapter"))):
        lines.append(
            f"| {CHAPTER_NAMES.get(chapter, chapter)} | {len(chapters[chapter])} |"
        )

    for chapter in sorted(chapters, key=lambda name: int(name.removeprefix("chapter"))):
        lines += [
            "",
            f"## {CHAPTER_NAMES.get(chapter, chapter)}",
            "",
            "| 文件 | 编号 | 出处 |",
            "|------|------|------|",
        ]
        for example in chapters[chapter]:
            source_link = f"<../{example.source_rel}>"
            file_link = f"{example.chapter}/{example.output_file}"
            heading = escape_table_cell(example.heading or example.title)
            lines.append(
                f"| [{example.output_file}]({file_link}) | "
                f"{example.number} | [{heading}]({source_link}) |"
            )

    lines += [
        "",
        "---",
        "",
        "示例只保证在 `cc -std=c11 -Wall -Wextra -Werror -pedantic` 下能编译。",
        "涉及输入或外部文件的程序会在 `examples/verify_skip.txt` 中单独列出。",
        "",
    ]
    return "\n".join(lines)


def write_examples(examples: list[Example], destination: Path) -> None:
    destination.mkdir(parents=True, exist_ok=True)
    for old_file in destination.rglob("*.c"):
        old_file.unlink()
    (destination / "README.md").unlink(missing_ok=True)
    for old_dir in sorted(
        (path for path in destination.rglob("*") if path.is_dir()),
        key=lambda path: len(path.parts),
        reverse=True,
    ):
        if not any(old_dir.iterdir()):
            old_dir.rmdir()

    for example in examples:
        chapter_dir = destination / example.chapter
        chapter_dir.mkdir(exist_ok=True)
        content = build_header(example) + example.code
        if not content.endswith("\n"):
            content += "\n"
        (chapter_dir / example.output_file).write_text(content, encoding="utf-8")

    (destination / "README.md").write_text(build_index(examples), encoding="utf-8")


def compare_directories(expected: Path, actual: Path) -> list[str]:
    problems: list[str] = []

    def is_generated(path: Path) -> bool:
        return path.suffix == ".c" or path.name == "README.md"

    expected_files = {
        path.relative_to(expected).as_posix(): path
        for path in expected.rglob("*")
        if path.is_file() and is_generated(path)
    }
    actual_files = {
        path.relative_to(actual).as_posix(): path
        for path in actual.rglob("*")
        if path.is_file()
        and is_generated(path)
        and "build" not in path.relative_to(actual).parts
    }

    for name in sorted(expected_files.keys() - actual_files.keys()):
        problems.append(f"缺少文件：examples/{name}")
    for name in sorted(actual_files.keys() - expected_files.keys()):
        problems.append(f"多余文件：examples/{name}")
    for name in sorted(expected_files.keys() & actual_files.keys()):
        if expected_files[name].read_bytes() != actual_files[name].read_bytes():
            problems.append(f"内容不同：examples/{name}")
    return problems


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--check",
        action="store_true",
        help="不写入文件，只检查 examples/ 是否与教程同步",
    )
    args = parser.parse_args()

    examples, problems = collect_examples()
    if problems:
        print("示例抽取失败：", file=sys.stderr)
        for problem in problems:
            print(f"  - {problem}", file=sys.stderr)
        return 1

    if args.check:
        with tempfile.TemporaryDirectory(prefix="learn-c-check-") as temp:
            expected = Path(temp) / "examples"
            write_examples(examples, expected)
            problems = compare_directories(expected, EXAMPLES)
        if problems:
            print("examples/ 与教程不同步：", file=sys.stderr)
            for problem in problems:
                print(f"  - {problem}", file=sys.stderr)
            print(
                "\n请运行 `python3 scripts/extract_examples.py` 重新生成。",
                file=sys.stderr,
            )
            return 1
        print(f"examples/ 已同步（{len(examples)} 个示例）。")
        return 0

    write_examples(examples, EXAMPLES)
    print(f"已生成 {len(examples)} 个示例到 examples/。")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
