/*
 * 教程来源：chapter8/sections/8.4 线性查找与二分查找.md
 * 示例编号：8.4.1
 * 所在小节：8.4.1 线性查找：从头找到尾
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 8.4.1_linear_search.c -o demo
 *
 * 预期输出：
 *   找到 70，下标是 3
 *   没找到 100
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 8.4.1 linear_search.c
#include <stdio.h>

int linear_search(const int nums[], int count, int target)
{
	for (int i = 0; i < count; i++) {
		if (nums[i] == target) {
			return i;
		}
	}

	return -1;
}

int main(void)
{
	int scores[6] = {88, 62, 95, 70, 79, 55};

	int index = linear_search(scores, 6, 70);
	if (index >= 0) {
		printf("找到 70，下标是 %d\n", index);
	} else {
		printf("没找到 70\n");
	}

	index = linear_search(scores, 6, 100);
	if (index >= 0) {
		printf("找到 100，下标是 %d\n", index);
	} else {
		printf("没找到 100\n");
	}

	return 0;
}
