/*
 * 教程来源：chapter4/sections/4.5 结构体与指针.md
 * 示例编号：4.5.4
 * 所在小节：4.5.4 综合示例：找出最高分学生
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.5.4_top_student.c -o demo
 *
 * 预期输出：
 *   最高分：小丽（98.0 分）
 *   地址没有变，students[3].score = 98.0
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.5.4 top_student.c
#include <stdio.h>

struct student {
	char name[20];
	double score;
};

struct student *top_student(struct student arr[], int count)
{
	struct student *best = &arr[0];

	for (int i = 1; i < count; i++) {
		if (arr[i].score > best->score) {
			best = &arr[i];
		}
	}

	return best;
}

int main(void)
{
	struct student students[5] = {
		{"小明", 85.0},
		{"小红", 92.0},
		{"小刚", 76.0},
		{"小丽", 98.0},
		{"小华", 60.0}
	};

	struct student *best = top_student(students, 5);

	printf("最高分：%s（%.1f 分）\n", best->name, best->score);
	printf("地址没有变，students[3].score = %.1f\n", students[3].score);

	return 0;
}
