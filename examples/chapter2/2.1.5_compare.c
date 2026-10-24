/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.5
 * 所在小节：2.1.5 比较运算符
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.5_compare.c -o demo
 *
 * 预期输出：
 *   a > b：1
 *   a == b：0
 *   a != b：1
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.5 compare.c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int a = 5;
	int b = 3;
	bool greater = a > b;
	bool equal = a == b;

	printf("a > b：%d\n", greater);
	printf("a == b：%d\n", equal);
	printf("a != b：%d\n", a != b);

	return 0;
}
