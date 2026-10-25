/*
 * 教程来源：chapter3/sections/3.5 数组与函数.md
 * 示例编号：3.5.6
 * 所在小节：3.5.6 冒泡排序的优化：提前退出
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.5.6_bubble_sort_opt.c -o demo
 *
 * 预期输出：
 *   1 2 3 4 5 6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.5.6 bubble_sort_opt.c
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

int main(void)
{
	int nums[6] = {1, 2, 3, 4, 5, 6};

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
