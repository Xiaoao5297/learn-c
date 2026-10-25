/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.3
 * 所在小节：3.4.3 strcpy：能复制，但不安全
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.3_strcpy_demo.c -o demo
 *
 * 预期输出：
 *   dst = hello
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.3 strcpy_demo.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char src[] = "hello";
	char dst[6];

	strcpy(dst, src);
	printf("dst = %s\n", dst);

	return 0;
}
