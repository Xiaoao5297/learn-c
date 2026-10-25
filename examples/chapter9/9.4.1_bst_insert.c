/*
 * 教程来源：chapter9/sections/9.4 二叉查找树项目.md
 * 示例编号：9.4.1
 * 所在小节：9.4.2 插入：一路走到空位
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.4.1_bst_insert.c -o demo
 *
 * 预期输出：
 *   中序遍历：20 30 40 50 60 70 80
 *   乱序插入后：20 30 40 50 60 70 80
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.4.1 bst_insert.c
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

struct tree_node *insert(struct tree_node *root, int value)
{
	if (root == NULL) {
		return create_node(value);
	}
	if (value < root->data) {
		root->left = insert(root->left, value);
	} else if (value > root->data) {
		root->right = insert(root->right, value);
	}
	return root;
}

void inorder(const struct tree_node *root)
{
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int main(void)
{
	struct tree_node *root = NULL;

	/* 依次插入，第一个数 50 成为根 */
	int values[] = {50, 30, 70, 20, 40, 60, 80};
	for (int i = 0; i < 7; i++) {
		root = insert(root, values[i]);
	}

	printf("中序遍历：");
	inorder(root);
	printf("\n");

	/* 再故意乱序插一棵，验证结果一样有序 */
	struct tree_node *root2 = NULL;
	int shuffled[] = {70, 20, 50, 40, 80, 30, 60};
	for (int i = 0; i < 7; i++) {
		root2 = insert(root2, shuffled[i]);
	}

	printf("乱序插入后：");
	inorder(root2);
	printf("\n");

	return 0;
}
