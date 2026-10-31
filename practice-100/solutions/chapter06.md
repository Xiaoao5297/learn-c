# 第 6 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 6.1 运行时才定的平方表

**思路**：`malloc(n * sizeof(int))` 让大小跟着变量 `n` 走，这是数组做不到的。`malloc` 返回值必查；用完 `free` 并置 `NULL`。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 8;

	int *arr = malloc((size_t)n * sizeof(int));

	if (arr == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	int sum = 0;

	for (int i = 0; i < n; i++) {
		arr[i] = (i + 1) * (i + 1);
		sum += arr[i];
	}

	printf("最后一个是 %d\n", arr[n - 1]);
	printf("总和是 %d\n", sum);

	free(arr);
	arr = NULL;

	return 0;
}
```

**示例运行**：

```text
最后一个是 64
总和是 204
```

---

## 6.2 三块内存的规范归还

**思路**：三块内存三个指针，任何一块申请失败都要把已到手的先释放掉再退出——失败路径也绝不泄漏。释放顺序"谁申请谁释放"，每块 `free` 后立刻置 `NULL`。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p_num = malloc(sizeof(int));
	double *p_val = malloc(sizeof(double));
	char *p_text = malloc(10);

	if (p_num == NULL || p_val == NULL || p_text == NULL) {
		free(p_num);
		free(p_val);
		free(p_text);
		printf("内存分配失败\n");
		return 1;
	}

	*p_num = 42;
	*p_val = 3.14;
	snprintf(p_text, 10, "hello");

	printf("%d %.2f %s\n", *p_num, *p_val, p_text);

	free(p_num);
	p_num = NULL;
	free(p_val);
	p_val = NULL;
	free(p_text);
	p_text = NULL;

	return 0;
}
```

**示例运行**：

```text
42 3.14 hello
```

---

## 6.3 拼接两个动态数组

**思路**：第三块的长度是前两块之和；复制用两段下标循环（或一个循环里分前后半段填）。三块内存各自独立，释放三次。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *a = malloc(3 * sizeof(int));
	int *b = malloc(3 * sizeof(int));

	if (a == NULL || b == NULL) {
		free(a);
		free(b);
		printf("内存分配失败\n");
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		a[i] = i + 1;
		b[i] = i + 4;
	}

	int *merged = malloc(6 * sizeof(int));

	if (merged == NULL) {
		free(a);
		free(b);
		printf("内存分配失败\n");
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		merged[i] = a[i];
		merged[3 + i] = b[i];
	}

	for (int i = 0; i < 6; i++) {
		printf("%d ", merged[i]);
	}
	printf("\n");

	free(a);
	a = NULL;
	free(b);
	b = NULL;
	free(merged);
	merged = NULL;

	return 0;
}
```

**示例运行**：

```text
1 2 3 4 5 6 
```

---

## 6.4 链表倒数第 k 个节点

**思路**：单链表不能倒着走，就先顺走一遍数出总数 `total`，再从头走 `total - k` 步，正好停在倒数第 k 个。释放时用临时变量存 `next`，防止释放当前节点后找不到下一个。

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create_node(int value)
{
	struct node *n = malloc(sizeof(struct node));

	if (n == NULL) {
		return NULL;
	}
	n->data = value;
	n->next = NULL;
	return n;
}

void push_back(struct node **head, int value)
{
	struct node *n = create_node(value);

	if (n == NULL) {
		return;
	}
	if (*head == NULL) {
		*head = n;
		return;
	}
	struct node *tail = *head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = n;
}

void print_list(struct node *head)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("NULL\n");
}

void free_list(struct node **head)
{
	struct node *cur = *head;

	while (cur != NULL) {
		struct node *next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}

int main(void)
{
	struct node *head = NULL;

	for (int i = 1; i <= 5; i++) {
		push_back(&head, i * 10);
	}
	print_list(head);

	int k = 2;
	int total = 0;
	struct node *cur = head;

	while (cur != NULL) {
		total++;
		cur = cur->next;
	}

	struct node *p = head;

	for (int i = 0; i < total - k; i++) {
		p = p->next;
	}
	printf("倒数第 %d 个：%d\n", k, p->data);

	free_list(&head);

	return 0;
}
```

**示例运行**：

```text
10 -> 20 -> 30 -> 40 -> 50 -> NULL
倒数第 2 个：40
```

---

## 6.5 有序插入

**思路**：三种情况——空表或比头小插头部；否则从头出发找"下一个节点值不小于新值"的最后一个节点，插在它后面。判断条件 `cur->next->data < value` 决定走到哪停。

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create_node(int value)
{
	struct node *n = malloc(sizeof(struct node));

	if (n == NULL) {
		return NULL;
	}
	n->data = value;
	n->next = NULL;
	return n;
}

void insert_sorted(struct node **head, int value)
{
	struct node *n = create_node(value);

	if (n == NULL) {
		return;
	}

	if (*head == NULL || value < (*head)->data) {
		n->next = *head;
		*head = n;
		return;
	}

	struct node *cur = *head;

	while (cur->next != NULL && cur->next->data < value) {
		cur = cur->next;
	}
	n->next = cur->next;
	cur->next = n;
}

void print_list(struct node *head)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("NULL\n");
}

void free_list(struct node **head)
{
	struct node *cur = *head;

	while (cur != NULL) {
		struct node *next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}

int main(void)
{
	struct node *head = NULL;

	insert_sorted(&head, 30);
	insert_sorted(&head, 10);
	insert_sorted(&head, 20);
	insert_sorted(&head, 25);
	print_list(head);

	free_list(&head);

	return 0;
}
```

**示例运行**：

```text
10 -> 20 -> 25 -> 30 -> NULL
```

---

## 6.6 在指定节点后面插一个

**思路**：找到目标节点后，插入动作只有两步：新节点的 `next` 接上目标的 `next`，目标的 `next` 接上新节点（顺序不能反，否则后面的链会丢）。找不到目标或 `malloc` 失败都返回 0。

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create_node(int value)
{
	struct node *n = malloc(sizeof(struct node));

	if (n == NULL) {
		return NULL;
	}
	n->data = value;
	n->next = NULL;
	return n;
}

void push_back(struct node **head, int value)
{
	struct node *n = create_node(value);

	if (n == NULL) {
		return;
	}
	if (*head == NULL) {
		*head = n;
		return;
	}
	struct node *tail = *head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = n;
}

void print_list(struct node *head)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("NULL\n");
}

int insert_after(struct node *head, int target, int value)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		if (cur->data == target) {
			struct node *n = create_node(value);

			if (n == NULL) {
				return 0;
			}
			n->next = cur->next;
			cur->next = n;
			return 1;
		}
	}
	return 0;
}

void free_list(struct node **head)
{
	struct node *cur = *head;

	while (cur != NULL) {
		struct node *next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}

int main(void)
{
	struct node *head = NULL;

	for (int i = 1; i <= 4; i++) {
		push_back(&head, i * 10);
	}
	print_list(head);

	if (insert_after(head, 20, 25)) {
		printf("插入成功\n");
	}
	if (!insert_after(head, 99, 5)) {
		printf("没找到 99，插入失败\n");
	}
	print_list(head);

	free_list(&head);

	return 0;
}
```

**示例运行**：

```text
10 -> 20 -> 30 -> 40 -> NULL
插入成功
没找到 99，插入失败
10 -> 20 -> 25 -> 30 -> 40 -> NULL
```

---

## 6.7 最大值在倒数第几站

**思路**：一趟遍历两个变量同步更新——`max` 记当前最大值，`pos` 记它的位置（从 1 数）。两个结果通过 `int *` 参数带回调用方。相等时不更新，所以多次出现时报的是第一次出现的位置。

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create_node(int value)
{
	struct node *n = malloc(sizeof(struct node));

	if (n == NULL) {
		return NULL;
	}
	n->data = value;
	n->next = NULL;
	return n;
}

void push_back(struct node **head, int value)
{
	struct node *n = create_node(value);

	if (n == NULL) {
		return;
	}
	if (*head == NULL) {
		*head = n;
		return;
	}
	struct node *tail = *head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = n;
}

void print_list(struct node *head)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("NULL\n");
}

void find_max(struct node *head, int *max_out, int *pos_out)
{
	int max = head->data;
	int pos = 1;
	int index = 1;

	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		if (cur->data > max) {
			max = cur->data;
			pos = index;
		}
		index++;
	}

	*max_out = max;
	*pos_out = pos;
}

void free_list(struct node **head)
{
	struct node *cur = *head;

	while (cur != NULL) {
		struct node *next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}

int main(void)
{
	struct node *head = NULL;

	int values[6] = {12, 45, 7, 89, 23, 56};

	for (int i = 0; i < 6; i++) {
		push_back(&head, values[i]);
	}
	print_list(head);

	int max;
	int pos;

	find_max(head, &max, &pos);
	printf("最大值：%d（第 %d 个节点）\n", max, pos);

	free_list(&head);

	return 0;
}
```

**示例运行**：

```text
12 -> 45 -> 7 -> 89 -> 23 -> 56 -> NULL
最大值：89（第 4 个节点）
```

---

## 6.8 删除所有目标节点

**思路**：删头节点单独处理——只要头还是目标就连删带挪，用 `while` 应对"开头连着一串目标"的情况；处理完中间部分后，前驱 `prev` 只在"下一个不是目标"时才前进，"下一个是目标"时摘掉它但 `prev` 原地不动（因为新的 `prev->next` 可能还是目标）。

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create_node(int value)
{
	struct node *n = malloc(sizeof(struct node));

	if (n == NULL) {
		return NULL;
	}
	n->data = value;
	n->next = NULL;
	return n;
}

void push_back(struct node **head, int value)
{
	struct node *n = create_node(value);

	if (n == NULL) {
		return;
	}
	if (*head == NULL) {
		*head = n;
		return;
	}
	struct node *tail = *head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = n;
}

void print_list(struct node *head)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("NULL\n");
}

int delete_all(struct node **head, int target)
{
	int removed = 0;

	while (*head != NULL && (*head)->data == target) {
		struct node *to_delete = *head;

		*head = (*head)->next;
		free(to_delete);
		removed++;
	}

	if (*head == NULL) {
		return removed;
	}

	struct node *prev = *head;

	while (prev->next != NULL) {
		if (prev->next->data == target) {
			struct node *to_delete = prev->next;

			prev->next = to_delete->next;
			free(to_delete);
			removed++;
		} else {
			prev = prev->next;
		}
	}

	return removed;
}

void free_list(struct node **head)
{
	struct node *cur = *head;

	while (cur != NULL) {
		struct node *next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}

int main(void)
{
	struct node *head = NULL;

	int values[8] = {3, 7, 3, 3, 9, 3, 5, 3};

	for (int i = 0; i < 8; i++) {
		push_back(&head, values[i]);
	}
	print_list(head);

	int removed = delete_all(&head, 3);

	printf("删除了 %d 个 3\n", removed);
	print_list(head);

	free_list(&head);

	return 0;
}
```

**示例运行**：

```text
3 -> 7 -> 3 -> 3 -> 9 -> 3 -> 5 -> 3 -> NULL
删除了 5 个 3
7 -> 9 -> 5 -> NULL
```

---

## 6.9 用二级指针搭一个二维矩阵

**思路**：`int **matrix` 指向"指针数组"，先申请 4 个 `int *`；再给每行单独申请 5 个 `int`。访问 `matrix[i][j]` 要两次解引用。释放必须先释放每行、最后释放行指针数组——顺序反了就会先把"目录"扔了，再也没法找到各"页"。

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int rows = 4;
	int cols = 5;

	int **matrix = malloc((size_t)rows * sizeof(int *));

	if (matrix == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	int ok = 1;

	for (int i = 0; i < rows; i++) {
		matrix[i] = malloc((size_t)cols * sizeof(int));
		if (matrix[i] == NULL) {
			ok = 0;
			rows = i;
			break;
		}
	}

	if (!ok) {
		for (int i = 0; i < rows; i++) {
			free(matrix[i]);
		}
		free(matrix);
		printf("内存分配失败\n");
		return 1;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = (i + 1) * (j + 1);
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 4; i++) {
		free(matrix[i]);
	}
	free(matrix);
	matrix = NULL;

	return 0;
}
```

**示例运行**：

```text
  1  2  3  4  5
  2  4  6  8 10
  3  6  9 12 15
  4  8 12 16 20
```

---

## 6.10 学生名单管理器

**思路**：命令循环读一行、解析第一个单词分发。删除时记前驱，删头节点单独处理；尾插沿用"走到末尾挂上去"的套路。退出前 `free_list` 释放整条链，防泄漏。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20

struct node {
	char name[MAX_NAME];
	int score;
	struct node *next;
};

struct node *create_node(const char *name, int score)
{
	struct node *n = malloc(sizeof(struct node));

	if (n == NULL) {
		return NULL;
	}
	snprintf(n->name, sizeof(n->name), "%s", name);
	n->score = score;
	n->next = NULL;
	return n;
}

int add_student(struct node **head, const char *name, int score)
{
	struct node *n = create_node(name, score);

	if (n == NULL) {
		return 0;
	}
	if (*head == NULL) {
		*head = n;
		return 1;
	}
	struct node *tail = *head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = n;
	return 1;
}

int remove_student(struct node **head, const char *name)
{
	struct node *prev = NULL;
	struct node *cur = *head;

	while (cur != NULL) {
		if (strcmp(cur->name, name) == 0) {
			if (prev == NULL) {
				*head = cur->next;
			} else {
				prev->next = cur->next;
			}
			free(cur);
			return 1;
		}
		prev = cur;
		cur = cur->next;
	}
	return 0;
}

void print_list(struct node *head)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		printf("%s %d\n", cur->name, cur->score);
	}
}

void free_list(struct node **head)
{
	struct node *cur = *head;

	while (cur != NULL) {
		struct node *next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}

int main(void)
{
	struct node *head = NULL;
	char line[128];

	printf("命令：add 姓名 分数 / del 姓名 / list / quit\n");

	while (fgets(line, sizeof(line), stdin) != NULL) {
		line[strcspn(line, "\n")] = '\0';

		char cmd[16];
		char name[MAX_NAME];
		int score;

		if (sscanf(line, "%15s", cmd) != 1) {
			continue;
		}

		if (strcmp(cmd, "quit") == 0) {
			break;
		} else if (strcmp(cmd, "add") == 0
			   && sscanf(line, "%*s %19s %d", name, &score) == 2) {
			if (add_student(&head, name, score)) {
				printf("已添加 %s %d\n", name, score);
			} else {
				printf("添加失败\n");
			}
		} else if (strcmp(cmd, "del") == 0
			   && sscanf(line, "%*s %19s", name) == 1) {
			if (remove_student(&head, name)) {
				printf("已删除 %s\n", name);
			} else {
				printf("没有 %s\n", name);
			}
		} else if (strcmp(cmd, "list") == 0) {
			print_list(head);
		} else {
			printf("命令不认识\n");
		}
	}

	free_list(&head);

	return 0;
}
```

**示例运行**（输入依次为 `add xiaoming 90`、`add xiaohong 85`、`list`、`del xiaoming`、`list`、`del zhangsan`、`add wang 92`、`list`、`quit`）：

```text
命令：add 姓名 分数 / del 姓名 / list / quit
已添加 xiaoming 90
已添加 xiaohong 85
xiaoming 90
xiaohong 85
已删除 xiaoming
xiaohong 85
没有 zhangsan
已添加 wang 92
xiaohong 85
wang 92
```

---
