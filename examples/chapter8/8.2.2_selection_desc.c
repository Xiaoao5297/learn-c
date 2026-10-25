/*
 * 教程来源：chapter8/sections/8.2 选择排序.md
 * 示例编号：8.2.2
 * 所在小节：8.2.4 变一变方向：从大到小
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.2.2_selection_desc.c -o demo
 *
 * 预期输出：
 *   90 88 64 33 25 12
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.2.2 selection_desc.c
#include <stdio.h>

void selection_sort_desc(int nums[], int count)
{
	for (int i = 0; i < count - 1; i++) {
		int max_index = i;

		for (int j = i + 1; j < count; j++) {
			if (nums[j] > nums[max_index]) {
				max_index = j;
			}
		}

		if (max_index != i) {
			int temp = nums[i];
			nums[i] = nums[max_index];
			nums[max_index] = temp;
		}
	}
}

int main(void)
{
	int nums[6] = {64, 25, 90, 12, 88, 33};

	selection_sort_desc(nums, 6);

	for (int i = 0; i < 6; i++) {
		printf("%d", nums[i]);
		if (i < 5) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
