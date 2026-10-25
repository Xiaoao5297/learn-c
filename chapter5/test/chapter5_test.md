# 第 5 章测试：文件读写与实战

> **测试说明**
>
> - 选择题 5 题，填空题 5 题，阅读程序 2 题，编程题 2 题。
> - 建议用时 60 到 90 分钟。
> - 先独立完成，再展开文末答案。
> - 编程题重点看思路和边界，不要求和参考答案逐字相同。

---

## 一、选择题（每题 2 分，共 10 分）

**1. `fopen` 打开文件失败时返回什么？**

A. `0`\
B. `NULL`\
C. `EOF`\
D. `-1`

---

**2. 想保留 `log.txt` 的原有内容，只在末尾追加新的一行，应该用哪个模式？**

A. `"r"`\
B. `"w"`\
C. `"a"`\
D. `"r+"`

---

**3. `fgetc` 读到文件末尾时返回？**

A. `'\0'`\
B. `0`\
C. `NULL`\
D. `EOF`

---

**4. 关于 `fgets` 读到的一行，下面说法正确的是？**

A. 换行符会被自动去掉\
B. 换行符会保留在数组里\
C. 遇到空格就停止读取\
D. 只能读出最多 10 个字符

---

**5. 用 `fwrite` 存的结构体二进制文件，下面哪种说法是对的？**

A. 换一台电脑、换一个编译器一定能正确读回\
B. 只能在同一平台、同一编译器编译的程序间可靠读回\
C. 用记事本打开也是清晰的文字\
D. `fwrite` 失败时返回负数

---

## 二、填空题（每题 4 分，共 20 分）

**6. 打开文件后必须调用函数 `________` 关闭它，否则缓冲区里的数据可能没有真正写进硬盘。**

**7. `fscanf(fp, "%d", &x)` 正常读到 1 个整数时返回值是 `________`。**

**8. `char line[32];` 想用 `fscanf` 从文件安全读入一个单词，转换说明应写成 `________`。**

**9. 用 `fseek(fp, 0, SEEK_END)` 跳到文件末尾后，调用 `________` 就能得到文件大小（字节数）。**

**10. 结构体的内存字节被 `fwrite` 原样存盘，其中编译器为了对齐插入的、看不见的字节叫 `________` 字节，它是二进制文件不可移植的原因之一。**

---

## 三、阅读程序（每题 5 分，共 10 分）

**11. 写出下面程序运行后 `nums.txt` 的内容和屏幕输出。**

```c
#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("nums.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	for (int i = 1; i <= 3; i++) {
		fprintf(fp, "%d\n", i);
	}
	fclose(fp);

	int sum = 0;
	int x;

	fp = fopen("nums.txt", "r");
	if (fp == NULL) {
		return 1;
	}
	while (fscanf(fp, "%d", &x) == 1) {
		sum += x;
	}
	fclose(fp);

	printf("%d\n", sum);
	return 0;
}
```

---

**12. 下面程序想把数据文件读进数组，存在两个安全问题，请指出并改正。**

```c
#include <stdio.h>

#define MAX 50

struct student {
	char name[20];
	int score;
};

int main(void)
{
	struct student list[MAX];
	int count;

	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	fscanf(fp, "%d", &count);
	for (int i = 0; i < count; i++) {
		fscanf(fp, "%s %d", list[i].name, &list[i].score);
	}
	fclose(fp);

	printf("%d\n", count);
	return 0;
}
```

---

## 四、编程题（每题 10 分，共 20 分）

**13. 单词统计**

文件 `words.txt` 内容为（每行一个单词）：

```text
red
green
blue
```

编写程序，用 `fgets` 逐行读取，统计单词个数，并输出最长单词的长度（读入后先去掉换行符），输出：

```text
3 个单词，最长 5 个字符
```

要求：

- 逐行读取前先用 `"w"` 模式把这三个单词写进文件，保证程序自给自足。
- 用 `strcspn` 去掉行尾换行符。
- 使用 `int main(void)`。

---

**14. 成绩存档**

定义结构体（不要用 `typedef`）：

```c
struct student {
	char name[20];
	int score;
};
```

编写两个函数和 `main`：

```c
int save_students(const struct student list[], int count);
int load_students(struct student list[], int max);
```

要求：

- `save_students` 把个数和每个学生（`"%s %d\n"`）写进 `students.txt`，成功返回 0，失败返回 -1。
- `load_students` 先读个数并**校验返回值和范围**（负数或大于 `max` 都算坏文件），再用限宽 `%19s` 读姓名，每条都要检查返回值；任何一步不对返回 -1。
- `main` 里存 2 个学生再读回打印，预期输出：

```text
读回 2 个学生：
xiaoming 90
xiaohong 85
```

---

## 参考答案

<details>
<summary>点击展开答案</summary>

### 一、选择题

1. **B**。失败返回 `NULL`，所以打开后必须检查 `if (fp == NULL)`。
2. **C**。`"a"` 追加模式不破坏原内容；`"w"` 会先清空整个文件。
3. **D**。`fgetc` 读到末尾返回 `EOF`，所以接收变量用 `int`。
4. **B**。`fgets` 会把换行符一起读进数组，处理前常用 `strcspn` 去掉；`%s` 才是遇空格停。
5. **B**。二进制文件里的填充字节、端序、类型大小都依赖平台和编译器，换环境就不可靠；用记事本打开是乱码；`fwrite` 失败返回的是小于请求值的元素个数，不是负数。

### 二、填空题

6. `fclose`
7. `1`。`fscanf` 返回成功读到的项目数。
8. `%31s`。宽度是缓冲区大小减 1：32 − 1 = 31。
9. `ftell(fp)`。末尾位置到开头的距离就是文件大小。
10. 填充（padding）。

### 三、阅读程序

11. `nums.txt` 的内容是三行：

```text
1
2
3
```

屏幕输出：

```text
6
```

写入用了 `"%d\n"`，每个数字后一个换行；读回时 `fscanf("%d", ...)` 会跳过空白依次读到 1、2、3，求和得 6。

12. 两处问题：

- `fscanf(fp, "%d", &count);` 没检查返回值，也没校验范围。文件坏了时 `count` 是垃圾值，`count > MAX` 时后面会越界写数组。应改成 `if (fscanf(fp, "%d", &count) != 1 || count < 0 || count > MAX) { fclose(fp); return 1; }`。
- `fscanf(fp, "%s %d", ...)` 的 `%s` 没有限宽，文件里出现超长姓名会冲出 `name[20]`。应改成 `%19s`（缓冲区大小减 1），并检查每次 `fscanf` 的返回值是否为 2。

### 四、编程题

13. 参考代码：

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char line[64];

	FILE *fp = fopen("words.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	fprintf(fp, "red\ngreen\nblue\n");
	fclose(fp);

	fp = fopen("words.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	int count = 0;
	int max_len = 0;

	while (fgets(line, sizeof(line), fp) != NULL) {
		line[strcspn(line, "\n")] = '\0';
		count++;
		if ((int)strlen(line) > max_len) {
			max_len = (int)strlen(line);
		}
	}
	fclose(fp);

	printf("%d 个单词，最长 %d 个字符\n", count, max_len);

	return 0;
}
```

14. 参考代码：

```c
#include <stdio.h>

#define DATA_FILE "students.txt"
#define MAX_STUDENTS 100

struct student {
	char name[20];
	int score;
};

int save_students(const struct student list[], int count)
{
	FILE *fp = fopen(DATA_FILE, "w");
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
	FILE *fp = fopen(DATA_FILE, "r");
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
	struct student class[MAX_STUDENTS] = {
		{"xiaoming", 90},
		{"xiaohong", 85},
	};

	if (save_students(class, 2) != 0) {
		printf("保存失败\n");
		return 1;
	}

	struct student loaded[MAX_STUDENTS];
	int count = load_students(loaded, MAX_STUDENTS);
	if (count < 0) {
		printf("加载失败\n");
		return 1;
	}

	printf("读回 %d 个学生：\n", count);
	for (int i = 0; i < count; i++) {
		printf("%s %d\n", loaded[i].name, loaded[i].score);
	}

	return 0;
}
```

</details>

---

[返回第 5 章](../README.md)
