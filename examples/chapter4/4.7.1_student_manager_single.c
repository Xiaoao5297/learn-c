/*
 * 教程来源：chapter4/sections/4.7 多文件工程与 Makefile.md
 * 示例编号：4.7.1
 * 所在小节：4.7.2 先看一个单文件版本
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.7.1_student_manager_single.c -o demo
 *
 * 预期输出：
 *   小明，20 岁，88.5 分
 *   小红，19 岁，92.0 分
 *   平均分：90.2
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.7.1 student_manager_single.c
#include <stdio.h>

#define MAX_NAME 32
#define STUDENT_COUNT 2

struct student {
	char name[MAX_NAME];
	int age;
	double score;
};

void print_student(const struct student *student)
{
	printf("%s，%d 岁，%.1f 分\n",
	       student->name, student->age, student->score);
}

double average_score(const struct student students[], int count)
{
	double sum = 0.0;

	for (int i = 0; i < count; i++) {
		sum += students[i].score;
	}

	if (count == 0) {
		return 0.0;
	}
	return sum / count;
}

int main(void)
{
	struct student students[STUDENT_COUNT] = {
		{"小明", 20, 88.5},
		{"小红", 19, 92.0},
	};
	double average = average_score(students, STUDENT_COUNT);

	for (int i = 0; i < STUDENT_COUNT; i++) {
		print_student(&students[i]);
	}

	printf("平均分：%.1f\n", average);

	return 0;
}
