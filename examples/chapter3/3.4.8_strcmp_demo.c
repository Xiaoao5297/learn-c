/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.8
 * 所在小节：3.4.8 strcmp：比较字符串
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.8_strcmp_demo.c -o demo
 *
 * 预期输出：
 *   a 和 b 内容相同
 *   a 排在 c 前面
 *   c 排在 a 后面
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.8 strcmp_demo.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[] = "apple";
	char b[] = "apple";
	char c[] = "banana";

	if (strcmp(a, b) == 0) {
		printf("a 和 b 内容相同\n");
	}
	if (strcmp(a, c) < 0) {
		printf("a 排在 c 前面\n");
	}
	if (strcmp(c, a) > 0) {
		printf("c 排在 a 后面\n");
	}

	return 0;
}
