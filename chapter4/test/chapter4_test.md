# 第 4 章测试：指针与结构体

> **测试说明**
>
> - 选择题 5 题，填空题 5 题，阅读程序 2 题，编程题 2 题。
> - 建议用时 60 到 90 分钟。
> - 先独立完成，再展开文末答案。
> - 编程题重点看思路和边界，不要求和参考答案逐字相同。

---

## 一、选择题（每题 2 分，共 10 分）

**1. `int x = 10; int *p = &x;`，`*p` 的值是？**

A. x 的地址\
B. `10`\
C. p 的地址\
D. 不确定

---

**2. 下面代码输出什么？**

```c
int arr[5] = {10, 20, 30, 40, 50};
int *p = arr + 1;

printf("%d", *(p + 2));
```

A. `30`\
B. `40`\
C. `50`\
D. 编译错误

---

**3. `int a[5];` 在常见 64 位系统上，`sizeof(a)` 是多少？**

A. `8`，因为数组名就是指针\
B. `20`，数组不是指针，`sizeof` 能看到整个数组\
C. `4`\
D. 取决于元素个数和元素类型，无法确定

---

**4. 想通过函数修改调用方的 `struct student` 变量的成员，函数参数应该声明为？**

A. `void f(struct student s)`\
B. `void f(struct student *s)`\
C. `void f(struct student &s)`\
D. `void f(struct student s[])`，调用时传 `stu`

---

**5. 关于 Makefile，下面说法正确的是？**

A. Makefile 是 C 语言的标准库头文件\
B. 用了 Makefile 就不需要写 `#include` 了\
C. Makefile 描述编译规则，`make` 只重新编译改动过的源文件\
D. 每次运行 `make` 都会把所有文件从头编译一遍

---

## 二、填空题（每题 4 分，共 20 分）

**6. 取变量地址用运算符\_\_\_\_\_\_\_，通过指针访问它指向的数据用运算符\_\_\_\_\_\_\_；声明 `int **pp;` 后，`**pp` 表示访问\_\_\_\_\_\_\_。**

**7. `int a[4] = {1, 2, 3, 4};`，表达式 `a[2]` 与 `*(a + \_\_\_\_\_\_\_)` 完全等价。**

**8. 把 `char` 数组传给函数时，函数内 `sizeof(数组参数)` 得到的是\_\_\_\_\_\_\_（常见 64 位系统上是 8 字节），所以长度必须\_\_\_\_\_\_\_传入。**

**9. 访问结构体变量的成员用\_\_\_\_\_\_\_运算符，访问结构体指针指向的成员用\_\_\_\_\_\_\_运算符；`const struct student *s` 表示函数承诺不修改\_\_\_\_\_\_\_。**

**10. `printf("%p", p)` 的正确写法是 `printf("%p", \_\_\_\_\_\_\_)`；指向字符串字面量的指针 `char *s = "hi";`，通过 `s` 修改字面量内容是\_\_\_\_\_\_\_（填写“合法”或“未定义行为”）。**

---

## 三、阅读程序（每题 5 分，共 10 分）

**11. 写出下面程序的输出。**

```c
#include <stdio.h>

void change(int *p)
{
	*p = *p + 10;
	p = NULL;
}

int main(void)
{
	int x = 5;
	int *q = &x;

	change(q);
	printf("%d\n", x);
	printf("%d\n", q != NULL);

	return 0;
}
```

---

**12. 写出下面程序的输出，并说明为什么。**

```c
#include <stdio.h>

struct score {
	int value;
};

void raise_value(struct score s)
{
	s.value += 10;
}

void raise_pointer(struct score *s)
{
	s->value += 10;
}

int main(void)
{
	struct score a = {50};

	raise_value(a);
	printf("%d\n", a.value);

	raise_pointer(&a);
	printf("%d\n", a.value);

	return 0;
}
```

---

## 四、编程题（每题 10 分，共 20 分）

**13. 指针带回多个结果**

编写函数 `void find_max_min(const int nums[], int count, int *max_out, int *min_out);`，通过指针参数同时带回数组的最大值和最小值。测试数组 `{34, 67, 12, 89, 45, 23}`，输出：

```text
最大值：89
最小值：12
```

要求：

- 数组参数加 `const`，因为函数只读不改。
- 使用 `int main(void)`。

---

**14. 结构体数组统计**

定义结构体：

```c
struct student {
	char name[20];
	double score;
};
```

用结构体数组存 5 个学生：小明 85 分、小红 92 分、小刚 76 分、小丽 98 分、小华 60 分。

编写函数 `struct student *top_student(struct student arr[], int count);`，返回指向最高分学生的指针，在 `main` 中输出：

```text
最高分学生：小丽（98.0 分）
平均分：82.2
```

要求：

- 平均分在 `main` 里直接计算，保留一位小数。
- `top_student` 内部用箭头运算符 `->` 访问成员。

---

## 参考答案

<details>
<summary>点击展开答案</summary>

### 一、选择题

1. **B**。`p` 指向 `x`，`*p` 解引用得到 `x` 本身，值是 10。
2. **B**。`p` 指向 `arr[1]`，`p + 2` 指向 `arr[3]`，解引用是 40。
3. **B**。5 个 `int` 共 20 字节。数组名在表达式中会转换为指向首元素的指针，但数组本身不是指针，`sizeof` 是为数不多的能看见数组本来面目的场合。
4. **B**。传地址才能修改原结构体，函数内用 `s->成员` 访问；调用时传 `&stu`。C 是 C++ 的引用语法，C 语言里没有。
5. **C**。Makefile 描述目标和依赖，`make` 检查文件的修改时间，只重新编译改动过的源文件，这正是它省时间的原因。

### 二、填空题

6. `&`；`*`；二级指针 `pp` 指向的那个指针所指向的变量（`*pp` 是一级指针，再解引用一次）。
7. `2`。`a[i]` 与 `*(a + i)` 完全等价，下标是指针算术的缩写。
8. 一个指针的大小；作为独立的参数。
9. `.`；`->`；该结构体的任何成员。
10. `(void *)p`；未定义行为。

### 三、阅读程序

11. 输出：

```text
15
1
```

`change` 收到的是 `x` 的地址，`*p = *p + 10` 顺着地址改了 `x`，所以输出 15。函数内的 `p = NULL` 只把**函数自己的副本** `p` 设为空，不影响 `main` 里的 `q`——想改变 `q` 本身得传 `&q`（二级指针，4.6.4），所以 `q != NULL` 为真，输出 1。

12. 输出：

```text
50
60
```

`raise_value` 按值传递，结构体被整包复制，加 10 加在副本上，`a.value` 不变。`raise_pointer` 传地址，`s->value += 10` 通过 `->` 修改原结构体，变成 60。

### 四、编程题

13. 参考代码：

```c
#include <stdio.h>

void find_max_min(const int nums[], int count, int *max_out, int *min_out)
{
	*max_out = nums[0];
	*min_out = nums[0];

	for (int i = 1; i < count; i++) {
		if (nums[i] > *max_out) {
			*max_out = nums[i];
		}
		if (nums[i] < *min_out) {
			*min_out = nums[i];
		}
	}
}

int main(void)
{
	int nums[6] = {34, 67, 12, 89, 45, 23};
	int max;
	int min;

	find_max_min(nums, 6, &max, &min);

	printf("最大值：%d\n", max);
	printf("最小值：%d\n", min);

	return 0;
}
```

要点：最大值和最小值都先设为第一个元素（3.1.8 的套路），再从第二个开始比较；两个结果通过 `&max`、`&min` 带回，这是“用指针返回多个值”的标准形态。

14. 参考代码：

```c
#include <stdio.h>

struct student {
	char name[20];
	double score;
};

struct student *top_student(struct student arr[], int count)
{
	struct student *best = &arr[0];

	for (int i = 1; i < count; i++) {
		if (arr[i].score > best->score) {
			best = &arr[i];
		}
	}

	return best;
}

int main(void)
{
	struct student students[5] = {
		{"小明", 85.0},
		{"小红", 92.0},
		{"小刚", 76.0},
		{"小丽", 98.0},
		{"小华", 60.0}
	};

	double sum = 0.0;

	for (int i = 0; i < 5; i++) {
		sum += students[i].score;
	}

	struct student *best = top_student(students, 5);

	printf("最高分学生：%s（%.1f 分）\n", best->name, best->score);
	printf("平均分：%.1f\n", sum / 5);

	return 0;
}
```

要点：`top_student` 返回的是**地址**（`&arr[i]`），不复制结构体；函数内用 `best->score` 访问当前最优者的成员。平均分用 `(double)sum / 5` 保证浮点除法——`sum` 已声明为 `double`，直接除即可。

</details>

---

[返回第 4 章](../README.md)
