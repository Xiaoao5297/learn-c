/*
 * 教程来源：chapter7/sections/7.3 斐波那契与递归代价.md
 * 示例编号：7.3.2
 * 所在小节：7.3.2 递归版：照着公式抄
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.3.2_fib_naive.c -o demo
 *
 * 预期输出：
 *   1 1 2 3 5 8 13 21 34 55
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.3.2 fib_naive.c
#include <stdio.h>

int fib(int n)
{
	if (n == 1 || n == 2) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int main(void)
{
	for (int i = 1; i <= 10; i++) {
		printf("%d ", fib(i));
	}
	printf("\n");

	return 0;
}
