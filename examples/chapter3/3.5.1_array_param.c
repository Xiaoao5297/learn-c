/*
 * 教程来源：chapter3/sections/3.5 数组与函数.md
 * 示例编号：3.5.1
 * 所在小节：3.5.1 数组作参数：退化为指针
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.5.1_array_param.c -o demo
 *
 * 预期输出：
 *   2 4 6 8 10
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.5.1 array_param.c
#include <stdio.h>

void double_all(int nums[], int count)
{
	for (int i = 0; i < count; i++) {
		nums[i] *= 2;
	}
}

int main(void)
{
	int nums[5] = {1, 2, 3, 4, 5};

	double_all(nums, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d", nums[i]);
		if (i < 4) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
