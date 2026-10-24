/*
 * 教程来源：chapter2/sections/2.4 循环控制.md
 * 示例编号：2.4.5
 * 所在小节：直角三角形
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.4.5_triangle.c -o demo
 *
 * 预期输出：
 *   *
 *   **
 *   ***
 *   ****
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.4.5 triangle.c
#include <stdio.h>

int main(void)
{
	for (int row = 1; row <= 4; row++) {
		for (int col = 1; col <= row; col++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
