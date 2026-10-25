/*
 * 教程来源：chapter4/sections/4.3 指针与字符串.md
 * 示例编号：4.3.1
 * 所在小节：4.3.1 char 与字符串字面量
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.3.1_char_star_string.c -o demo
 *
 * 预期输出：
 *   arr = hello
 *   s   = hello
 *   *s 的首字符：h
 *   sizeof(arr) = 6
 *   strlen(s)   = 5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.3.1 char_star_string.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[] = "hello";
	char *s = "hello";

	printf("arr = %s\n", arr);
	printf("s   = %s\n", s);
	printf("*s 的首字符：%c\n", *s);
	printf("sizeof(arr) = %zu\n", sizeof(arr));
	printf("strlen(s)   = %zu\n", strlen(s));

	return 0;
}
