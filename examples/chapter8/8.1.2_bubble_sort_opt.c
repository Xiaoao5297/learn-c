/*
 * 教程来源：chapter8/sections/8.1 冒泡排序.md
 * 示例编号：8.1.2
 * 所在小节：8.1.5 提前退出：swapped 标志
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.1.2_bubble_sort_opt.c -o demo
 *
 * 预期输出：
 *   有序数组：1 2 3 4 5
 *   近乎有序：1 2 3 4 5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.1.2 bubble_sort_opt.c
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
	int sorted[5] = {1, 2, 3, 4, 5};
	int almost[5] = {1, 2, 3, 5, 4};

	bubble_sort(sorted, 5);
	bubble_sort(almost, 5);

	printf("有序数组：");
	for (int i = 0; i < 5; i++) {
		printf("%d", sorted[i]);
		if (i < 4) {
			printf(" ");
		}
	}
	printf("\n");

	printf("近乎有序：");
	for (int i = 0; i < 5; i++) {
		printf("%d", almost[i]);
		if (i < 4) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
