/*
 * 教程来源：chapter2/sections/2.5 函数基础.md
 * 示例编号：2.5.1
 * 所在小节：2.5.1 定义和调用
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.5.1_add.c -o demo
 *
 * 预期输出：
 *   3 + 4 = 7
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.5.1 add.c
#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int main(void)
{
	int result = add(3, 4);

	printf("3 + 4 = %d\n", result);

	return 0;
}
