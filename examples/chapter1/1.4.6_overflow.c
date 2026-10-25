/*
 * 教程来源：chapter1/sections/1.4 变量与数据类型.md
 * 示例编号：1.4.6
 * 所在小节：int 的范围与溢出
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.4.6_overflow.c -o demo
 *
 * 预期输出：
 *   count = 4294967295
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.4.6 overflow.c
#include <stdio.h>

int main(void)
{
	unsigned int count = 0;

	count = count - 1;

	printf("count = %u\n", count);

	return 0;
}
