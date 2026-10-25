/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.7
 * 所在小节：3.4.7 strncat：带上限的拼接
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.7_strncat_demo.c -o demo
 *
 * 预期输出：
 *   你好，C 语言
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.7 strncat_demo.c
#include <stdio.h>
#include <string.h>

#define SIZE 20

int main(void)
{
	char greeting[SIZE] = "你好，";
	char name[] = "C 语言";
	size_t used = strlen(greeting);

	strncat(greeting, name, SIZE - used - 1);

	printf("%s\n", greeting);

	return 0;
}
