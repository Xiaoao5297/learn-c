/*
 * 教程来源：chapter8/sections/8.5 综合项目：快速排序.md
 * 示例编号：8.5.1
 * 所在小节：8.5.2 一趟分区：Lomuto 写法
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.5.1_partition.c -o demo
 *
 * 预期输出：
 *   分区结果：5 3 4 2 7 8
 *   基准 7 归位到下标 4
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.5.1 partition.c
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

int main(void)
{
	int nums[6] = {5, 3, 8, 4, 2, 7};

	int p = partition(nums, 0, 5);

	printf("分区结果：");
	for (int i = 0; i < 6; i++) {
		printf("%d", nums[i]);
		if (i < 5) {
			printf(" ");
		}
	}
	printf("\n");
	printf("基准 7 归位到下标 %d\n", p);

	return 0;
}
