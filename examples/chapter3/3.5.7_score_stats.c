/*
 * 教程来源：chapter3/sections/3.5 数组与函数.md
 * 示例编号：3.5.7
 * 所在小节：3.5.7 综合示例：成绩统计程序
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.5.7_score_stats.c -o demo
 *
 * 预期输出：
 *   请输入人数（1 到 50）：
 *   请输入 5 个成绩（0 到 100）：
 *   平均分：84.0
 *   最高分：100
 *   从低到高：65 78 85 92 100
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.5.7 score_stats.c
#include <stdio.h>
#include <stdbool.h>

#define MAX_STUDENTS 50

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

double average(const int scores[], int count)
{
	int sum = 0;

	for (int i = 0; i < count; i++) {
		sum += scores[i];
	}

	return (double)sum / count;
}

int max_of(const int scores[], int count)
{
	int max = scores[0];

	for (int i = 1; i < count; i++) {
		if (scores[i] > max) {
			max = scores[i];
		}
	}

	return max;
}

int main(void)
{
	int scores[MAX_STUDENTS];
	int count = 0;

	printf("请输入人数（1 到 %d）：\n", MAX_STUDENTS);
	if (scanf("%d", &count) != 1 || count < 1 || count > MAX_STUDENTS) {
		printf("人数不合法\n");
		return 1;
	}

	printf("请输入 %d 个成绩（0 到 100）：\n", count);
	for (int i = 0; i < count; i++) {
		if (scanf("%d", &scores[i]) != 1) {
			printf("成绩读取失败\n");
			return 1;
		}
	}

	printf("平均分：%.1f\n", average(scores, count));
	printf("最高分：%d\n", max_of(scores, count));

	bubble_sort(scores, count);
	printf("从低到高：");
	for (int i = 0; i < count; i++) {
		printf("%d", scores[i]);
		if (i < count - 1) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
