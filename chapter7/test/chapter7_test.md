# 第 7 章测试：函数进阶与递归

> **测试说明**
>
> - 选择题 5 题，填空题 5 题，阅读程序 2 题，编程题 2 题。
> - 建议用时 60 到 90 分钟。
> - 先独立完成，再展开文末答案。
> - 编程题重点看思路和边界，不要求和参考答案逐字相同。

---

## 一、选择题（每题 2 分，共 10 分）

**1. 一个正确的递归函数必须包含哪些要素？**

A. 至少两个参数和一个全局变量\
B. 基线条件、递归步骤，且参数朝基线条件收敛\
C. 一个 `for` 循环和一个 `while` 循环\
D. 只要函数体里有对自身的调用就行

---

**2. 下面代码输出什么？**

```c
void f(int n)
{
	if (n == 0) {
		return;
	}
	f(n - 1);
	printf("%d ", n);
}

f(3);
```

A. `3 2 1`\
B. `1 2 3`\
C. `3 3 3`\
D. 无限递归崩溃

---

**3. 无限递归最终会导致什么后果？**

A. 程序自动停止，返回 0\
B. 返回值变成随机数\
C. 栈被压满，程序崩溃（栈溢出）\
D. 编译器报错，无法生成程序

---

**4. 朴素递归算 `fib(30)` 实测触发约 166 万次函数调用，根本原因是？**

A. 递归写法代码太长\
B. 大量相同子问题被反复重算\
C. `fib` 函数用了太多局部变量\
D. 斐波那契数列本身没有第 30 项

---

**5. 递归释放链表的正确顺序是？**

A. 先 `free(head)`，再递归释放 `head->next`\
B. 先递归释放 `head->next`，再 `free(head)`\
C. 先 `free(head->data)`，再 `free(head)`\
D. 链表内存会自动回收，不用释放

---

## 二、填空题（每题 4 分，共 20 分）

**6. 递归三要素是\_\_\_\_\_\_\_、递归步骤和\_\_\_\_\_\_\_；递归函数的出口处必须直接给出\_\_\_\_\_\_\_。**

**7. 每次函数调用，系统在栈上压入一条记录，叫\_\_\_\_\_\_\_，上面记着参数、局部变量和\_\_\_\_\_\_\_。**

**8. 汉诺塔 n 个盘子最少要移\_\_\_\_\_\_\_步（用含 n 的式子表示）；n = 5 时是\_\_\_\_\_\_\_步。**

**9. 递归处理链表时，基线条件是 `head` 等于\_\_\_\_\_\_\_；想让逆序打印链表，`printf` 应放在递归调用之\_\_\_\_\_\_\_。**

**10. 记忆化优化斐波那契的做法是：把算过的结果存进\_\_\_\_\_\_\_，下次遇到同样的子问题直接\_\_\_\_\_\_\_。**

---

## 三、阅读程序（每题 5 分，共 10 分）

**11. 写出下面程序的输出。**

```c
#include <stdio.h>

int mystery(int n)
{
	if (n == 0) {
		return 0;
	}
	return n % 10 + mystery(n / 10);
}

int main(void)
{
	printf("%d\n", mystery(918));
	return 0;
}
```

---

**12. 写出下面程序的输出，并说明 `count` 最终为什么是这个值。**

```c
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

void print_odd(struct node *head)
{
	if (head == NULL) {
		return;
	}
	if (head->data % 2 == 1) {
		printf("%d ", head->data);
	}
	print_odd(head->next);
}

int main(void)
{
	struct node d = {8, NULL};
	struct node c = {5, &d};
	struct node b = {3, &c};
	struct node a = {4, &b};

	print_odd(&a);
	printf("\n");
	printf("count = %d\n", 1 + (5 % 2) + (3 % 2) + (8 % 2 == 1));

	return 0;
}
```

---

## 四、编程题（每题 10 分，共 20 分）

**13. 递归求最大公约数与倒序打印**

编写程序，包含两个递归函数：`int gcd(int a, int b);` 用辗转相除法求最大公约数；`void print_reverse_number(int n);` 按位倒序打印一个非负整数（先打印个位）。运行效果：

```text
gcd(48, 18) = 6
2026 倒序：6 2 0 2
```

要求：

- 两个函数都必须是递归实现，各自写清基线条件。
- 使用 `int main(void)`。

---

**14. 递归操作链表**

定义 `struct node { int data; struct node *next; };`，在 main 里用栈上变量搭出链表 `10 -> 20 -> 30`，然后用**递归**完成：正序打印、逆序打印、求节点数，最后递归释放（本题节点在栈上，用一个递归函数统计“释放”了几个节点即可，不必真的调用 `free`）。运行效果：

```text
正序：10 -> 20 -> 30 -> NULL
逆序：30 -> 20 -> 10 -> NULL
节点数：3
```

要求：

- 打印、计数各用一个递归函数，出口都是 `head == NULL`。
- 不用 `malloc`，直接在 main 里定义三个节点变量连接成链。

---

## 参考答案

<details>
<summary>点击展开答案</summary>

### 一、选择题

1. **B**。三要素缺一不可：出口直接给出答案，递归步骤调用更小的自己，参数收敛保证到达出口。
2. **B**。`printf` 在递归调用**之后**，归来的路上打印，从小到大输出 `1 2 3`。
3. **C**。每层调用压一个栈帧，无限递归把栈压满，程序崩溃。
4. **B**。`fib(n-1)` 和 `fib(n-2)` 的子树大量重叠，同一个 `fib(k)` 被重算很多遍；实测 n 每加 1 调用次数约乘 1.6。
5. **B**。先 `free(head)` 再读 `head->next` 是悬垂访问；必须先递归释放后面的链，再释放自己。

### 二、填空题

6. 基线条件；规模收敛；答案（结果）。
7. 栈帧；返回地址。
8. 2^n − 1；31。
9. `NULL`；后。
10. 数组；查表返回（不再递归计算）。

### 三、阅读程序

11. 输出：

```text
18
```

`mystery` 是各位数字之和：`mystery(918) = 8 + mystery(91) = 8 + 1 + mystery(9) = 8 + 1 + 9 + mystery(0) = 18`。

12. 输出：

```text
3 5
count = 3
```

`print_odd` 只打印 `data` 为奇数的节点：链表是 4 -> 3 -> 5 -> 8，奇数是 3 和 5（正序打印，`printf` 在递归之前）。`count` 的算式是 `1 + 1 + 1 + 0 = 3`，即链表里奇数节点的个数——`(8 % 2 == 1)` 为假，在 C 里就是 0。

### 四、编程题

13. 参考代码：

```c
#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void print_reverse_number(int n)
{
	if (n == 0) {
		return;
	}
	printf("%d ", n % 10);
	print_reverse_number(n / 10);
}

int main(void)
{
	printf("gcd(48, 18) = %d\n", gcd(48, 18));
	printf("2026 倒序：");
	print_reverse_number(2026);
	printf("\n");

	return 0;
}
```

要点：`gcd` 的基线条件是 `b == 0`，收敛靠 `a % b` 让第二个参数严格变小；倒序打印把 `printf` 放在递归调用之前（递去时打印个位）。

14. 参考代码：

```c
#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

void print_list(struct node *head)
{
	if (head == NULL) {
		printf("NULL\n");
		return;
	}
	printf("%d ", head->data);
	print_list(head->next);
}

void print_reverse(struct node *head)
{
	if (head == NULL) {
		return;
	}
	print_reverse(head->next);
	printf("%d ", head->data);
}

int count_nodes(struct node *head)
{
	if (head == NULL) {
		return 0;
	}
	return 1 + count_nodes(head->next);
}

int main(void)
{
	struct node third = {30, NULL};
	struct node second = {20, &third};
	struct node first = {10, &second};
	struct node *head = &first;

	printf("正序：");
	print_list(head);
	printf("逆序：");
	print_reverse(head);
	printf("NULL\n");
	printf("节点数：%d\n", count_nodes(head));

	return 0;
}
```

要点：逆序只是把 `printf` 挪到递归调用之后；计数在归来的路上 `1 + count_nodes(head->next)` 逐层累加。

</details>

---

[返回第 7 章导读](../README.md)
