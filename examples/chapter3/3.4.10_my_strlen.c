/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.10
 * 所在小节：3.4.10 动手实现 mystrlen
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.10_my_strlen.c -o demo
 *
 * 预期输出：
 *   my_strlen = 5
 *   strlen    = 5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.10 my_strlen.c
#include <stdio.h>
#include <string.h>

size_t my_strlen(const char s[])
{
	size_t count = 0;

	while (s[count] != '\0') {
		count++;
	}

	return count;
}

int main(void)
{
	char s[] = "hello";

	printf("my_strlen = %zu\n", my_strlen(s));
	printf("strlen    = %zu\n", strlen(s));

	return 0;
}
