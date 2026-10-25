/*
 * 教程来源：chapter2/sections/2.5 函数基础.md
 * 示例编号：2.5.5
 * 所在小节：2.5.5 变量的作用域
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.5.5_scope.c -o demo
 *
 * 预期输出：
 *   number = 10
 *   result = 11
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.5.5 scope.c
#include <stdio.h>

int add_one(int value)
{
	int result = value + 1;
	return result;
}

int main(void)
{
	int number = 10;
	int result = add_one(number);

	printf("number = %d\n", number);
	printf("result = %d\n", result);

	return 0;
}
