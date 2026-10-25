/*
 * 教程来源：chapter10/sections/10.1 预处理与宏.md
 * 示例编号：10.1.2
 * 所在小节：10.1.3 常量宏还是 const
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.1.2_macro_vs_const.c -o demo
 *
 * 预期输出：
 *   宏定义的数组占 32 字节
 *   const 定义的数组占 32 字节
 *   两者元素个数相同：1
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.1.2 macro_vs_const.c
#include <stdio.h>

#define TABLE_SIZE 8

int main(void)
{
	const int table_size = 8;

	int macro_table[TABLE_SIZE];
	int const_table[table_size];

	printf("宏定义的数组占 %zu 字节\n", sizeof(macro_table));
	printf("const 定义的数组占 %zu 字节\n", sizeof(const_table));
	printf("两者元素个数相同：%d\n", TABLE_SIZE == table_size);

	return 0;
}
