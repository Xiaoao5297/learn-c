/*
 * 教程来源：chapter6/sections/6.3 链表.md
 * 示例编号：6.3.3
 * 所在小节：6.3.3 创建节点
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.3.3_create_node.c -o demo
 *
 * 预期输出：
 *   head->data = 10
 *   head->next = NULL
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.3.3 create_node.c
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
	n->next = NULL;    /* 新节点先不连任何人 */
	return n;
}

int main(void)
{
	struct node *head = create_node(10);
	if (head == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	printf("head->data = %d\n", head->data);
	printf("head->next = %s\n", head->next == NULL ? "NULL" : "非NULL");

	free(head);
	head = NULL;

	return 0;
}
