/*
 * 教程来源：chapter3/sections/3.1 数组.md
 * 示例编号：3.1.8
 * 所在小节：3.1.8 统计：求和、平均分、最值
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.1.8_array_stats.c -o demo
 *
 * 预期输出：
 *   总分：638
 *   平均分：79.8
 *   最高分：100
 *   最低分：54
 *   及格人数：7
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.1.8 array_stats.c
#include <stdio.h>

int main(void)
{
	int scores[8] = {85, 92, 78, 65, 100, 54, 88, 76};
	int count = 8;

	int sum = 0;
	int max = scores[0];
	int min = scores[0];
	int pass = 0;

	for (int i = 0; i < count; i++) {
		sum += scores[i];
		if (scores[i] > max) {
			max = scores[i];
		}
		if (scores[i] < min) {
			min = scores[i];
		}
		if (scores[i] >= 60) {
			pass++;
		}
	}

	printf("总分：%d\n", sum);
	printf("平均分：%.1f\n", (double)sum / count);
	printf("最高分：%d\n", max);
	printf("最低分：%d\n", min);
	printf("及格人数：%d\n", pass);

	return 0;
}
