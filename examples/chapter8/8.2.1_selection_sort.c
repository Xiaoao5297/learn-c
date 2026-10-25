/*
 * 教程来源：chapter8/sections/8.2 选择排序.md
 * 示例编号：8.2.1
 * 所在小节：8.2.2 实现
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.2.1_selection_sort.c -o demo
 *
 * 预期输出：
 *   排序前：5 2 9 1 7
 *   排序后：1 2 5 7 9
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.2.1 selection_sort.c
#include <stdio.h>

void selection_sort(int nums[], int count)
{
	for (int i = 0; i < count - 1; i++) {
		int min_index = i;

		for (int j = i + 1; j < count; j++) {
			if (nums[j] < nums[min_index]) {
				min_index = j;
			}
		}

		if (min_index != i) {
			int temp = nums[i];
			nums[i] = nums[min_index];
			nums[min_index] = temp;
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

	selection_sort(nums, 5);

	printf("排序后：");
	print_array(nums, 5);

	return 0;
}
