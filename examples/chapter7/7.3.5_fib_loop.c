/*
 * 教程来源：chapter7/sections/7.3 斐波那契与递归代价.md
 * 示例编号：7.3.5
 * 所在小节：7.3.5 循环版：从前往后推
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.3.5_fib_loop.c -o demo
 *
 * 预期输出：
 *   1 1 2 3 5 8 13 21 34 55
 *   fib(40) = 102334155
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.3.5 fib_loop.c
#include <stdio.h>

int fib_loop(int n)
{
	if (n == 1 || n == 2) {
		return 1;
	}
	int a = 1;
	int b = 1;
	int c = 0;

	for (int i = 3; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	return b;
}

int main(void)
{
	for (int i = 1; i <= 10; i++) {
		printf("%d ", fib_loop(i));
	}
	printf("\n");
	printf("fib(40) = %d\n", fib_loop(40));

	return 0;
}
