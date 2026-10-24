/*
 * 教程来源：chapter2/sections/2.5 函数基础.md
 * 示例编号：2.5.4
 * 所在小节：2.5.4 函数声明
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.5.4_prototype.c -o demo
 *
 * 预期输出：
 *   5 的平方是 25
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.5.4 prototype.c
#include <stdio.h>

int square(int x);

int main(void)
{
	printf("5 的平方是 %d\n", square(5));

	return 0;
}

int square(int x)
{
	return x * x;
}
