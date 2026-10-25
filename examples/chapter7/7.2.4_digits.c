/*
 * 教程来源：chapter7/sections/7.2 调用栈与栈溢出.md
 * 示例编号：7.2.4
 * 所在小节：7.2.4 拆数字：各位和与倒序打印
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.2.4_digits.c -o demo
 *
 * 预期输出：
 *   2026 各位之和 = 10
 *   6 2 0 2
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.2.4 digits.c
#include <stdio.h>

int digit_sum(int n)
{
	if (n == 0) {
		return 0;
	}
	return n % 10 + digit_sum(n / 10);
}

void print_digits(int n)
{
	if (n == 0) {
		return;
	}
	printf("%d ", n % 10);
	print_digits(n / 10);
}

int main(void)
{
	printf("2026 各位之和 = %d\n", digit_sum(2026));
	print_digits(2026);
	printf("\n");

	return 0;
}
