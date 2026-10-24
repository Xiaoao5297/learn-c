/*
 * 教程来源：chapter2/sections/2.5 函数基础.md
 * 示例编号：2.5.7
 * 所在小节：计算阶乘
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.5.7_factorial.c -o demo
 *
 * 预期输出：
 *   5! = 120
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.5.7 factorial.c
#include <stdio.h>

int factorial(int n)
{
	int result = 1;

	for (int i = 2; i <= n; i++) {
		result *= i;
	}

	return result;
}

int main(void)
{
	printf("5! = %d\n", factorial(5));

	return 0;
}
