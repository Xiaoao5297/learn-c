/*
 * 教程来源：chapter8/sections/8.4 线性查找与二分查找.md
 * 示例编号：8.4.2
 * 所在小节：8.4.2 二分查找：每次砍掉一半
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.4.2_binary_search.c -o demo
 *
 * 预期输出：
 *   找到 60，下标是 4
 *   没找到 61
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.4.2 binary_search.c
#include <stdio.h>

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

int main(void)
{
	int nums[7] = {12, 25, 38, 47, 60, 83, 95};

	int index = binary_search(nums, 7, 60);
	if (index >= 0) {
		printf("找到 60，下标是 %d\n", index);
	} else {
		printf("没找到 60\n");
	}

	index = binary_search(nums, 7, 61);
	if (index >= 0) {
		printf("找到 61，下标是 %d\n", index);
	} else {
		printf("没找到 61\n");
	}

	return 0;
}
