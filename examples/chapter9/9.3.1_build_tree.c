/*
 * 教程来源：chapter9/sections/9.3 二叉树.md
 * 示例编号：9.3.1
 * 所在小节：9.3.3 造一棵树：先手动接线
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.3.1_build_tree.c -o demo
 *
 * 预期输出：
 *   根：50
 *   根的左孩子：30
 *   根的右孩子：70
 *   左孩子是叶子吗：是，left 和 right 都是 NULL
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.3.1 build_tree.c
#include <stdio.h>
#include <stdlib.h>

struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node *create_node(int value)
{
	struct tree_node *node = malloc(sizeof(struct tree_node));
	if (node == NULL) {
		return NULL;
	}
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int main(void)
{
	/* 目标形状：
	 *       50
	 *      /  \
	 *    30    70
	 */
	struct tree_node *root = create_node(50);
	struct tree_node *left_child = create_node(30);
	struct tree_node *right_child = create_node(70);

	if (root == NULL || left_child == NULL || right_child == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	root->left = left_child;
	root->right = right_child;

	printf("根：%d\n", root->data);
	printf("根的左孩子：%d\n", root->left->data);
	printf("根的右孩子：%d\n", root->right->data);

	printf("左孩子是叶子吗：");
	if (root->left->left == NULL && root->left->right == NULL) {
		printf("是，left 和 right 都是 NULL\n");
	}

	free(left_child);
	left_child = NULL;
	free(right_child);
	right_child = NULL;
	free(root);
	root = NULL;

	return 0;
}
