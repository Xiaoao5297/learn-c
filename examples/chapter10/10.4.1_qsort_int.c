/*
 * 教程来源：chapter10/sections/10.4 qsort 与比较器.md
 * 示例编号：10.4.1
 * 所在小节：10.4.3 第一个实战：int 数组排序
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.4.1_qsort_int.c -o demo
 *
 * 预期输出：
 *   升序：2 2 4 5 7 9
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.4.1 qsort_int.c
#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;

	return (x > y) - (x < y);
}

int main(void)
{
	int nums[6] = {7, 2, 9, 4, 5, 2};

	qsort(nums, 6, sizeof(int), compare_int);

	printf("升序：");
	for (int i = 0; i < 6; i++) {
		printf("%d", nums[i]);
		if (i < 5) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
