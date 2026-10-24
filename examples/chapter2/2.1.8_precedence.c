/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.8
 * 所在小节：2.1.8 运算符优先级
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.8_precedence.c -o demo
 *
 * 预期输出：
 *   2 + 3 * 4 = 14
 *   (2 + 3) * 4 = 20
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.8 precedence.c
#include <stdio.h>

int main(void)
{
	int a = 2 + 3 * 4;
	int b = (2 + 3) * 4;

	printf("2 + 3 * 4 = %d\n", a);
	printf("(2 + 3) * 4 = %d\n", b);

	return 0;
}
