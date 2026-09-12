# 第10章测试：C语言收官篇

> 📋 **测试说明：**
> 
> - 📝 **选择题（5题）：** 每题考查一个核心概念
> - 📝 **填空题（5题）：** 考查记忆和理解
> - 📝 **改错题（1题）：** 考查代码调试能力
> - 📝 **编程题（3题）：** 考查综合运用能力
> 
> 💡 **建议：** 先独立完成后，再对照参考答案检查。

---

## 一、选择题（共5题）

**1. `#define MAX 100` 的本质是：**

A. 定义变量 MAX，值为 100  
B. 编译前把代码里的 MAX 文本替换成 100  
C. 分配一块内存  
D. 定义一个函数

---

**2. `6 & 3` 的结果是：**

A. 7  
B. 5  
C. 2  
D. 1

---

**3. 判断整数 n 是否为奇数，位运算写法是：**

A. `n | 1` 为真  
B. `n & 1` 为真  
C. `n << 1` 为真  
D. `~n` 为真

---

**4. 正确的函数指针声明是：**

A. `int *op(int, int);`  
B. `int (*op)(int, int);`  
C. `int op(int, int);`  
D. `op int (*)(int, int);`

---

**5. 用 `qsort` 排序时，第 4 个参数（比较器函数）的作用是：**

A. 指定排序算法名字  
B. 告诉 qsort 每个元素多大  
C. 决定"谁该排前面"（返回负/0/正）  
D. 打印排序过程

---

## 二、填空题（共5题）

**6. `#define` 语句结尾不能写_______；宏名习惯用_______字母写。**

**7. 按位与是"全1才1"用______，按位或是"有1就1"用______，异或"不同才1"用______。**

**8. 函数指针声明里 `(*op)` 的括号不能省，否则会变成"返回指针的普通函数"的声明。**

**9. `qsort` 比较器返回：负数表示 a 在 b_______（前/后），0 表示相等，正数表示 b 在前。**

**10. 打开文件后必须检查返回值是否为_______；用完要调用_______关闭。**

---

## 三、改错题（共1题）

**11. 以下程序想：用函数指针调用 add、判断 n 奇偶、用宏算平方。有 3 处错误：**

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }

#define SQUARE(x) x * x                 // 错误区①：缺括号，SQUARE(2+3) 会算成多少？

int main() {
    int *op(int, int);                  // 错误区②：这是函数声明还是函数指针？
    op = add;                           // 想让 op 指向 add
    printf("add：%d\n", op(2, 3));      // 期望 5

    int n = 7;
    if (n = 1) {                        // 错误区③：想判断奇偶，写成什么了？
        printf("%d 是奇数\n", n);
    }

    printf("SQUARE(2+3) = %d\n", SQUARE(2 + 3));  // 期望 25
    return 0;
}
```

> 提示：①宏参数要加括号 `((x)*(x))`；②函数指针要写 `int (*op)(int,int);`；③奇偶判断要 `n & 1`，`n = 1` 是赋值！

---

## 四、编程题（共3题）

### 12. 基础题：宏求圆

> 用 `#define PI 3.14159`，输入半径 r=5，打印圆的周长和面积（%.4f）：
> 
> ```
> 周长 = 31.4159
> 面积 = 78.5397
> ```
> 公式：周长 2*PI*r，面积 PI*r*r。

---

### 13. 进阶题：qsort 降序排 int

> 用 `qsort` 把 `{4, 9, 2, 6, 1}` 从大到小排序并打印：
> 
> ```
> 排序后：9 6 4 2 1
> ```
> 要求：自己写比较器 `cmpDesc`。

---

### 14. 挑战题：给结构体排序

> 定义 `Student { char name[32]; int score; }`，用 `qsort` 按**分数从高到低**排下面三人：
> 
> ```
> Alice 88
> Bob 72
> Carol 95
> ```
> 输出：
> ```
> 按分数降序：Carol(95) Alice(88) Bob(72)
> ```

---

## ✅ 参考答案

<details>
<summary>🔑 点击展开答案</summary>

### 选择题答案

**1. B** — `#define` 是预处理阶段的"文本替换"，不是定义变量。

**2. C** — 6=`110`，3=`011`，按位与得 `010` = 2。

**3. B** — 奇数最低位是 1，`n & 1` 非 0 即奇数。

**4. B** — `int (*op)(int, int);`，`(*op)` 的括号表示 op 是指针。

**5. C** — 比较器返回负/0/正，告诉排序函数任意两个元素谁该在前。

---

### 填空题答案

**6.** 分号（`;`）；大写

**7.** `&`；`|`；`^`

**8.** （该空已给出）

**9.** 前

**10.** `NULL`；`fclose`

---

### 改错题答案

**11. 三处错误：**

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }

#define SQUARE(x) ((x) * (x))          // 错误1：参数加括号，SQUARE(2+3)=25

int main() {
    int (*op)(int, int);                // 错误2：写成函数指针声明
    op = add;
    printf("add：%d\n", op(2, 3));      // 5

    int n = 7;
    if (n & 1) {                        // 错误3：位与判断奇偶，不是赋值
        printf("%d 是奇数\n", n);        // 7 是奇数
    }

    printf("SQUARE(2+3) = %d\n", SQUARE(2 + 3));  // 25
    return 0;
}
```

> 正确输出：
> ```
> add：5
> 7 是奇数
> SQUARE(2+3) = 25
> ```

---

### 编程题参考答案

**12. 宏求圆：**

```c
#include <stdio.h>

#define PI 3.14159

int main() {
    double r = 5.0;
    printf("周长 = %.4f\n", 2 * PI * r);
    printf("面积 = %.4f\n", PI * r * r);
    return 0;
}
```

---

**13. qsort 降序排 int：**

```c
#include <stdio.h>
#include <stdlib.h>

int cmpDesc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return y - x;            // 大的在前 → 降序
}

int main() {
    int a[] = {4, 9, 2, 6, 1};
    int n = 5;
    qsort(a, n, sizeof(int), cmpDesc);
    printf("排序后：");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
```

---

**14. 给结构体按分数降序排序：**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int score;
} Student;

int cmpScoreDesc(const void *a, const void *b) {
    const Student *sa = (const Student *)a;
    const Student *sb = (const Student *)b;
    return sb->score - sa->score;   // 分数高的在前 → 降序
}

int main() {
    Student stu[] = {
        {"Alice", 88},
        {"Bob", 72},
        {"Carol", 95}
    };
    int n = 3;

    qsort(stu, n, sizeof(Student), cmpScoreDesc);
    printf("按分数降序：");
    for (int i = 0; i < n; i++) {
        printf("%s(%d) ", stu[i].name, stu[i].score);
    }
    printf("\n");
    return 0;
}
```

</details>

---

> 🎉 **第10章测试完成！**
> 
> 如果答对了80%以上，说明预处理、位运算、函数指针你已经全部掌握——C 语言十章修炼，圆满收官！
> 
> 如果有不会的，回去复习对应的章节吧。
> 
> [← 回到第10章](../README.md)
