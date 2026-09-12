# 第7章测试：递归

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

**1. 一个正确的递归函数，必须包含：**

A. 至少两个参数  
B. 能直接返回答案的"基线条件"（出口）  
C. 一个 for 循环  
D. 全局变量

---

**2. 执行下面的代码，输出是：**

```c
void printUp(int n) {
    if (n == 0) return;
    printUp(n - 1);
    printf("%d ", n);
}

printUp(3);
```

A. `3 2 1`  
B. `1 2 3`  
C. `3 3 3`  
D. 无限递归崩溃

---

**3. 递归释放链表的正确顺序是：**

A. 先 `free(head)`，再递归释放 `head->next`  
B. 先递归释放 `head->next`，再 `free(head)`  
C. 先 `free(head->data)`  
D. 链表不用释放

---

**4. 汉诺塔有 3 个盘子时，最少需要搬多少步：**

A. 3  
B. 6  
C. 7  
D. 8

---

**5. 斐波那契的递归写法（`fib(n) = fib(n-1) + fib(n-2)`）的主要缺点是：**

A. 代码写不出来  
B. 不能返回结果  
C. 大量重复计算，n 稍大就很慢  
D. 会占用硬盘空间

---

## 二、填空题（共5题）

**6. 递归函数必须有两个部分：_______（直接返回答案的出口）和_______（调用更小号的自己）。**

**7. 函数每次被调用时，系统在内存的_______区压入一张记录参数、局部变量和返回地址的"纸条"（栈帧）；递归太深会导致_______。**

**8. 汉诺塔 n 个盘子的最少步数是_______（如 n=3 是 7）。**

**9. 想让递归"倒着"处理链表，要把处理代码写在递归调用之_______（前/后）。**

**10. 递归求链表节点数 `countNodes` 遇到空链表（NULL）时应返回_______。**

---

## 三、改错题（共1题）

**11. 以下程序想"递归求 1 到 n 的和，并按从大到小打印 5 4 3 2 1"，有 3 个错误，请逐一找出并改正：**

```c
#include <stdio.h>

// 求 1+2+...+n
int sumUp(int n) {
    if (n == 0) return 1;          // 错误区①：出口的返回值对吗？
    return n + sumUp(n - 1);
}

// 想打印 5 4 3 2 1（从大到小）
void printDown(int n) {
    if (n == 0) return;
    printDown(n--);                // 错误区②：n-- 传给函数的是什么值？
    printf("%d ", n);              // 错误区③：printf 的位置对吗？
}

int main() {
    printf("总和：%d\n", sumUp(3));   // 期望：总和：6
    printDown(5);                     // 期望：5 4 3 2 1
    return 0;
}
```

> 预期正确输出：
> ```
> 总和：6
> 5 4 3 2 1
> ```

---

## 四、编程题（共3题）

### 12. 基础题：递归求阶乘

> 用递归计算 `6!` 并打印：
> 
> ```
> 6! = 720
> ```
> 要求：实现 `int fact(int n)`，出口 `fact(0) = 1`。

---

### 13. 进阶题：递归打印斐波那契前 10 项

> 实现递归函数 `fib`，在 main 里打印前 10 项：
> 
> ```
> 1 1 2 3 5 8 13 21 34 55
> ```

---

### 14. 挑战题：递归逆序打印链表

> 用尾插法建链表 `10 → 20 → 30`，再用**递归**实现逆序打印和节点计数，输出：
> 
> ```
> 正序：10 -> 20 -> 30 -> NULL
> 逆序：30 -> 20 -> 10 -> NULL
> 节点数：3
> ```
> 
> 要求：实现 `push_back`（第6章）、`printListRec`、`printReverseRec`、`countNodes`、`freeListRec`，并在 main 里完成建链、打印、释放。

---

## ✅ 参考答案

<details>
<summary>🔑 点击展开答案</summary>

### 选择题答案

**1. B** — 递归必须有"基线条件"（出口），否则会无限递归崩溃。

**2. B** — `printf` 在递归调用之后 → "归来"时打印 → 正序 `1 2 3`。

**3. B** — 必须先递归释放 `head->next`，再 `free(head)`；否则 `free` 后再读 `head->next` 是访问已释放内存。

**4. C** — 3 个盘子最少 2³−1 = 7 步。

**5. C** — 递归版会反复计算同一个子问题（如 `fib(3)` 被算多次），n 大了指数级变慢。

---

### 填空题答案

**6.** 基线条件（出口）；递归步骤（自我调用）

**7.** 栈（Stack）；栈溢出（Stack Overflow）

**8.** 2ⁿ − 1（n=3 时是 7）

**9.** 后

**10.** 0

---

### 改错题答案

**11. 三处错误：**

```c
#include <stdio.h>

// 求 1+2+...+n
int sumUp(int n) {
    if (n == 0) return 0;          // 错误1：出口应返回 0（不是 1），否则 sumUp(3)=7≠6
    return n + sumUp(n - 1);
}

// 想打印 5 4 3 2 1（从大到小）
void printDown(int n) {
    if (n == 0) return;
    printf("%d ", n);              // 错误2：printf 应放在递归调用之前（递去时打印 = 从大到小）
    printDown(n - 1);              // 错误3：要传 n-1，不是 n--（n-- 传的还是原值，会无限递归）
}

int main() {
    printf("总和：%d\n", sumUp(3));   // 输出：总和：6
    printDown(5);                     // 输出：5 4 3 2 1
    return 0;
}
```

---

### 编程题参考答案

**12. 递归求阶乘：**

```c
#include <stdio.h>

int fact(int n) {
    if (n == 0) return 1;          // 出口：0! = 1
    return n * fact(n - 1);        // 递推：n! = n * (n-1)!
}

int main() {
    printf("6! = %d\n", fact(6));  // 720
    return 0;
}
```

---

**13. 递归打印斐波那契前 10 项：**

```c
#include <stdio.h>

int fib(int n) {
    if (n == 1 || n == 2) return 1;   // 出口：前两项都是 1
    return fib(n - 1) + fib(n - 2);   // 递推：第 n 项 = 前两项之和
}

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}
```

---

**14. 递归逆序打印链表：**

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->data = value;
    node->next = NULL;
    return node;
}

void push_back(Node **head, int value) {
    Node *node = createNode(value);
    if (node == NULL) return;
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node *tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = node;
}

void printListRec(Node *head) {          // 递归正序
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    printListRec(head->next);
}

void printReverseRec(Node *head) {       // 递归逆序：归来时打印
    if (head == NULL) return;
    printReverseRec(head->next);
    printf("%d -> ", head->data);
}

int countNodes(Node *head) {             // 递归计数
    if (head == NULL) return 0;
    return 1 + countNodes(head->next);
}

void freeListRec(Node *head) {           // 递归释放：先释放后面，再释放自己
    if (head == NULL) return;
    freeListRec(head->next);
    free(head);
}

int main() {
    Node *head = NULL;
    push_back(&head, 10);
    push_back(&head, 20);
    push_back(&head, 30);

    printf("正序：");
    printListRec(head);

    printf("逆序：");
    printReverseRec(head);
    printf("NULL\n");

    printf("节点数：%d\n", countNodes(head));

    freeListRec(head);
    head = NULL;
    return 0;
}
```

</details>

---

> 🎉 **第7章测试完成！**
> 
> 如果答对了80%以上，说明递归你已经真正入门了！
> 
> 如果有不会的，回去复习对应的章节吧。
> 
> [← 回到第7章](../README.md)
