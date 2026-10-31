# 第 2 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 2.1 超市收银的对账员

**思路**：把两种商品的金额累加成总额，用 `if (total >= 100)` 决定是否乘 0.9。

```c
#include <stdio.h>

int main(void)
{
	int count1 = 0;
	int count2 = 0;
	double price1 = 0.0;
	double price2 = 0.0;

	printf("请输入第 1 种商品的数量和单价：\n");
	if (scanf("%d %lf", &count1, &price1) != 2) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("请输入第 2 种商品的数量和单价：\n");
	if (scanf("%d %lf", &count2, &price2) != 2) {
		printf("输入格式不对\n");
		return 1;
	}

	double total = count1 * price1 + count2 * price2;
	double final_total = total;

	if (total >= 100.0) {
		final_total = total * 0.9;
	}

	printf("原价总额：%.2f 元\n", total);
	printf("折后总额：%.2f 元\n", final_total);

	return 0;
}
```

**示例运行**：

```text
请输入第 1 种商品的数量和单价：
5 12.5
请输入第 2 种商品的数量和单价：
2 20.0
原价总额：102.50 元
折后总额：92.25 元
```

---

## 2.2 停车场收费员

**思路**：`(minutes + 29) / 30` 是整数向上取整的经典写法：不足 30 分钟也会凑够一份，再乘单价即可。

```c
#include <stdio.h>

int main(void)
{
	int minutes = 0;

	printf("请输入停车分钟数：\n");
	if (scanf("%d", &minutes) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	int units = (minutes + 29) / 30;
	int fee = units * 2;

	printf("停车 %d 分钟，收费 %d 元\n", minutes, fee);

	return 0;
}
```

**示例运行**：

```text
请输入停车分钟数：
75
停车 75 分钟，收费 6 元
```

---

## 2.3 今年是平年还是闰年

**思路**：一个布尔表达式写全闰年规则：`(y % 4 == 0 && y % 100 != 0) || y % 400 == 0`，用 `bool` 存起来再判断，可读性最好。

```c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int year = 0;

	printf("请输入年份：\n");
	if (scanf("%d", &year) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	bool is_leap = (year % 4 == 0 && year % 100 != 0)
	               || year % 400 == 0;

	if (is_leap) {
		printf("%d 是闰年\n", year);
	} else {
		printf("%d 不是闰年\n", year);
	}

	return 0;
}
```

**示例运行**：

```text
请输入年份：
2028
2028 是闰年
```

---

## 2.4 猜数字的裁判

**思路**：`while` 循环里比较猜测与 `ANSWER`；输入不合法时按三件套处理（提示 + 清空缓冲区）；计数器在每轮有效判断后自增。

```c
#include <stdio.h>

int main(void)
{
	const int ANSWER = 42;
	int guess = -1;
	int tries = 0;

	while (guess != ANSWER) {
		printf("请猜一个 0 到 100 的整数：\n");

		if (scanf("%d", &guess) != 1) {
			printf("输入格式不对，请重新输入\n");

			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF) {
			}

			continue;
		}

		tries++;

		if (guess > ANSWER) {
			printf("大了\n");
		} else if (guess < ANSWER) {
			printf("小了\n");
		}
	}

	printf("猜对了！答案是 %d\n", ANSWER);
	printf("你一共猜了 %d 次\n", tries);

	return 0;
}
```

**示例运行**：

```text
请猜一个 0 到 100 的整数：
大了
请猜一个 0 到 100 的整数：
小了
请猜一个 0 到 100 的整数：
猜对了！答案是 42
你一共猜了 3 次
```

---

## 2.5 倒数计时器

**思路**：`while` 负责从 N 递减报数，`for` 负责"3，2，1"的发射序列；两种循环都能完成递减，注意 `while` 里别忘更新变量。

```c
#include <stdio.h>

int main(void)
{
	int seconds = 0;

	printf("请输入倒计时秒数（1 到 60）：\n");
	if (scanf("%d", &seconds) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	if (seconds < 1 || seconds > 60) {
		printf("范围不对\n");
		return 1;
	}

	int left = seconds;
	while (left >= 1) {
		printf("还剩 %d 秒\n", left);
		left--;
	}

	for (int i = 3; i >= 1; i--) {
		printf("%d", i);
		if (i > 1) {
			printf("，");
		}
	}
	printf("，发射！\n");

	printf("时间到\n");

	return 0;
}
```

**示例运行**（输入 3）：

```text
请输入倒计时秒数（1 到 60）：
3
还剩 3 秒
还剩 2 秒
还剩 1 秒
3，2，1，发射！
时间到
```

---

## 2.6 数字搜索游戏

**思路**：`continue` 负责"这个不行，看下一个"，`break` 负责"找到了，收工"；`found` 标志让循环结束后还能分情况报告。

```c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool found = false;

	for (int i = 1; i <= 200; i++) {
		if (i % 7 != 0 || i % 9 != 0) {
			continue;
		}

		printf("找到了：%d\n", i);
		found = true;
		break;
	}

	if (!found) {
		printf("没找到\n");
	}

	return 0;
}
```

**示例运行**：

```text
找到了：63
```

---

## 2.7 乘法口诀的单行检验

**思路**：外层定行数 N，内层 `j` 从 1 走到 N，每轮打印一条 `N x j = N*j`；两个乘数都来自循环变量。

```c
#include <stdio.h>

int main(void)
{
	int n = 0;

	printf("请输入口诀行数（1 到 9）：\n");
	if (scanf("%d", &n) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	if (n < 1 || n > 9) {
		printf("范围不对\n");
		return 1;
	}

	for (int j = 1; j <= n; j++) {
		printf("%d x %d = %d\n", n, j, n * j);
	}

	return 0;
}
```

**示例运行**（输入 6）：

```text
请输入口诀行数（1 到 9）：
6
6 x 1 = 6
6 x 2 = 12
6 x 3 = 18
6 x 4 = 24
6 x 5 = 30
6 x 6 = 36
```

---

## 2.8 亲密数对查找器

**思路**：真因数之和从 1 试到 `n / 2`；判断"亲密"要小心 220 和 284 这种"各算各"的双向关系——两边的和都要等于对方。

```c
#include <stdio.h>
#include <stdbool.h>

int sum_of_divisors(int n)
{
	int sum = 0;

	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}

	return sum;
}

bool is_amicable(int a, int b)
{
	return sum_of_divisors(a) == b && sum_of_divisors(b) == a;
}

int main(void)
{
	printf("220 的真因数之和：%d\n", sum_of_divisors(220));
	printf("284 的真因数之和：%d\n", sum_of_divisors(284));

	if (is_amicable(220, 284)) {
		printf("220 和 284 是亲密数对\n");
	} else {
		printf("220 和 284 不是亲密数对\n");
	}

	if (is_amicable(100, 200)) {
		printf("100 和 200 是亲密数对\n");
	} else {
		printf("100 和 200 不是亲密数对\n");
	}

	return 0;
}
```

**示例运行**：

```text
220 的真因数之和：284
284 的真因数之和：220
220 和 284 是亲密数对
100 和 200 不是亲密数对
```

---

## 2.9 简易四则运算测验机

**思路**：题目数据放在二维初始化列表里，`make_question` 只管出题，`check_answer` 只管判卷，`main` 负责串流程和计分；输入不合法走三件套。

```c
#include <stdio.h>
#include <stdbool.h>

void make_question(int index, int a, int b)
{
	printf("第 %d 题：%d + %d = \n", index, a, b);
}

bool check_answer(int a, int b, int given)
{
	return given == a + b;
}

int main(void)
{
	const int QUESTION_COUNT = 5;
	const int QUESTIONS[5][2] = {
		{3, 7}, {2, 9}, {5, 5}, {0, 8}, {6, 4}
	};

	int score = 0;

	for (int i = 0; i < QUESTION_COUNT; i++) {
		int a = QUESTIONS[i][0];
		int b = QUESTIONS[i][1];

		make_question(i + 1, a, b);

		int given = 0;
		if (scanf("%d", &given) != 1) {
			printf("输入格式不对，请重新输入\n");

			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF) {
			}

			i--;
			continue;
		}

		if (check_answer(a, b, given)) {
			printf("答对了\n");
			score += 20;
		} else {
			printf("答错了，正确答案是 %d\n", a + b);
		}
	}

	printf("总分：%d 分\n", score);

	return 0;
}
```

**示例运行**（答案依次 `7`、`11`、`9`、`8`、`10`）：

```text
第 1 题：3 + 7 =
7
答对了
第 2 题：2 + 9 =
11
答对了
第 3 题：5 + 5 =
9
答错了，正确答案是 10
第 4 题：0 + 8 =
8
答对了
第 5 题：6 + 4 =
10
答对了
总分：80 分
```

---

## 2.10 健身房的月度打卡报告

**思路**：把"求和""计数""找最值""画星图"各写成一个小函数，`main` 只做组装；星号个数用 `minutes / 10` 再和 6 取较小值。

```c
#include <stdio.h>

#define DAYS 30

int total_minutes(const int minutes[], int days)
{
	int sum = 0;

	for (int i = 0; i < days; i++) {
		sum += minutes[i];
	}

	return sum;
}

int count_effective(const int minutes[], int days)
{
	int count = 0;

	for (int i = 0; i < days; i++) {
		if (minutes[i] >= 30) {
			count++;
		}
	}

	return count;
}

int max_day(const int minutes[], int days)
{
	int max_index = 0;

	for (int i = 1; i < days; i++) {
		if (minutes[i] > minutes[max_index]) {
			max_index = i;
		}
	}

	return max_index;
}

void print_stars(const int minutes[], int days)
{
	for (int i = 0; i < days; i++) {
		printf("第 %d 天 |", i + 1);

		int stars = minutes[i] / 10;
		if (stars > 6) {
			stars = 6;
		}

		for (int j = 0; j < stars; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main(void)
{
	const int minutes[DAYS] = {
		45, 20, 0, 60, 35, 30, 25,
		50, 0, 40, 70, 65, 15, 0,
		30, 55, 45, 20, 10, 60, 40,
		35, 50, 45, 30, 0, 25, 65,
		20, 40
	};

	printf("总分钟数：%d\n", total_minutes(minutes, DAYS));
	printf("有效锻炼天数：%d\n", count_effective(minutes, DAYS));

	int best = max_day(minutes, DAYS);
	printf("最长的一天：第 %d 天（%d 分钟）\n", best + 1, minutes[best]);

	print_stars(minutes, DAYS);

	return 0;
}
```

**示例运行**：

```text
总分钟数：1025
有效锻炼天数：19
最长的一天：第 11 天（70 分钟）
第 1 天 |****
第 2 天 |**
第 3 天 |
第 4 天 |******
第 5 天 |***
第 6 天 |***
第 7 天 |**
第 8 天 |*****
第 9 天 |
第 10 天 |****
第 11 天 |******
第 12 天 |******
第 13 天 |*
第 14 天 |
第 15 天 |***
第 16 天 |*****
第 17 天 |****
第 18 天 |**
第 19 天 |*
第 20 天 |******
第 21 天 |****
第 22 天 |***
第 23 天 |*****
第 24 天 |****
第 25 天 |***
第 26 天 |
第 27 天 |**
第 28 天 |******
第 29 天 |**
第 30 天 |****
```

---
