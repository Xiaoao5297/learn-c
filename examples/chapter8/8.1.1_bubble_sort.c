/*
 * 教程来源：chapter8/sections/8.1 冒泡排序.md
 * 示例编号：8.1.1
 * 所在小节：8.1.3 基本实现
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.1.1_bubble_sort.c -o demo
 *
 * 预期输出：
 *   排序前：5 2 9 1 7
 *   排序后：1 2 5 7 9
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.1.1 bubble_sort.c
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

void print_array(const int nums[], int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d", nums[i]);
		if (i < count - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int main(void)
{
	int nums[5] = {5, 2, 9, 1, 7};

	printf("排序前：");
	print_array(nums, 5);

	bubble_sort(nums, 5);

	printf("排序后：");
	print_array(nums, 5);

	return 0;
}
