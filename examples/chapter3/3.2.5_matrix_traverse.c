/*
 * 教程来源：chapter3/sections/3.2 二维数组.md
 * 示例编号：3.2.5
 * 所在小节：3.2.5 嵌套循环遍历
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.2.5_matrix_traverse.c -o demo
 *
 * 预期输出：
 *     85  92  78  90
 *     65  88  95  72
 *    100  54  76  83
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.2.5 matrix_traverse.c
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main(void)
{
	int matrix[ROWS][COLS] = {
		{85, 92, 78, 90},
		{65, 88, 95, 72},
		{100, 54, 76, 83}
	};

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			printf("%4d", matrix[row][col]);
		}
		printf("\n");
	}

	return 0;
}
