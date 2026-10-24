/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.1
 * 所在小节：2.1.1 算术运算符
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.1_arithmetic.c -o demo
 *
 * 预期输出：
 *   7 + 2 = 9
 *   7 - 2 = 5
 *   7 * 2 = 14
 *   7 / 2 = 3
 *   7 % 2 = 1
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.1 arithmetic.c
#include <stdio.h>

int main(void)
{
	int a = 7;
	int b = 2;

	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = %d\n", a, b, a / b);
	printf("%d %% %d = %d\n", a, b, a % b);

	return 0;
}
