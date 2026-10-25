/*
 * 教程来源：chapter2/sections/2.5 函数基础.md
 * 示例编号：2.5.9
 * 所在小节：2.5.8 综合示例：简易计算器
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.5.9_calculator.c -o demo
 *
 * 预期输出：
 *   8 + 3 = 11
 *   8 - 3 = 5
 *   8 * 3 = 24
 *   8 / 3 = 2
 *   8 / 0 = 0
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.5.9 calculator.c
#include <stdio.h>

int calculate(int left, int right, char op)
{
	switch (op) {
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		if (right == 0) {
			return 0;
		}
		return left / right;
	default:
		return 0;
	}
}

int main(void)
{
	printf("8 + 3 = %d\n", calculate(8, 3, '+'));
	printf("8 - 3 = %d\n", calculate(8, 3, '-'));
	printf("8 * 3 = %d\n", calculate(8, 3, '*'));
	printf("8 / 3 = %d\n", calculate(8, 3, '/'));
	printf("8 / 0 = %d\n", calculate(8, 0, '/'));

	return 0;
}
