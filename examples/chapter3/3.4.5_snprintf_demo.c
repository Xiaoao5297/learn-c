/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.5
 * 所在小节：3.4.5 snprintf：推荐的复制方式
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.5_snprintf_demo.c -o demo
 *
 * 预期输出：
 *   dst = hello
 *   strlen(dst) = 5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.5 snprintf_demo.c
#include <stdio.h>

int main(void)
{
	char src[] = "hello world";
	char dst[6];

	snprintf(dst, sizeof(dst), "%s", src);

	printf("dst = %s\n", dst);
	printf("strlen(dst) = %zu\n", strlen(dst));

	return 0;
}
