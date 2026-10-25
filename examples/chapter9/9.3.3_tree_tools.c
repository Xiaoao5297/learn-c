/*
 * 教程来源：chapter9/sections/9.3 二叉树.md
 * 示例编号：9.3.3
 * 所在小节：9.3.5 递归小工具：计数、深度、释放
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.3.3_tree_tools.c -o demo
 *
 * 预期输出：
 *   节点数：5
 *   深度：3
 *   数据和：210
 *   整棵树已释放
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.3.3 tree_tools.c
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

int count_nodes(const struct tree_node *root)
{
	if (root == NULL) {
		return 0;
	}
	return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int tree_depth(const struct tree_node *root)
{
	if (root == NULL) {
		return 0;
	}
	int left_depth = tree_depth(root->left);
	int right_depth = tree_depth(root->right);
	return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

int sum_tree(const struct tree_node *root)
{
	if (root == NULL) {
		return 0;
	}
	return root->data + sum_tree(root->left) + sum_tree(root->right);
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

	printf("节点数：%d\n", count_nodes(n50));
	printf("深度：%d\n", tree_depth(n50));
	printf("数据和：%d\n", sum_tree(n50));

	free_tree(n50);
	n50 = NULL;

	printf("整棵树已释放\n");

	return 0;
}
