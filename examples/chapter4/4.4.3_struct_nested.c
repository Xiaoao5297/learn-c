/*
 * 教程来源：chapter4/sections/4.4 结构体.md
 * 示例编号：4.4.3
 * 所在小节：4.4.3 嵌套结构体
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.4.3_struct_nested.c -o demo
 *
 * 预期输出：
 *   小红 的生日：2007 年 3 月 15 日
 *   更正后的出生年份：2008
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.4.3 struct_nested.c
#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};

struct student {
	char name[20];
	struct date birthday;    /* 嵌套：成员是另一个结构体 */
	double score;
};

int main(void)
{
	struct student s = {"小红", {2007, 3, 15}, 92.0};

	printf("%s 的生日：%d 年 %d 月 %d 日\n",
	       s.name, s.birthday.year, s.birthday.month, s.birthday.day);

	s.birthday.year = 2008;
	printf("更正后的出生年份：%d\n", s.birthday.year);

	return 0;
}
