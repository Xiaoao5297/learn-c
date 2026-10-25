/*
 * 教程来源：chapter1/sections/1.4 变量与数据类型.md
 * 示例编号：1.4.3
 * 所在小节：1.4.3 基本数据类型
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.4.3_sizeof_types.c -o demo
 *
 * 预期输出：
 *   int 的大小：4 字节
 *   double 的大小：8 字节
 *   char 的大小：1 字节
 *   变量 x 的大小：4 字节
 *   变量 y 的大小：8 字节
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.4.3 sizeof_types.c
#include <stdio.h>

int main(void)
{
	printf("int 的大小：%zu 字节\n", sizeof(int));
	printf("double 的大小：%zu 字节\n", sizeof(double));
	printf("char 的大小：%zu 字节\n", sizeof(char));

	int x = 10;
	double y = 3.14;

	printf("变量 x 的大小：%zu 字节\n", sizeof(x));
	printf("变量 y 的大小：%zu 字节\n", sizeof(y));

	return 0;
}
