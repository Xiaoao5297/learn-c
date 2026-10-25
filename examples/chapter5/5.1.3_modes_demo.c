/*
 * 教程来源：chapter5/sections/5.1 文件与 FILE.md
 * 示例编号：5.1.3
 * 所在小节：5.1.4 打开模式：r、w、a 和带 + 的模式
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.1.3_modes_demo.c -o demo
 *
 * 预期输出：
 *   第一天：学了 fopen
 *   第二天：学了 fprintf
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.1.3 modes_demo.c
#include <stdio.h>

int main(void)
{
	char line[64];

	FILE *fp = fopen("diary.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	fprintf(fp, "第一天：学了 fopen\n");
	fclose(fp);

	fp = fopen("diary.txt", "a");
	if (fp == NULL) {
		return 1;
	}
	fprintf(fp, "第二天：学了 fprintf\n");
	fclose(fp);

	fp = fopen("diary.txt", "r");
	if (fp == NULL) {
		return 1;
	}
	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("%s", line);
	}
	fclose(fp);

	return 0;
}
