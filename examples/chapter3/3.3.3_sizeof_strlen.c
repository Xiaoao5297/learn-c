/*
 * 教程来源：chapter3/sections/3.3 字符串基础.md
 * 示例编号：3.3.3
 * 所在小节：3.3.3 sizeof vs strlen
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.3.3_sizeof_strlen.c -o demo
 *
 * 预期输出：
 *   sizeof(s) = 10
 *   strlen(s) = 2
 *   sizeof(t) = 6
 *   strlen(t) = 5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.3.3 sizeof_strlen.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[10] = "Hi";

	printf("sizeof(s) = %zu\n", sizeof(s));
	printf("strlen(s) = %zu\n", strlen(s));

	char t[] = "Hello";
	printf("sizeof(t) = %zu\n", sizeof(t));
	printf("strlen(t) = %zu\n", strlen(t));

	return 0;
}
