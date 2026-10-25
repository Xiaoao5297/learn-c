/*
 * 教程来源：chapter8/sections/8.5 综合项目：快速排序.md
 * 示例编号：8.5.2
 * 所在小节：8.5.3 加上递归，快排完成
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.5.2_quick_sort.c -o demo
 *
 * 预期输出：
 *   排序前：5 3 8 4 2 7
 *   排序后：2 3 4 5 7 8
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.5.2 quick_sort.c
#include <stdio.h>

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int nums[], int left, int right)
{
	int pivot = nums[right];
	int i = left - 1;

	for (int j = left; j < right; j++) {
		if (nums[j] <= pivot) {
			i++;
			swap_int(&nums[i], &nums[j]);
		}
	}

	swap_int(&nums[i + 1], &nums[right]);
	return i + 1;
}

void quick_sort(int nums[], int left, int right)
{
	if (left >= right) {
		return;
	}

	int p = partition(nums, left, right);
	quick_sort(nums, left, p - 1);
	quick_sort(nums, p + 1, right);
}

int main(void)
{
	int nums[6] = {5, 3, 8, 4, 2, 7};

	printf("排序前：");
	for (int i = 0; i < 6; i++) {
		printf("%d", nums[i]);
		if (i < 5) {
			printf(" ");
		}
	}
	printf("\n");

	quick_sort(nums, 0, 5);

	printf("排序后：");
	for (int i = 0; i < 6; i++) {
		printf("%d", nums[i]);
		if (i < 5) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
