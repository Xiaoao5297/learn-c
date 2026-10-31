# 第 7 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 7.1 递归打印二进制

**思路**：`n % 2` 是最低位，`n / 2` 是去掉最低位后剩下的数。把 `printf` 放在递归调用**之后**：先一路递归到最高位，归来的路上从高位到低位依次打印——这正是 7.2 顺序魔法的应用。

```c
#include <stdio.h>

void print_binary(unsigned int n)
{
	if (n >= 2) {
		print_binary(n / 2);
	}
	printf("%d", n % 2);
}

int main(void)
{
	unsigned int n = 26;

	print_binary(n);
	printf("\n");

	return 0;
}
```

**示例运行**：

```text
11010
```

---

## 7.2 亲眼看看调用栈

**思路**：函数进入时打印一句（压栈），递归调用之后再打印一句（弹栈归来）。因为返回是按调用相反的顺序发生的，"离开"的打印正好倒过来——调用栈的进出规律直接看得见。

```c
#include <stdio.h>

void dive(int n)
{
	if (n == 0) {
		printf("到底了，开始返回\n");
		return;
	}
	printf("进入第 %d 层\n", n);
	dive(n - 1);
	printf("离开第 %d 层\n", n);
}

int main(void)
{
	dive(3);

	return 0;
}
```

**示例运行**：

```text
进入第 3 层
进入第 2 层
进入第 1 层
到底了，开始返回
离开第 1 层
离开第 2 层
离开第 3 层
```

---

## 7.3 递归逆序打印数组

**思路**：`printf` 放在递归之后——先把"后面 `count - 1` 个"全部逆序打完，归来时才轮到当前第一个元素，于是它最后被打出。参数 `const int nums[]` 承诺只读。

```c
#include <stdio.h>

void print_array_reverse(const int nums[], int count)
{
	if (count == 0) {
		return;
	}
	print_array_reverse(nums + 1, count - 1);
	printf("%d ", nums[0]);
}

int main(void)
{
	int nums[5] = {10, 20, 30, 40, 50};

	print_array_reverse(nums, 5);
	printf("\n");

	return 0;
}
```

**示例运行**：

```text
50 40 30 20 10 
```

---

## 7.4 递归版 strlen

**思路**：基线条件是空串返回 0；否则长度等于 1 加上"跳过当前字符后的子串长度"，`s + 1` 就是第 4 章的指针算术。

```c
#include <stdio.h>

size_t my_strlen_rec(const char *s)
{
	if (*s == '\0') {
		return 0;
	}
	return 1 + my_strlen_rec(s + 1);
}

int main(void)
{
	printf("hello 有 %zu 个字符\n", my_strlen_rec("hello"));
	printf("c 有 %zu 个字符\n", my_strlen_rec("c"));
	printf("空串有 %zu 个字符\n", my_strlen_rec(""));

	return 0;
}
```

**示例运行**：

```text
hello 有 5 个字符
c 有 1 个字符
空串有 0 个字符
```

---

## 7.5 递归找数组最大值

**思路**：`count == 1` 时整组只剩一个元素，它就是最大值（基线条件）；否则先递归求"剩下 `count - 1` 个"的最大值，再和 `nums[0]` 比大小。每层只做一次比较，规模每层减一。

```c
#include <stdio.h>

int find_max_rec(const int nums[], int count)
{
	if (count == 1) {
		return nums[0];
	}
	int rest_max = find_max_rec(nums + 1, count - 1);

	if (nums[0] > rest_max) {
		return nums[0];
	}
	return rest_max;
}

int main(void)
{
	int nums[6] = {34, 67, 12, 89, 45, 23};

	printf("最大值：%d\n", find_max_rec(nums, 6));

	return 0;
}
```

**示例运行**：

```text
最大值：89
```

---

## 7.6 递归给数组集体翻倍

**思路**：每层递归改一个元素：先翻倍 `nums[0]`，再递归处理 `nums + 1`。参数不能加 `const`——这次要写。递归顺序（先改再递）这里无所谓，因为各层处理的是不同元素，互不影响。

```c
#include <stdio.h>

void double_all(int nums[], int count)
{
	if (count == 0) {
		return;
	}
	nums[0] *= 2;
	double_all(nums + 1, count - 1);
}

int main(void)
{
	int nums[5] = {1, 2, 3, 4, 5};

	double_all(nums, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	return 0;
}
```

**示例运行**：

```text
2 4 6 8 10 
```

---

## 7.7 回文判断

**思路**：首尾相等就剥掉两端，问题变成"中间那段是不是回文"，长度从 `len` 变成 `len - 2`——因为首尾两个字符都被处理掉了。`len <= 1` 时（剩 0 或 1 个字符）天然是回文。

```c
#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s, size_t len)
{
	if (len <= 1) {
		return 1;
	}
	if (s[0] != s[len - 1]) {
		return 0;
	}
	return is_palindrome(s + 1, len - 2);
}

int main(void)
{
	const char *words[4] = {"level", "abcba", "hello", "a"};

	for (int i = 0; i < 4; i++) {
		if (is_palindrome(words[i], strlen(words[i]))) {
			printf("%s：是回文\n", words[i]);
		} else {
			printf("%s：不是回文\n", words[i]);
		}
	}

	return 0;
}
```

**示例运行**：

```text
level：是回文
abcba：是回文
hello：不是回文
a：是回文
```

---

## 7.8 递归二分查找

**思路**：每次取中点和目标比较，查左半或右半，规模每层减半——和汉诺塔同属分治。`mid = low + (high - low) / 2` 与 `(low + high) / 2` 数学上等价，但前者在极端大的下标下更稳（避免两数相加溢出），是工程上的好习惯。

```c
#include <stdio.h>

int binary_search(const int nums[], int target, int low, int high)
{
	if (low > high) {
		return -1;
	}

	int mid = low + (high - low) / 2;

	if (nums[mid] == target) {
		return mid;
	}
	if (nums[mid] > target) {
		return binary_search(nums, target, low, mid - 1);
	}
	return binary_search(nums, target, mid + 1, high);
}

int main(void)
{
	int nums[7] = {3, 8, 15, 22, 31, 40, 57};

	printf("22 的下标：%d\n", binary_search(nums, 22, 0, 6));
	printf("40 的下标：%d\n", binary_search(nums, 40, 0, 6));
	printf("25 的下标：%d\n", binary_search(nums, 25, 0, 6));

	return 0;
}
```

**示例运行**：

```text
22 的下标：3
40 的下标：5
25 的下标：-1
```

---

## 7.9 递归反转链表

**思路**：先递归反转 `head->next`（子链反转后，原来的第二个节点成了新头）；此时 `head->next` 正好指向新链的尾巴，让尾巴的 `next` 指回 `head`，再把 `head->next` 置 `NULL`（它成了新尾巴）。基线条件是空链或单节点，反转后还是自己。

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

struct node *reverse_list(struct node *head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct node *new_head = reverse_list(head->next);

	head->next->next = head;
	head->next = NULL;
	return new_head;
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

	head = reverse_list(head);
	print_list(head);

	free_list(&head);

	return 0;
}
```

**示例运行**：

```text
10 -> 20 -> 30 -> 40 -> NULL
40 -> 30 -> 20 -> 10 -> NULL
```

---

## 7.10 爬楼梯的走法

**思路**：到第 n 阶的最后一步要么从 n−1 阶跨 1、要么从 n−2 阶跨 2，所以 `count_ways(n) = count_ways(n-1) + count_ways(n-2)`——和斐波那契同构，基线条件不同（0 阶算 1 种）。打印路径则是在递归的每层"做出一个选择"，把选择记进 `path` 数组，走到 0 阶时整条路径成形。

```c
#include <stdio.h>

int count_ways(int steps)
{
	if (steps == 0) {
		return 1;
	}
	if (steps < 0) {
		return 0;
	}
	return count_ways(steps - 1) + count_ways(steps - 2);
}

void print_paths(int steps, int path[], int len)
{
	if (steps == 0) {
		for (int i = 0; i < len; i++) {
			if (i > 0) {
				printf("+");
			}
			printf("%d", path[i]);
		}
		printf("\n");
		return;
	}

	if (steps >= 1) {
		path[len] = 1;
		print_paths(steps - 1, path, len + 1);
	}
	if (steps >= 2) {
		path[len] = 2;
		print_paths(steps - 2, path, len + 1);
	}
}

int main(void)
{
	int n = 5;
	int path[16];

	printf("%d 阶台阶共有 %d 种走法\n", n, count_ways(n));
	printf("所有走法：\n");
	print_paths(n, path, 0);

	return 0;
}
```

**示例运行**：

```text
5 阶台阶共有 8 种走法
所有走法：
1+1+1+1+1
1+1+1+2
1+1+2+1
1+2+1+1
1+2+2
2+1+1+1
2+1+2
2+2+1
```

---
