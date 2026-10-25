/*
 * 教程来源：chapter8/sections/8.4 线性查找与二分查找.md
 * 示例编号：8.4.3
 * 所在小节：8.4.4 先排序，再二分：黄金搭档
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.4.3_sort_then_search.c -o demo
 *
 * 预期输出：
 *   排序后：55 62 70 79 88 95
 *   79 分的下标是 3，排名第 4
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.4.3 sort_then_search.c
#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int nums[], int count)
{
	for (int i = 0; i < count - 1; i++) {
		bool swapped = false;

		for (int j = 0; j < count - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
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

int main(void)
{
	int scores[6] = {88, 62, 95, 70, 79, 55};

	bubble_sort(scores, 6);

	printf("排序后：");
	for (int i = 0; i < 6; i++) {
		printf("%d", scores[i]);
		if (i < 5) {
			printf(" ");
		}
	}
	printf("\n");

	int target = 79;
	int index = binary_search(scores, 6, target);
	if (index >= 0) {
		printf("%d 分的下标是 %d，排名第 %d\n",
		       target, index, index + 1);
	} else {
		printf("没有 %d 分\n", target);
	}

	return 0;
}
