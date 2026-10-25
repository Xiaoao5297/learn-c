/*
 * 教程来源：chapter10/sections/10.4 qsort 与比较器.md
 * 示例编号：10.4.4
 * 所在小节：10.4.4 给结构体排序
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.4.4_qsort_struct.c -o demo
 *
 * 预期输出：
 *   按姓名：Alice(88) Bob(72) Carol(95) Dave(88)
 *   按分数降序：Carol(95) Alice(88) Dave(88) Bob(72)
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.4.4 qsort_struct.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[32];
	int score;
};

int compare_by_name(const void *a, const void *b)
{
	const struct student *sa = (const struct student *)a;
	const struct student *sb = (const struct student *)b;

	return strcmp(sa->name, sb->name);
}

int compare_by_score_desc(const void *a, const void *b)
{
	const struct student *sa = (const struct student *)a;
	const struct student *sb = (const struct student *)b;

	return (sa->score < sb->score) - (sa->score > sb->score);
}

void print_students(const struct student list[], int count)
{
	for (int i = 0; i < count; i++) {
		printf("%s(%d)", list[i].name, list[i].score);
		if (i < count - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int main(void)
{
	struct student list[4] = {
		{"Bob", 72},
		{"Alice", 88},
		{"Dave", 88},
		{"Carol", 95},
	};

	qsort(list, 4, sizeof(struct student), compare_by_name);
	printf("按姓名：");
	print_students(list, 4);

	qsort(list, 4, sizeof(struct student), compare_by_score_desc);
	printf("按分数降序：");
	print_students(list, 4);

	return 0;
}
