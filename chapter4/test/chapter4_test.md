# 第4章测试：指针与结构体

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

**1. `int x = 10; int *p = &x;` 中，`*p` 的值是：**

A. x 的地址  
B. `10`  
C. p 的地址  
D. 编译错误

---

**2. 以下代码的输出是什么？**

```c
int x = 5;
int *p = &x;
*p = *p + 3;
printf("%d", x);
```

A. `5`  
B. `8`  
C. `3`  
D. 编译错误

---

**3. `int arr[5] = {10, 20, 30, 40, 50};` 中，`*(arr + 3)` 的值是：**

A. `30`  
B. `40`  
C. `50`  
D. arr 的地址

---

**4. 想写一个函数交换 main 里的两个 int，参数应该声明为：**

A. `void f(int a, int b)`  
B. `void f(int &a, int &b)`  
C. `void f(int *a, int *b)`  
D. `void f(*a, *b)`

---

**5. 以下代码的输出是什么？**

```c
typedef struct {
    char name[20];
    int age;
} Student;

void setAge(Student *s, int newAge) {
    s->age = newAge;
}

int main() {
    Student stu = {"小明", 18};
    Student *p = &stu;
    setAge(p, 20);
    printf("%s %d", p->name, p->age);
    return 0;
}
```

A. `小明 18`  
B. `小明 20`  
C. `p 20`  
D. 编译错误

---

## 二、填空题（共5题）

**6. 取变量地址的运算符是_______，通过指针访问它指向的变量的运算符是_______。**

**7. `arr[2]` 完全等价于写法_______（用指针和解引用表示）。**

**8. 访问结构体**变量**的成员用符号_______，访问结构体**指针**指向的成员用符号_______。**

**9. C语言中，把数组传给函数时，真正传递的是数组的_______（所以函数能修改原数组）。**

**10. 定义结构体时，结尾的 `}` 后面要写_______（符号），而且可以用_______给结构体起别名。**

---

## 三、改错题（共1题）

**11. 以下程序想用函数把一个学生的成绩改成满分并打印，有4个错误，请逐一找出并改正：**

```c
#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    double score;
} Student;

void setFullScore(Student s) {    // 错误区①：传值，改不到外面
    s.score = 100.0;
}

int main() {
    Student stu = {"小明", 18, 95.5};
    Student *p = stu;             // 错误区②：应该用 &stu
    
    p->score = 99;                // 错误区③：?（这一行其实语法正确，请检查其余行）
    
    setFullScore(p);              // 错误区④：?（这里传的是地址，其实OK？）
    
    printf("%s 的成绩：%.1f\n", stu.name, stu.score);
    return 0;
}
```

> 提示：除了第1处（必须用指针参数）和第2处（取地址），还要注意即使传了指针，`setFullScore` 内部也得用 `->`；以及想一想最终 stu.score 到底会不会变成 100。

---

## 四、编程题（共3题）

### 12. 基础题：swap 交换

> 编写 `void swap(int *a, int *b)` 交换两个整数，在 main 中验证：
> 
> ```
> 交换前：a = 3, b = 7
> 交换后：a = 7, b = 3
> ```

---

### 13. 进阶题：结构体求最大值

> 定义 `Student` 结构体（姓名、成绩），用结构体数组存 5 个学生：
> 
> ```c
> {"小明", 85}, {"小红", 92}, {"小刚", 76}, {"小丽", 98}, {"小华", 60}
> ```
> 
> 编写 `int topIndex(Student arr[], int n)` 返回最高分学生的下标，在 main 中输出：
> 
> ```
> 最高分学生：小丽（98分）
> ```

---

### 14. 挑战题：指针返回多个值

> 编写一个函数，输入一个整数数组，用指针参数同时"带回"**最大值和最小值**：
> 
> ```c
> void findMaxMin(int arr[], int n, int *maxOut, int *minOut);
> ```
> 
> 测试数组 `{34, 67, 12, 89, 45, 23}`，输出：
> 
> ```
> 最大值：89
> 最小值：12
> ```

---

## ✅ 参考答案

<details>
<summary>🔑 点击展开答案</summary>

### 选择题答案

**1. B** — p 指向 x，`*p` 就是 x，值是 10。

**2. B** — `*p = *p + 3` 即 `x = 5 + 3 = 8`。

**3. B** — `arr + 3` 指向 arr[3]（值是 40）。

**4. C** — 想修改外部变量，参数必须是指针，调用时传 `&a`、`&b`。

**5. B** — `setAge(p, 20)` 通过指针把 age 改成 20，`p->name` 是 "小明"。

---

### 填空题答案

**6.** `&`；`*`

**7.** `*(arr + 2)`

**8.** `.`；`->`

**9.** 地址

**10.** `;`；`typedef`

---

### 改错题答案

**11. 四处错误：**

```c
#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    double score;
} Student;

// 错误1：参数要改成指针，内部用 ->
void setFullScore(Student *s) {
    s->score = 100.0;
}

int main() {
    Student stu = {"小明", 18, 95.5};
    Student *p = &stu;             // 错误2：取地址要用 &stu

    p->score = 99;                 // 这一行本身没错（可以保留或删除）
    
    setFullScore(p);               // 错误3：p 是 Student*，这里传指针没问题；
                                   // 但若按原题意图 setFullScore(Student s)，这里是错的
                                   // —— 因为参数已经改成指针，所以正确调用是 setFullScore(&stu) 或 setFullScore(p)
    
    printf("%s 的成绩：%.1f\n", stu.name, stu.score);
    return 0;
}
```

> 小结：核心是把 `setFullScore` 的参数从 `Student s` 改成 `Student *s`、函数体内用 `s->score`，并确保传入的是地址。最终 `stu.score` 会变成 100.0。

---

### 编程题参考答案

**12. swap 交换：**

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 3, b = 7;
    
    printf("交换前：a = %d, b = %d\n", a, b);
    
    swap(&a, &b);
    
    printf("交换后：a = %d, b = %d\n", a, b);
    return 0;
}
```

---

**13. 结构体求最大值：**

```c
#include <stdio.h>

typedef struct {
    char name[20];
    double score;
} Student;

int topIndex(Student arr[], int n) {
    int top = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].score > arr[top].score) {
            top = i;
        }
    }
    return top;
}

int main() {
    Student class[5] = {
        {"小明", 85}, {"小红", 92}, {"小刚", 76},
        {"小丽", 98}, {"小华", 60}
    };
    
    int top = topIndex(class, 5);
    printf("最高分学生：%s（%.0f分）\n", class[top].name, class[top].score);
    return 0;
}
```

---

**14. 指针返回多个值：**

```c
#include <stdio.h>

void findMaxMin(int arr[], int n, int *maxOut, int *minOut) {
    *maxOut = arr[0];
    *minOut = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *maxOut) *maxOut = arr[i];
        if (arr[i] < *minOut) *minOut = arr[i];
    }
}

int main() {
    int nums[] = {34, 67, 12, 89, 45, 23};
    int n = sizeof(nums) / sizeof(nums[0]);
    int max, min;
    
    findMaxMin(nums, n, &max, &min);
    
    printf("最大值：%d\n", max);
    printf("最小值：%d\n", min);
    return 0;
}
```

</details>

---

> 🎉 **第4章测试完成！**
> 
> 如果答对了80%以上，说明你已经掌握了C语言最核心的指针和结构体！
> 
> 如果有不会的，回去复习对应的章节吧。
> 
> [← 回到第4章](../README.md)
