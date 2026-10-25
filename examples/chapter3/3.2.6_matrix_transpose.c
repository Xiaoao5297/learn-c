/*
 * 教程来源：chapter3/sections/3.2 二维数组.md
 * 示例编号：3.2.6
 * 所在小节：3.2.6 例：矩阵转置
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.2.6_matrix_transpose.c -o demo
 *
 * 预期输出：
 *   转置前的 a：
 *      1   2   3
 *      4   5   6
 *   转置后的 b：
 *      1   4
 *      2   5
 *      3   6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.2.6 matrix_transpose.c
#include <stdio.h>

#define ROWS 2
#define COLS 3

int main(void)
{
	int a[ROWS][COLS] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	int b[COLS][ROWS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			b[j][i] = a[i][j];
		}
	}

	printf("转置前的 a：\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}

	printf("转置后的 b：\n");
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			printf("%4d", b[i][j]);
		}
		printf("\n");
	}

	return 0;
}
