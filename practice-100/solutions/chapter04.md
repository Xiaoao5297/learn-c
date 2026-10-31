# 第 4 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 4.1 一个指针轮流指挥三个变量

**思路**：指针的价值在于"可重指向"。让 `p` 先指向 `a`，通过 `*p` 翻倍；再 `p = &b` 换目标，以此类推。翻倍的是 `p` 当前指向的变量，不是 `p` 本身。

```c
#include <stdio.h>

int main(void)
{
	int a = 3;
	int b = 4;
	int c = 5;

	int *p = &a;
	*p *= 2;

	p = &b;
	*p *= 2;

	p = &c;
	*p *= 2;

	printf("%d %d %d\n", a, b, c);

	return 0;
}
```

**示例运行**：

```text
6 8 10
```

---

## 4.2 指针遍历气温数组

**思路**：`double *p` 从 `temps` 出发，循环条件 `p < temps + 6` 保证正好走 6 个元素；`p++` 每次前进一个 `double` 的宽度。全程只用 `*p` 读元素。

```c
#include <stdio.h>

int main(void)
{
	double temps[6] = {12.5, 13.0, 11.5, 14.2, 13.8, 12.9};
	double sum = 0.0;

	for (double *p = temps; p < temps + 6; p++) {
		sum += *p;
	}

	printf("平均气温：%.2f\n", sum / 6);

	return 0;
}
```

**示例运行**：

```text
平均气温：12.98
```

---

## 4.3 只留字母

**思路**：读写双指针。`read_pos` 负责侦察每个字符，是字母就交给 `write_pos` 安放并前进一步；不是字母就跳过。最后 `*write_pos = '\0'` 截断——压缩后数组尾部还有旧数据，不补结尾符就会打印出脏内容。

```c
#include <stdio.h>

void keep_letters(char *s)
{
	char *write_pos = s;
	char *read_pos = s;

	while (*read_pos != '\0') {
		if ((*read_pos >= 'a' && *read_pos <= 'z')
		    || (*read_pos >= 'A' && *read_pos <= 'Z')) {
			*write_pos = *read_pos;
			write_pos++;
		}
		read_pos++;
	}
	*write_pos = '\0';
}

int main(void)
{
	char line[] = "He said: \"Hi, C!\" in 2026.";

	keep_letters(line);
	printf("只留字母：%s\n", line);

	return 0;
}
```

**示例运行**：

```text
只留字母：HesaidHiCin
```

---

## 4.4 文具库存盘点

**思路**：遍历结构体数组累加 `price * stock` 得总金额；找"占用金额最多"用"先记第一个、再逐个比较"的老套路，记下标即可。两件事一趟循环就能做完。

```c
#include <stdio.h>

struct item {
	char name[20];
	double price;
	int stock;
};

int main(void)
{
	struct item goods[4] = {
		{"笔记本", 5.0, 20},
		{"钢笔", 25.0, 8},
		{"橡皮", 1.5, 50},
		{"尺子", 3.0, 30}
	};

	double total = 0.0;
	int best = 0;

	for (int i = 0; i < 4; i++) {
		total += goods[i].price * goods[i].stock;
		if (goods[i].price * goods[i].stock
		    > goods[best].price * goods[best].stock) {
			best = i;
		}
	}

	printf("库存总金额：%.1f 元\n", total);
	printf("占用金额最多：%s（%.1f 元）\n",
	       goods[best].name, goods[best].price * goods[best].stock);

	return 0;
}
```

**示例运行**：

```text
库存总金额：465.0 元
占用金额最多：钢笔（200.0 元）
```

---

## 4.5 电子表走一秒

**思路**：加一秒后从低位往高位检查进位：秒满 60 归零并让分钟加一，分满 60 归零并让小时加一，时满 24 归零。参数用 `struct time *` 才能改到原结构体；打印函数只读，参数加 `const`。

```c
#include <stdio.h>

struct time {
	int hour;
	int minute;
	int second;
};

void tick(struct time *t)
{
	t->second++;
	if (t->second >= 60) {
		t->second = 0;
		t->minute++;
	}
	if (t->minute >= 60) {
		t->minute = 0;
		t->hour++;
	}
	if (t->hour >= 24) {
		t->hour = 0;
	}
}

void print_time(const struct time *t)
{
	printf("%02d:%02d:%02d\n", t->hour, t->minute, t->second);
}

int main(void)
{
	struct time t = {23, 59, 59};

	print_time(&t);
	tick(&t);
	print_time(&t);

	struct time normal = {10, 30, 40};
	tick(&normal);
	print_time(&normal);

	return 0;
}
```

**示例运行**：

```text
23:59:59
00:00:00
10:30:40
10:30:41
```

---

## 4.6 让指针改指最大值

**思路**：想修改调用方的指针，参数就得是 `int **`。函数里先在只读数组里找到最大元素的地址，然后 `*pp = 地址` 完成改指。验证步骤很关键：通过 `*p` 减 1 后原数组跟着变，说明指的确实是原元素，而不是复制出来的值。

```c
#include <stdio.h>

void point_to_max(int **pp, const int *nums, int count)
{
	const int *best = &nums[0];

	for (int i = 1; i < count; i++) {
		if (nums[i] > *best) {
			best = &nums[i];
		}
	}

	*pp = (int *)best;
}

int main(void)
{
	int nums[6] = {34, 67, 12, 89, 45, 23};
	int *p = NULL;

	point_to_max(&p, nums, 6);

	printf("最大值：%d\n", *p);
	*p -= 1;
	printf("减 1 后 nums[3] = %d\n", nums[3]);

	return 0;
}
```

**示例运行**：

```text
最大值：89
减 1 后 nums[3] = 88
```

---

## 4.7 长方形小工具（多文件工程）

**思路**：头文件放结构体和声明（带三件套头文件卫士），源文件放实现，`main` 只管调用。自己写的头文件用双引号包含；参数用 `const struct rect *` 既省复制又防误改。

`shape.h`：

```c
#ifndef SHAPE_H
#define SHAPE_H

struct rect {
	double width;
	double height;
};

double rect_area(const struct rect *r);
double rect_perimeter(const struct rect *r);

#endif
```

`shape.c`：

```c
#include "shape.h"

double rect_area(const struct rect *r)
{
	return r->width * r->height;
}

double rect_perimeter(const struct rect *r)
{
	return 2.0 * (r->width + r->height);
}
```

`main.c`：

```c
#include <stdio.h>
#include "shape.h"

int main(void)
{
	struct rect r = {3.0, 4.0};

	printf("面积：%.1f\n", rect_area(&r));
	printf("周长：%.1f\n", rect_perimeter(&r));

	return 0;
}
```

手工编译命令：

```text
cc -std=c11 -Wall -Wextra -Werror -pedantic -c main.c -o main.o
cc -std=c11 -Wall -Wextra -Werror -pedantic -c shape.c -o shape.o
cc main.o shape.o -o rect_demo
./rect_demo
```

有余力版 Makefile：

```text
CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -pedantic
TARGET := rect_demo
OBJS := main.o shape.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c shape.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
```

**示例运行**：

```text
面积：12.0
周长：14.0
```

---

## 4.8 成绩排名

**思路**：冒泡排序两两比较相邻元素，逆序就交换。结构体交换靠整包赋值（三次赋值，连 `name` 数组一起复制）。降序只需把比较条件写成"前一个小于后一个就交换"。

```c
#include <stdio.h>
#include <string.h>

struct student {
	char name[20];
	double score;
};

void sort_students(struct student arr[], int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (arr[j].score < arr[j + 1].score) {
				struct student temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
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

	sort_students(students, 5);

	for (int i = 0; i < 5; i++) {
		printf("%s %.1f\n", students[i].name, students[i].score);
	}

	return 0;
}
```

**示例运行**：

```text
小丽 98.0
小红 92.0
小明 85.0
小刚 76.0
小华 60.0
```

---

## 4.9 拆分单词（指针数组）

**思路**：`tokens` 是指针数组，存的只是"每个单词开头在哪"。三步走：跳过空格；把当前地址记进 `tokens` 并让读指针走到单词末尾；把末尾的空格改成 `'\0'`（相当于就地切分）。`*count_out` 把单词个数带回给调用方。

```c
#include <stdio.h>

void split_words(char *s, char *tokens[], int max, int *count_out)
{
	int count = 0;
	char *read_pos = s;

	while (*read_pos != '\0' && count < max) {
		while (*read_pos == ' ') {
			read_pos++;
		}
		if (*read_pos == '\0') {
			break;
		}

		tokens[count] = read_pos;
		count++;

		while (*read_pos != '\0' && *read_pos != ' ') {
			read_pos++;
		}
		if (*read_pos == ' ') {
			*read_pos = '\0';
			read_pos++;
		}
	}

	*count_out = count;
}

int main(void)
{
	char line[] = "c is fun and fast";
	char *tokens[10];
	int count = 0;

	split_words(line, tokens, 10, &count);

	printf("共 %d 个单词\n", count);
	for (int i = 0; i < count; i++) {
		printf("tokens[%d] = %s\n", i, tokens[i]);
	}

	return 0;
}
```

**示例运行**：

```text
共 5 个单词
tokens[0] = c
tokens[1] = is
tokens[2] = fun
tokens[3] = and
tokens[4] = fast
```

---

## 4.10 水果店进货与售卖

**思路**：`add_stock` 和 `sell_fruit` 都要修改库存，参数是 `struct fruit *`（不带 `const`）；`print_fruit` 只读，参数是 `const struct fruit *`。`sell_fruit` 用返回值区分"卖成了"和"库存不足"，调用方据此打印不同的提示。

```c
#include <stdio.h>
#include <string.h>

#define MAX_NAME 20

struct fruit {
	char name[MAX_NAME];
	double price;
	int stock;
};

void add_stock(struct fruit *f, int amount)
{
	f->stock += amount;
}

int sell_fruit(struct fruit *f, int amount)
{
	if (f->stock < amount) {
		return 0;
	}
	f->stock -= amount;
	return 1;
}

void print_fruit(const struct fruit *f)
{
	printf("%s %.1f 元/斤，剩 %d 斤\n", f->name, f->price, f->stock);
}

int main(void)
{
	struct fruit fruits[3] = {
		{"苹果", 5.5, 30},
		{"香蕉", 3.8, 40},
		{"橙子", 6.2, 25}
	};

	add_stock(&fruits[0], 10);
	if (sell_fruit(&fruits[1], 15)) {
		printf("卖出 15 斤香蕉\n");
	}
	if (!sell_fruit(&fruits[1], 100)) {
		printf("香蕉库存不足，没卖成\n");
	}

	double total = 0.0;

	for (int i = 0; i < 3; i++) {
		print_fruit(&fruits[i]);
		total += fruits[i].price * fruits[i].stock;
	}
	printf("库存总价值：%.1f 元\n", total);

	return 0;
}
```

拆成多文件的思路：`fruit.h` 放 `struct fruit`、常量和三个函数声明（带头文件卫士），`fruit.c` 放实现，`main.c` 只管流程，Makefile 照 4.7 的模板把 `OBJS` 写成 `main.o fruit.o` 即可。

**示例运行**：

```text
卖出 15 斤香蕉
香蕉库存不足，没卖成
苹果 5.5 元/斤，剩 40 斤
香蕉 3.8 元/斤，剩 25 斤
橙子 6.2 元/斤，剩 25 斤
库存总价值：470.0 元
```

---
