/*
 * 教程来源：chapter4/sections/4.5 结构体与指针.md
 * 示例编号：4.5.2
 * 所在小节：4.5.2 函数传结构体：传值还是传指针
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.5.2_struct_param.c -o demo
 *
 * 预期输出：
 *   修改前：92.5
 *   按值传递后：92.5
 *   按指针传递后：97.5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.5.2 struct_param.c
#include <stdio.h>

struct student {
	char name[20];
	double score;
};

void raise_by_value(struct student s)
{
	s.score += 5.0;
}

void raise_by_pointer(struct student *s, double bonus)
{
	s->score += bonus;
}

int main(void)
{
	struct student stu = {"小明", 92.5};

	printf("修改前：%.1f\n", stu.score);

	raise_by_value(stu);
	printf("按值传递后：%.1f\n", stu.score);

	raise_by_pointer(&stu, 5.0);
	printf("按指针传递后：%.1f\n", stu.score);

	return 0;
}
