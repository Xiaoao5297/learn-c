#!/usr/bin/env python3
"""编译并运行 examples/ 中的示例，核对教程里写的预期输出。

用法：
    python3 scripts/verify_examples.py

需要输入的示例：把输入内容放到 examples/verify_inputs/<文件名>.txt，
运行时会作为 stdin 喂给程序（例如 examples/chapter1/1.5.1_scan_two.c
对应 examples/verify_inputs/1.5.1_scan_two.txt）。

仍不适合自动运行（依赖外部文件、真交互等）的示例，写到
examples/verify_skip.txt，一行一个相对路径。被跳过的示例仍然会参与编译，
只是不运行、不比对输出。
"""

from __future__ import annotations

import os
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
EXAMPLES = ROOT / "examples"
SKIP_FILE = EXAMPLES / "verify_skip.txt"
INPUT_DIR = EXAMPLES / "verify_inputs"


def read_skip_list() -> set[str]:
    if not SKIP_FILE.exists():
        return set()
    skipped: set[str] = set()
    for line in SKIP_FILE.read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if line and not line.startswith("#"):
            skipped.add(line)
    return skipped


def normalize_output(text: str) -> str:
    """忽略行尾空格，其他字符保持原样。"""
    return "\n".join(line.rstrip() for line in text.splitlines()).rstrip("\n")


def expected_output(source: Path) -> str:
    lines = source.read_text(encoding="utf-8").splitlines()
    try:
        start = lines.index(" * 预期输出：")
    except ValueError as error:
        raise ValueError(f"{source}: 找不到“预期输出”") from error

    output: list[str] = []
    for line in lines[start + 1 :]:
        if line.startswith(" * 本文件") or line.startswith(" */"):
            break
        if line.startswith(" *   "):
            output.append(line[len(" *   ") :])
        elif line == " *":
            output.append("")
        else:
            raise ValueError(f"{source}: 预期输出格式不正确：{line!r}")
    return "\n".join(output).rstrip("\n") + "\n"


def compile_example(source: Path, binary: Path, compiler: str) -> str | None:
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
    result = subprocess.run(command, capture_output=True, text=True, check=False)
    if result.returncode == 0:
        return None
    return result.stderr.strip() or result.stdout.strip() or "编译失败"


def read_input(source: Path) -> str | None:
    """返回喂给示例的 stdin 内容；没有对应的输入文件则返回 None。"""
    input_file = INPUT_DIR / (source.stem + ".txt")
    if input_file.exists():
        return input_file.read_text(encoding="utf-8")
    return None


def run_example(binary: Path, stdin_text: str | None) -> subprocess.CompletedProcess:
    stdin_data = stdin_text.encode("utf-8") if stdin_text is not None else b""
    return subprocess.run(
        [str(binary)],
        input=stdin_data,
        capture_output=True,
        timeout=3,
        check=False,
        cwd=binary.parent,
    )


def main() -> int:
    compiler = os.environ.get("CC", "cc")
    skipped = read_skip_list()
    sources = sorted(EXAMPLES.glob("chapter*/*.c"))

    if not sources:
        print("examples/ 中没有找到示例，请先运行 extract_examples.py。", file=sys.stderr)
        return 1

    failures: list[str] = []
    with tempfile.TemporaryDirectory(prefix="learn-c-verify-") as temp:
        workdir = Path(temp)
        for source in sources:
            relative = source.relative_to(EXAMPLES).as_posix()
            binary = workdir / source.stem
            error = compile_example(source, binary, compiler)
            if error:
                failures.append(f"{relative}: 编译失败\n{error}")
                continue

            if relative in skipped:
                continue

            try:
                expected = expected_output(source)
            except ValueError as error:
                failures.append(str(error))
                continue

            try:
                result = run_example(binary, read_input(source))
            except subprocess.TimeoutExpired:
                failures.append(f"{relative}: 运行超过 3 秒，可能需要输入")
                continue

            stdout = result.stdout.decode("utf-8", errors="replace")
            stderr_text = result.stderr.decode("utf-8", errors="replace")
            if result.returncode != 0:
                failures.append(
                    f"{relative}: 退出码 {result.returncode}\n{stderr_text.strip()}"
                )
                continue

            if normalize_output(stdout) != normalize_output(expected):
                failures.append(
                    f"{relative}: 输出与教程不一致\n"
                    f"--- 教程 ---\n{expected}"
                    f"--- 实际 ---\n{stdout}"
                )

    if failures:
        print(f"{len(failures)} 个示例未通过：", file=sys.stderr)
        for failure in failures:
            print(f"\n{failure}", file=sys.stderr)
        return 1

    print(f"示例验证通过：{len(sources)} 个文件，{len(skipped)} 个跳过运行。")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
