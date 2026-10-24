/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.2
 * 所在小节：2.1.2 整数除法和浮点数除法
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.2_integer_division.c -o demo
 *
 * 预期输出：
 *   整数除法：7 / 2 = 3
 *   浮点除法：7.0 / 2.0 = 3.50
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.2 integer_division.c
#include <stdio.h>

int main(void)
{
	int a = 7;
	int b = 2;

	printf("整数除法：%d / %d = %d\n", a, b, a / b);
	printf("浮点除法：%.1f / %.1f = %.2f\n", (double)a, (double)b, (double)a / (double)b);

	return 0;
}
