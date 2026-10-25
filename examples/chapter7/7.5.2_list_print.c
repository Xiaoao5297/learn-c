/*
 * 教程来源：chapter7/sections/7.5 递归操作链表.md
 * 示例编号：7.5.2
 * 所在小节：7.5.2 递归遍历：正序与逆序打印
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.5.2_list_print.c -o demo
 *
 * 预期输出：
 *   10 -> 20 -> 30 -> NULL
 *   30 -> 20 -> 10 -> NULL
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.5.2 list_print.c
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

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

int main(void)
{
	struct node third = {30, NULL};
	struct node second = {20, &third};
	struct node first = {10, &second};
	struct node *head = &first;

	print_list(head);

	print_reverse(head);
	printf("NULL\n");

	return 0;
}
