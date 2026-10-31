# 第 9 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 9.1 倒着报数（与题面一致）

**思路**：最朴素的数组栈。压入顺序是报到顺序，弹出顺序自然倒过来——栈天生会倒序。

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct stack {
	int data[MAX];
	int top;
};

void init(struct stack *s)
{
	s->top = -1;
}

bool push(struct stack *s, int value)
{
	if (s->top == MAX - 1) {
		return false;
	}
	s->top++;
	s->data[s->top] = value;
	return true;
}

bool pop(struct stack *s, int *value)
{
	if (s->top == -1) {
		return false;
	}
	*value = s->data[s->top];
	s->top--;
	return true;
}

int main(void)
{
	int numbers[5] = {7, 3, 9, 1, 5};
	struct stack s;

	init(&s);

	printf("正着报：");
	for (int i = 0; i < 5; i++) {
		printf("%d ", numbers[i]);
		push(&s, numbers[i]);
	}
	printf("\n");

	printf("倒着报：");
	int value;
	while (pop(&s, &value)) {
		printf("%d ", value);
	}
	printf("\n");

	return 0;
}
```

**示例运行**：

```text
正着报：7 3 9 1 5
倒着报：5 1 9 3 7
```

---

## 9.2 队伍不插队（与题面一致）

**思路**：标准循环队列。入队写 `data[tail]` 后 `tail = (tail + 1) % MAX`，出队读 `data[head]` 后 `head = (head + 1) % MAX`，`size` 记个数，空满两界都靠它。

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 8

struct queue {
	int data[MAX];
	int head;
	int tail;
	int size;
};

void init(struct queue *q)
{
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}

bool enqueue(struct queue *q, int value)
{
	if (q->size == MAX) {
		return false;
	}
	q->data[q->tail] = value;
	q->tail = (q->tail + 1) % MAX;
	q->size++;
	return true;
}

bool dequeue(struct queue *q, int *value)
{
	if (q->size == 0) {
		return false;
	}
	*value = q->data[q->head];
	q->head = (q->head + 1) % MAX;
	q->size--;
	return true;
}

int main(void)
{
	int tasks[4] = {301, 302, 303, 304};
	struct queue q;

	init(&q);

	printf("提交任务：");
	for (int i = 0; i < 4; i++) {
		printf("%d ", tasks[i]);
		if (!enqueue(&q, tasks[i])) {
			printf("\n队列满，%d 没排上\n", tasks[i]);
			return 1;
		}
	}
	printf("\n");

	printf("打印顺序：");
	int value;
	while (dequeue(&q, &value)) {
		printf("%d ", value);
	}
	printf("\n");

	return 0;
}
```

**示例运行**：

```text
提交任务：301 302 303 304
打印顺序：301 302 303 304
```

---

## 9.3 回文鉴定（与题面一致）

**思路**：先用循环数长度，把前 `len / 2` 个字符压栈；后半段从 `len / 2 + (len % 2)`（跳过奇数长度的中间字符）开始，每读一个字符弹一个比较，全相等且栈正好弹空就是回文。

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

struct char_stack {
	char data[MAX];
	int top;
};

void init(struct char_stack *s)
{
	s->top = -1;
}

bool push(struct char_stack *s, char ch)
{
	if (s->top == MAX - 1) {
		return false;
	}
	s->top++;
	s->data[s->top] = ch;
	return true;
}

bool pop(struct char_stack *s, char *ch)
{
	if (s->top == -1) {
		return false;
	}
	*ch = s->data[s->top];
	s->top--;
	return true;
}

bool is_palindrome(const char word[])
{
	struct char_stack s;

	init(&s);

	int len = 0;
	while (word[len] != '\0') {
		len++;
	}

	for (int i = 0; i < len / 2; i++) {
		if (!push(&s, word[i])) {
			return false;
		}
	}

	int start = len / 2 + len % 2;    /* 奇数长度跳过中间字符 */
	char ch;
	for (int i = start; i < len; i++) {
		if (!pop(&s, &ch) || ch != word[i]) {
			return false;
		}
	}

	return true;
}

int main(void)
{
	const char *words[] = {"level", "noon", "abcba", "abc"};

	for (int i = 0; i < 4; i++) {
		printf("%s：%s\n", words[i],
		       is_palindrome(words[i]) ? "是回文" : "不是回文");
	}

	return 0;
}
```

**示例运行**：

```text
level：是回文
noon：是回文
abcba：是回文
abc：不是回文
```

---

## 9.4 循环队列慢镜头（与题面一致）

**思路**：把 9.2 的循环队列原样搬来，写一个打印状态的辅助函数，按题目给的动作序列逐个执行、逐帧打印。入队 5 之后 `tail` 从 3 绕回 0、再走到 1，是本题的观察重点。

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 4

struct queue {
	int data[MAX];
	int head;
	int tail;
	int size;
};

void init(struct queue *q)
{
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}

bool enqueue(struct queue *q, int value)
{
	if (q->size == MAX) {
		return false;
	}
	q->data[q->tail] = value;
	q->tail = (q->tail + 1) % MAX;
	q->size++;
	return true;
}

bool dequeue(struct queue *q, int *value)
{
	if (q->size == 0) {
		return false;
	}
	*value = q->data[q->head];
	q->head = (q->head + 1) % MAX;
	q->size--;
	return true;
}

void show(const char *action, const struct queue *q)
{
	printf("%s：head = %d, tail = %d, size = %d\n",
	       action, q->head, q->tail, q->size);
}

int main(void)
{
	struct queue q;
	int value;

	init(&q);

	enqueue(&q, 1);
	show("入队 1", &q);
	enqueue(&q, 2);
	show("入队 2", &q);
	enqueue(&q, 3);
	show("入队 3", &q);

	dequeue(&q, &value);
	show("出队 → 1", &q);

	enqueue(&q, 4);
	show("入队 4", &q);
	enqueue(&q, 5);
	show("入队 5", &q);

	dequeue(&q, &value);
	show("出队 → 2", &q);
	dequeue(&q, &value);
	show("出队 → 3", &q);

	enqueue(&q, 6);
	show("入队 6", &q);

	printf("剩余数据：");
	while (dequeue(&q, &value)) {
		printf("%d ", value);
	}
	printf("\n");

	return 0;
}
```

**示例运行**：

```text
入队 1：head = 0, tail = 1, size = 1
入队 2：head = 0, tail = 2, size = 2
入队 3：head = 0, tail = 3, size = 3
出队 → 1：head = 1, tail = 3, size = 2
入队 4：head = 1, tail = 0, size = 3
入队 5：head = 1, tail = 1, size = 4
出队 → 2：head = 2, tail = 1, size = 3
出队 → 3：head = 3, tail = 1, size = 2
入队 6：head = 3, tail = 2, size = 3
剩余数据：4 5 6
```

---

## 9.5 数一数叶子（与题面一致）

**思路**：空树 0 个叶子；某节点左右都是 `NULL`，它自己就是叶子，返回 1；否则叶子数 = 左子树叶子数 + 右子树叶子数。这和 9.3.5 的 `count_nodes` 是同一个递归模式，只是基线值不同。

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

int count_leaves(const struct tree_node *root)
{
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return count_leaves(root->left) + count_leaves(root->right);
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
	/*        50
	 *       /  \
	 *     30    70
	 *    /  \     \
	 *  20   40    80
	 */
	struct tree_node *n50 = create_node(50);
	struct tree_node *n30 = create_node(30);
	struct tree_node *n70 = create_node(70);
	struct tree_node *n20 = create_node(20);
	struct tree_node *n40 = create_node(40);
	struct tree_node *n80 = create_node(80);

	if (n50 == NULL || n30 == NULL || n70 == NULL ||
	    n20 == NULL || n40 == NULL || n80 == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	n50->left = n30;
	n50->right = n70;
	n30->left = n20;
	n30->right = n40;
	n70->right = n80;

	printf("叶子数：%d\n", count_leaves(n50));

	free_tree(n50);
	n50 = NULL;

	printf("整棵树已释放\n");

	return 0;
}
```

**示例运行**：

```text
叶子数：3
整棵树已释放
```

---

## 9.6 BST 查找路径回放（与题面一致）

**思路**：查找函数沿 9.4.3 的路线走，每经过一个节点先打印它的值；找到返回 `true`，走到空返回 `false`。打印时用 ` -> ` 分隔，最后一并报告结果。

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

void inorder(const struct tree_node *root)
{
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

bool search_path(const struct tree_node *root, int value)
{
	printf("查找 %d：", value);
	const struct tree_node *cur = root;

	bool found = false;

	while (cur != NULL) {
		printf("%d", cur->data);
		if (value == cur->data) {
			found = true;
			break;
		}
		printf(" -> ");
		cur = (value < cur->data) ? cur->left : cur->right;
	}

	printf(found ? "（找到）\n" : "(没找到)\n");
	return found;
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

	search_path(root, 60);
	search_path(root, 55);

	free_tree(root);
	root = NULL;

	return 0;
}
```

**示例运行**：

```text
中序遍历：20 30 40 50 60 70 80
查找 60：50 -> 70 -> 60（找到）
查找 55：50 -> 70 -> 60(没找到)
```

说明：参考答案用循环改写了递归查找（树上查找尾递归天然可改循环）；如果你用递归实现并在每层打印，效果一样。

---

## 9.7 范围筛选（与题面一致）

**思路**：中序遍历的骨架上做两个剪枝：当前值比下界大，左子树才可能有范围内的值，值得递归；比上界小，右子树才值得递归。落进 `[low, high]` 的值打印出来——递归顺序仍是"左根右"，输出自然升序。

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
		root->left = insert(root->left, value);
	} else if (value > root->data) {
		root->right = insert(root->right, value);
	}
	return root;
}

void print_range(const struct tree_node *root, int low, int high)
{
	if (root == NULL) {
		return;
	}
	if (root->data > low) {
		print_range(root->left, low, high);
	}
	if (root->data >= low && root->data <= high) {
		printf("%d ", root->data);
	}
	if (root->data < high) {
		print_range(root->right, low, high);
	}
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

	int values[] = {50, 30, 70, 20, 40, 60, 80, 35, 65};
	for (int i = 0; i < 9; i++) {
		root = insert(root, values[i]);
	}

	printf("[35, 65] 范围内：");
	print_range(root, 35, 65);
	printf("\n");

	printf("全量中序：");
	inorder(root);
	printf("\n");

	free_tree(root);
	root = NULL;

	return 0;
}
```

**示例运行**：

```text
[35, 65] 范围内：35 40 50 60 65
全量中序：20 30 35 40 50 60 65 70 80
```

---

## 9.8 一层一层点名（与题面一致）

**思路**：队列里存节点指针。根先入队；之后循环"出队一个、打印、把它的非空孩子入队"，队空即遍历完。根的先进先出保证了"第 1 层全访问完才轮到第 2 层"。

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 16

struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
};

struct node_queue {
	const struct tree_node *data[MAX];
	int head;
	int tail;
	int size;
};

void queue_init(struct node_queue *q)
{
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}

bool enqueue(struct node_queue *q, const struct tree_node *node)
{
	if (q->size == MAX) {
		return false;
	}
	q->data[q->tail] = node;
	q->tail = (q->tail + 1) % MAX;
	q->size++;
	return true;
}

bool dequeue(struct node_queue *q, const struct tree_node **node)
{
	if (q->size == 0) {
		return false;
	}
	*node = q->data[q->head];
	q->head = (q->head + 1) % MAX;
	q->size--;
	return true;
}

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

void levelorder(const struct tree_node *root)
{
	struct node_queue q;

	queue_init(&q);

	if (root == NULL || !enqueue(&q, root)) {
		return;
	}

	const struct tree_node *cur;
	while (dequeue(&q, &cur)) {
		printf("%d ", cur->data);
		if (cur->left != NULL && !enqueue(&q, cur->left)) {
			return;
		}
		if (cur->right != NULL && !enqueue(&q, cur->right)) {
			return;
		}
	}
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
	/*        50
	 *       /  \
	 *     30    70
	 *    /  \   / \
	 *  20   40 60  80
	 */
	struct tree_node *nodes[7];
	int values[] = {50, 30, 70, 20, 40, 60, 80};

	for (int i = 0; i < 7; i++) {
		nodes[i] = create_node(values[i]);
		if (nodes[i] == NULL) {
			printf("内存分配失败\n");
			return 1;
		}
	}

	nodes[0]->left = nodes[1];
	nodes[0]->right = nodes[2];
	nodes[1]->left = nodes[3];
	nodes[1]->right = nodes[4];
	nodes[2]->left = nodes[5];
	nodes[2]->right = nodes[6];

	printf("前序：");
	preorder(nodes[0]);
	printf("\n");

	printf("层序：");
	levelorder(nodes[0]);
	printf("\n");

	free_tree(nodes[0]);
	nodes[0] = NULL;

	printf("整棵树已释放\n");

	return 0;
}
```

**示例运行**：

```text
前序：50 30 20 40 70 60 80
层序：50 30 70 20 40 60 80
整棵树已释放
```

---

## 9.9 镜像树（与题面一致）

**思路**：递归三步：出口是空树；每层把当前节点的 `left`、`right` 用临时指针互换；再递归镜像两棵（已换位的）子树。先换后递归和先递归后换都会让每个节点恰好被换一次，结果一样。BST 中序升序，镜像后中序降序，正好当验收标准。

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
		root->left = insert(root->left, value);
	} else if (value > root->data) {
		root->right = insert(root->right, value);
	}
	return root;
}

void mirror(struct tree_node *root)
{
	if (root == NULL) {
		return;
	}

	struct tree_node *temp = root->left;
	root->left = root->right;
	root->right = temp;

	mirror(root->left);
	mirror(root->right);
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

	printf("翻转前中序：");
	inorder(root);
	printf("\n");

	mirror(root);

	printf("翻转后中序：");
	inorder(root);
	printf("\n");

	free_tree(root);
	root = NULL;

	printf("整棵树已释放\n");

	return 0;
}
```

**示例运行**：

```text
翻转前中序：20 30 40 50 60 70 80
翻转后中序：80 70 60 50 40 30 20
整棵树已释放
```

---

## 9.10 数字集合管理器（与题面一致）

**思路**：BST 的插入、中序打印、查找、删除（三种情况，双子找右子树最小当替身）全部按 9.4、9.5 的套路实现；主循环读命令分发，每个操作后打印如实的反馈；退出前 `free_tree`。

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

bool contains(const struct tree_node *root, int value)
{
	if (root == NULL) {
		return false;
	}
	if (value == root->data) {
		return true;
	}
	if (value < root->data) {
		return contains(root->left, value);
	}
	return contains(root->right, value);
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

void inorder(const struct tree_node *root, int *count)
{
	if (root == NULL) {
		return;
	}
	inorder(root->left, count);
	printf("%d ", root->data);
	(*count)++;
	inorder(root->right, count);
}

void print_set(const struct tree_node *root)
{
	int count = 0;

	if (root == NULL) {
		printf("集合为空\n");
		return;
	}
	printf("集合：");
	inorder(root, &count);
	printf("（共 %d 个）\n", count);
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
	int running = 1;

	while (running) {
		int cmd = 0;
		printf("命令：");
		if (scanf("%d", &cmd) != 1) {
			printf("\n命令读取失败\n");
			return 1;
		}

		int value = 0;

		switch (cmd) {
		case 1:
			if (scanf("%d", &value) != 1) {
				printf("数值读取失败\n");
				return 1;
			}
			if (contains(root, value)) {
				printf("集合里已有 %d，没有重复插入\n",
				       value);
			} else {
				root = insert(root, value);
				printf("已插入 %d\n", value);
			}
			break;
		case 2:
			if (scanf("%d", &value) != 1) {
				printf("数值读取失败\n");
				return 1;
			}
			if (contains(root, value)) {
				root = delete_node(root, value);
				printf("已删除 %d\n", value);
			} else {
				printf("集合里没有 %d，无法删除\n",
				       value);
			}
			break;
		case 3:
			print_set(root);
			break;
		case 4:
			if (scanf("%d", &value) != 1) {
				printf("数值读取失败\n");
				return 1;
			}
			printf("%s %d\n",
			       contains(root, value) ? "找到" : "没找到",
			       value);
			break;
		case 0:
			printf("再见\n");
			running = 0;
			break;
		default:
			printf("没有这个命令（1 插入 2 删除 3 打印 4 查找 0 退出）\n");
			break;
		}
	}

	free_tree(root);
	root = NULL;

	return 0;
}
```

**示例运行**（输入 `1 50`、`1 30`、`1 70`、`1 30`、`3`、`2 50`、`3`、`4 70`、`0`）：

```text
命令：已插入 50
命令：已插入 30
命令：已插入 70
命令：集合里已有 30，没有重复插入
命令：集合：30 50 70 （共 3 个）
命令：已删除 50
命令：集合：30 70 （共 2 个）
命令：找到 70
命令：再见
```

---
