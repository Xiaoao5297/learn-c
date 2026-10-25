/*
 * 教程来源：chapter5/sections/5.1 文件与 FILE.md
 * 示例编号：5.1.1
 * 所在小节：5.1.2 打开与关闭：fopen 和 fclose
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.1.1_first_write.c -o demo
 *
 * 预期输出：
 *   已写入 hello.txt
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.1.1 first_write.c
#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("hello.txt", "w");
	if (fp == NULL) {
		printf("打开失败\n");
		return 1;
	}

	fprintf(fp, "你好，文件！\n");
	fprintf(fp, "这行字存在硬盘上。\n");
	fclose(fp);

	printf("已写入 hello.txt\n");

	return 0;
}
