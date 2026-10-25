/*
 * 教程来源：chapter5/sections/5.3 行读写与安全输入.md
 * 示例编号：5.3.1
 * 所在小节：5.3.1 fgets：从文件读一行
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.3.1_fgets_lines.c -o demo
 *
 * 预期输出：
 *   [first
 *   ]
 *   [second
 *   ]
 *   [third
 *   ]
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.3.1 fgets_lines.c
#include <stdio.h>

int main(void)
{
	char line[64];

	FILE *fp = fopen("lines.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	fprintf(fp, "first\nsecond\nthird\n");
	fclose(fp);

	fp = fopen("lines.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("[%s]\n", line);
	}
	fclose(fp);

	return 0;
}
