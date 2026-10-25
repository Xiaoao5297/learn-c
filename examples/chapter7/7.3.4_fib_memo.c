/*
 * 教程来源：chapter7/sections/7.3 斐波那契与递归代价.md
 * 示例编号：7.3.4
 * 所在小节：7.3.4 记忆化：算过的存起来
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.3.4_fib_memo.c -o demo
 *
 * 预期输出：
 *   朴素递归 fib(30)：调用 1664079 次
 *   记忆化 fib(30)：调用 57 次
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.3.4 fib_memo.c
#include <stdio.h>

int memo[50] = {0};
int naive_calls = 0;
int memo_calls = 0;
int fib_naive(int n)
{
	naive_calls++;
	if (n == 1 || n == 2) {
		return 1;
	}
	return fib_naive(n - 1) + fib_naive(n - 2);
}

int fib_memo(int n)
{
	memo_calls++;
	if (n == 1 || n == 2) {
		return 1;
	}
	if (memo[n] != 0) {
		return memo[n];
	}
	memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
	return memo[n];
}

int main(void)
{
	fib_naive(30);
	printf("朴素递归 fib(30)：调用 %d 次\n", naive_calls);

	memo_calls = 0;
	for (int i = 0; i < 50; i++) {
		memo[i] = 0;
	}
	fib_memo(30);
	printf("记忆化 fib(30)：调用 %d 次\n", memo_calls);

	return 0;
}
