# 第 5 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 5.1 乘法口诀表存盘

**思路**：`"w"` 写、检查 `fopen`、`fclose` 后用 `"r"` 重新打开验证。读回用 `fgets` 逐行循环，行尾自带换行所以直接 `%s` 打即可（`line` 本身含 `\n`）。

```c
#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("table.txt", "w");

	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}

	for (int i = 1; i <= 9; i++) {
		fprintf(fp, "%d x 9 = %d\n", i, i * 9);
	}

	fclose(fp);

	fp = fopen("table.txt", "r");
	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}
	char line[64];
	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("%s", line);
	}
	fclose(fp);

	return 0;
}
```

**示例运行**：

```text
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
```

---

## 5.2 数一数文件里的数字

**思路**：先写后读保证自给自足。`fgetc` 的返回值必须用 `int` 接（要能容纳 `EOF`），逐字符判断是否落在 `'0'` 到 `'9'` 区间。

```c
#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("note.txt", "w");

	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}
	fprintf(fp, "第1行 abc 123\n第2行 45 def\n第3行 6 ghi 789\n");
	fclose(fp);

	fp = fopen("note.txt", "r");
	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}

	int count = 0;
	int ch;

	while ((ch = fgetc(fp)) != EOF) {
		if (ch >= '0' && ch <= '9') {
			count++;
		}
	}
	fclose(fp);

	printf("数字字符共有 %d 个\n", count);

	return 0;
}
```

**示例运行**：

```text
数字字符共有 12 个
```

---

## 5.3 把每行倒过来

**思路**：一行一个缓冲区，去掉换行符后按下标首尾对调；写回时补 `'\n'`——因为去掉的那一下只在缓冲区里，文件里每行仍要各占一行。中文一个字占多个字节，但反转的是"字节顺序"恰好等于反转"字顺序"（多字节字符整体被搬动，不会拆开），这是本题的意外彩蛋。

```c
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int main(void)
{
	char line[MAX_LEN];
	char reversed[MAX_LEN];

	FILE *src = fopen("poem.txt", "r");

	if (src == NULL) {
		printf("文件打开失败\n");
		return 1;
	}

	FILE *dest = fopen("reverse.txt", "w");

	if (dest == NULL) {
		fclose(src);
		printf("文件打开失败\n");
		return 1;
	}

	while (fgets(line, sizeof(line), src) != NULL) {
		line[strcspn(line, "\n")] = '\0';
		size_t len = strlen(line);

		for (size_t i = 0; i < len; i++) {
			reversed[i] = line[len - 1 - i];
		}
		reversed[len] = '\0';

		fputs(reversed, dest);
		fputc('\n', dest);
	}

	fclose(src);
	fclose(dest);

	dest = fopen("reverse.txt", "r");
	if (dest == NULL) {
		printf("文件打开失败\n");
		return 1;
	}
	while (fgets(line, sizeof(line), dest) != NULL) {
		printf("%s", line);
	}
	fclose(dest);

	return 0;
}
```

**示例运行**（`reverse.txt` 内容为）：

```text
光月
色夜
光月明前窗
```

---

## 5.4 成绩单读取与统计

**思路**：`fscanf` 的返回值是"成功读到的项目数"，读到 2 才算一条完整记录；`%19s` 给 `name[20]` 留足 `'\0'` 的位置。循环读到返回值不是 2 为止，之后求和、记最高分下标。

```c
#include <stdio.h>

#define MAX_NAME 20

struct score_rec {
	char name[MAX_NAME];
	int score;
};

int main(void)
{
	struct score_rec list[50];
	int count = 0;

	FILE *fp = fopen("scores.txt", "r");

	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}

	while (count < 50
	       && fscanf(fp, "%19s %d", list[count].name,
			 &list[count].score) == 2) {
		count++;
	}
	fclose(fp);

	if (count == 0) {
		printf("没有读到数据\n");
		return 1;
	}

	int sum = 0;
	int top = 0;

	for (int i = 0; i < count; i++) {
		sum += list[i].score;
		if (list[i].score > list[top].score) {
			top = i;
		}
	}

	printf("共 %d 人，平均分 %.1f\n", count, (double)sum / count);
	printf("最高分：%s（%d 分）\n", list[top].name, list[top].score);

	return 0;
}
```

**示例运行**：

```text
共 4 人，平均分 86.2
最高分：xiaohong（92 分）
```

---

## 5.5 程序运行计数器

**思路**：行数就是历史运行次数。先用 `"r"` 数已有行数（第一次运行时文件不存在，`fopen` 返回 `NULL`，按 0 次处理），再用 `"a"` 追加——`"a"` 保证写在末尾、绝不破坏旧日志。

```c
#include <stdio.h>
#include <string.h>

#define LOG_FILE "run.log"

int main(void)
{
	int count = 0;
	char line[64];

	FILE *fp = fopen(LOG_FILE, "r");

	if (fp != NULL) {
		while (fgets(line, sizeof(line), fp) != NULL) {
			count++;
		}
		fclose(fp);
	}

	fp = fopen(LOG_FILE, "a");
	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}
	fprintf(fp, "第 %d 次运行\n", count + 1);
	fclose(fp);

	printf("这是第 %d 次运行\n", count + 1);

	return 0;
}
```

**示例运行**（连续运行 3 次的输出）：

```text
这是第 1 次运行
这是第 2 次运行
这是第 3 次运行
```

---

## 5.6 二进制文件定点取记录

**思路**：每条记录大小固定 `sizeof(struct point)`，第 i 条（从 0 数）的偏移就是 `i * sizeof(struct point)`。读第 2 条（下标 1）就跳过 1 条记录的距离。`fseek` 返回 0 表示成功，`fread` 返回读到的条数。

```c
#include <stdio.h>

struct point {
	int x;
	int y;
};

int main(void)
{
	struct point pts[3] = {{1, 2}, {3, 4}, {5, 6}};

	FILE *fp = fopen("points.bin", "wb");

	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}
	fwrite(pts, sizeof(struct point), 3, fp);
	fclose(fp);

	struct point one;

	fp = fopen("points.bin", "rb");
	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}

	if (fseek(fp, (long)sizeof(struct point), SEEK_SET) != 0) {
		fclose(fp);
		printf("定位失败\n");
		return 1;
	}
	if (fread(&one, sizeof(struct point), 1, fp) != 1) {
		fclose(fp);
		printf("读取失败\n");
		return 1;
	}
	fclose(fp);

	printf("第 2 条记录：(%d, %d)\n", one.x, one.y);

	return 0;
}
```

**示例运行**：

```text
第 2 条记录：(3, 4)
```

想读第 i 条记录（从 1 数），偏移量写 `(i - 1) * sizeof(struct point)`。

---

## 5.7 给文件上个最简单的锁

**思路**：加密是每个字符 `+1`，解密是 `-1`，互为逆操作。写文件时必须知道自己写了多少字节（密文是按字符逐个生成的，`strlen` 数的是明文长度，但可以自己数），读回时逐字符解密到文件尾。

```c
#include <stdio.h>

int main(void)
{
	char plain[128] = "attack at dawn";
	char cipher[128];
	char decoded[128];
	int len = 0;

	for (int i = 0; plain[i] != '\0'; i++) {
		cipher[i] = (char)(plain[i] + 1);
		len++;
	}
	cipher[len] = '\0';

	FILE *fp = fopen("cipher.txt", "w");

	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}
	fputs(cipher, fp);
	fclose(fp);

	fp = fopen("cipher.txt", "r");
	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}
	int read_len = 0;
	int ch;

	while ((ch = fgetc(fp)) != EOF && read_len < 127) {
		decoded[read_len] = (char)(ch - 1);
		read_len++;
	}
	decoded[read_len] = '\0';
	fclose(fp);

	printf("密文已写入 cipher.txt\n");
	printf("解密回读：%s\n", decoded);

	return 0;
}
```

**示例运行**：

```text
密文已写入 cipher.txt
解密回读：attack at dawn
```

---

## 5.8 日记关键词统计

**思路**：目标词和计数各放进一个数组，用同一个下标 `i` 对应"第 i 个词"和"它的次数"，逐行 `strcmp` 比对。按行读 + 整行比较的前提是"每行正好一个词"；如果一行有多个词，就该用 `fscanf("%63s", ...)` 逐词读——两种思路按数据格式选。

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char *targets[3] = {"cat", "dog", "sun"};
	int counts[3] = {0, 0, 0};
	char line[64];

	FILE *fp = fopen("diary.txt", "r");

	if (fp == NULL) {
		printf("文件打开失败\n");
		return 1;
	}

	while (fgets(line, sizeof(line), fp) != NULL) {
		line[strcspn(line, "\n")] = '\0';
		for (int i = 0; i < 3; i++) {
			if (strcmp(line, targets[i]) == 0) {
				counts[i]++;
			}
		}
	}
	fclose(fp);

	for (int i = 0; i < 3; i++) {
		printf("%s 出现 %d 次\n", targets[i], counts[i]);
	}

	return 0;
}
```

**示例运行**：

```text
cat 出现 3 次
dog 出现 2 次
sun 出现 1 次
```

---

## 5.9 找出两个文件的第一处不同

**思路**：两个 `int` 变量分别接两个文件的 `fgetc`，同步前进。四种情况要分清：都 `EOF`（相同）、只有 a 是 `EOF`、只有 b 是 `EOF`、两个字符不同。字节编号从 1 起，所以打印 `pos + 1`。

```c
#include <stdio.h>

int main(void)
{
	FILE *fa = fopen("version_a.txt", "r");
	FILE *fb = fopen("version_b.txt", "r");

	if (fa == NULL || fb == NULL) {
		if (fa != NULL) {
			fclose(fa);
		}
		if (fb != NULL) {
			fclose(fb);
		}
		printf("文件打开失败\n");
		return 1;
	}

	long pos = 0;
	int ca;
	int cb;

	while (1) {
		ca = fgetc(fa);
		cb = fgetc(fb);
		if (ca == EOF && cb == EOF) {
			printf("两个文件完全相同\n");
			break;
		}
		if (ca != cb) {
			printf("第 %ld 字节不同：", pos + 1);
			if (ca == EOF) {
				printf("a 已结束，b 是 '%c'\n", cb);
			} else if (cb == EOF) {
				printf("a 是 '%c'，b 已结束\n", ca);
			} else {
				printf("a 是 '%c'，b 是 '%c'\n", ca, cb);
			}
			break;
		}
		pos++;
	}

	fclose(fa);
	fclose(fb);

	return 0;
}
```

**示例运行**：

```text
第 12 字节不同：a 是 'a'，b 是 'u'
```

把 `version_b.txt` 改回 `attack at dawn\n` 再运行，输出：

```text
两个文件完全相同
```

---

## 5.10 班级成绩单系统

**思路**：录入用 `fgets` + `sscanf`（`sscanf` 从字符串读，格式不合法时返回值小于 2，能识别坏行）；存盘和加载是 5.5 节通讯录的标准套路——人数打头、逐条限宽、步步校验。三个函数各司其职，`main` 只串流程。

```c
#include <stdio.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_STUDENTS 50

struct student {
	char name[MAX_NAME];
	int score;
};

int save_students(const struct student list[], int count)
{
	FILE *fp = fopen("report.txt", "w");

	if (fp == NULL) {
		return -1;
	}

	fprintf(fp, "%d\n", count);
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %d\n", list[i].name, list[i].score);
	}

	fclose(fp);
	return 0;
}

int load_students(struct student list[], int max)
{
	FILE *fp = fopen("report.txt", "r");

	if (fp == NULL) {
		return -1;
	}

	int count = 0;
	if (fscanf(fp, "%d", &count) != 1 || count < 0 || count > max) {
		fclose(fp);
		return -1;
	}

	for (int i = 0; i < count; i++) {
		if (fscanf(fp, "%19s %d", list[i].name, &list[i].score) != 2) {
			fclose(fp);
			return -1;
		}
	}

	fclose(fp);
	return count;
}

int main(void)
{
	struct student entered[MAX_STUDENTS];
	int count = 0;
	char line[64];

	printf("逐行输入 姓名 分数，输入 end 结束：\n");

	while (count < MAX_STUDENTS) {
		if (fgets(line, sizeof(line), stdin) == NULL) {
			break;
		}
		line[strcspn(line, "\n")] = '\0';
		if (strcmp(line, "end") == 0) {
			break;
		}
		char name[MAX_NAME];
		int score;
		if (sscanf(line, "%19s %d", name, &score) == 2) {
			snprintf(entered[count].name,
				 sizeof(entered[count].name), "%s", name);
			entered[count].score = score;
			count++;
		} else {
			printf("格式不对，请重新输入\n");
		}
	}

	if (count == 0) {
		printf("没有录入任何学生\n");
		return 1;
	}

	if (save_students(entered, count) != 0) {
		printf("保存失败\n");
		return 1;
	}

	struct student loaded[MAX_STUDENTS];
	int loaded_count = load_students(loaded, MAX_STUDENTS);

	if (loaded_count < 0) {
		printf("加载失败\n");
		return 1;
	}

	int sum = 0;
	int top = 0;

	for (int i = 0; i < loaded_count; i++) {
		printf("%s %d\n", loaded[i].name, loaded[i].score);
		sum += loaded[i].score;
		if (loaded[i].score > loaded[top].score) {
			top = i;
		}
	}

	printf("平均分：%.1f\n", (double)sum / loaded_count);
	printf("最高分：%s（%d 分）\n", loaded[top].name, loaded[top].score);

	return 0;
}
```

**示例运行**（输入 `zhang 90`、`li 85`、`wang 92`、`end`）：

```text
逐行输入 姓名 分数，输入 end 结束：
zhang 90
li 85
wang 92
zhang 90
li 85
wang 92
平均分：89.0
最高分：wang（92 分）
```

---
