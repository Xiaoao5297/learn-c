/*
 * 教程来源：chapter3/sections/3.5 数组与函数.md
 * 示例编号：3.5.4
 * 所在小节：3.5.4 二维数组传参：列数必须写死
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.5.4_matrix_param.c -o demo
 *
 * 预期输出：
 *      1   2   3
 *      4   5   6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.5.4 matrix_param.c
#include <stdio.h>

#define ROWS 2
#define COLS 3

void print_matrix(int m[][COLS], int rows)
{
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < COLS; col++) {
			printf("%4d", m[row][col]);
		}
		printf("\n");
	}
}

int main(void)
{
	int matrix[ROWS][COLS] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	print_matrix(matrix, ROWS);

	return 0;
}
