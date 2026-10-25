/*
 * 教程来源：chapter6/sections/6.3 链表.md
 * 示例编号：6.3.6
 * 所在小节：6.3.6 遍历：顺着 next 走
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.3.6_list_basic.c -o demo
 *
 * 预期输出：
 *   尾插后：10 -> 20 -> 30 -> NULL
 *   头插后：1 -> 5 -> 10 -> 20 -> 30 -> NULL
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.3.6 list_basic.c
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

void push_front(struct node **head, int value)
{
	struct node *n = create_node(value);
	if (n == NULL) {
		return;
	}
	n->next = *head;
	*head = n;
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

void free_list(struct node *head)
{
	struct node *cur = head;
	while (cur != NULL) {
		struct node *next = cur->next;    /* 先记住下一个 */
		free(cur);                        /* 再释放当前 */
		cur = next;
	}
}

int main(void)
{
	struct node *head = NULL;

	push_back(&head, 10);
	push_back(&head, 20);
	push_back(&head, 30);
	printf("尾插后：");
	print_list(head);

	push_front(&head, 5);
	push_front(&head, 1);
	printf("头插后：");
	print_list(head);

	free_list(head);
	head = NULL;

	return 0;
}
