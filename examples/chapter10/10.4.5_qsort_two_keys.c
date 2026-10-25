/*
 * 教程来源：chapter10/sections/10.4 qsort 与比较器.md
 * 示例编号：10.4.5
 * 所在小节：10.4.5 多关键字比较：总分相同比语文
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.4.5_qsort_two_keys.c -o demo
 *
 * 预期输出：
 *   xiaomei 总分 180（语文 85 数学 95）
 *   xiaohong 总分 175（语文 90 数学 85）
 *   xiaoming 总分 175（语文 85 数学 90）
 *   xiaogang 总分 172（语文 88 数学 84）
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.4.5 qsort_two_keys.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
	char name[32];
	int chinese;
	int math;
};

/* 先比总分（降序），总分相同再按语文分（降序） */
int compare_total_then_chinese(const void *a, const void *b)
{
	const struct record *ra = (const struct record *)a;
	const struct record *rb = (const struct record *)b;

	int total_a = ra->chinese + ra->math;
	int total_b = rb->chinese + rb->math;

	if (total_a != total_b) {
		return (total_a < total_b) - (total_a > total_b);
	}

	return (ra->chinese < rb->chinese) - (ra->chinese > rb->chinese);
}

int main(void)
{
	struct record list[4] = {
		{"xiaoming", 85, 90},
		{"xiaohong", 90, 85},
		{"xiaogang", 88, 84},
		{"xiaomei", 85, 95},
	};

	qsort(list, 4, sizeof(struct record),
	      compare_total_then_chinese);

	for (int i = 0; i < 4; i++) {
		printf("%s 总分 %d（语文 %d 数学 %d）\n",
		       list[i].name,
		       list[i].chinese + list[i].math,
		       list[i].chinese, list[i].math);
	}

	return 0;
}
