/*
 * 教程来源：chapter6/sections/6.4 链表进阶.md
 * 示例编号：6.4.3
 * 所在小节：6.4.3 删除的完整演示
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.4.3_list_delete.c -o demo
 *
 * 预期输出：
 *   初始链表：10 -> 20 -> 30 -> 40 -> NULL
 *   删除 20 后：10 -> 30 -> 40 -> NULL
 *   删除 10（头节点）后：30 -> 40 -> NULL
 *   没找到 99，链表不变：30 -> 40 -> NULL
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.4.3 list_delete.c
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

void print_list(struct node *head)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("NULL\n");
}

int delete_node(struct node **head, int target)
{
	if (*head == NULL) {
		return 0;
	}

	if ((*head)->data == target) {
		struct node *to_delete = *head;
		*head = (*head)->next;
		free(to_delete);
		return 1;
	}

	struct node *prev = *head;
	while (prev->next != NULL && prev->next->data != target) {
		prev = prev->next;
	}

	if (prev->next == NULL) {
		return 0;
	}

	struct node *to_delete = prev->next;
	prev->next = to_delete->next;
	free(to_delete);
	return 1;
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

	int values[] = {10, 20, 30, 40};
	for (int i = 0; i < 4; i++) {
		push_back(&head, values[i]);
	}
	printf("初始链表：");
	print_list(head);

	delete_node(&head, 20);
	printf("删除 20 后：");
	print_list(head);

	delete_node(&head, 10);
	printf("删除 10（头节点）后：");
	print_list(head);

	if (delete_node(&head, 99) == 0) {
		printf("没找到 99，链表不变：");
		print_list(head);
	}

	free_list(head);
	head = NULL;

	return 0;
}
