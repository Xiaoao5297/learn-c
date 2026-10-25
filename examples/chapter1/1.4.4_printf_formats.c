/*
 * 教程来源：chapter1/sections/1.4 变量与数据类型.md
 * 示例编号：1.4.4
 * 所在小节：1.4.4 printf 格式符表
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.4.4_printf_formats.c -o demo
 *
 * 预期输出：
 *   20
 *   12.500000
 *   12.50
 *   L
 *   Lin
 *   4
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.4.4 printf_formats.c
#include <stdio.h>

int main(void)
{
	int age = 20;
	double price = 12.5;
	char initial = 'L';
	char name[] = "Lin";

	printf("%d\n", age);
	printf("%f\n", price);
	printf("%.2f\n", price);
	printf("%c\n", initial);
	printf("%s\n", name);
	printf("%zu\n", sizeof(int));

	return 0;
}
