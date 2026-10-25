/*
 * 教程来源：chapter4/sections/4.4 结构体.md
 * 示例编号：4.4.2
 * 所在小节：4.4.2 结构体数组
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.4.2_struct_array.c -o demo
 *
 * 预期输出：
 *   小明 18 岁 85.0 分
 *   小红 17 岁 92.0 分
 *   小刚 18 岁 76.0 分
 *   平均分：84.3
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.4.2 struct_array.c
#include <stdio.h>

struct student {
	char name[20];
	int age;
	double score;
};

int main(void)
{
	struct student students[3] = {
		{"小明", 18, 85.0},
		{"小红", 17, 92.0},
		{"小刚", 18, 76.0}
	};

	double sum = 0.0;

	for (int i = 0; i < 3; i++) {
		printf("%s %d 岁 %.1f 分\n",
		       students[i].name, students[i].age, students[i].score);
		sum += students[i].score;
	}

	printf("平均分：%.1f\n", sum / 3);

	return 0;
}
