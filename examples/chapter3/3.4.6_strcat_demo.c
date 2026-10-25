/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.6
 * 所在小节：3.4.6 strcat：拼接与它的风险
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.6_strcat_demo.c -o demo
 *
 * 预期输出：
 *   你好，C 语言
 *   strlen(greeting) = 17
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.6 strcat_demo.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char greeting[20] = "你好，";
	char name[] = "C 语言";

	strcat(greeting, name);
	printf("%s\n", greeting);
	printf("strlen(greeting) = %zu\n", strlen(greeting));

	return 0;
}
