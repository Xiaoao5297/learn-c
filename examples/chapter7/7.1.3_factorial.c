/*
 * 教程来源：chapter7/sections/7.1 递归入门.md
 * 示例编号：7.1.3
 * 所在小节：7.1.3 阶乘：返回值的递归
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.1.3_factorial.c -o demo
 *
 * 预期输出：
 *   5! = 120
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.1.3 factorial.c
#include <stdio.h>

int fact(int n)
{
	if (n == 0) {
		return 1;
	}
	return n * fact(n - 1);
}

int main(void)
{
	printf("5! = %d\n", fact(5));

	return 0;
}
