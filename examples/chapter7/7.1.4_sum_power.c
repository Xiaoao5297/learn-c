/*
 * 教程来源：chapter7/sections/7.1 递归入门.md
 * 示例编号：7.1.4
 * 所在小节：7.1.4 两个基础例：求和与幂
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.1.4_sum_power.c -o demo
 *
 * 预期输出：
 *   1 + 2 + ... + 100 = 5050
 *   2 的 10 次方 = 1024
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.1.4 sum_power.c
#include <stdio.h>

int sum_to(int n)
{
	if (n == 0) {
		return 0;
	}
	return n + sum_to(n - 1);
}

int power2(int n)
{
	if (n == 0) {
		return 1;
	}
	return 2 * power2(n - 1);
}

int main(void)
{
	printf("1 + 2 + ... + 100 = %d\n", sum_to(100));
	printf("2 的 10 次方 = %d\n", power2(10));

	return 0;
}
