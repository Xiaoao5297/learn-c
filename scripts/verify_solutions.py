#!/usr/bin/env python3
"""编译 practice-100 的参考答案，并核对示例输出。

solutions/ 里每一节对应一道题，通常是一个完整的 .c 程序；
4.7 是多文件工程，会按代码块前面的 `文件名` 标签拆开编译。

只自动运行“不读标准输入、不打开文件”的程序：这类程序的
“示例运行”就是纯 stdout，可以逐行比对。其余程序只检查编译。
"""

from __future__ import annotations

import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SOLUTIONS = ROOT / "practice-100" / "solutions"

SECTION_RE = re.compile(r"^## (\d+\.\d+) (.+)$", re.M)
CODE_RE = re.compile(r"^```c\n(.*?)^```$", re.S | re.M)
OUTPUT_RE = re.compile(r"\*\*示例运行\*\*[^\n]*：\s*\n+```text\n(.*?)^```$", re.S | re.M)
FILE_LABEL_RE = re.compile(r"^`([^`]+\.(?:c|h))`：$")
STDIN_RE = re.compile(r"\b(scanf|fgets|getchar|gets|getline)\s*\(")
FILE_RE = re.compile(r"\bfopen\s*\(")


def normalize(text: str) -> str:
    lines = [line.rstrip() for line in text.splitlines()]
    return "\n".join(lines).rstrip("\n")


def split_sections(text: str) -> list[tuple[str, str]]:
    """返回 (小节标题, 正文) 列表。"""
    matches = list(SECTION_RE.finditer(text))
    sections = []
    for i, match in enumerate(matches):
        end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
        sections.append((match.group(1) + " " + match.group(2).strip(), text[match.end():end]))
    return sections


def code_files(section: str) -> list[tuple[str, str]]:
    """从一节的正文里取出 (文件名, 代码)。"""
    blocks = [(m.start(), m.group(1)) for m in CODE_RE.finditer(section)]
    if not blocks:
        return []

    if len(blocks) == 1:
        return [("main.c", blocks[0][1])]

    files = []
    for position, code in blocks:
        before = section[:position].rstrip().splitlines()
        label = FILE_LABEL_RE.match(before[-1].strip()) if before else None
        if label is None:
            raise ValueError("多文件小节里，代码块前面缺少 `文件名`：标签")
        files.append((label.group(1), code))
    return files


def compile_program(files: list[tuple[str, str]], workdir: Path) -> str | None:
    for name, code in files:
        (workdir / name).write_text(code, encoding="utf-8")

    sources = sorted(name for name, _ in files if name.endswith(".c"))
    if not sources:
        return "这一节没有 .c 源文件"

    compiler = os.environ.get("CC", "cc")
    extra = os.environ.get("EXTRA_CFLAGS", "").split()
    command = [
        compiler,
        "-std=c11",
        "-Wall",
        "-Wextra",
        "-Werror",
        "-pedantic",
        *extra,
        *sources,
        "-o",
        "program",
        "-lm",
    ]
    result = subprocess.run(
        command, cwd=workdir, capture_output=True, text=True, check=False
    )
    if result.returncode == 0:
        return None
    return (result.stderr or result.stdout).strip() or "编译失败"


def main() -> int:
    sections = []
    for markdown in sorted(SOLUTIONS.glob("*.md")):
        for title, body in split_sections(markdown.read_text(encoding="utf-8")):
            sections.append((markdown.name, title, body))

    if not sections:
        print("practice-100/solutions 中没有找到题目小节。", file=sys.stderr)
        return 1

    failures: list[str] = []
    compiled = ran = skipped = 0

    with tempfile.TemporaryDirectory(prefix="learn-c-solutions-") as temp:
        for index, (markdown, title, body) in enumerate(sections):
            name = f"{markdown} {title}"
            try:
                files = code_files(body)
            except ValueError as error:
                failures.append(f"{name}: {error}")
                continue
            if not files:
                failures.append(f"{name}: 没有找到 C 代码块")
                continue

            workdir = Path(temp) / str(index)
            workdir.mkdir()

            error = compile_program(files, workdir)
            if error:
                failures.append(f"{name}: 编译失败\n{error}")
                continue
            compiled += 1

            output = OUTPUT_RE.search(body)
            code = "\n".join(code for _, code in files)
            if output is None:
                failures.append(f"{name}: 缺少“示例运行”输出块")
                continue
            expected = output.group(1)

            if STDIN_RE.search(code) or FILE_RE.search(code):
                skipped += 1
                continue

            try:
                result = subprocess.run(
                    [str(workdir / "program")],
                    input=b"",
                    capture_output=True,
                    timeout=3,
                    check=False,
                    cwd=workdir,
                )
            except subprocess.TimeoutExpired:
                failures.append(f"{name}: 运行超过 3 秒")
                continue

            ran += 1
            stdout = result.stdout.decode("utf-8", errors="replace")
            stderr_text = result.stderr.decode("utf-8", errors="replace")
            if result.returncode != 0:
                failures.append(
                    f"{name}: 退出码 {result.returncode}\n{stderr_text.strip()}"
                )
                continue
            if normalize(stdout) != normalize(expected):
                failures.append(
                    f"{name}: 输出与“示例运行”不一致\n"
                    f"--- 教程 ---\n{expected}"
                    f"--- 实际 ---\n{stdout}"
                )

    if failures:
        print(f"{len(failures)} 个参考答案未通过：", file=sys.stderr)
        for failure in failures:
            print(f"\n{failure}", file=sys.stderr)
        return 1

    print(
        f"参考答案验证通过：{len(sections)} 题，{compiled} 题编译成功，"
        f"{ran} 题核对输出，{skipped} 题只编译（需要输入或文件）。"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
