/*
 * 教程来源：chapter9/sections/9.5 BST 的删除.md
 * 示例编号：9.5.2
 * 所在小节：9.5.6 一次删完三种情况的演示
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.5.2_bst_delete_demo.c -o demo
 *
 * 预期输出：
 *   原始树：30 40 50 60 70
 *   删 40（叶子）：30 50 60 70
 *   删 30（独子 70？不，删后看中序）：50 60 70
 *   删 50（双子）：60 70
 *   最后剩几棵子树：60 70
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.5.2 bst_delete_demo.c
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
		return NULL;
	}

	if (value < root->data) {
		root->left = delete_node(root->left, value);
	} else if (value > root->data) {
		root->right = delete_node(root->right, value);
	} else {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		} else if (root->left == NULL) {
			struct tree_node *child = root->right;
			free(root);
			return child;
		} else if (root->right == NULL) {
			struct tree_node *child = root->left;
			free(root);
			return child;
		} else {
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

	/* 建一棵带"独子"的树：
	 *       50
	 *      /  \
	 *    30    70
	 *      \   /
	 *      40 60
	 */
	int values[] = {50, 30, 70, 40, 60};
	for (int i = 0; i < 5; i++) {
		root = insert(root, values[i]);
	}

	printf("原始树：");
	inorder(root);
	printf("\n");

	root = delete_node(root, 40);
	printf("删 40（叶子）：");
	inorder(root);
	printf("\n");

	root = delete_node(root, 30);
	printf("删 30（独子 70？不，删后看中序）：");
	inorder(root);
	printf("\n");

	root = delete_node(root, 50);
	printf("删 50（双子）：");
	inorder(root);
	printf("\n");

	printf("最后剩几棵子树：");
	inorder(root);
	printf("\n");

	free_tree(root);
	root = NULL;

	return 0;
}
