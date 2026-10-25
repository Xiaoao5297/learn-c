/*
 * 教程来源：chapter3/sections/3.1 数组.md
 * 示例编号：3.1.5
 * 所在小节：3.1.5 遍历数组
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.1.5_array_traverse.c -o demo
 *
 * 预期输出：
 *   scores[0] = 95
 *   scores[1] = 88
 *   scores[2] = 72
 *   scores[3] = 100
 *   scores[4] = 60
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.1.5 array_traverse.c
#include <stdio.h>

int main(void)
{
	int scores[5] = {95, 88, 72, 100, 60};

	for (int i = 0; i < 5; i++) {
		printf("scores[%d] = %d\n", i, scores[i]);
	}

	return 0;
}
