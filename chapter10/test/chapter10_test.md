# 第 10 章测试：宏、位运算、函数指针与毕业项目

> **测试说明**
>
> - 选择题 5 题，填空题 5 题，阅读程序 2 题，编程题 2 题。
> - 建议用时 60 到 90 分钟。
> - 先独立完成，再展开文末答案。
> - 编程题重点看思路和边界，不要求和参考答案逐字相同。

---

## 一、选择题（每题 2 分，共 10 分）

**1. `#define SQUARE(x) ((x) * (x))`，则 `SQUARE(2 + 3)` 的值是？**

A. 25\
B. 11\
C. 10\
D. 编译错误

---

**2. `12 & 10` 的值是？（12 是 `1100`，10 是 `1010`）**

A. 14\
B. 8\
C. 6\
D. 2

---

**3. 把权限 `perm` 中的 `PERM_WRITE`（值为 2）关闭，应写？**

A. `perm &= PERM_WRITE;`\
B. `perm |= PERM_WRITE;`\
C. `perm &= ~PERM_WRITE;`\
D. `perm ^= PERM_WRITE;`

---

**4. 下列哪个是正确的函数指针声明？**

A. `int *op(int, int);`\
B. `int (*op)(int, int);`\
C. `int op*(int, int);`\
D. `(*int) op(int, int);`

---

**5. 关于 `qsort` 比较器的返回值，正确的说法是？**

A. 只能返回 -1 和 1，不能是别的负数正数\
B. 返回 0 表示 a 和 b 相等，`qsort` 只看返回值的符号\
C. 返回 1 表示 a 应排在 b 前面\
D. 返回 `x - y` 是标准写法

---

## 二、填空题（每题 4 分，共 20 分）

**6. C 程序的诞生分三步：预处理、\_\_\_\_\_\_\_\_、链接；`#define` 发生在其中的\_\_\_\_\_\_\_\_阶段。**

**7. 判断整数 n 是奇是偶的位运算写法是 `if (\_\_\_\_\_\_\_\_)`；把第 k 位打开（置 1）的写法是 `x \|= \_\_\_\_\_\_\_\_`。**

**8. 声明 `int (*op)(int, int)` 时，`(*op)` 的括号不能省，否则会被理解成"返回\_\_\_\_\_\_\_\_的普通函数"；通过指针调用可以写 `op(2, 3)`，也可以写 `\_\_\_\_\_\_\_\_(2, 3)`。**

**9. int 比较器为了防溢出，应写 `return (x > y) - (x < y);` 而不是 `return \_\_\_\_\_\_\_\_;`；`qsort` 的第三个参数传的是\_\_\_\_\_\_\_\_。**

**10. 读盘函数对文件头的个数要做两道检查：`fscanf` 的\_\_\_\_\_\_\_\_是否为 1，以及个数是否在\_\_\_\_\_\_\_\_范围内。**

---

## 三、阅读程序（每题 5 分，共 10 分）

**11. 写出下面程序的输出。**

```c
#include <stdio.h>

#define TRIPLE(x) ((x) * 3)

void apply(int nums[], int count, int (*fn)(int))
{
	for (int i = 0; i < count; i++) {
		nums[i] = fn(nums[i]);
	}
}

int add_ten(int x)
{
	return x + 10;
}

int main(void)
{
	int nums[4] = {1, 2, 3, 4};

	apply(nums, 4, add_ten);

	for (int i = 0; i < 4; i++) {
		printf("%d", TRIPLE(nums[i]));
		if (i < 3) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
```

---

**12. 下面程序想读入并校验通讯录文件，有两处错误，请指出并改正。**

```c
#include <stdio.h>

#define MAX_CONTACTS 10

int main(void)
{
	FILE *fp = fopen("contacts.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	int count;
	fscanf(fp, "%d", &count);

	for (int i = 0; i < count; i++) {
		char name[30];
		char phone[20];
		fscanf(fp, "%s %s", name, phone);
		printf("%s %s\n", name, phone);
	}

	fclose(fp);
	return 0;
}
```

---

## 四、编程题（每题 10 分，共 20 分）

**13. 位标志系统**

定义 `FLAG_BOLD 1`、`FLAG_ITALIC 2`、`FLAG_UNDER 4`。初始 `style = FLAG_BOLD`，然后依次：打开 `FLAG_UNDER`、切换 `FLAG_ITALIC`、关闭 `FLAG_BOLD`。每步之后打印 `style` 的值，最后检查三个标志各自是开还是关。运行效果：

```text
打开 UNDER 后：5
切换 ITALIC 后：7
关闭 BOLD 后：6
粗体：关
斜体：开
下划线：开
```

要求：

- 打开用 `|=`，切换用 `^=`，关闭用 `&= ~`。
- 标志定义为宏，取值每个独占一个二进制位。
- 使用 `int main(void)`。

---

**14. 通讯录核心功能**

编写程序：定义 `struct contact { char name[30]; char phone[20]; };`，预置 `{"carol", "3"}`、`{"alice", "1"}`、`{"bob", "2"}` 三人，用 `qsort` 按姓名升序排序后逐行打印，再提示输入一个姓名查找并报告找到与否。运行效果（输入 `bob`）：

```text
alice 1
bob 2
carol 3
要找谁：找到：bob（2）
```

要求：

- 比较器参数是 `const void *`，先转换回 `const struct contact *`，直接返回 `strcmp` 的结果。
- 查找输入用 `scanf("%29s", ...)` 并检查返回值。
- 使用 `int main(void)`。

---

## 参考答案

<details>
<summary>点击展开答案</summary>

### 一、选择题

1. **A**。参数带了括号，`(2 + 3)` 先算成 5，得 `((5) * (5))` = 25。缺括号的版本才会展开成 `2 + 3 * 2 + 3` = 11。
2. **B**。逐位与：只有权重 8 那一位两边都是 1，`1100 & 1010 = 1000` = 8。
3. **C**。`~PERM_WRITE` 把掩码反转成"只差这一位是 0"，按位与后恰好清掉这一位；`^=` 是切换，`|=` 是打开。
4. **B**。`(*op)` 的括号把"op 是指针"钉死；A 是返回 `int *` 的普通函数。
5. **B**。`qsort` 只看符号，返回任何负数/0/正数都合法；返回 1 是 b 在前；`x - y` 有溢出风险，不是标准写法。

### 二、填空题

6. 编译；预处理。
7. `n & 1`；`x |= (1u << k)`（写 `(1u << k)` 或具体标志宏都对）。
8. `int *`；`(*op)`。
9. `x - y`；单个元素的字节数（`sizeof(元素类型)`）。
10. 返回值；`0` 到数组容量（含两端）。

### 三、阅读程序

11. 输出：

```text
33 36 39 42
```

`apply` 通过函数指针给每个元素加 10，数组变成 `{11, 12, 13, 14}`；`TRIPLE` 是带参宏，展开成 `((nums[i]) * 3)`，得 33、36、39、42。

12. 两处错误：

- `fscanf(fp, "%d", &count)` 没有检查返回值，也没有校验范围。文件开头不是数字时 `count` 是未初始化的垃圾值；数字超过 `MAX_CONTACTS` 时循环越界。应改为 `if (fscanf(fp, "%d", &count) != 1 || count < 0 || count > MAX_CONTACTS) { fclose(fp); return 1; }`。
- `fscanf(fp, "%s %s", name, phone)` 不限宽，也不检查返回值。文件里出现超长字段就会溢出，残缺记录也照常打印。应改为 `if (fscanf(fp, "%29s %19s", name, phone) != 2) { fclose(fp); return 1; }`。

### 四、编程题

13. 参考代码：

```c
#include <stdio.h>

#define FLAG_BOLD 1
#define FLAG_ITALIC 2
#define FLAG_UNDER 4

int main(void)
{
	unsigned int style = FLAG_BOLD;

	style |= FLAG_UNDER;
	printf("打开 UNDER 后：%u\n", style);

	style ^= FLAG_ITALIC;
	printf("切换 ITALIC 后：%u\n", style);

	style &= (unsigned int)~FLAG_BOLD;
	printf("关闭 BOLD 后：%u\n", style);

	printf("粗体：%s\n", (style & FLAG_BOLD) ? "开" : "关");
	printf("斜体：%s\n", (style & FLAG_ITALIC) ? "开" : "关");
	printf("下划线：%s\n", (style & FLAG_UNDER) ? "开" : "关");

	return 0;
}
```

过程：1 → 打开 UNDER 得 5（`101`）→ 切换 ITALIC 得 7（`111`）→ 关闭 BOLD 得 6（`110`）。

14. 参考代码：

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
	char name[30];
	char phone[20];
};

int compare_by_name(const void *a, const void *b)
{
	const struct contact *ca = (const struct contact *)a;
	const struct contact *cb = (const struct contact *)b;

	return strcmp(ca->name, cb->name);
}

int main(void)
{
	struct contact book[3] = {
		{"carol", "3"},
		{"alice", "1"},
		{"bob", "2"},
	};

	qsort(book, 3, sizeof(struct contact), compare_by_name);

	for (int i = 0; i < 3; i++) {
		printf("%s %s\n", book[i].name, book[i].phone);
	}

	char key[30];

	printf("要找谁：");
	if (scanf("%29s", key) != 1) {
		printf("读取失败\n");
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		if (strcmp(book[i].name, key) == 0) {
			printf("找到：%s（%s）\n",
			       book[i].name, book[i].phone);
			return 0;
		}
	}

	printf("没有找到 %s\n", key);

	return 0;
}
```

</details>

---

[返回第 10 章导读](../README.md)
