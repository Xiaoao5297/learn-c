/*
 * 教程来源：chapter5/sections/5.3 行读写与安全输入.md
 * 示例编号：5.3.3
 * 所在小节：5.3.3 fputs：往文件写一行
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.3.3_fputs_write.c -o demo
 *
 * 预期输出：
 *   1. buy milk
 *   2. read book
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.3.3 fputs_write.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char line[64];

	FILE *fp = fopen("todo.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	fputs("buy milk\n", fp);
	fputs("read book\n", fp);
	fclose(fp);

	fp = fopen("todo.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	int number = 1;
	while (fgets(line, sizeof(line), fp) != NULL) {
		line[strcspn(line, "\n")] = '\0';
		printf("%d. %s\n", number, line);
		number++;
	}
	fclose(fp);

	return 0;
}
