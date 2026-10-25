/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.2
 * 所在小节：3.4.2 strlen：求长度
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.2_strlen_chars.c -o demo
 *
 * 预期输出：
 *   长度是 5
 *   s[0] = h
 *   s[1] = e
 *   s[2] = l
 *   s[3] = l
 *   s[4] = o
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.2 strlen_chars.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "hello";
	size_t length = strlen(s);

	printf("长度是 %zu\n", length);

	for (size_t i = 0; i < length; i++) {
		printf("s[%zu] = %c\n", i, s[i]);
	}

	return 0;
}
