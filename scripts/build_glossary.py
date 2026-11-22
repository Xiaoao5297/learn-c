#!/usr/bin/env python3
"""从各节末尾的「术语对照表」汇总生成根目录的总对照表。

用法：
    python3 scripts/build_glossary.py           # 重新生成 术语对照表.md
    python3 scripts/build_glossary.py --check   # 只检查是否与各节同步
"""

from __future__ import annotations

import argparse
import difflib
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
MASTER = ROOT / "术语对照表.md"
HEADING = "## 术语对照表"
HEADER = ("中文术语", "英文", "命名/写法示例", "说明")

CHAPTER_RE = re.compile(r"^chapter(\d+)$")
SECTION_RE = re.compile(r"^(\d+\.\d+)")


def split_row(line: str) -> list[str]:
    """按未转义的 | 拆分表格行，保留单元格里的 \\|。"""
    cells = re.split(r"(?<!\\)\|", line.strip())
    if cells and cells[0] == "":
        cells = cells[1:]
    if cells and cells[-1] == "":
        cells = cells[:-1]
    return [cell.strip() for cell in cells]


def is_separator(cells: list[str]) -> bool:
    return bool(cells) and all(re.fullmatch(r":?-{3,}:?", cell) for cell in cells)


def parse_section(path: Path) -> list[list[str]]:
    lines = path.read_text(encoding="utf-8").splitlines()
    if lines.count(HEADING) != 1:
        raise SystemExit(f"{path}: 应当恰好有一个「{HEADING}」")

    rows: list[list[str]] = []
    started = False
    for line in lines[lines.index(HEADING) + 1 :]:
        if line.startswith("|"):
            started = True
            cells = split_row(line)
            if is_separator(cells) or tuple(cells) == HEADER:
                continue
            if len(cells) != 4:
                raise SystemExit(f"{path}: 表格应有 4 列，实际 {len(cells)} 列：{line}")
            rows.append(cells)
        elif started:
            break

    if not rows:
        raise SystemExit(f"{path}: 术语表没有数据行")
    return rows


def chapter_title(chapter_dir: Path) -> str:
    readme = chapter_dir / "README.md"
    if readme.exists():
        first = readme.read_text(encoding="utf-8").splitlines()[0]
        if first.startswith("# "):
            return first[2:].strip()
    return chapter_dir.name


def section_number(path: Path) -> str:
    match = SECTION_RE.match(path.name)
    if not match:
        raise SystemExit(f"{path}: 文件名不是「数字.数字 标题.md」格式")
    return match.group(1)


def natural_key(path: Path) -> tuple[int, int]:
    return tuple(int(part) for part in section_number(path).split("."))  # type: ignore[return-value]


def collect() -> tuple[list[tuple[Path, list[Path]]], int]:
    """返回 [(章目录, 按顺序排列的小节)] 和术语总条数。"""
    chapters = sorted(
        (path for path in ROOT.iterdir() if path.is_dir() and CHAPTER_RE.match(path.name)),
        key=lambda path: int(CHAPTER_RE.match(path.name).group(1)),  # type: ignore[union-attr]
    )
    if not chapters:
        raise SystemExit("没有找到 chapterN 目录")

    result = []
    total = 0
    for chapter_dir in chapters:
        sections = sorted((chapter_dir / "sections").glob("*.md"), key=natural_key)
        if not sections:
            raise SystemExit(f"{chapter_dir}: sections/ 下没有小节")
        result.append((chapter_dir, sections))
        total += len(sections)
    return result, total


def build() -> str:
    chapters, section_count = collect()
    lines = [
        "# C 语言术语总对照表",
        "",
        "> 本表由 [`scripts/build_glossary.py`](scripts/build_glossary.py) 从各节文末的「术语对照表」自动汇总，",
        "> 覆盖第 0～10 章。同一章内重复出现的术语只列一次并合并出处；不同章节按各自语境分别保留。",
        "",
        "## 怎么用",
        "",
        "- 写变量名时，用 `Ctrl+F` 搜中文术语，再看「命名/写法示例」列。",
        "- 本书统一使用 snake_case：小写单词加下划线，例如 `student_count`、`max_score`。",
        "- 布尔变量用 `is_`、`has_`、`can_` 开头；数量用 `_count` 结尾，总数用 `total_`，最值用 `max_` / `min_`。",
        "- 想回到原小节，点「出处」里的编号；每节的完整表格在正文末尾、练习之前。",
        "",
    ]

    row_count = 0
    for chapter_dir, sections in chapters:
        grouped: dict[tuple[str, str], dict[str, object]] = {}
        for section in sections:
            number = section_number(section)
            relative = section.relative_to(ROOT).as_posix()
            for cells in parse_section(section):
                key = (cells[0], cells[1])
                if key in grouped:
                    sources = grouped[key]["sources"]
                    assert isinstance(sources, list)
                    if (number, relative) not in sources:
                        sources.append((number, relative))
                else:
                    grouped[key] = {
                        "cells": cells,
                        "sources": [(number, relative)],
                    }

        lines.append(f"## {chapter_title(chapter_dir)}")
        lines.append("")
        lines.append("| 中文术语 | 英文 | 命名/写法示例 | 说明 | 出处 |")
        lines.append("|------|------|------|------|------|")
        for entry in grouped.values():
            cells = entry["cells"]
            assert isinstance(cells, list)
            sources = entry["sources"]
            assert isinstance(sources, list)
            links = "、".join(f"[{number}](<{relative}>)" for number, relative in sources)
            lines.append(f"| {cells[0]} | {cells[1]} | {cells[2]} | {cells[3]} | {links} |")
            row_count += 1
        lines.append("")

    lines.append(f"共汇总 {section_count} 个小节、{row_count} 条术语。")
    lines.append("")
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="只检查总表是否与各节同步")
    args = parser.parse_args()

    expected = build()
    if args.check:
        if not MASTER.exists():
            print(f"缺少 {MASTER.name}，请运行 python3 scripts/build_glossary.py", file=sys.stderr)
            return 1
        actual = MASTER.read_text(encoding="utf-8")
        if actual != expected:
            diff = difflib.unified_diff(
                actual.splitlines(),
                expected.splitlines(),
                fromfile=str(MASTER.name),
                tofile="重新生成的结果",
                lineterm="",
            )
            print("\n".join(list(diff)[:80]), file=sys.stderr)
            print(
                f"\n{MASTER.name} 与各节术语表不同步，请运行 python3 scripts/build_glossary.py",
                file=sys.stderr,
            )
            return 1
        print(f"{MASTER.name} 已是最新。")
        return 0

    MASTER.write_text(expected, encoding="utf-8", newline="\n")
    print(f"已生成 {MASTER.name}：{len(expected.splitlines())} 行。")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
