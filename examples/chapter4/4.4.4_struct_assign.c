/*
 * 教程来源：chapter4/sections/4.4 结构体.md
 * 示例编号：4.4.4
 * 所在小节：4.4.4 结构体赋值：整包复制
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.4.4_struct_assign.c -o demo
 *
 * 预期输出：
 *   a：小明 18 岁 90.0 分
 *   b：小明 19 岁 88.0 分
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.4.4 struct_assign.c
#include <stdio.h>

struct student {
	char name[20];
	int age;
	double score;
};

int main(void)
{
	struct student a = {"小明", 18, 90.0};
	struct student b = a;    /* 整包复制 */

	b.age = 19;
	b.score = 88.0;

	printf("a：%s %d 岁 %.1f 分\n", a.name, a.age, a.score);
	printf("b：%s %d 岁 %.1f 分\n", b.name, b.age, b.score);

	return 0;
}
