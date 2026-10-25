/*
 * 教程来源：chapter5/sections/5.2 读写文件.md
 * 示例编号：5.2.2
 * 所在小节：5.2.2 fgetc 和 fputc：一个字符一个字符处理
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.2.2_fgetc_count.c -o demo
 *
 * 预期输出：
 *   abc
 *   def
 *   一共 8 个字符
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.2.2 fgetc_count.c
#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("note.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	fprintf(fp, "abc\ndef\n");
	fclose(fp);

	fp = fopen("note.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	int count = 0;
	int ch;
	while ((ch = fgetc(fp)) != EOF) {
		count++;
		printf("%c", ch);
	}
	fclose(fp);

	printf("一共 %d 个字符\n", count);

	return 0;
}
