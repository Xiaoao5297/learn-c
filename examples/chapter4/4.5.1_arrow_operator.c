/*
 * 教程来源：chapter4/sections/4.5 结构体与指针.md
 * 示例编号：4.5.1
 * 所在小节：4.5.1 箭头运算符 -
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.5.1_arrow_operator.c -o demo
 *
 * 预期输出：
 *   (*p).age = 18
 *   p->age   = 18
 *   p->name  = 小明
 *   修改后 s.age = 19
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.5.1 arrow_operator.c
#include <stdio.h>

struct student {
	char name[20];
	int age;
	double score;
};

int main(void)
{
	struct student s = {"小明", 18, 92.5};
	struct student *p = &s;

	printf("(*p).age = %d\n", (*p).age);
	printf("p->age   = %d\n", p->age);
	printf("p->name  = %s\n", p->name);

	p->age = 19;
	printf("修改后 s.age = %d\n", s.age);

	return 0;
}
