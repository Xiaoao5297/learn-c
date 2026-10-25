/*
 * 教程来源：chapter7/sections/7.5 递归操作链表.md
 * 示例编号：7.5.3
 * 所在小节：7.5.3 计数与求和
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.5.3_list_stats.c -o demo
 *
 * 预期输出：
 *   节点数：3
 *   总和：60
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.5.3 list_stats.c
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

int count_nodes(struct node *head)
{
	if (head == NULL) {
		return 0;
	}
	return 1 + count_nodes(head->next);
}

int sum_list(struct node *head)
{
	if (head == NULL) {
		return 0;
	}
	return head->data + sum_list(head->next);
}

int main(void)
{
	struct node third = {30, NULL};
	struct node second = {20, &third};
	struct node first = {10, &second};
	struct node *head = &first;

	printf("节点数：%d\n", count_nodes(head));
	printf("总和：%d\n", sum_list(head));

	return 0;
}
