# 第3章测试：数组与字符串

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

**1. 声明 `int a[5];` 后，以下哪个下标是合法的？**

A. `a[5]`  
B. `a[0]`  
C. `a[-1]`  
D. `a[6]`

---

**2. 以下代码的输出是什么？**

```c
int sum = 0;
int a[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
    if (i % 2 == 1) {
        sum += a[i];
    }
}
printf("%d", sum);
```

A. `60`  
B. `90`  
C. `120`  
D. `150`

---

**3. 以下代码的输出是什么？**

```c
int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
printf("%d", a[1][2]);
```

A. `3`  
B. `4`  
C. `5`  
D. `6`

---

**4. 关于 `strlen("Hello")` 和 `sizeof("Hello")`，正确的是：**

A. 都是 5  
B. 都是 6  
C. `strlen("Hello")` 是 5，`sizeof("Hello")` 是 6  
D. `strlen("Hello")` 是 6，`sizeof("Hello")` 是 5

---

**5. 以下代码的输出是什么？**

```c
void f(int arr[], int n) {
    arr[0] = 99;
    arr[n - 1] = 99;
}

int main() {
    int nums[3] = {1, 2, 3};
    f(nums, 3);
    printf("%d %d %d", nums[0], nums[1], nums[2]);
    return 0;
}
```

A. `1 2 3`  
B. `99 2 3`  
C. `99 2 99`  
D. `99 99 99`

---

## 二、填空题（共5题）

**6. 数组的下标从_______开始。**

**7. 遍历二维数组，通常用_______循环嵌套来实现。**

**8. C语言中，字符串靠字符数组末尾的特殊字符_______来表示结束。**

**9. 把字符串 src 的内容复制到 dest，应该用函数_______（填函数名）。**

**10. 把数组传给函数时，传的是数组的_______，所以函数内部修改数组会影响外面的数组。**

---

## 三、改错题（共1题）

**11. 以下程序想计算一个班成绩的平均分和最高分，有4个错误，请逐一找出并改正：**

```c
#include <stdio.h>

double average(int scores[]) {        // 错误区①：没传长度
    int sum = 0;
    int n = sizeof(scores) / sizeof(scores[0]);   // 错误区②：这样算长度是错的
    for (int i = 0; i <= n; i++) {    // 错误区③：越界
        sum += scores[i];
    }
    return sum / n;                   // 错误区④：整数除法
}

int main() {
    int scores[] = {85, 92, 78, 65};
    printf("平均分：%.1f\n", average(scores, 4));
    return 0;
}
```

> 提示：4个错误分别涉及：
> 1. 参数缺少长度
> 2. sizeof 数长度在函数里失效
> 3. 越界
> 4. 整数除法丢精度

---

## 四、编程题（共3题）

### 12. 基础题：数组统计函数

> 编写 `double averageArray(int arr[], int n)` 计算平均值，
> 和 `int maxArray(int arr[], int n)` 找最大值。
> 
> 在 main 中对数组 `{78, 92, 85, 100, 60}` 测试：
> 
> ```
> 平均分：83.0
> 最高分：100
> ```

---

### 13. 进阶题：二维数组成绩统计

> 3个学生各考了3门课，成绩存在二维数组里：
> 
> ```c
> int score[3][3] = {{85, 92, 78}, {96, 88, 91}, {72, 65, 80}};
> ```
> 
> 编写程序，计算并输出**每个学生的总分**和**每门课的平均分**：
> 
> ```
> 第 0 个学生总分：255
> 第 1 个学生总分：275
> 第 2 个学生总分：217
> 第 0 科平均分：84.3
> 第 1 科平均分：81.7
> 第 2 科平均分：83.0
> ```

---

### 14. 挑战题：字符串反转

> 编写一个函数，把字符串**倒过来**（不用 string.h 的函数）：
> 
> ```c
> void reverseString(char s[]);
> ```
> 
> 例如把 `"hello"` 变成 `"olleh"`。
> 
> 在 main 中测试：
> 
> ```
> 原字符串：hello
> 反转后：olleh
> ```
> 
> 提示：
> - 用 `strlen` 求长度（可以用 string.h）
> - 一头一尾交换字符，遇到中间就停
> - 注意 `'\0'` 不要动

---

## ✅ 参考答案

<details>
<summary>🔑 点击展开答案</summary>

### 选择题答案

**1. B** — 长度为5的数组，合法下标是 0~4。

**2. A** — 下标为奇数的是 1、3，对应 `a[1]=20`、`a[3]=40`，和为 60。

**3. D** — `a[1][2]` 是第1行第2列，即第二行 `{4,5,6}` 的第3个元素 6。

**4. C** — `strlen` 数可见字符（5），`sizeof` 包含 `'\0'`（6）。

**5. C** — 数组传的是地址，函数修改 `arr[0]` 和 `arr[n-1]` 会影响原数组，所以是 `99 2 99`。

---

### 填空题答案

**6.** 0

**7.** for（或双重/嵌套）

**8.** `'\0'`（空字符，值0）

**9.** `strcpy`

**10.** 地址

---

### 改错题答案

**11. 四处错误：**

```c
#include <stdio.h>

// 错误1：参数要加上长度 n
double average(int scores[], int n) {
    int sum = 0;
    // 错误2：不能用 sizeof 数长度（函数里 scores 退化成地址），直接用 n
    for (int i = 0; i < n; i++) {   // 错误3：原来是 i <= n，越界
        sum += scores[i];
    }
    return (double)sum / n;         // 错误4：要类型转换，(double)sum / n 才是小数除法
}

int main() {
    int scores[] = {85, 92, 78, 65};
    printf("平均分：%.1f\n", average(scores, 4));
    return 0;
}
```

---

### 编程题参考答案

**12. 数组统计函数：**

```c
#include <stdio.h>

double averageArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

int maxArray(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int scores[] = {78, 92, 85, 100, 60};
    int n = sizeof(scores) / sizeof(scores[0]);
    
    printf("平均分：%.1f\n", averageArray(scores, n));
    printf("最高分：%d\n", maxArray(scores, n));
    return 0;
}
```

---

**13. 二维数组成绩统计：**

```c
#include <stdio.h>

int main() {
    int score[3][3] = {{85, 92, 78}, {96, 88, 91}, {72, 65, 80}};
    
    // 每个学生的总分（按行）
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += score[i][j];
        }
        printf("第 %d 个学生总分：%d\n", i, sum);
    }
    
    // 每门课的平均分（按列）
    for (int j = 0; j < 3; j++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += score[i][j];
        }
        double avg = (double)sum / 3;
        printf("第 %d 科平均分：%.1f\n", j, avg);
    }
    return 0;
}
```

---

**14. 字符串反转：**

```c
#include <stdio.h>
#include <string.h>

void reverseString(char s[]) {
    int left = 0;
    int right = (int)strlen(s) - 1;   // 最后一个有效字符的下标
    
    while (left < right) {
        // 交换两头的字符
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        left++;    // 左边往中间走
        right--;   // 右边往中间走
    }
}

int main() {
    char s[] = "hello";
    
    printf("原字符串：%s\n", s);
    
    reverseString(s);
    
    printf("反转后：%s\n", s);
    return 0;
}
```

</details>

---

> 🎉 **第3章测试完成！**
> 
> 如果答对了80%以上，说明你对第3章的内容掌握得很好！
> 
> 如果有不会的，回去复习对应的章节吧。
> 
> [← 回到第3章](../README.md)
