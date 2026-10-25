/*
 * 教程来源：chapter4/sections/4.2 指针与数组.md
 * 示例编号：4.2.4
 * 所在小节：4.2.4 数组作为函数参数
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.2.4_array_param.c -o demo
 *
 * 预期输出：
 *   加分前总分：400
 *   加分后总分：425
 *   第一个人的成绩变成了 85
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.2.4 array_param.c
#include <stdio.h>

int sum(const int nums[], int count)
{
	int total = 0;

	for (int i = 0; i < count; i++) {
		total += nums[i];
	}

	return total;
}

void add_bonus(int nums[], int count)
{
	for (int i = 0; i < count; i++) {
		nums[i] += 5;
	}
}

int main(void)
{
	int scores[5] = {80, 90, 70, 60, 100};

	printf("加分前总分：%d\n", sum(scores, 5));

	add_bonus(scores, 5);

	printf("加分后总分：%d\n", sum(scores, 5));
	printf("第一个人的成绩变成了 %d\n", scores[0]);

	return 0;
}
