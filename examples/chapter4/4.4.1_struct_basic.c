/*
 * 教程来源：chapter4/sections/4.4 结构体.md
 * 示例编号：4.4.1
 * 所在小节：4.4.1 定义和使用结构体
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.4.1_struct_basic.c -o demo
 *
 * 预期输出：
 *   小明 18 岁，成绩 92.5
 *   更新后的成绩：95.0
 *   s1 占 32 字节
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.4.1 struct_basic.c
#include <stdio.h>

struct student {
	char name[20];
	int age;
	double score;
};

int main(void)
{
	struct student s1 = {"小明", 18, 92.5};

	printf("%s %d 岁，成绩 %.1f\n", s1.name, s1.age, s1.score);

	s1.score = 95.0;
	printf("更新后的成绩：%.1f\n", s1.score);

	printf("s1 占 %zu 字节\n", sizeof(s1));

	return 0;
}
