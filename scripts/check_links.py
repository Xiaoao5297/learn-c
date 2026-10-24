#!/usr/bin/env python3
"""检查 Markdown 中的相对链接和图片路径是否存在。

只检查仓库内路径；http(s)、mailto、锚点等外部链接会跳过。
代码块和行内代码里的内容不会被当作链接。
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path
from urllib.parse import unquote, urlsplit

ROOT = Path(__file__).resolve().parent.parent

FENCE_RE = re.compile(r"^```.*?^```", re.M | re.S)
INLINE_CODE_RE = re.compile(r"`[^`\n]*`")
INLINE_LINK_RE = re.compile(
    r"!?\[[^\]]*\]\(\s*(<[^>]*>|[^\s)]+)(?:\s+[\"'][^\"']*[\"'])?\s*\)"
)
REFERENCE_DEF_RE = re.compile(r"^\s*\[[^\]]+\]:\s*(\S+)", re.M)

SKIP_SCHEMES = ("http://", "https://", "mailto:", "tel:", "data:")


def line_number(text: str, position: int) -> int:
    return text.count("\n", 0, position) + 1


def is_external(target: str) -> bool:
    lowered = target.lower()
    return lowered.startswith(SKIP_SCHEMES) or target.startswith(("#", "//"))


def resolve_target(markdown: Path, target: str) -> Path | None:
    target = target.strip()
    if not target:
        return None
    if target.startswith("<") and target.endswith(">"):
        target = target[1:-1]
    if is_external(target):
        return None

    # 去掉锚点和查询参数，只检查文件本身。
    target = urlsplit(target).path
    if not target:
        return None
    target = unquote(target)
    if target.startswith("/"):
        return (ROOT / target.lstrip("/")).resolve()
    return (markdown.parent / target).resolve()


def check_file(markdown: Path) -> list[str]:
    text = markdown.read_text(encoding="utf-8")
    # 代码块和行内代码可能包含看似链接的文本（如 a[i][j]），先移除。
    cleaned = FENCE_RE.sub("", text)
    cleaned = INLINE_CODE_RE.sub("", cleaned)

    problems: list[str] = []
    matches = list(INLINE_LINK_RE.finditer(cleaned))
    matches += list(REFERENCE_DEF_RE.finditer(cleaned))
    for match in matches:
        target = match.group(1)
        resolved = resolve_target(markdown, target)
        if resolved is None:
            continue
        if not resolved.exists():
            problems.append(
                f"{markdown.relative_to(ROOT)}:{line_number(cleaned, match.start())}: "
                f"找不到链接目标 {target!r}（解析为 {resolved}）"
            )
    return problems


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "paths",
        nargs="*",
        type=Path,
        help="要检查的 Markdown 文件或目录，默认检查整个仓库",
    )
    args = parser.parse_args()

    paths = args.paths or [ROOT]
    markdown_files: list[Path] = []
    for path in paths:
        path = path.resolve()
        if path.is_dir():
            markdown_files.extend(
                sorted(
                    candidate
                    for candidate in path.rglob("*.md")
                    if "node_modules" not in candidate.parts
                    and "build" not in candidate.parts
                )
            )
        elif path.suffix.lower() == ".md":
            markdown_files.append(path)

    problems: list[str] = []
    for markdown in sorted(set(markdown_files)):
        problems.extend(check_file(markdown))

    if problems:
        print(f"发现 {len(problems)} 个失效链接：", file=sys.stderr)
        for problem in problems:
            print(f"  - {problem}", file=sys.stderr)
        return 1

    print(f"链接检查通过：{len(set(markdown_files))} 个 Markdown 文件。")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
