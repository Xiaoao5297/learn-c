# 第 3 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 3.1 值日表查询机

**思路**：名字和星期几各存一个字符串数组，用同一个下标去查；下标先做范围检查再访问，避免越界。

```c
#include <stdio.h>

int main(void)
{
	const char *duty[5] = {"小明", "小红", "小刚", "小丽", "小强"};
	const char *weekday[5] = {"一", "二", "三", "四", "五"};

	int index = 0;

	printf("请输入星期序号（0 到 4）：\n");
	if (scanf("%d", &index) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	if (index < 0 || index > 4) {
		printf("没有这一天\n");
		return 1;
	}

	printf("周%s 值日：%s\n", weekday[index], duty[index]);

	return 0;
}
```

**示例运行**：

```text
请输入星期序号（0 到 4）：
3
周四 值日：小丽
```

---

## 3.2 眼保健操节拍器

**思路**：打印和求和各自封装成函数，`main` 只负责提供数据和调用；数组传参要同时传长度。

```c
#include <stdio.h>

void print_beats(const int beats[], int count)
{
	for (int i = 0; i < count; i++) {
		printf("第 %d 节：%d 拍\n", i + 1, beats[i]);
	}
}

int total_beats(const int beats[], int count)
{
	int sum = 0;

	for (int i = 0; i < count; i++) {
		sum += beats[i];
	}

	return sum;
}

int main(void)
{
	const int beats[8] = {8, 8, 8, 16, 8, 8, 8, 16};

	print_beats(beats, 8);
	printf("共 %d 拍\n", total_beats(beats, 8));

	return 0;
}
```

**示例运行**：

```text
第 1 节：8 拍
第 2 节：8 拍
第 3 节：8 拍
第 4 节：16 拍
第 5 节：8 拍
第 6 节：8 拍
第 7 节：8 拍
第 8 节：16 拍
共 80 拍
```

---

## 3.3 成绩段人数统计

**思路**：四个档位放进一个长度 4 的计数数组，`else if` 链判断档位，下标 0 到 3 对应优秀到不及格；元素个数用 `sizeof / sizeof` 算。

```c
#include <stdio.h>

int main(void)
{
	const int scores[10] = {95, 58, 72, 88, 61, 90, 45, 83, 76, 66};
	const int count = (int)(sizeof(scores) / sizeof(scores[0]));
	int buckets[4] = {0, 0, 0, 0};

	for (int i = 0; i < count; i++) {
		if (scores[i] >= 90) {
			buckets[0]++;
		} else if (scores[i] >= 80) {
			buckets[1]++;
		} else if (scores[i] >= 60) {
			buckets[2]++;
		} else {
			buckets[3]++;
		}
	}

	printf("优秀：%d 人\n", buckets[0]);
	printf("良好：%d 人\n", buckets[1]);
	printf("及格：%d 人\n", buckets[2]);
	printf("不及格：%d 人\n", buckets[3]);
	printf("总人数：%d 人\n", count);

	return 0;
}
```

**示例运行**：

```text
优秀：2 人
良好：2 人
及格：4 人
不及格：2 人
总人数：10 人
```

---

## 3.4 座位表调换

**思路**：新表的下标和老表的下标做个映射——`result[0]` 抄 `seats[1]`，`result[1]` 抄 `seats[0]`，其余照抄；打印用 `%3d` 对齐。

```c
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main(void)
{
	int seats[ROWS][COLS] = {
		{11, 12, 13, 14},
		{21, 22, 23, 24},
		{31, 32, 33, 34}
	};
	int result[ROWS][COLS] = {{0}};
	const int swap_order[ROWS] = {1, 0, 2};

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			result[row][col] = seats[swap_order[row]][col];
		}
	}

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			printf("%3d ", result[row][col]);
		}
		printf("\n");
	}

	return 0;
}
```

**示例运行**：

```text
 21  22  23  24
 11  12  13  14
 31  32  33  34
```

---

## 3.5 单词长度分布

**思路**：从头扫描，用 `in_word` 标志记住"当前在不在单词里"；遇到空格时结算上一个单词，扫描到 `'\0'` 时再结算最后一个。

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char line[128];

	printf("请输入一行英文：\n");
	if (fgets(line, sizeof(line), stdin) == NULL) {
		return 1;
	}

	line[strcspn(line, "\n")] = '\0';

	size_t length = 0;
	int word_no = 0;
	int in_word = 0;

	for (size_t i = 0; i <= strlen(line); i++) {
		if (line[i] != ' ' && line[i] != '\0') {
			length++;
			in_word = 1;
		} else if (in_word) {
			word_no++;
			printf("单词 %d：长度 %zu\n", word_no, length);
			length = 0;
			in_word = 0;
		}
	}

	printf("共 %d 个单词\n", word_no);

	return 0;
}
```

**示例运行**（输入 `I love C language`）：

```text
请输入一行英文：
单词 1：长度 1
单词 2：长度 4
单词 3：长度 1
单词 4：长度 8
共 4 个单词
```

---

## 3.6 谁在名单里

**思路**：`strcmp` 返回 0 表示内容相同；遍历时找到就记下下标并停止，找不到用 -1 表示。

```c
#include <stdio.h>
#include <string.h>

int find_name(const char *roster[], int count, const char target[])
{
	for (int i = 0; i < count; i++) {
		if (strcmp(roster[i], target) == 0) {
			return i;
		}
	}

	return -1;
}

int main(void)
{
	const char *roster[6] = {
		"anna", "ben", "cindy", "david", "elena", "frank"
	};
	char target[32];

	printf("请输入要查找的名字：\n");
	if (scanf("%31s", target) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	int index = find_name(roster, 6, target);

	if (index >= 0) {
		printf("%s 在名单第 %d 位\n", target, index + 1);
	} else {
		printf("%s 不在名单里\n", target);
	}

	return 0;
}
```

**示例运行**：

```text
请输入要查找的名字：
david
david 在名单第 4 位
```

---

## 3.7 身份证生日提取

**思路**：先检查长度是不是 18；第 7 到 14 位（下标 6 到 13）按"年 4 位、月 2 位、日 2 位"切出来，各补 `'\0'`，最后 `snprintf` 拼成中文格式。

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char id[32];
	char year[5] = {0};
	char month[3] = {0};
	char day[3] = {0};
	char birthday[64];

	printf("请输入 18 位身份证号：\n");
	if (scanf("%31s", id) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	if (strlen(id) != 18) {
		printf("号码长度不对\n");
		return 1;
	}

	for (int i = 0; i < 4; i++) {
		year[i] = id[6 + i];
	}
	year[4] = '\0';

	month[0] = id[10];
	month[1] = id[11];
	month[2] = '\0';

	day[0] = id[12];
	day[1] = id[13];
	day[2] = '\0';

	snprintf(birthday, sizeof(birthday), "出生日期：%s 年 %s 月 %s 日",
	         year, month, day);
	printf("%s\n", birthday);

	return 0;
}
```

**示例运行**：

```text
请输入 18 位身份证号：
110101200808154321
出生日期：2008 年 08 月 15 日
```

---

## 3.8 拼接与裁剪

**思路**：`snprintf` 一次完成拼接（比 `strcat` 先算空间更稳妥）；`strstr` 找子串，返回非 NULL 即为包含；`strlen` 报长度。

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char dir[32];
	char name[32];
	char path[96];

	printf("请输入目录名：\n");
	if (scanf("%31s", dir) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("请输入文件名：\n");
	if (scanf("%31s", name) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	snprintf(path, sizeof(path), "%s/%s", dir, name);
	printf("拼接结果：%s\n", path);

	if (strstr(path, "tmp") != NULL) {
		printf("路径包含 tmp\n");
	} else {
		printf("路径不包含 tmp\n");
	}

	printf("长度是 %zu\n", strlen(path));

	return 0;
}
```

**示例运行**：

```text
请输入目录名：
var
请输入文件名：
log.txt
拼接结果：var/log.txt
路径不包含 tmp
长度是 11
```

---

## 3.9 十字路口的红绿灯统计

**思路**：按列求和、按行求和各写一个函数；求"合计最少的一天"复用 `row_sum`，用擂台法记最小行号。

```c
#include <stdio.h>

#define DAYS 7
#define COLORS 3

int column_sum(const int table[][COLORS], int rows, int col)
{
	int sum = 0;

	for (int i = 0; i < rows; i++) {
		sum += table[i][col];
	}

	return sum;
}

int row_sum(const int table[][COLORS], int row)
{
	int sum = 0;

	for (int j = 0; j < COLORS; j++) {
		sum += table[row][j];
	}

	return sum;
}

int main(void)
{
	const int lights[DAYS][COLORS] = {
		{120, 300, 30},
		{110, 310, 25},
		{130, 290, 35},
		{115, 305, 28},
		{125, 295, 32},
		{140, 280, 40},
		{105, 315, 22}
	};

	printf("红灯总时长：%d 秒\n", column_sum(lights, DAYS, 0));
	printf("绿灯总时长：%d 秒\n", column_sum(lights, DAYS, 1));
	printf("黄灯总时长：%d 秒\n", column_sum(lights, DAYS, 2));

	for (int i = 0; i < DAYS; i++) {
		printf("第 %d 天合计：%d 秒\n", i + 1, row_sum(lights, i));
	}

	int min_row = 0;
	for (int i = 1; i < DAYS; i++) {
		if (row_sum(lights, i) < row_sum(lights, min_row)) {
			min_row = i;
		}
	}
	printf("合计最少的是第 %d 天，共 %d 秒\n",
	       min_row + 1, row_sum(lights, min_row));

	return 0;
}
```

**示例运行**：

```text
红灯总时长：845 秒
绿灯总时长：2095 秒
黄灯总时长：212 秒
第 1 天合计：450 秒
第 2 天合计：445 秒
第 3 天合计：455 秒
第 4 天合计：448 秒
第 5 天合计：452 秒
第 6 天合计：460 秒
第 7 天合计：442 秒
合计最少的是第 7 天，共 442 秒
```

---

## 3.10 文章编辑小助手

**思路**：三个函数各管一件事——统计靠一个标志区分字母和空格；改写靠"行首或空格后"这两个位置判断；长单词计数复用"进单词/出单词"的状态机。

```c
#include <stdio.h>
#include <string.h>

void count_chars(const char line[], size_t *letters, size_t *spaces)
{
	*letters = 0;
	*spaces = 0;

	for (size_t i = 0; line[i] != '\0'; i++) {
		if (line[i] == ' ') {
			(*spaces)++;
		} else {
			(*letters)++;
		}
	}
}

void capitalize(char line[])
{
	if (line[0] >= 'a' && line[0] <= 'z') {
		line[0] = (char)(line[0] - 32);
	}

	for (size_t i = 1; line[i] != '\0'; i++) {
		if (line[i - 1] == ' ' && line[i] >= 'a' && line[i] <= 'z') {
			line[i] = (char)(line[i] - 32);
		}
	}
}

size_t count_long_words(const char line[])
{
	size_t count = 0;
	size_t length = 0;
	int in_word = 0;

	for (size_t i = 0; i <= strlen(line); i++) {
		if (line[i] != ' ' && line[i] != '\0') {
			length++;
			in_word = 1;
		} else if (in_word) {
			if (length > 3) {
				count++;
			}
			length = 0;
			in_word = 0;
		}
	}

	return count;
}

int main(void)
{
	char line[128];

	printf("请输入一行英文：\n");
	if (fgets(line, sizeof(line), stdin) == NULL) {
		return 1;
	}

	line[strcspn(line, "\n")] = '\0';

	size_t letters = 0;
	size_t spaces = 0;
	count_chars(line, &letters, &spaces);
	printf("字母 %zu 个，空格 %zu 个\n", letters, spaces);

	capitalize(line);
	printf("改写后：%s\n", line);

	printf("长单词 %zu 个\n", count_long_words(line));

	return 0;
}
```

**示例运行**（输入 `the quick brown fox`）：

```text
请输入一行英文：
字母 16 个，空格 3 个
改写后：The Quick Brown Fox
长单词 2 个
```

---
