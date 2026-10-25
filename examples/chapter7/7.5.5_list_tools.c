/*
 * 教程来源：chapter7/sections/7.5 递归操作链表.md
 * 示例编号：7.5.5
 * 所在小节：7.5.5 综合实战：递归链表工具箱
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.5.5_list_tools.c -o demo
 *
 * 预期输出：
 *   10 -> 20 -> 30 -> 40 -> NULL
 *   40 -> 30 -> 20 -> 10 -> NULL
 *   节点数：4
 *   有 30 吗：1
 *   有 99 吗：0
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.5.5 list_tools.c
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

void print_list(struct node *head)
{
	if (head == NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d -> ", head->data);
	print_list(head->next);
}

void print_reverse(struct node *head)
{
	if (head == NULL) {
		return;
	}
	print_reverse(head->next);
	printf("%d -> ", head->data);
}

int count_nodes(struct node *head)
{
	if (head == NULL) {
		return 0;
	}
	return 1 + count_nodes(head->next);
}

int contains(struct node *head, int value)
{
	if (head == NULL) {
		return 0;
	}
	if (head->data == value) {
		return 1;
	}
	return contains(head->next, value);
}

void free_list(struct node *head)
{
	if (head == NULL) {
		return;
	}
	free_list(head->next);
	free(head);
}

int main(void)
{
	struct node *head = NULL;
	struct node *tail = NULL;

	int values[4] = {10, 20, 30, 40};

	for (int i = 0; i < 4; i++) {
		struct node *n = create_node(values[i]);
		if (n == NULL) {
			free_list(head);
			return 1;
		}
		if (head == NULL) {
			head = n;
		} else {
			tail->next = n;
		}
		tail = n;
	}

	print_list(head);

	print_reverse(head);
	printf("NULL\n");

	printf("节点数：%d\n", count_nodes(head));
	printf("有 30 吗：%d\n", contains(head, 30));
	printf("有 99 吗：%d\n", contains(head, 99));

	free_list(head);
	head = NULL;

	return 0;
}
