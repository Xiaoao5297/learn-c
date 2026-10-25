/*
 * 教程来源：chapter10/sections/10.2 位运算.md
 * 示例编号：10.2.2
 * 所在小节：10.2.2 六个位运算符
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.2.2_six_operators.c -o demo
 *
 * 预期输出：
 *   a     = 00000110（6）
 *   b     = 00000011（3）
 *   a & b = 00000010（2）
 *   a | b = 00000111（7）
 *   a ^ b = 00000101（5）
 *   ~a    = 11111001（低 8 位）
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.2.2 six_operators.c
#include <stdio.h>

void print_bits(unsigned int x)
{
	for (int i = 7; i >= 0; i--) {
		printf("%u", (x >> i) & 1u);
	}
}

int main(void)
{
	unsigned int a = 6;
	unsigned int b = 3;

	printf("a     = "); print_bits(a); printf("（%u）\n", a);
	printf("b     = "); print_bits(b); printf("（%u）\n", b);
	printf("a & b = "); print_bits(a & b); printf("（%u）\n", a & b);
	printf("a | b = "); print_bits(a | b); printf("（%u）\n", a | b);
	printf("a ^ b = "); print_bits(a ^ b); printf("（%u）\n", a ^ b);
	printf("~a    = "); print_bits(~a & 0xFFu); printf("（低 8 位）\n");

	return 0;
}
