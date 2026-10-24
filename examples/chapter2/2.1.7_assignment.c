/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.7
 * 所在小节：2.1.7 赋值运算符
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.7_assignment.c -o demo
 *
 * 预期输出：
 *   加 20 后：120
 *   减 30 后：90
 *   乘 2 后：180
 *   除 3 后：60
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.7 assignment.c
#include <stdio.h>

int main(void)
{
	int total = 100;

	total += 20;
	printf("加 20 后：%d\n", total);

	total -= 30;
	printf("减 30 后：%d\n", total);

	total *= 2;
	printf("乘 2 后：%d\n", total);

	total /= 3;
	printf("除 3 后：%d\n", total);

	return 0;
}
