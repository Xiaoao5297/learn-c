/*
 * 教程来源：chapter6/sections/6.4 链表进阶.md
 * 示例编号：6.4.4
 * 所在小节：6.4.4 综合项目：成绩单链表
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.4.4_score_list.c -o demo
 *
 * 预期输出：
 *   === 成绩单 ===
 *   第1名：xiaoli（98.0 分）
 *   第2名：xiaohong（92.0 分）
 *   第3名：xiaoming（85.5 分）
 *   第4名：xiaogang（76.5 分）
 *   第5名：xiaohua（60.0 分）
 *   查到 xiaohong：92.0 分
 *   删除 xiaohong 后：
 *   第1名：xiaoli（98.0 分）
 *   第2名：xiaoming（85.5 分）
 *   第3名：xiaogang（76.5 分）
 *   第4名：xiaohua（60.0 分）
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.4.4 score_list.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20

struct student {
	char name[NAME_LEN];
	double score;
	struct student *next;
};

struct student *create_student(const char *name, double score)
{
	struct student *s = malloc(sizeof(struct student));
	if (s == NULL) {
		return NULL;
	}

	snprintf(s->name, sizeof(s->name), "%s", name);
	s->score = score;
	s->next = NULL;
	return s;
}

/* 按分数从高到低插入；插入失败返回 0 */
int insert_sorted(struct student **head, const char *name, double score)
{
	struct student *s = create_student(name, score);
	if (s == NULL) {
		return 0;
	}

	/* 空链表，或新学生分数比第一名还高：插到最前面 */
	if (*head == NULL || (*head)->score < score) {
		s->next = *head;
		*head = s;
		return 1;
	}

	/* 找到"下一个分数更低"的位置，插进去 */
	struct student *cur = *head;
	while (cur->next != NULL && cur->next->score >= score) {
		cur = cur->next;
	}
	s->next = cur->next;
	cur->next = s;
	return 1;
}

void print_list(const struct student *head)
{
	int rank = 1;
	for (const struct student *cur = head; cur != NULL; cur = cur->next) {
		printf("第%d名：%s（%.1f 分）\n", rank, cur->name, cur->score);
		rank++;
	}
}

struct student *find_student(struct student *head, const char *name)
{
	for (struct student *cur = head; cur != NULL; cur = cur->next) {
		if (strcmp(cur->name, name) == 0) {
			return cur;
		}
	}
	return NULL;
}

int delete_student(struct student **head, const char *name)
{
	if (*head == NULL) {
		return 0;
	}

	if (strcmp((*head)->name, name) == 0) {
		struct student *to_delete = *head;
		*head = (*head)->next;
		free(to_delete);
		return 1;
	}

	struct student *prev = *head;
	while (prev->next != NULL && strcmp(prev->next->name, name) != 0) {
		prev = prev->next;
	}

	if (prev->next == NULL) {
		return 0;
	}

	struct student *to_delete = prev->next;
	prev->next = to_delete->next;
	free(to_delete);
	return 1;
}

void free_list(struct student *head)
{
	struct student *cur = head;
	while (cur != NULL) {
		struct student *next = cur->next;
		free(cur);
		cur = next;
	}
}

int main(void)
{
	struct student *head = NULL;

	/* 乱序插入，insert_sorted 自动按分数排好 */
	const char *names[] = {"xiaoming", "xiaohong", "xiaogang", "xiaoli", "xiaohua"};
	double scores[] = {85.5, 92.0, 76.5, 98.0, 60.0};
	for (int i = 0; i < 5; i++) {
		if (!insert_sorted(&head, names[i], scores[i])) {
			printf("创建节点失败\n");
			free_list(head);
			return 1;
		}
	}

	printf("=== 成绩单 ===\n");
	print_list(head);

	struct student *found = find_student(head, "xiaohong");
	if (found != NULL) {
		printf("查到 xiaohong：%.1f 分\n", found->score);
	}

	if (delete_student(&head, "xiaohong") == 1) {
		printf("删除 xiaohong 后：\n");
		print_list(head);
	}

	free_list(head);
	head = NULL;

	return 0;
}
