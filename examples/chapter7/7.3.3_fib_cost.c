/*
 * 教程来源：chapter7/sections/7.3 斐波那契与递归代价.md
 * 示例编号：7.3.3
 * 所在小节：7.3.3 代价：同一个子问题算了一遍又一遍
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.3.3_fib_cost.c -o demo
 *
 * 预期输出：
 *   fib(10) = 55，调用 109 次
 *   fib(20) = 6765，调用 13529 次
 *   fib(30) = 832040，调用 1664079 次
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.3.3 fib_cost.c
#include <stdio.h>

int calls = 0;

int fib(int n)
{
	calls++;
	if (n == 1 || n == 2) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int main(void)
{
	int ns[3] = {10, 20, 30};

	for (int i = 0; i < 3; i++) {
		calls = 0;
		int value = fib(ns[i]);
		printf("fib(%d) = %d，调用 %d 次\n", ns[i], value, calls);
	}

	return 0;
}
