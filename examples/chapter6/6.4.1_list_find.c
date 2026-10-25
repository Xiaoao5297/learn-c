/*
 * 教程来源：chapter6/sections/6.4 链表进阶.md
 * 示例编号：6.4.1
 * 所在小节：6.4.1 查找
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.4.1_list_find.c -o demo
 *
 * 预期输出：
 *   找到 20
 *   没找到 99
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.4.1 list_find.c
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create_node(int value)
{
	struct node *n = malloc(sizeof(struct node));
	if (n == NULL) {
		return NULL;
	}
	n->data = value;
	n->next = NULL;
	return n;
}

void push_back(struct node **head, int value)
{
	struct node *n = create_node(value);
	if (n == NULL) {
		return;
	}

	if (*head == NULL) {
		*head = n;
		return;
	}

	struct node *tail = *head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = n;
}

struct node *find_node(struct node *head, int target)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		if (cur->data == target) {
			return cur;
		}
	}
	return NULL;
}

void free_list(struct node *head)
{
	struct node *cur = head;
	while (cur != NULL) {
		struct node *next = cur->next;
		free(cur);
		cur = next;
	}
}

int main(void)
{
	struct node *head = NULL;

	int values[] = {10, 20, 30};
	for (int i = 0; i < 3; i++) {
		push_back(&head, values[i]);
	}

	struct node *found = find_node(head, 20);
	if (found != NULL) {
		printf("找到 20\n");
	} else {
		printf("没找到 20\n");
	}

	found = find_node(head, 99);
	if (found == NULL) {
		printf("没找到 99\n");
	}

	free_list(head);
	head = NULL;

	return 0;
}
