/*
 * 教程来源：chapter10/sections/10.2 位运算.md
 * 示例编号：10.2.3
 * 所在小节：10.2.3 移位：左移翻倍，右移减半（有前提）
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.2.3_shift_rules.c -o demo
 *
 * 预期输出：
 *   x     = 6
 *   x << 1 = 12
 *   x << 2 = 24
 *   u     = 12
 *   u >> 1 = 6（无符号：等于除以 2）
 *   u >> 2 = 3（无符号：等于除以 4）
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.2.3 shift_rules.c
#include <stdio.h>

int main(void)
{
	int x = 6;

	printf("x     = %d\n", x);
	printf("x << 1 = %d\n", x << 1);
	printf("x << 2 = %d\n", x << 2);

	unsigned int u = 12;

	printf("u     = %u\n", u);
	printf("u >> 1 = %u（无符号：等于除以 2）\n", u >> 1);
	printf("u >> 2 = %u（无符号：等于除以 4）\n", u >> 2);

	return 0;
}
