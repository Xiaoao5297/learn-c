# 第 10 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 10.1 温控宏（与题面一致）

**思路**：常量宏带括号防止"负数 + 符号"被劈开（`-5` 若不加括号，`X - WARN_LOW` 这类展开会出错）；带参宏三处括号一个不少，保证 `IN_RANGE(x + 1, lo, hi)` 这类实参不被运算符优先级破坏。

```c
#include <stdio.h>

#define WARN_LOW (-5)
#define WARN_HIGH (10)
#define IN_RANGE(x, lo, hi) (((x) >= (lo)) && ((x) <= (hi)))

int main(void)
{
	int temps[6] = {5, -3, 12, 0, -8, 7};

	for (int i = 0; i < 6; i++) {
		if (IN_RANGE(temps[i], WARN_LOW, WARN_HIGH)) {
			printf("%d 度：正常\n", temps[i]);
		} else {
			printf("%d 度：告警\n", temps[i]);
		}
	}

	return 0;
}
```

**示例运行**：

```text
5 度：正常
-3 度：正常
12 度：告警
0 度：正常
-8 度：告警
7 度：正常
```

---

## 10.2 开关面板（与题面一致）

**思路**：`|=` 打开、`^=` 切换、`&= ~` 关闭，三步各打印一次状态；最后用 `lamps & LAMP_x` 逐个检查。

```c
#include <stdio.h>

#define LAMP_POWER 1
#define LAMP_NET 2
#define LAMP_DISK 4
#define LAMP_ALARM 8

int main(void)
{
	unsigned int lamps = LAMP_POWER | LAMP_DISK;

	lamps |= LAMP_NET;
	printf("打开 NET 后 lamps = %u\n", lamps);

	lamps ^= LAMP_ALARM;
	printf("切换 ALARM 后 lamps = %u\n", lamps);

	lamps &= (unsigned int)~LAMP_DISK;
	printf("关闭 DISK 后 lamps = %u\n", lamps);

	printf("电源：%s\n", (lamps & LAMP_POWER) ? "开" : "关");
	printf("网络：%s\n", (lamps & LAMP_NET) ? "开" : "关");
	printf("硬盘：%s\n", (lamps & LAMP_DISK) ? "开" : "关");
	printf("告警：%s\n", (lamps & LAMP_ALARM) ? "开" : "关");

	return 0;
}
```

**示例运行**：

```text
打开 NET 后 lamps = 7
切换 ALARM 后 lamps = 15
关闭 DISK 后 lamps = 11
电源：开
网络：开
硬盘：关
告警：开
```

---

## 10.3 八位二进制计算器（与题面一致）

**思路**：`(x >> i) & 1u` 从第 7 位到第 0 位逐位抠出，高位自然是 0；`&`、`|`、`^` 各算一次，按同样格式打印两遍（二进制 + 十进制）。

```c
#include <stdio.h>

void print_bits8(unsigned int x)
{
	for (int i = 7; i >= 0; i--) {
		printf("%u", (x >> i) & 1u);
	}
}

int main(void)
{
	unsigned int a = 12;
	unsigned int b = 10;

	printf("a     = ");
	print_bits8(a);
	printf("（%u）\n", a);

	printf("b     = ");
	print_bits8(b);
	printf("（%u）\n", b);

	printf("a & b = ");
	print_bits8(a & b);
	printf("（%u）\n", a & b);

	printf("a | b = ");
	print_bits8(a | b);
	printf("（%u）\n", a | b);

	printf("a ^ b = ");
	print_bits8(a ^ b);
	printf("（%u）\n", a ^ b);

	printf("a 的最低位是 %u（a 是%s数）\n",
	       a & 1u, (a & 1u) ? "奇" : "偶");

	return 0;
}
```

**示例运行**：

```text
a     = 00001100（12）
b     = 00001010（10）
a & b = 00001000（8）
a | b = 00001110（14）
a ^ b = 00000110（6）
a 的最低位是 0（a 是偶数）
```

---

## 10.4 可切换的计算器（与题面一致）

**思路**：4 个同形状函数排进函数指针数组，编号减 1 即下标；先检查返回值和范围，再分发调用。

```c
#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int mod(int a, int b)
{
	return a % b;
}

int main(void)
{
	int (*ops[])(int, int) = {add, sub, mul, mod};
	const char symbols[] = {'+', '-', '*', '%'};

	int a = 0;
	int b = 0;
	int choice = 0;

	printf("请输入两个整数和运算编号（1 加 2 减 3 乘 4 余）：");
	if (scanf("%d %d %d", &a, &b, &choice) != 3) {
		printf("读取失败\n");
		return 1;
	}

	if (choice < 1 || choice > 4) {
		printf("没有编号 %d 这个运算\n", choice);
		return 1;
	}

	int result = ops[choice - 1](a, b);
	printf("%d %c %d = %d\n", a, symbols[choice - 1], b, result);

	return 0;
}
```

**示例运行**（输入 `20 6 4`）：

```text
请输入两个整数和运算编号（1 加 2 减 3 乘 4 余）：20 6 4
20 % 6 = 2
```

---

## 10.5 一份骨架，两种规则（与题面一致）

**思路**：`map_books` 只管遍历，规则全靠 `fn`；补货和打印是两个 `void xxx(struct book *)` 形状的函数。排序交给 `qsort`，比较器按三条约定写，库存降序用 `(a->stock < b->stock) - (a->stock > b->stock)` 规约。

```c
#include <stdio.h>
#include <stdlib.h>

struct book {
	char title[32];
	int stock;
};

void map_books(struct book list[], int count, void (*fn)(struct book *))
{
	for (int i = 0; i < count; i++) {
		fn(&list[i]);
	}
}

void restock(struct book *b)
{
	b->stock += 10;
}

void print_one(struct book *b)
{
	printf("%s %d\n", b->title, b->stock);
}

int compare_by_stock_desc(const void *a, const void *b)
{
	const struct book *ba = (const struct book *)a;
	const struct book *bb = (const struct book *)b;

	return (ba->stock < bb->stock) - (ba->stock > bb->stock);
}

int main(void)
{
	struct book books[4] = {
		{"C语言入门", 120},
		{"数据结构", 85},
		{"操作系统", 60},
		{"计算机网络", 85},
	};

	map_books(books, 4, restock);
	printf("补货后：\n");
	map_books(books, 4, print_one);

	qsort(books, 4, sizeof(struct book), compare_by_stock_desc);
	printf("按库存降序：\n");
	map_books(books, 4, print_one);

	return 0;
}
```

**示例运行**：

```text
补货后：
C语言入门 130
数据结构 95
操作系统 70
计算机网络 95
按库存降序：
C语言入门 130
数据结构 95
计算机网络 95
操作系统 70
```

说明：排序后的打印也走 `map_books`，顺序由 `qsort` 决定；两次 95 谁先出现取决于 `qsort` 的实现，不作保证。

---

## 10.6 位花样统计（与题面一致）

**思路**：`(x >> i) & 1u` 逐位数 1 的个数；2 的幂用 `x & (x - 1)` 判断——2 的幂只有一个 1，减 1 后这个 1 变 0、低位全变 1，按位与必为 0（注意 `x == 0` 要单独排除，0 不是 2 的幂）。

```c
#include <stdio.h>

int main(void)
{
	unsigned int x = 0;

	printf("请输入一个非负整数：");
	if (scanf("%u", &x) != 1) {
		printf("读取失败\n");
		return 1;
	}
	if (x > 1000000u) {
		printf("超出 100 万，不处理\n");
		return 1;
	}

	int ones = 0;
	for (int i = 0; i < 32; i++) {
		if ((x >> i) & 1u) {
			ones++;
		}
	}
	printf("%u 的二进制里有 %d 个 1\n", x, ones);

	if (x != 0 && (x & (x - 1u)) == 0) {
		printf("%u 是 2 的幂\n", x);
	} else {
		printf("%u 不是 2 的幂\n", x);
	}

	printf("%u << 3 = %u，%u >> 2 = %u\n",
	       x, x << 3, x, x >> 2);

	return 0;
}
```

**示例运行**（输入 `40`）：

```text
请输入一个非负整数：40
40 的二进制里有 2 个 1
40 不是 2 的幂
40 << 3 = 320，40 >> 2 = 10
```

---

## 10.7 谁快谁慢，比较器说了算（与题面一致）

**思路**：两级关键字层层 `if`：先比 `solved`（降序规约），不等直接返回；相等再比 `penalty`（升序规约）。两级各自是 `(x > y) - (x < y)` 的方向变体，永远不溢出。

```c
#include <stdio.h>
#include <stdlib.h>

struct contestant {
	char name[32];
	int solved;
	int penalty;
};

int compare(const void *a, const void *b)
{
	const struct contestant *ca = (const struct contestant *)a;
	const struct contestant *cb = (const struct contestant *)b;

	if (ca->solved != cb->solved) {
		return (ca->solved < cb->solved) - (ca->solved > cb->solved);
	}

	return (ca->penalty > cb->penalty) - (ca->penalty < cb->penalty);
}

int main(void)
{
	struct contestant list[5] = {
		{"zhang", 5, 320},
		{"wang", 5, 280},
		{"li", 4, 150},
		{"zhao", 6, 400},
		{"qian", 4, 210},
	};

	qsort(list, 5, sizeof(struct contestant), compare);

	for (int i = 0; i < 5; i++) {
		printf("第 %d 名：%s %d %d\n",
		       i + 1, list[i].name, list[i].solved, list[i].penalty);
	}

	printf("说明：解题数和罚时都相同的两人，qsort 不保证谁在前。本组数据没有平手，排名是确定的；若出现平手，谁前谁后由 qsort 的实现决定。\n");

	return 0;
}
```

**示例运行**：

```text
第 1 名：zhao 6 400
第 2 名：wang 5 280
第 3 名：zhang 5 320
第 4 名：qian 4 210
第 5 名：li 4 150
说明：解题数和罚时都相同的两人，qsort 不保证谁在前。本组数据没有平手，排名是确定的；若出现平手，谁前谁后由 qsort 的实现决定。
```

---

## 10.8 四则运算流水线（与题面一致）

**思路**：`process` 是遍历骨架，三个一步函数是规则；`APPLY_ALL` 宏是薄封装。参数加括号防止实参是表达式时被劈开。`DOUBLE(x) ((x) * (x))` 展开是平方不是翻倍：`DOUBLE(5)` 得 `25`，翻倍应该是 `((x) + (x))` 或 `((x) * 2)`。

```c
#include <stdio.h>

#define APPLY_ALL(arr, n, f) process((arr), (n), (f))

void process(int nums[], int count, int (*fn)(int))
{
	for (int i = 0; i < count; i++) {
		nums[i] = fn(nums[i]);
	}
}

int double_it(int x)
{
	return x * 2;
}

int clamp100(int x)
{
	if (x > 100) {
		return 100;
	}
	return x;
}

/* add_index 需要知道下标，借助一个全局游标；
 * 每次只把一个元素交给 process 处理，游标就是它的下标 */
int g_index = 0;

int add_index_at(int x)
{
	return x + g_index;
}

void print_array(const int nums[], int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d", nums[i]);
		if (i < count - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int main(void)
{
	int nums[4] = {3, 4, 5, 6};

	printf("初始：");
	print_array(nums, 4);

	APPLY_ALL(nums, 4, double_it);
	printf("第 1 步后：");
	print_array(nums, 4);

	for (int i = 0; i < 4; i++) {
		g_index = i;
		APPLY_ALL(&nums[i], 1, add_index_at);
	}
	printf("第 2 步后：");
	print_array(nums, 4);

	APPLY_ALL(nums, 4, clamp100);
	printf("第 3 步后：");
	print_array(nums, 4);

	printf("说明：APPLY_ALL 的参数加括号，防止实参是表达式时被展开劈开；\n");
	printf("DOUBLE(x) ((x) * (x)) 展开是平方，DOUBLE(5) = 25，不是翻倍 10。\n");

	return 0;
}
```

**示例运行**：

```text
初始：3 4 5 6
第 1 步后：6 8 10 12
第 2 步后：6 9 12 15
第 3 步后：6 9 12 15
说明：APPLY_ALL 的参数加括号，防止实参是表达式时被展开劈开；
DOUBLE(x) ((x) * (x)) 展开是平方，DOUBLE(5) = 25，不是翻倍 10。
```

说明：`add_index` 要用下标，参考答案借了一个全局游标配合 `APPLY_ALL` 逐个元素调用（`add_index_at`）；如果你把 `process` 写成"同时把下标传给 `fn`"的形状（`int (*fn)(int, int)`），骨架更干净，也是好解法。第 3 步截断在这组数据里没有触发（最大 15），换一组更大的数据就能看到 `clamp100` 生效。

---

## 10.9 通用查找器（与题面一致）

**思路**：`find_first` 只负责遍历和调用 `match`，"什么算满足"由条件函数决定——和 `qsort` 的"排序算法 + 比较器"是同一个分离思想。排序会改变元素的排列，"第一个满足条件"自然跟着变。

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_even(int x)
{
	return x % 2 == 0;
}

bool greater_than_20(int x)
{
	return x > 20;
}

int find_first(const int nums[], int count, bool (*match)(int))
{
	for (int i = 0; i < count; i++) {
		if (match(nums[i])) {
			return i;
		}
	}
	return -1;
}

void report(const int nums[], int count, bool (*match)(int),
	    const char *what)
{
	int index = find_first(nums, count, match);
	if (index >= 0) {
		printf("%s：%d（下标 %d）\n", what, nums[index], index);
	} else {
		printf("%s：没有满足条件的元素\n", what);
	}
}

void print_array(const int nums[], int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d", nums[i]);
		if (i < count - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int compare_int(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;

	return (x > y) - (x < y);
}

int main(void)
{
	int nums[6] = {12, 7, 25, 9, 30, 6};

	report(nums, 6, is_even, "第一个偶数");
	report(nums, 6, greater_than_20, "第一个大于 20");

	qsort(nums, 6, sizeof(int), compare_int);
	printf("排序后：");
	print_array(nums, 6);
	report(nums, 6, greater_than_20, "排序后第一个大于 20");

	return 0;
}
```

**示例运行**：

```text
第一个偶数：12（下标 0）
第一个大于 20：25（下标 2）
排序后：6 7 9 12 25 30
排序后第一个大于 20：25（下标 4）
```

说明：这组数据里"第一个大于 20"排序前后恰好都是 25，但下标从 2 变成了 4——顺序变了，"第一个是谁"的判定位置跟着变。换一组数据（比如把 30 放在开头）就能看到找到的元素本身也变了。

---

## 10.10 学生成绩小管家（与题面一致）

**思路**：结构体数组 + `count` 是数据骨架；增、删走 10.5 的老路（满员拒绝、删除整块前移）；排序用两级关键字比较器（分数降序、同分 `strcmp` 升序）；筛选用位运算 `tags & TAG_x`。主循环 `switch` 分发，每条命令检查返回值、限宽读入。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 20
#define NAME_LEN 30
#define TAG_MONITOR 1
#define TAG_ATHLETE 2

struct student {
	char name[NAME_LEN];
	int score;
	unsigned int tags;
};

struct student roster[MAX_STUDENTS];
int count = 0;

int find_by_name(const char name[])
{
	for (int i = 0; i < count; i++) {
		if (strcmp(roster[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

void cmd_add(void)
{
	char name[NAME_LEN];
	int score = 0;

	if (scanf("%29s %d", name, &score) != 2) {
		printf("读取失败\n");
		return;
	}

	if (count >= MAX_STUDENTS) {
		printf("名单已满\n");
		return;
	}
	if (find_by_name(name) >= 0) {
		printf("已有 %s，没有重复添加\n", name);
		return;
	}

	snprintf(roster[count].name, NAME_LEN, "%s", name);
	roster[count].score = score;
	roster[count].tags = 0;
	count++;
	printf("已添加 %s（%d 分）\n", name, score);
}

void cmd_delete(void)
{
	char name[NAME_LEN];

	if (scanf("%29s", name) != 1) {
		printf("读取失败\n");
		return;
	}

	int index = find_by_name(name);
	if (index < 0) {
		printf("没有 %s，无法删除\n", name);
		return;
	}

	for (int j = index; j < count - 1; j++) {
		roster[j] = roster[j + 1];
	}
	count--;
	printf("已删除 %s\n", name);
}

int compare_rank(const void *a, const void *b)
{
	const struct student *sa = (const struct student *)a;
	const struct student *sb = (const struct student *)b;

	if (sa->score != sb->score) {
		return (sa->score < sb->score) - (sa->score > sb->score);
	}
	return strcmp(sa->name, sb->name);
}

void cmd_rank(void)
{
	if (count == 0) {
		printf("名单是空的\n");
		return;
	}

	qsort(roster, (size_t)count, sizeof(struct student), compare_rank);
	printf("按分数排名：\n");
	for (int i = 0; i < count; i++) {
		printf("%d. %s %d\n", i + 1, roster[i].name, roster[i].score);
	}
}

void cmd_tag(void)
{
	char name[NAME_LEN];
	int tag = 0;

	if (scanf("%29s %d", name, &tag) != 2) {
		printf("读取失败\n");
		return;
	}
	if (tag != TAG_MONITOR && tag != TAG_ATHLETE) {
		printf("标志号只能是 1 或 2\n");
		return;
	}

	int index = find_by_name(name);
	if (index < 0) {
		printf("没有 %s\n", name);
		return;
	}

	roster[index].tags |= (unsigned int)tag;
	printf("已给 %s 打开标志 %d\n", roster[index].name, tag);
}

void cmd_lists(void)
{
	int has_monitor = 0;
	int has_athlete = 0;

	printf("班长：");
	for (int i = 0; i < count; i++) {
		if (roster[i].tags & TAG_MONITOR) {
			if (has_monitor) {
				printf(" ");
			}
			printf("%s", roster[i].name);
			has_monitor = 1;
		}
	}
	printf("\n");

	printf("运动员：");
	for (int i = 0; i < count; i++) {
		if (roster[i].tags & TAG_ATHLETE) {
			if (has_athlete) {
				printf(" ");
			}
			printf("%s", roster[i].name);
			has_athlete = 1;
		}
	}
	printf("\n");
}

int main(void)
{
	int running = 1;

	while (running) {
		int cmd = 0;

		if (scanf("%d", &cmd) != 1) {
			printf("命令读取失败\n");
			return 1;
		}

		switch (cmd) {
		case 1:
			cmd_add();
			break;
		case 2:
			cmd_delete();
			break;
		case 3:
			cmd_rank();
			break;
		case 4:
			cmd_tag();
			break;
		case 5:
			cmd_lists();
			break;
		case 0:
			printf("再见\n");
			running = 0;
			break;
		default:
			printf("没有这个命令（1 增 2 删 3 排 4 标志 5 名单 0 退出）\n");
			break;
		}
	}

	return 0;
}
```

**示例运行**（输入 `1 alice 90`、`1 bob 85`、`1 carol 90`、`4 alice 1`、`4 carol 2`、`3`、`5`、`2 bob`、`3`、`0`）：

```text
已添加 alice（90 分）
已添加 bob（85 分）
已添加 carol（90 分）
已给 alice 打开标志 1
已给 carol 打开标志 2
按分数排名：
1. alice 90
2. carol 90
3. bob 85
班长：alice
运动员：carol
已删除 bob
按分数排名：
1. alice 90
2. carol 90
再见
```

---
