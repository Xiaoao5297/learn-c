/*
 * 教程来源：chapter9/sections/9.5 BST 的删除.md
 * 示例编号：9.5.1
 * 所在小节：9.5.5 完整实现：一个函数吃下三种情况
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.5.1_bst_delete.c -o demo
 *
 * 预期输出：
 *   原始树：20 30 40 50 60 70 80
 *   删 20（叶子）：30 40 50 60 70 80
 *   删 50（双子）：30 40 60 70 80
 *   删 99（没有）：30 40 60 70 80
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.5.1 bst_delete.c
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

struct tree_node *find_min(struct tree_node *root)
{
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

struct tree_node *delete_node(struct tree_node *root, int value)
{
	if (root == NULL) {
		return NULL;    /* 没找到，树不变 */
	}

	if (value < root->data) {
		root->left = delete_node(root->left, value);
	} else if (value > root->data) {
		root->right = delete_node(root->right, value);
	} else {
		/* 找到了，按孩子个数分三种情况 */
		if (root->left == NULL && root->right == NULL) {
			free(root);           /* 情况一：叶子，直接摘 */
			return NULL;
		} else if (root->left == NULL) {
			struct tree_node *child = root->right;
			free(root);           /* 情况二：只有右孩子，孩子顶上 */
			return child;
		} else if (root->right == NULL) {
			struct tree_node *child = root->left;
			free(root);           /* 情况二：只有左孩子 */
			return child;
		} else {
			/* 情况三：两个孩子，找右子树最小的当替身 */
			struct tree_node *successor = find_min(root->right);
			root->data = successor->data;
			root->right = delete_node(root->right, successor->data);
		}
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

void free_tree(struct tree_node *root)
{
	if (root == NULL) {
		return;
	}
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int main(void)
{
	struct tree_node *root = NULL;

	int values[] = {50, 30, 70, 20, 40, 60, 80};
	for (int i = 0; i < 7; i++) {
		root = insert(root, values[i]);
	}

	printf("原始树：");
	inorder(root);
	printf("\n");

	root = delete_node(root, 20);
	printf("删 20（叶子）：");
	inorder(root);
	printf("\n");

	root = delete_node(root, 50);
	printf("删 50（双子）：");
	inorder(root);
	printf("\n");

	root = delete_node(root, 99);
	printf("删 99（没有）：");
	inorder(root);
	printf("\n");

	free_tree(root);
	root = NULL;

	return 0;
}
