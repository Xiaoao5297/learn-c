/*
 * 教程来源：chapter3/sections/3.2 二维数组.md
 * 示例编号：3.2.7
 * 所在小节：3.2.7 例：按行求和
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.2.7_matrix_row_sum.c -o demo
 *
 * 预期输出：
 *   第 0 行的和是 255
 *   第 1 行的和是 248
 *   第 2 行的和是 230
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.2.7 matrix_row_sum.c
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main(void)
{
	int scores[ROWS][COLS] = {
		{85, 92, 78},
		{65, 88, 95},
		{100, 54, 76}
	};

	for (int row = 0; row < ROWS; row++) {
		int sum = 0;
		for (int col = 0; col < COLS; col++) {
			sum += scores[row][col];
		}
		printf("第 %d 行的和是 %d\n", row, sum);
	}

	return 0;
}
