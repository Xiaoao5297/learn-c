# 第 9 章测试：栈、队列与二叉树

> **测试说明**
>
> - 选择题 5 题，填空题 5 题，阅读程序 2 题，编程题 2 题。
> - 建议用时 60 到 90 分钟。
> - 先独立完成，再展开文末答案。
> - 编程题重点看思路和边界，不要求和参考答案逐字相同。

---

## 一、选择题（每题 2 分，共 10 分）

**1. 栈与队列最本质的区别是？**

A. 栈用数组，队列用链表\
B. 栈后进先出，队列先进先出\
C. 栈只能存整数，队列什么都能存\
D. 栈比队列慢

---

**2. 循环队列里，出队空出来的数组格子如何被重新用上？**

A. 不用上，直接浪费\
B. 靠 `(下标 + 1) % MAX` 让下标绕回开头\
C. 每次出队后把后面的数据往前挪\
D. 每次出队后重新 malloc 整个数组

---

**3. 对二叉查找树做中序遍历，输出是？**

A. 从大到小\
B. 先根后左右\
C. 从小到大\
D. 随机顺序

---

**4. BST 里删除一个有两个孩子的节点，本书用哪个节点当替身？**

A. 左孩子\
B. 右孩子\
C. 右子树里最小的节点\
D. 随机选一个叶子

---

**5. 释放整棵二叉树应该按什么顺序 free？**

A. 先 free 根，再 free 两个孩子\
B. 先把左右子树都释放光，最后 free 根\
C. 随便什么顺序，结果一样\
D. 只 free 根，孩子自动跟着释放

---

## 二、填空题（每题 4 分，共 20 分）

**6. 栈只在_______位置进出；队列从队尾进、从_______出。**

**7. 空栈的 `top` 是_______；循环队列只靠 `head` 和 `tail` 分不清空和满，所以要额外记录_______。**

**8. 二叉树节点除数据外有_______和_______两个指针成员；两个指针都是 NULL 的节点叫_______。**

**9. 三种遍历里，"左 → 根 → 右"是_______遍历；"左 → 右 → 根"是_______遍历。**

**10. BST 的递归插入中，`root->left = insert(root->left, value);` 的作用是把插入后的子树根_______回去。**

---

## 三、阅读程序（每题 5 分，共 10 分）

**11. 写出下面程序的输出。**

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 4

int main(void)
{
	int data[MAX];
	int top = -1;

	for (int i = 1; i <= 4; i++) {
		if (top < MAX - 1) {
			top++;
			data[top] = i * i;
		}
	}

	int value;
	while (top >= 0) {
		value = data[top];
		top--;
		printf("%d ", value);
	}
	printf("\n");

	return 0;
}
```

---

**12. 下面的程序想建一棵 BST 并中序输出，有两处错误，请指出并改正。**

```c
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
		insert(root->left, value);
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
	printf("%d ", root->data);
	inorder(root->left);
	inorder(root->right);
}

int main(void)
{
	struct tree_node *root = NULL;

	int values[] = {5, 3, 8};
	for (int i = 0; i < 3; i++) {
		root = insert(root, values[i]);
	}

	inorder(root);
	printf("\n");

	return 0;
}
```

---

## 四、编程题（每题 10 分，共 20 分）

**13. 数组版栈与括号检查**

编写程序：实现一个字符栈（数组 + `top`），用它检查一行字符串里的圆括号是否配对。对 `"(a+b)*(c-d)"` 输出 `配对正确`，对 `"((a+b)"` 输出 `配对错误`。运行效果：

```text
(a+b)*(c-d) ：配对正确
((a+b)      ：配对错误
```

要求：

- 遇到 `(` 压栈，遇到 `)` 弹栈；弹不出即右括号没人配，读完后栈不空即左括号没配完。
- 判空、判满都要检查，函数不打印错误信息，用返回值报告。
- 使用 `int main(void)`。

---

**14. BST 插入、查找、删除**

编写程序：依次把 `{50, 30, 70, 20, 40, 60, 80}` 插入 BST，中序输出；查找 60 和 99 各一次；删除 20、50 各一次，每次删除后中序输出。运行效果：

```text
中序遍历：20 30 40 50 60 70 80
查找 60：找到
查找 99：没找到
删除 20 后：30 40 50 60 70 80
删除 50 后：30 40 60 70 80
```

要求：

- 删除用"返回新子树根"的方案，双子情况用右子树最小节点当替身。
- 程序结束前释放整棵树（后序）。
- 使用 `int main(void)`。

---

## 参考答案

<details>
<summary>点击展开答案</summary>

### 一、选择题

1. **B**。栈后进先出（盘子架），队列先进先出（排队），这是两者的定义性差别，和底层用什么实现无关。
2. **B**。取余让下标在 0 到 MAX-1 之间循环，出队空出的格子会被绕回来的入队重新写入。
3. **C**。左子树全比根小、右子树全比根大，中序"左根右"自然升序。
4. **C**。右子树最小节点（后继）比左子树都大、比右子树其余值都小，顶上后家规两头都成立。
5. **B**。这是后序顺序；先 free 根就再也够不着孩子了。

### 二、填空题

6. 栈顶；队头。
7. -1；`size`（当前数据个数）。
8. `left`；`right`；叶子。
9. 中序；后序。
10. 接（接回）。

### 三、阅读程序

11. 输出：

```text
16 9 4 1
```

压栈的是 `i * i`，即 1、4、9、16；弹栈从 `top` 往下取，最后压入的 16 先出。注意循环里 `top < MAX - 1` 的判满检查：四个数恰好都装下了。

12. 两处错误：

- `insert` 的左分支缺少接回动作：`insert(root->left, value);` 应为 `root->left = insert(root->left, value);`。不接回去，插到左边的新节点没人指向，树里根本找不到它。
- `inorder` 把 `printf` 放在了两次递归之前，输出的是前序 `5 3 8`（碰巧和输入顺序一样，容易误以为对）。中序应先递归左子树，再打印，再递归右子树。

### 四、编程题

13. 参考代码：

```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 64

struct bracket_stack {
	char data[MAX];
	int top;
};

void init(struct bracket_stack *s)
{
	s->top = -1;
}

bool push(struct bracket_stack *s, char ch)
{
	if (s->top == MAX - 1) {
		return false;
	}
	s->top++;
	s->data[s->top] = ch;
	return true;
}

bool pop(struct bracket_stack *s, char *ch)
{
	if (s->top == -1) {
		return false;
	}
	*ch = s->data[s->top];
	s->top--;
	return true;
}

bool is_balanced(const char str[])
{
	struct bracket_stack s;

	init(&s);

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') {
			if (!push(&s, '(')) {
				return false;
			}
		} else if (str[i] == ')') {
			char ch;
			if (!pop(&s, &ch)) {
				return false;
			}
		}
	}

	return s.top == -1;
}

int main(void)
{
	const char *lines[] = {"(a+b)*(c-d)", "((a+b)"};

	for (int i = 0; i < 2; i++) {
		printf("%-12s：%s\n", lines[i],
		       is_balanced(lines[i]) ? "配对正确" : "配对错误");
	}

	return 0;
}
```

输出：

```text
(a+b)*(c-d) ：配对正确
((a+b)      ：配对错误
```

读完后栈不空说明还有 `(` 没等到配对，`s.top == -1` 才是"配对正确"。

14. 参考代码：

```c
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

	int values[] = {50, 30, 70, 20, 40, 60, 80};
	for (int i = 0; i < 7; i++) {
		root = insert(root, values[i]);
	}

	printf("中序遍历：");
	inorder(root);
	printf("\n");

	printf("查找 60：%s\n", search(root, 60) != NULL ? "找到" : "没找到");
	printf("查找 99：%s\n", search(root, 99) != NULL ? "找到" : "没找到");

	root = delete_node(root, 20);
	printf("删除 20 后：");
	inorder(root);
	printf("\n");

	root = delete_node(root, 50);
	printf("删除 50 后：");
	inorder(root);
	printf("\n");

	free_tree(root);
	root = NULL;

	return 0;
}
```

输出：

```text
中序遍历：20 30 40 50 60 70 80
查找 60：找到
查找 99：没找到
删除 20 后：30 40 50 60 70 80
删除 50 后：30 40 60 70 80
```

删 50 命中"双子"情况，替身是右子树 `{60, 70, 80}` 里最小的 60；抄值后再从右子树里删掉原 60（叶子，落回情况一）。

</details>

---

[返回第 9 章导读](../README.md)
