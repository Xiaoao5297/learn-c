/*
 * 教程来源：chapter10/sections/10.4 qsort 与比较器.md
 * 示例编号：10.4.3
 * 所在小节：10.4.3 第一个实战：int 数组排序
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.4.3_qsort_desc_double.c -o demo
 *
 * 预期输出：
 *   分数降序：91 85 78 73 66
 *   身高升序：1.62 1.68 1.75 1.80
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.4.3 qsort_desc_double.c
#include <stdio.h>
#include <stdlib.h>

int compare_int_desc(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;

	return (x < y) - (x > y);
}

int compare_double(const void *a, const void *b)
{
	double x = *(const double *)a;
	double y = *(const double *)b;

	if (x < y) {
		return -1;
	}
	if (x > y) {
		return 1;
	}
	return 0;
}

void print_ints(const int nums[], int count)
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
	int scores[5] = {73, 91, 66, 85, 78};

	qsort(scores, 5, sizeof(int), compare_int_desc);
	printf("分数降序：");
	print_ints(scores, 5);

	double heights[4] = {1.75, 1.62, 1.80, 1.68};

	qsort(heights, 4, sizeof(double), compare_double);
	printf("身高升序：");
	for (int i = 0; i < 4; i++) {
		printf("%.2f", heights[i]);
		if (i < 3) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
