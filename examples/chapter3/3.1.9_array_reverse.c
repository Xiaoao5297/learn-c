/*
 * 教程来源：chapter3/sections/3.1 数组.md
 * 示例编号：3.1.9
 * 所在小节：3.1.9 逆序输出
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.1.9_array_reverse.c -o demo
 *
 * 预期输出：
 *   5
 *   4
 *   3
 *   2
 *   1
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.1.9 array_reverse.c
#include <stdio.h>

int main(void)
{
	int nums[5] = {1, 2, 3, 4, 5};

	for (int i = 4; i >= 0; i--) {
		printf("%d\n", nums[i]);
	}

	return 0;
}
