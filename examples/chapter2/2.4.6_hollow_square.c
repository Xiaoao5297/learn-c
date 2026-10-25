/*
 * 教程来源：chapter2/sections/2.4 循环控制.md
 * 示例编号：2.4.6
 * 所在小节：空心正方形
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.4.6_hollow_square.c -o demo
 *
 * 预期输出：
 *   *****
 *   *   *
 *   *   *
 *   *   *
 *   *****
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.4.6 hollow_square.c
#include <stdio.h>

int main(void)
{
	int size = 5;

	for (int row = 1; row <= size; row++) {
		for (int col = 1; col <= size; col++) {
			if (row == 1 || row == size || col == 1 || col == size) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
