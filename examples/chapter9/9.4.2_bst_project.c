/*
 * 教程来源：chapter9/sections/9.4 二叉查找树项目.md
 * 示例编号：9.4.2
 * 所在小节：9.4.4 完整项目：一棵会排序、会查找的树
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.4.2_bst_project.c -o demo
 *
 * 预期输出：
 *   中序遍历（自动升序）：20 30 40 50 60 70 80
 *   查找 40：找到了，值是 40
 *   查找 100：没找到
 *   整棵树已释放
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.4.2 bst_project.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct tree_node *search(struct tree_node *root, int value)
{
	if (root == NULL) {
		return NULL;
	}
	if (value == root->data) {
		return root;
	}
	if (value < root->data) {
		return search(root->left, value);
	}
	return search(root->right, value);
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

	/* 故意乱序插入，模拟"边来边存"的真实场景 */
	int values[] = {50, 30, 70, 20, 40, 60, 80};
	for (int i = 0; i < 7; i++) {
		root = insert(root, values[i]);
	}

	printf("中序遍历（自动升序）：");
	inorder(root);
	printf("\n");

	struct tree_node *found = search(root, 40);
	if (found != NULL) {
		printf("查找 40：找到了，值是 %d\n", found->data);
	}

	if (search(root, 100) == NULL) {
		printf("查找 100：没找到\n");
	}

	free_tree(root);
	root = NULL;

	printf("整棵树已释放\n");

	return 0;
}
