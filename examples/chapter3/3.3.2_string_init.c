/*
 * 教程来源：chapter3/sections/3.3 字符串基础.md
 * 示例编号：3.3.2
 * 所在小节：3.3.2 初始化字符串的几种写法
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.3.2_string_init.c -o demo
 *
 * 预期输出：
 *   s1 = Hello
 *   s2 = Hello
 *   s3 = Hello
 *   sizeof(s2) = 6
 *   sizeof(s3) = 6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.3.2 string_init.c
#include <stdio.h>

int main(void)
{
	char s1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
	char s2[6] = "Hello";
	char s3[] = "Hello";

	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("s3 = %s\n", s3);

	printf("sizeof(s2) = %zu\n", sizeof(s2));
	printf("sizeof(s3) = %zu\n", sizeof(s3));

	return 0;
}
