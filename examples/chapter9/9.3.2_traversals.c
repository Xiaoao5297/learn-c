/*
 * 教程来源：chapter9/sections/9.3 二叉树.md
 * 示例编号：9.3.2
 * 所在小节：9.3.4 三种遍历
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.3.2_traversals.c -o demo
 *
 * 预期输出：
 *   前序：50 30 20 40 70
 *   中序：20 30 40 50 70
 *   后序：20 40 30 70 50
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.3.2 traversals.c
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

void preorder(const struct tree_node *root)
{
	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
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

void postorder(const struct tree_node *root)
{
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

int main(void)
{
	/*       50
	 *      /  \
	 *    30    70
	 *   /  \
	 *  20   40
	 */
	struct tree_node *n50 = create_node(50);
	struct tree_node *n30 = create_node(30);
	struct tree_node *n70 = create_node(70);
	struct tree_node *n20 = create_node(20);
	struct tree_node *n40 = create_node(40);

	if (n50 == NULL || n30 == NULL || n70 == NULL ||
	    n20 == NULL || n40 == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	n50->left = n30;
	n50->right = n70;
	n30->left = n20;
	n30->right = n40;

	printf("前序：");
	preorder(n50);
	printf("\n");

	printf("中序：");
	inorder(n50);
	printf("\n");

	printf("后序：");
	postorder(n50);
	printf("\n");

	return 0;
}
