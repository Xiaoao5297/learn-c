/*
 * 教程来源：chapter10/sections/10.2 位运算.md
 * 示例编号：10.2.1
 * 所在小节：10.2.1 二进制速成：把数摊开成位
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.2.1_binary_basics.c -o demo
 *
 * 预期输出：
 *   13 >> 1 = 6
 *   13 >> 2 = 3
 *   13 & 1 = 1（13 是奇数）
 *   12 & 1 = 0（12 是偶数）
 *   1101 是 13 的二进制（低 4 位）
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.2.1 binary_basics.c
#include <stdio.h>

int main(void)
{
	printf("13 >> 1 = %d\n", 13 >> 1);
	printf("13 >> 2 = %d\n", 13 >> 2);
	printf("13 & 1 = %d（13 是奇数）\n", 13 & 1);
	printf("12 & 1 = %d（12 是偶数）\n", 12 & 1);

	unsigned int x = 13;

	for (int i = 3; i >= 0; i--) {
		printf("%u", (x >> i) & 1u);
	}
	printf(" 是 13 的二进制（低 4 位）\n");

	return 0;
}
