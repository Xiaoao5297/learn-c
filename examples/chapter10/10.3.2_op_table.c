/*
 * 教程来源：chapter10/sections/10.3 函数指针.md
 * 示例编号：10.3.2
 * 所在小节：10.3.2 函数指针数组：按下标选函数
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.3.2_op_table.c -o demo
 *
 * 预期输出：
 *   加法：25
 *   减法：15
 *   乘法：100
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.3.2 op_table.c
#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int main(void)
{
	int (*ops[])(int, int) = {add, sub, mul};
	const char *names[] = {"加法", "减法", "乘法"};

	int a = 20;
	int b = 5;

	for (int i = 0; i < 3; i++) {
		printf("%s：%d\n", names[i], ops[i](a, b));
	}

	return 0;
}
