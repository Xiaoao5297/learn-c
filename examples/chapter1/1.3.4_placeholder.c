/*
 * 教程来源：chapter1/sections/1.3 第一个 C 程序.md
 * 示例编号：1.3.4
 * 所在小节：1.3.4 printf 占位符初步
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.3.4_placeholder.c -o demo
 *
 * 预期输出：
 *   年龄：20
 *   价格：12.500000
 *   价格：12.50
 *   首字母：C
 *   课程：C 语言入门
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.3.4 placeholder.c
#include <stdio.h>

int main(void)
{
	int age = 20;
	double price = 12.5;

	printf("年龄：%d\n", age);
	printf("价格：%f\n", price);
	printf("价格：%.2f\n", price);
	printf("首字母：%c\n", 'C');
	printf("课程：%s\n", "C 语言入门");

	return 0;
}
