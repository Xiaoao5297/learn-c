/*
 * 教程来源：chapter7/sections/7.5 递归操作链表.md
 * 示例编号：7.5.4
 * 所在小节：7.5.4 递归查找与整链释放
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.5.4_list_free.c -o demo
 *
 * 预期输出：
 *   有 20 吗：1
 *   有 99 吗：0
 *   释放了 3 个节点
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.5.4 list_free.c
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

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

int free_list(struct node *head)
{
	if (head == NULL) {
		return 0;
	}
	int count = free_list(head->next);
	free(head);
	return count + 1;
}

int main(void)
{
	struct node *n1 = malloc(sizeof(struct node));
	struct node *n2 = malloc(sizeof(struct node));
	struct node *n3 = malloc(sizeof(struct node));

	if (n1 == NULL || n2 == NULL || n3 == NULL) {
		free(n1);
		free(n2);
		free(n3);
		return 1;
	}

	n1->data = 10;
	n1->next = n2;
	n2->data = 20;
	n2->next = n3;
	n3->data = 30;
	n3->next = NULL;

	struct node *head = n1;
	printf("有 20 吗：%d\n", contains(head, 20));
	printf("有 99 吗：%d\n", contains(head, 99));

	int freed = free_list(head);
	printf("释放了 %d 个节点\n", freed);
	head = NULL;

	return 0;
}
