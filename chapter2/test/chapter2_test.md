# 第2章测试：C语言基础运算

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

**1. 以下代码的输出是什么？**

```c
int a = 17;
int b = 5;
printf("%d", a % b);
```

A. `3`  
B. `2`  
C. `3.4`  
D. `12`

---

**2. 在C语言中，下面哪个表达式的值是"真"（非0）？**

A. `5 > 10 && 3 < 8`  
B. `!0`  
C. `0 && 1`  
D. `5 == 10`

---

**3. 以下代码的输出是什么？**

```c
int score = 85;
if (score >= 90) {
    printf("A");
} else if (score >= 80) {
    printf("B");
} else if (score >= 70) {
    printf("C");
} else {
    printf("D");
}
```

A. `A`  
B. `B`  
C. `C`  
D. `D`

---

**4. 以下代码的输出是什么？**

```c
int count = 0;
for (int i = 1; i <= 10; i++) {
    if (i % 3 == 0) {
        count++;
    }
}
printf("%d", count);
```

A. `3`  
B. `4`  
C. `5`  
D. `10`

---

**5. 以下代码的输出是什么？**

```c
int f(int x) {
    if (x < 0) {
        return 0;
    }
    return x * 2;
}

int main() {
    printf("%d", f(5) + f(-3));
    return 0;
}
```

A. `4`  
B. `10`  
C. `16`  
D. `-6`

---

## 二、填空题（共5题）

**6. 在C语言中，`=` 是赋值运算符，而判断是否相等的运算符是_______。**

**7. 在C语言中，条件"成立"用非0表示，"不成立"用_______表示。**

**8. 在 `switch` 语句中，每个 `case` 后通常需要写_______来防止"穿透"。**

**9. 在函数内部定义的变量叫_______变量，它只在这个函数内有效。**

**10. 一段代码要"重复执行"，且**至少要执行一次**，应该用_______循环。**

---

## 三、改错题（共1题）

**11. 以下程序有4个错误，请逐一找出并改正，使程序能正确输出从1到20的奇数：**

```c
#include <stdio.h>

int isOdd(int n) {
    return n % 2 = 1;
}

int main() {
    for (int i = 1; i <= 20, i++) {
        if (isOdd(i)) {
            printf("%d ", i)
        }
    }
    printf("\n");
    return 0;
}
```

> 提示：4个错误分别涉及：
> 1. 运算符错误（`=` 应为 `==`）
> 2. for 循环语法错误（分隔符）
> 3. 缺少分号
> 4. 函数定义顺序问题（要不要声明？）

---

## 四、编程题（共3题）

### 12. 基础题：阶乘函数

> 编写一个 `factorial` 函数，计算 n 的阶乘（n! = 1×2×3×...×n）。
> 
> 在 `main` 中分别计算 5! 和 10!，并输出：
> 
> ```
> 5! = 120
> 10! = 3628800
> ```
> 
> 提示：注意使用循环；10! 比较大，考虑用 `long long`（格式符 `%lld`）。

---

### 13. 进阶题：素数判断器

> 编写一个 `isPrime` 函数，判断一个数是否为素数。
> 
> 在 `main` 中找出 2~50 之间的所有素数并打印：
> 
> ```
> 2~50之间的素数：
> 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 
> ```
> 
> 提示：素数只能被 1 和它本身整除；试除只需要到 `d * d <= n` 即可。

---

### 14. 挑战题：水仙花数函数版

> 编写一个 `isNarcissistic` 函数，判断一个三位数是否为"水仙花数"（各位数字的立方和等于它本身，如 153 = 1³+5³+3³）。
> 
> 在 `main` 中找出所有三位水仙花数并打印：
> 
> ```
> 三位水仙花数有：
> 153 370 371 407 
> ```
> 
> 提示：
> - 在函数里用取余和除法拆分百位、十位、个位
> - 在 main 里用 for 循环从 100 遍历到 999

---

## ✅ 参考答案

<details>
<summary>🔑 点击展开答案</summary>

### 选择题答案

**1. B** — `17 % 5 = 2`（17 ÷ 5 = 3 余 2）。

**2. B** — `!0` 是"非0"，即真（结果为1）。A、C、D 都是假。

**3. B** — 85 分满足 `>= 80`，输出 B。

**4. A** — 1~10 中能被 3 整除的有 3、6、9，共 3 个。

**5. B** — `f(5) = 10`，`f(-3) = 0`（因为 x < 0 返回 0），所以 10 + 0 = 10。

---

### 填空题答案

**6.** `==`

**7.** `0`

**8.** `break;`（break 语句）

**9.** 局部（local）

**10.** `do-while`

---

### 改错题答案

**11. 四处错误：**

```c
#include <stdio.h>

// 在 main 前面声明（或把定义放在 main 前面），否则 main 里调用会报错
int isOdd(int n);

int isOdd(int n) {
    return n % 2 == 1;   // 错误1：= 应为 ==
}

int main() {
    for (int i = 1; i <= 20; i++) {   // 错误2：for 里用逗号(,)分隔，应为分号(;)
        if (isOdd(i)) {
            printf("%d ", i);          // 错误3：末尾少分号
        }
    }
    printf("\n");
    return 0;
}
```

---

### 编程题参考答案

**12. 阶乘函数：**

```c
#include <stdio.h>

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    printf("5! = %lld\n", factorial(5));
    printf("10! = %lld\n", factorial(10));
    return 0;
}
```

---

**13. 素数判断器：**

```c
#include <stdio.h>

int isPrime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("2~50之间的素数：\n");
    for (int i = 2; i <= 50; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
```

---

**14. 水仙花数函数版：**

```c
#include <stdio.h>

int isNarcissistic(int n) {
    int hundreds = n / 100;          // 百位
    int tens = n / 10 % 10;          // 十位
    int ones = n % 10;               // 个位
    
    int sum = hundreds * hundreds * hundreds
            + tens * tens * tens
            + ones * ones * ones;
    
    return sum == n;
}

int main() {
    printf("三位水仙花数有：\n");
    for (int i = 100; i <= 999; i++) {
        if (isNarcissistic(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
```

</details>

---

> 🎉 **第2章测试完成！**
> 
> 如果答对了80%以上，说明你对第2章的内容掌握得很好！
> 
> 如果有不会的，回去复习对应的章节吧。
> 
> [← 回到第2章](../README.md)
