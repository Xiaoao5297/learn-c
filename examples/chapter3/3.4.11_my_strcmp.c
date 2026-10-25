/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.11
 * 所在小节：3.4.11 动手实现 mystrcmp
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.11_my_strcmp.c -o demo
 *
 * 预期输出：
 *   my_strcmp("apple", "apple") = 0
 *   my_strcmp("apple", "banana") = -1
 *   my_strcmp("banana", "apple") = 1
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.11 my_strcmp.c
#include <stdio.h>

int my_strcmp(const char a[], const char b[])
{
	int i = 0;

	while (a[i] != '\0' && a[i] == b[i]) {
		i++;
	}

	return (unsigned char)a[i] - (unsigned char)b[i];
}

int main(void)
{
	printf("my_strcmp(\"apple\", \"apple\") = %d\n",
	       my_strcmp("apple", "apple"));
	printf("my_strcmp(\"apple\", \"banana\") = %d\n",
	       my_strcmp("apple", "banana"));
	printf("my_strcmp(\"banana\", \"apple\") = %d\n",
	       my_strcmp("banana", "apple"));

	return 0;
}
