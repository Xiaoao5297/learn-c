/*
 * 教程来源：chapter4/sections/4.3 指针与字符串.md
 * 示例编号：4.3.2
 * 所在小节：4.3.2 遍历字符串：以 '\0' 为终点
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.3.2_my_strlen.c -o demo
 *
 * 预期输出：
 *   hello 有 5 个字符
 *   hi 有 2 个字符
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.3.2 my_strlen.c
#include <stdio.h>

size_t my_strlen(const char *s)
{
	size_t count = 0;

	while (*s != '\0') {
		count++;
		s++;
	}

	return count;
}

int main(void)
{
	printf("hello 有 %zu 个字符\n", my_strlen("hello"));
	printf("hi 有 %zu 个字符\n", my_strlen("hi"));

	return 0;
}
