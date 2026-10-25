/*
 * 教程来源：chapter3/sections/3.2 二维数组.md
 * 示例编号：3.2.4
 * 所在小节：3.2.4 用宏定义行数和列数
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.2.4_matrix_macro.c -o demo
 *
 * 预期输出：
 *   行数是 2
 *   列数是 3
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.2.4 matrix_macro.c
#include <stdio.h>

#define ROWS 2
#define COLS 3

int main(void)
{
	int matrix[ROWS][COLS] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	printf("行数是 %zu\n", sizeof(matrix) / sizeof(matrix[0]));
	printf("列数是 %zu\n", sizeof(matrix[0]) / sizeof(matrix[0][0]));

	return 0;
}
