# 第6章测试：动态内存与链表

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

**1. malloc 申请内存失败时返回：**

A. `0`  
B. `-1`  
C. `NULL`  
D. 抛出异常

---

**2. 以下代码有什么问题？**

```c
int *p = (int *)malloc(sizeof(int));
*p = 10;
free(p);
p = NULL;
```

A. 内存泄漏  
B. 双重释放  
C. 悬垂指针  
D. 没有明显问题（写法正确）

---

**3. 想在程序运行中把动态数组从 5 个扩容到 10 个，应使用：**

A. `malloc(10 * sizeof(int))`  
B. `calloc(5, 10)`  
C. `realloc(p, 10 * sizeof(int))`（并用返回值覆盖 p）  
D. `free(p)` 后再 malloc

---

**4. 定义链表节点的正确写法是：**

A. 
```c
typedef struct Node {
    int data;
    Node *next;
} Node;
```
B. 
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```
C. 
```c
struct Node {
    int data;
    int *next;
} Node;
```
D. 
```c
typedef Node {
    int data;
    Node *next;
};
```

---

**5. 删除链表"第一个节点"时，除了 free 它，还必须：**

A. 什么都不用做  
B. 把 `*head` 改为原来的第二个节点  
C. 把链表重建一遍  
D. 把 `head` 指向 NULL

---

## 二、填空题（共5题）

**6. malloc 申请的内存在内存的_______区，用完必须调用_______释放。**

**7. 申请了内存却忘记释放，会导致_______；释放后再使用这块内存，会形成_______指针。**

**8. 链表里表示"到头了、没有下一个"的是把 next 置为_______。**

**9. 删除链表中部节点时，关键是让目标节点的_______节点跳过它、直接连到目标的下一个。**

**10. 链表要存进文件时，只应该保存每个节点的_______，读回来再重新搭链（不能存指针）。**

---

## 三、改错题（共1题）

**11. 以下程序想在链表头部插入 3 个数字并打印，有4个错误，请逐一找出并改正：**

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void push_front(Node **head, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;        // 错误区①：缺检查
    node->next = *head;
    head = node;               // 错误区②：用错指针层数
}

void printList(Node *head) {
    for (Node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->data);
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    push_front(&head, 1);
    push_front(&head, 2);
    push_front(&head, 3);
    printList(head);           // 错误区③④：缺链表释放
    return 0;
}
```

> 预期正确输出：`3 2 1`

---

## 四、编程题（共3题）

### 12. 基础题：动态数组求和

> 用 malloc 动态申请能装 5 个 int 的数组，存入 `{11, 22, 33, 44, 55}`，求和并输出：
> 
> ```
> 总和：165
> ```

---

### 13. 进阶题：链表建 + 遍历 + 释放

> 用尾插法依次插入 5、10、15，然后打印：
> 
> ```
> 5 -> 10 -> 15 -> NULL
> ```
> 
> 要求：实现 `createNode`、`push_back`、`printList`、`freeList`，main 里用它们完成并释放。

---

### 14. 挑战题：链表删除（含删头）

> 实现 `int deleteByValue(Node **head, int value)`（删第一个匹配的节点，返回1；没找到返回0）。
> 
> 测试流程：
> ```
> 初始链表：10 -> 20 -> 30 -> 40
> 删除 20 后：10 -> 30 -> 40
> 删除 10（头）后：30 -> 40
> 删除 99（不存在）后：30 -> 40（不变，返回0）
> ```

---

## ✅ 参考答案

<details>
<summary>🔑 点击展开答案</summary>

### 选择题答案

**1. C** — malloc 失败返回 `NULL`。

**2. D** — 申请→使用→free→置NULL，标准写法，没毛病。

**3. C** — 扩容用 `realloc`，且用返回值覆盖原指针（不能用旧的 p，可能已搬家失效）。

**4. B** — 结构体内部指向自身，还没起别名，必须写 `struct Node *next`。

**5. B** — 删头节点必须让 `*head` 指向原来的第二个节点，否则链表就"断头"了。

---

### 填空题答案

**6.** 堆；`free`

**7.** 内存泄漏（Memory Leak）；悬垂（dangling）

**8.** `NULL`

**9.** 前一个（prev）

**10.** 数据（data）

---

### 改错题答案

**11. 四处错误：**

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void push_front(Node **head, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {        // 错误1：malloc 后检查 NULL
        return;
    }
    node->data = value;
    node->next = *head;
    *head = node;              // 错误2：改的是 *head，不是 head
}

void printList(Node *head) {
    for (Node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->data);
    }
    printf("\n");
}

void freeList(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main() {
    Node *head = NULL;
    push_front(&head, 1);
    push_front(&head, 2);
    push_front(&head, 3);
    printList(head);           // 输出 3 2 1
    freeList(head);            // 错误3：用完释放链表
    head = NULL;               // 错误4（习惯）：释放后置 NULL
    return 0;
}
```

---

### 编程题参考答案

**12. 动态数组求和：**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("分配失败\n");
        return 1;
    }
    
    int nums[] = {11, 22, 33, 44, 55};
    int sum = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = nums[i];
        sum += arr[i];
    }
    printf("总和：%d\n", sum);
    
    free(arr);
    return 0;
}
```

---

**13. 链表建 + 遍历 + 释放：**

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

void printList(Node *head) {
    for (Node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d -> ", cur->data);
    }
    printf("NULL\n");
}

void freeList(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

int main() {
    Node *head = NULL;
    push_back(&head, 5);
    push_back(&head, 10);
    push_back(&head, 15);
    printList(head);
    freeList(head);
    return 0;
}
```

---

**14. 链表删除（含删头）：**

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) { /* 略，同第13题 */ }
void push_back(Node **head, int value) { /* 略，同第13题 */ }
void printList(Node *head) { /* 略，同第13题 */ }
void freeList(Node *head) { /* 略，同第13题 */ }

int deleteByValue(Node **head, int value) {
    if (*head == NULL) {
        return 0;
    }
    // 目标在头部
    if ((*head)->data == value) {
        Node *toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
        return 1;
    }
    // 目标在中部或尾部
    Node *prev = *head;
    while (prev->next != NULL && prev->next->data != value) {
        prev = prev->next;
    }
    if (prev->next == NULL) {
        return 0;    // 没找到
    }
    Node *toDelete = prev->next;
    prev->next = toDelete->next;
    free(toDelete);
    return 1;
}

int main() {
    Node *head = NULL;
    int vals[] = {10, 20, 30, 40};
    for (int i = 0; i < 4; i++) {
        push_back(&head, vals[i]);
    }

    printf("初始链表："); printList(head);

    deleteByValue(&head, 20);
    printf("删除 20 后："); printList(head);

    deleteByValue(&head, 10);
    printf("删除 10 后："); printList(head);

    int r = deleteByValue(&head, 99);
    printf("删除 99（返回%d）后：", r); printList(head);

    freeList(head);
    return 0;
}
```

</details>

---

> 🎉 **第6章测试完成！**
> 
> 如果答对了80%以上，说明动态内存和链表你已经入门了！
> 
> 如果有不会的，回去复习对应的章节吧。
> 
> [← 回到第6章](../README.md)
