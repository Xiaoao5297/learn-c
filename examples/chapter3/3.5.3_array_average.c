/*
 * 教程来源：chapter3/sections/3.5 数组与函数.md
 * 示例编号：3.5.3
 * 所在小节：3.5.3 一维数组传参示例
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.5.3_array_average.c -o demo
 *
 * 预期输出：
 *   平均分：79.0
 *   最高分：100
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.5.3 array_average.c
#include <stdio.h>

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
	int scores[6] = {85, 92, 78, 65, 100, 54};

	printf("平均分：%.1f\n", average(scores, 6));
	printf("最高分：%d\n", max_of(scores, 6));

	return 0;
}
