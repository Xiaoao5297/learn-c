/*
 * 教程来源：chapter3/sections/3.5 数组与函数.md
 * 示例编号：3.5.5
 * 所在小节：3.5.5 冒泡排序
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.5.5_bubble_sort.c -o demo
 *
 * 预期输出：
 *   12 25 33 64 88 90
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.5.5 bubble_sort.c
#include <stdio.h>

void bubble_sort(int nums[], int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int nums[6] = {64, 25, 90, 12, 88, 33};

	bubble_sort(nums, 6);

	for (int i = 0; i < 6; i++) {
		printf("%d", nums[i]);
		if (i < 5) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
