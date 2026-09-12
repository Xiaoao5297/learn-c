# 复习 第4节：工程好习惯 —— 让 bug 无处藏身

> 💬 **节前语：**
>
> 前几节讲了"好看"，这一节讲"结实"。
>
> 很多C程序的崩溃，不是语法错，而是**习惯没养好**：忘了检查、忘了关文件、下标越界、空指针……
>
> 下面的习惯**不是新语法**，而是前4章知识的"正确用法"。照做，你的程序会结实很多。

---

## 习惯1：凡可能失败，必检查

### 打开文件必查 NULL

```c
FILE *fp = fopen("data.txt", "r");
if (fp == NULL) {          // ✅ 必查
    perror("打开失败");
    return -1;
}
```

### 除法/取余前查除数

```c
if (divisor == 0) {        // ✅ 除前先查
    return -1;
}
```

> 🚨 **不检查的后果：** 用 NULL 文件指针读写 → 直接崩溃（段错误）。

---

## 习惯2：凡用数组，必想边界

C不检查下标越界，所以**只能靠你自己**：

```c
// ✅ 循环条件写 i < n，别写 i <= n
for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
}
```

**记住两个"差一"：**
- 数组长度为 n，下标最大是 `n - 1`
- 循环写 `i < n`，写 `i <= n` 就多访问了一个（越界！）

---

## 习惯3：凡"打开/申请"，必"关闭/释放"

| 打开/申请 | 用后必须 |
|-----------|----------|
| `fopen(...)` | `fclose(...)` |
| 后面学的 `malloc(...)` | `free(...)` |

```c
FILE *fp = fopen("log.txt", "w");
if (fp == NULL) { ... }
// ... 使用 ...
fclose(fp);     // ✅ 成对出现
```

> 💡 **好处：** 1) 把缓冲区数据真正写进磁盘；2) 不浪费系统资源。

---

## 习惯4：指针用前，先想"它指向哪"

```c
int *p = NULL;

if (p != NULL) {           // ✅ 先判断再用
    *p = 100;
}
```

> 🚨 **常见翻车现场：** `int *p;`（没指向）就 `*p = 100;` → p 里是垃圾地址 → 乱写内存 → 崩溃或数据错乱。

---

## 习惯5：善用 typedef / #define 减少重复

**把"魔法数字"变成有名字的常量：**

```c
#define MAX_STUDENTS 100          // 魔法数字 → 有名字
#define DATA_FILE "students.txt"  // 路径只写一遍
```

**typedef 少敲 struct：**

```c
typedef struct { ... } Student;   // 之后写 Student，不用写 struct Student
```

**用"宏函数"自动算数组长度（超省事）：**

```c
#define ARRAY_LEN(a) (sizeof(a) / sizeof((a)[0]))
// 用法：
int scores[] = {85, 92, 78, 65, 100};
int n = ARRAY_LEN(scores);        // 自动得到 5，不用手数！
```

> 📌 `#define ARRAY_LEN(a)` 在编译时会把 `ARRAY_LEN(x)` 替换成那串公式。注意：它只在"定义数组的地方"有效（函数参数里的数组不能用——回忆第3章的 sizeof 陷阱）。

---

## 📊 代码质量自查清单

写代码时，问自己这些问题：

| ✅ 问题 | 是/否 |
|---------|-------|
| 代码排版整齐（缩进、空格、空行）吗？ | |
| 每个变量的名字都能一眼看出含义吗？ | |
| 布尔变量读起来像一句话吗（is/has/can）？ | |
| 常量、宏用了全大写吗？ | |
| 每个函数只做一件事吗？每个函数不超过30行吗？ | |
| 参数太多时，用结构体打包了吗？ | |
| 相关的数据组织在结构体里了吗？ | |
| 代码有合理的注释分块吗？ | |
| 每个可能失败的地方都检查了吗？ | |
| 文件用完 fclose 了吗？循环下标会越界吗？ | |
| 如果让别人读你的代码，他们能看懂吗？ | |

如果全部回答"是"，那么恭喜你——你在写出**好代码**！

---

## 练习题

### 练习7：代码审查

从**格式、命名、结构**三个维度审查下面的代码，列出所有问题：

```c
#include <stdio.h>
int m(int a[],int n){int r=a[0];for(int i=1;i<n;i++){if(a[i]>r)r=a[i];}return r;}
int main(){
int d[]={3,9,5,2,8};
int mx=m(d,5);
printf("max=%d\n",mx);
FILE*fp=fopen("result.txt","w");
fprintf(fp,"%d\n",mx);
return 0;
}
```

### 练习8：完整重构

重构下面的程序：修正变量名、拆分函数、修正整数除法、补充文件检查与关闭：

```c
#include <stdio.h>

int main() {
    int sc[] = {90, 55, 78, 66, 99, 45, 81, 70};
    int n = 8;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += sc[i];
    double av = sum / 8;      // ❌ 整数除法！
    printf("平均分：%f\n", av);

    int cnt = 0;
    for (int i = 0; i < n; i++) if (sc[i] >= 60) cnt++;
    printf("及格人数：%d\n", cnt);

    FILE *fp = fopen("report.txt", "w");
    fprintf(fp, "平均分：%f 及格：%d\n", av, cnt);
    // ❌ 没检查 fp、没 fclose
    return 0;
}
```

---

<details>
<summary>🔑 练习7 参考答案</summary>

**格式问题：**
- 函数都挤在一行，应拆成多行、规范缩进
- 运算符、逗号两侧缺空格

**命名问题：**
- `m` → `find_max`；`d` → `numbers`；`mx` → `max`

**结构问题：**
- `main` 里既找最大值又写文件，应拆成 `find_max` 和 `save_result` 两个函数
- `fopen` 没检查是否成功，也没 `fclose`

**参考修复：**
```c
#include <stdio.h>

int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int save_result(int value) {
    FILE *fp = fopen("result.txt", "w");
    if (fp == NULL) {
        perror("打开失败");
        return -1;
    }
    fprintf(fp, "%d\n", value);
    fclose(fp);
    return 0;
}

int main() {
    int numbers[] = {3, 9, 5, 2, 8};
    int max = find_max(numbers, 5);
    printf("max=%d\n", max);
    save_result(max);
    return 0;
}
```
</details>

<details>
<summary>🔑 练习8 参考答案</summary>

```c
#include <stdio.h>

#define ARRAY_LEN(a) (sizeof(a) / sizeof((a)[0]))

double average_of(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;          // ✅ 修正整数除法
}

int count_pass(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 60) {
            count++;
        }
    }
    return count;
}

int save_report(double average, int pass_count) {
    FILE *fp = fopen("report.txt", "w");
    if (fp == NULL) {                // ✅ 检查
        perror("打开失败");
        return -1;
    }
    fprintf(fp, "平均分：%.1f 及格：%d\n", average, pass_count);
    fclose(fp);                      // ✅ 关闭
    return 0;
}

int main() {
    int scores[] = {90, 55, 78, 66, 99, 45, 81, 70};
    int n = ARRAY_LEN(scores);

    double average = average_of(scores, n);
    int pass_count = count_pass(scores, n);

    printf("平均分：%.1f\n", average);
    printf("及格人数：%d\n", pass_count);

    save_report(average, pass_count);
    return 0;
}
```
</details>

---

> 🎓 **第4节完成！** 好习惯 = 少熬夜调bug。
>
> [下一节：5. 编写 Makefile →](5_makefile.md)　｜　[← 返回目录](README.md)
