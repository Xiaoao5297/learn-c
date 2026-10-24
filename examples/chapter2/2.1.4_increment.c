/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.4
 * 所在小节：2.1.4 自增和自减
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.4_increment.c -o demo
 *
 * 预期输出：
 *   x++ 的值：5
 *   自增后 x：6
 *   ++x 的值：7
 *   自减后 x：6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.4 increment.c
#include <stdio.h>

int main(void)
{
	int x = 5;

	printf("x++ 的值：%d\n", x++);
	printf("自增后 x：%d\n", x);
	printf("++x 的值：%d\n", ++x);
	printf("自减后 x：%d\n", --x);

	return 0;
}
