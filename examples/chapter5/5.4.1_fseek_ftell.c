/*
 * 教程来源：chapter5/sections/5.4 文件定位与二进制.md
 * 示例编号：5.4.1
 * 所在小节：5.4.1 文件位置：ftell、fseek、rewind
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.4.1_fseek_ftell.c -o demo
 *
 * 预期输出：
 *   文件大小是 10 字节
 *   回到开头，第一个字符是 0
 *   跳到第 2 个字节，读到 2
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.4.1 fseek_ftell.c
#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("digits.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	fprintf(fp, "0123456789");
	fclose(fp);

	fp = fopen("digits.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	printf("文件大小是 %ld 字节\n", size);

	rewind(fp);
	int ch = fgetc(fp);
	printf("回到开头，第一个字符是 %c\n", ch);

	fseek(fp, 2, SEEK_SET);
	ch = fgetc(fp);
	printf("跳到第 2 个字节，读到 %c\n", ch);

	fclose(fp);

	return 0;
}
