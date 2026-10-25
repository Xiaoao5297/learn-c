/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.4
 * 所在小节：3.4.4 strncpy：有限复制，有坑
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.4_strncpy_demo.c -o demo
 *
 * 预期输出：
 *   dst = hello
 *   strlen(dst) = 5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.4 strncpy_demo.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char src[] = "hello world";
	char dst[6];

	strncpy(dst, src, sizeof(dst) - 1);
	dst[sizeof(dst) - 1] = '\0';

	printf("dst = %s\n", dst);
	printf("strlen(dst) = %zu\n", strlen(dst));

	return 0;
}
