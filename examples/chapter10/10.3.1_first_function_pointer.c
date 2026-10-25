/*
 * 教程来源：chapter10/sections/10.3 函数指针.md
 * 示例编号：10.3.1
 * 所在小节：10.3.1 声明、赋值、调用
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.3.1_first_function_pointer.c -o demo
 *
 * 预期输出：
 *   op = add：20 + 5 = 25
 *   op = sub：20 - 5 = 15
 *   op = mul：20 * 5 = 100
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.3.1 first_function_pointer.c
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
	int (*op)(int, int);

	op = add;
	printf("op = add：20 + 5 = %d\n", op(20, 5));

	op = sub;
	printf("op = sub：20 - 5 = %d\n", op(20, 5));

	op = mul;
	printf("op = mul：20 * 5 = %d\n", op(20, 5));

	return 0;
}
