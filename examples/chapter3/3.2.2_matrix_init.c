/*
 * 教程来源：chapter3/sections/3.2 二维数组.md
 * 示例编号：3.2.2
 * 所在小节：3.2.2 初始化二维数组
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.2.2_matrix_init.c -o demo
 *
 * 预期输出：
 *   1 2 3
 *   4 5 6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.2.2 matrix_init.c
#include <stdio.h>

int main(void)
{
	int matrix[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 3; col++) {
			printf("%d", matrix[row][col]);
			if (col < 2) {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
