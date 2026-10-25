/*
 * 教程来源：chapter8/sections/8.5 综合项目：快速排序.md
 * 示例编号：8.5.3
 * 所在小节：8.5.6 综合项目：成绩排序加查找小系统
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.5.3_score_system.c -o demo
 *
 * 预期输出：
 *   排序前：88 62 95 70 79
 *   快排后：62 70 79 88 95
 *   79 分的下标是 2，从低到高排第 3
 *   没有 100 分（查找返回 -1）
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.5.3 score_system.c
#include <stdio.h>

#define MAX_SCORES 100

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

int binary_search(const int nums[], int count, int target)
{
	int left = 0;
	int right = count - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return -1;
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
	int scores[MAX_SCORES] = {88, 62, 95, 70, 79};
	int count = 5;

	printf("排序前：");
	print_array(scores, count);

	quick_sort(scores, 0, count - 1);

	printf("快排后：");
	print_array(scores, count);

	int target = 79;
	int index = binary_search(scores, count, target);
	if (index >= 0) {
		printf("%d 分的下标是 %d，从低到高排第 %d\n",
		       target, index, index + 1);
	} else {
		printf("没有 %d 分\n", target);
	}

	int miss = 100;
	index = binary_search(scores, count, miss);
	if (index >= 0) {
		printf("%d 分的下标是 %d\n", miss, index);
	} else {
		printf("没有 %d 分（查找返回 -1）\n", miss);
	}

	return 0;
}
