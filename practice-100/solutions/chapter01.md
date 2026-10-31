# 第 1 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 1.1 自我介绍卡片

**思路**：四行 `printf` 各负责一段文字；引号用转义字符 `\"` 打印，制表对齐用 `\t`。

```c
#include <stdio.h>

int main(void)
{
	printf("=== 自我介绍 ===\n");
	printf("名字：小林\n");
	printf("爱好：\"打篮球\"和\"听音乐\"\n");
	printf("目标：\n");
	printf("\t学会 C 语言\n");
	printf("\t写出自己的小程序\n");

	return 0;
}
```

**示例运行**：

```text
=== 自我介绍 ===
名字：小林
爱好："打篮球"和"听音乐"
目标：
	学会 C 语言
	写出自己的小程序
```

---

## 1.2 字符的左右邻居

**思路**：`char` 本质是整数，`ch - 1` 和 `ch + 1` 就是字母表里的左右邻居；`%c` 打印字符本身。

```c
#include <stdio.h>

int main(void)
{
	char ch = 0;

	printf("请输入一个小写字母：\n");
	if (scanf(" %c", &ch) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("左边邻居是 %c，右边邻居是 %c\n", ch - 1, ch + 1);

	return 0;
}
```

**示例运行**：

```text
请输入一个小写字母：
b
左边邻居是 a，右边邻居是 c
```

---

## 1.3 长方形面积与周长计算器

**思路**：两次 `scanf("%lf", ...)` 各读一个数，公式直接套：面积 `长 * 宽`，周长 `2 * (长 + 宽)`。

```c
#include <stdio.h>

int main(void)
{
	double length = 0.0;
	double width = 0.0;

	printf("请输入长：\n");
	if (scanf("%lf", &length) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("请输入宽：\n");
	if (scanf("%lf", &width) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("面积是 %.2f\n", length * width);
	printf("周长是 %.2f\n", 2 * (length + width));

	return 0;
}
```

**示例运行**：

```text
请输入长：
3.5
请输入宽：
2.0
面积是 7.00
周长是 11.00
```

---

## 1.4 找零钱计算器

**思路**：读入总价和支付金额，找零就是两者的差；`%.2f` 负责保留两位小数。

```c
#include <stdio.h>

int main(void)
{
	double total = 0.0;
	double paid = 0.0;

	printf("请输入商品总价：\n");
	if (scanf("%lf", &total) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("请输入支付金额：\n");
	if (scanf("%lf", &paid) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("总价 %.2f 元，支付 %.2f 元\n", total, paid);
	printf("找零 %.2f 元\n", paid - total);

	return 0;
}
```

**示例运行**：

```text
请输入商品总价：
12.5
请输入支付金额：
20.0
总价 12.50 元，支付 20.00 元
找零 7.50 元
```

---

## 1.5 三本藏书的平均价

**思路**：三个变量读入、相加得总价；平均价除以 `3.0`（浮点除法）而不是 `3`（整数除法会丢小数）。

```c
#include <stdio.h>

int main(void)
{
	double price1 = 0.0;
	double price2 = 0.0;
	double price3 = 0.0;

	printf("请输入三本书的价格：\n");
	if (scanf("%lf", &price1) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	if (scanf("%lf", &price2) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	if (scanf("%lf", &price3) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("总价是 %.2f 元\n", price1 + price2 + price3);
	printf("平均价是 %.2f 元\n", (price1 + price2 + price3) / 3.0);

	return 0;
}
```

**示例运行**：

```text
请输入三本书的价格：
35.0
42.5
28.0
总价是 105.50 元
平均价是 35.17 元
```

---

## 1.6 温度双刻度表

**思路**：用 `const double` 存公式系数，避免"魔法数字"；`printf` 一行里可以放多个占位符。

```c
#include <stdio.h>

int main(void)
{
	const double FACTOR_NUMERATOR = 9.0;
	const double FACTOR_DENOMINATOR = 5.0;
	const double FREEZING_OFFSET = 32.0;
	double celsius = 0.0;

	printf("请输入摄氏温度：\n");
	if (scanf("%lf", &celsius) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	double fahrenheit = celsius * FACTOR_NUMERATOR / FACTOR_DENOMINATOR
	    + FREEZING_OFFSET;

	printf("%.1f C = %.1f F\n", celsius, fahrenheit);

	return 0;
}
```

**示例运行**：

```text
请输入摄氏温度：
21.5
21.5 C = 70.7 F
```

---

## 1.7 大写字母的编号密码

**思路**：大写字母在 ASCII 表里连续排列，`ch - 'A'` 直接得到它相对 `A` 的编号，不必背表。

```c
#include <stdio.h>

int main(void)
{
	char ch = 0;

	printf("请输入一个大写字母：\n");
	if (scanf(" %c", &ch) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("它比 A 大 %d 个编号\n", ch - 'A');

	return 0;
}
```

**示例运行**：

```text
请输入一个大写字母：
F
它比 A 大 5 个编号
```

---

## 1.8 三人身高体重登记表

**思路**：三个学生用三段"读入 + 存变量"完成；`%31s` 限宽读姓名、`%lf` 读数字；表格列用 `\t` 对齐。

```c
#include <stdio.h>

int main(void)
{
	char name1[32];
	char name2[32];
	char name3[32];
	double height1 = 0.0;
	double height2 = 0.0;
	double height3 = 0.0;
	double weight1 = 0.0;
	double weight2 = 0.0;
	double weight3 = 0.0;

	printf("请依次输入第 1 位学生的姓名、身高、体重：\n");
	if (scanf("%31s", name1) != 1 || scanf("%lf", &height1) != 1
	    || scanf("%lf", &weight1) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("请依次输入第 2 位学生的姓名、身高、体重：\n");
	if (scanf("%31s", name2) != 1 || scanf("%lf", &height2) != 1
	    || scanf("%lf", &weight2) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("请依次输入第 3 位学生的姓名、身高、体重：\n");
	if (scanf("%31s", name3) != 1 || scanf("%lf", &height3) != 1
	    || scanf("%lf", &weight3) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("名字\t身高(cm)\t体重(kg)\n");
	printf("%s\t%.1f\t%.1f\n", name1, height1, weight1);
	printf("%s\t%.1f\t%.1f\n", name2, height2, weight2);
	printf("%s\t%.1f\t%.1f\n", name3, height3, weight3);

	double avg_height = (height1 + height2 + height3) / 3.0;
	double avg_weight = (weight1 + weight2 + weight3) / 3.0;
	printf("平均身高 %.1f cm，平均体重 %.1f kg\n", avg_height, avg_weight);

	return 0;
}
```

**示例运行**：

```text
请依次输入第 1 位学生的姓名、身高、体重：
小明
172.5
60.0
请依次输入第 2 位学生的姓名、身高、体重：
Helen
165.0
52.5
请依次输入第 3 位学生的姓名、身高、体重：
大卫
180.0
75.0
名字	身高(cm)	体重(kg)
小明	172.5	60.0
Helen	165.0	52.5
大卫	180.0	75.0
平均身高 172.5 cm，平均体重 62.5 kg
```

---

## 1.9 批改作业的小助手

**思路**：输入校验三件套——检查 `scanf` 返回值、检查范围、非法输入后用 `getchar` 清空一行；三者都放进同一个 `while` 循环条件。

```c
#include <stdio.h>

int main(void)
{
	int score = -1;

	while (score < 0 || score > 100) {
		printf("请输入一个 0 到 100 的整数：\n");

		if (scanf("%d", &score) != 1) {
			printf("输入的不是整数，请重新输入\n");

			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF) {
			}

			score = -1;
		} else if (score < 0 || score > 100) {
			printf("范围不对，请重新输入\n");
		}
	}

	printf("分数是 %d\n", score);

	return 0;
}
```

**示例运行**（输入依次是 `abc`、`120`、`85`）：

```text
请输入一个 0 到 100 的整数：
输入的不是整数，请重新输入
请输入一个 0 到 100 的整数：
范围不对，请重新输入
请输入一个 0 到 100 的整数：
分数是 85
```

---

## 1.10 我的每周零花钱账本

**思路**：按题意先写"读一个、存一个、打一行"的 7 组顺序代码，用 `const` 存总天数；算完总和除以 7.0 得平均。重复的部分正是第 2 章循环要解决的问题。

```c
#include <stdio.h>

int main(void)
{
	const double DAYS_IN_WEEK = 7.0;

	double mon = 0.0;
	double tue = 0.0;
	double wed = 0.0;
	double thu = 0.0;
	double fri = 0.0;
	double sat = 0.0;
	double sun = 0.0;

	printf("请输入周一的零花钱：\n");
	if (scanf("%lf", &mon) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	printf("请输入周二的零花钱：\n");
	if (scanf("%lf", &tue) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	printf("请输入周三的零花钱：\n");
	if (scanf("%lf", &wed) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	printf("请输入周四的零花钱：\n");
	if (scanf("%lf", &thu) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	printf("请输入周五的零花钱：\n");
	if (scanf("%lf", &fri) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	printf("请输入周六的零花钱：\n");
	if (scanf("%lf", &sat) != 1) {
		printf("输入格式不对\n");
		return 1;
	}
	printf("请输入周日的零花钱：\n");
	if (scanf("%lf", &sun) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("周一：%.1f 元\n", mon);
	printf("周二：%.1f 元\n", tue);
	printf("周三：%.1f 元\n", wed);
	printf("周四：%.1f 元\n", thu);
	printf("周五：%.1f 元\n", fri);
	printf("周六：%.1f 元\n", sat);
	printf("周日：%.1f 元\n", sun);

	double total = mon + tue + wed + thu + fri + sat + sun;
	printf("本周合计：%.2f 元\n", total);
	printf("平均每天：%.2f 元\n", total / DAYS_IN_WEEK);

	return 0;
}
```

**示例运行**：

```text
请输入周一的零花钱：
10.0
请输入周二的零花钱：
5.5
请输入周三的零花钱：
8.0
请输入周四的零花钱：
0.0
请输入周五的零花钱：
12.5
请输入周六的零花钱：
20.0
请输入周日的零花钱：
6.5
周一：10.0 元
周二：5.5 元
周三：8.0 元
周四：0.0 元
周五：12.5 元
周六：20.0 元
周日：6.5 元
本周合计：62.50 元
平均每天：8.93 元
```

---
