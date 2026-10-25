# 第 6 章测试：动态内存与链表

> **测试说明**
>
> - 选择题 5 题，填空题 5 题，阅读程序 2 题，编程题 2 题。
> - 建议用时 60 到 90 分钟。
> - 先独立完成，再展开文末答案。
> - 编程题重点看思路和边界，不要求和参考答案逐字相同。

---

## 一、选择题（每题 2 分，共 10 分）

**1. `malloc` 申请内存失败时返回？**

A. `0`\
B. `-1`\
C. `NULL`\
D. 什么都不返回，程序直接崩溃

---

**2. 下面代码的主要问题是什么？**

```c
for (int i = 0; i < 100000; i++) {
	int *p = malloc(sizeof(int));
	if (p == NULL) {
		return 1;
	}
	*p = i;
}
```

A. 没检查 `malloc` 的返回值\
B. 每次循环都泄漏一块内存，没有 `free`\
C. 双重释放\
D. 循环变量 `i` 用错了

---

**3. 用 `realloc` 把动态数组扩容，正确的写法是？**

A. `arr = realloc(arr, new_size);`\
B. `realloc(arr, new_size);`，不接返回值\
C. `int *tmp = realloc(arr, new_size); if (tmp == NULL) { ... } arr = tmp;`\
D. `arr = calloc(arr, new_size);`

---

**4. 定义链表节点，正确的是？**

A. `struct node { int data; node *next; };`\
B. `struct node { int data; struct node *next; };`\
C. `struct node { int data; int *next; };`\
D. `struct node { int data; struct node next; };`

---

**5. 删除链表的头节点，除了 `free` 它，还必须？**

A. 把 `*head` 改指原来的第二个节点\
B. 把整个链表重建一遍\
C. 把 `head` 保持原样\
D. 把所有节点的 `data` 清零

---

## 二、填空题（每题 4 分，共 20 分）

**6. `malloc` 申请的内存在\_\_\_\_\_\_\_上，用完必须调用\_\_\_\_\_\_\_释放；栈上的内存由\_\_\_\_\_\_\_自动回收。**

**7. 申请了内存却不释放叫\_\_\_\_\_\_\_；释放后指针仍指向原地址叫\_\_\_\_\_\_\_指针；同一块内存释放两次叫\_\_\_\_\_\_\_。**

**8. 打印 `sizeof` 的结果应该使用格式符\_\_\_\_\_\_\_。**

**9. 头插要修改外面的头指针，函数参数类型是 `struct node \*\*head`，函数体内修改头指针要写\_\_\_\_\_\_\_。**

**10. 删除中间节点时，先让前一个节点的 `next` 接到目标的\_\_\_\_\_\_\_，再 `free` 目标节点。**

---

## 三、阅读程序（每题 5 分，共 10 分）

**11. 写出下面程序的输出。**

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *arr = calloc(4, sizeof(int));
	if (arr == NULL) {
		return 1;
	}

	arr[1] = 5;
	arr[3] = arr[1] * 2;

	for (int i = 0; i < 4; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	arr = NULL;

	return 0;
}
```

---

**12. 写出下面程序片段执行后链表的内容（用 `10 -> 20 -> NULL` 的格式表示），并说明每步之后 head 指向谁。**

```c
/* create_node、push_front、push_back、delete_node 均为 6.3、6.4 的正确实现 */

struct node *head = NULL;

push_front(&head, 20);
push_front(&head, 10);
push_back(&head, 30);

delete_node(&head, 10);
```

---

## 四、编程题（每题 10 分，共 20 分）

**13. 动态数组求最值**

用 `malloc` 申请能装 6 个 `int` 的动态数组，存入 `{34, 67, 12, 89, 45, 23}`，求最大值并输出。运行效果：

```text
最大值：89
```

要求：

- `malloc` 之后检查返回值。
- 用完 `free`，并把指针置 `NULL`。
- 使用 `int main(void)`。

---

**14. 链表：建表、查找、删除、释放**

实现 `struct node` 单链表，编写 `create_node`、`push_back`、`print_list`、`find_node`、`delete_node`、`free_list`，完成下面的流程。运行效果：

```text
初始链表：10 -> 20 -> 30 -> 40 -> NULL
删除 20 后：10 -> 30 -> 40 -> NULL
查找 40：找到了
查找 20：没找到
```

要求：

- 插入和删除函数收 `struct node **head`，删头节点也要正确。
- 所有函数空链表安全。
- 最后释放整条链，`head` 置 `NULL`。
- 使用 `int main(void)`。

---

## 参考答案

<details>
<summary>点击展开答案</summary>

### 一、选择题

1. **C**。失败时返回 `NULL`，所以每次分配后都要检查。
2. **B**。返回值检查了，但每循环一次申请一块、从不释放，10 万块内存全部泄漏。
3. **C**。三步曲：临时变量接返回值、检查 `NULL`、成功才覆盖。A 的写法在失败时会把旧地址覆盖成 `NULL` 造成泄漏；B 不接返回值等于白扩；D 参数就错了。
4. **B**。结构体定义还没结束，只能用完整的 `struct node *`；`int *` 类型不对；`struct node next` 会试图在结构体里嵌一个自己，大小无穷，编译报错。
5. **A**。头节点一删，head 必须接上第二个节点，否则整条链丢失。这个函数的参数必须是 `struct node **`。

### 二、填空题

6. 堆；`free`；系统（编译器/函数结束时自动清理）。
7. 内存泄漏；悬垂；双重释放。
8. `%zu`。
9. `*head = ...`（例如 `*head = n;`）。直接写 `head = ...` 改的是副本。
10. 下一个节点（`to_delete->next`）。

### 三、阅读程序

11. 输出：

```text
0 5 0 10
```

`calloc` 把 4 个元素清零，`arr[1]` 改为 5，`arr[3] = 5 * 2 = 10`，`arr[0]` 和 `arr[2]` 保持 0。

程序里 `printf("%d ", arr[i])` 每个数字后都打一个空格，所以真实输出的行尾有一个空格。核对输出时留意这种细节，写答案时标注出来即可。

12. 最终链表：

```text
20 -> 30 -> NULL
```

过程：`push_front(&head, 20)` 后 head 指向 20；`push_front(&head, 10)` 后 head 指向 10（链是 `10 -> 20`）；`push_back(&head, 30)` 后 head 仍指向 10（链是 `10 -> 20 -> 30`）；`delete_node(&head, 10)` 删掉头节点，head 改指 20，链是 `20 -> 30`。

### 四、编程题

13. 参考代码：

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int values[6] = {34, 67, 12, 89, 45, 23};

	int *arr = malloc(6 * sizeof(int));
	if (arr == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	int max = 0;
	for (int i = 0; i < 6; i++) {
		arr[i] = values[i];
		if (i == 0 || arr[i] > max) {
			max = arr[i];
		}
	}

	printf("最大值：%d\n", max);

	free(arr);
	arr = NULL;

	return 0;
}
```

14. 参考代码：

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

struct node *find_node(struct node *head, int target)
{
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		if (cur->data == target) {
			return cur;
		}
	}
	return NULL;
}

int delete_node(struct node **head, int target)
{
	if (*head == NULL) {
		return 0;
	}

	if ((*head)->data == target) {
		struct node *to_delete = *head;
		*head = (*head)->next;
		free(to_delete);
		return 1;
	}

	struct node *prev = *head;
	while (prev->next != NULL && prev->next->data != target) {
		prev = prev->next;
	}

	if (prev->next == NULL) {
		return 0;
	}

	struct node *to_delete = prev->next;
	prev->next = to_delete->next;
	free(to_delete);
	return 1;
}

void free_list(struct node *head)
{
	struct node *cur = head;
	while (cur != NULL) {
		struct node *next = cur->next;
		free(cur);
		cur = next;
	}
}

int main(void)
{
	struct node *head = NULL;

	int values[] = {10, 20, 30, 40};
	for (int i = 0; i < 4; i++) {
		push_back(&head, values[i]);
	}

	printf("初始链表：");
	print_list(head);

	delete_node(&head, 20);
	printf("删除 20 后：");
	print_list(head);

	if (find_node(head, 40) != NULL) {
		printf("查找 40：找到了\n");
	} else {
		printf("查找 40：没找到\n");
	}

	if (find_node(head, 20) != NULL) {
		printf("查找 20：找到了\n");
	} else {
		printf("查找 20：没找到\n");
	}

	free_list(head);
	head = NULL;

	return 0;
}
```

</details>

---

[返回第 6 章导读](../README.md)
