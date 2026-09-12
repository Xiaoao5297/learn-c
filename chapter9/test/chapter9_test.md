# 第9章测试：栈、队列与二叉树

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

**1. 栈与队列最本质的区别是：**

A. 栈用数组，队列用链表  
B. 栈是"后进先出"（LIFO），队列是"先进先出"（FIFO）  
C. 栈只能存整数，队列能存任何数据  
D. 没有区别

---

**2. 依次 enqueue 1、2、3，再 dequeue 一次，得到的是：**

A. 1  
B. 3  
C. 2  
D. 队空报错

---

**3. 循环队列中，入队/出队后写 `head = (head + 1) % MAX` 是为了：**

A. 让下标越界  
B. 让下标走到末尾后能绕回开头，复用空出来的格子  
C. 让下标加两次  
D. 防止整数溢出

---

**4. 对一棵二叉查找树（BST）做中序遍历，输出是：**

A. 从大到小  
B. 先根后左右  
C. 从小到大  
D. 随机顺序

---

**5. 二叉查找树插入新节点时，如果 value 比当前节点小，应该：**

A. 往左子树走  
B. 往右子树走  
C. 直接替换当前节点  
D. 放弃插入

---

## 二、填空题（共5题）

**6. 栈的核心操作是_______（压入）和_______（弹出）；队列的核心操作是_______（入队）和_______（出队）。**

**7. 朴素数组队列出队几次后，前面的格子就_______了；循环队列用取模 `%` 让下标可以绕回开头。**

**8. 二叉树节点通常由数据 `data` 和两个指针成员_______、_______组成；没有孩子的节点叫_______。**

**9. 三种遍历里，顺序为"左 根 右"的是_______遍历；顺序为"根 左 右"的是_______遍历。**

**10. 二叉查找树遵守"左_______右_______"的规则，所以它的中序遍历会输出升序。**

---

## 三、改错题（共1题）

**11. 以下二叉查找树的查找函数有 3 个错误：**

```c
#include <stdio.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *search(TreeNode *root, int value) {
    if (value == root->data) return root;     // 错误区①：root 是 NULL 时能访问 root->data 吗？
    if (value < root->data) {
        return search(root->right, value);    // 错误区②：比根小应该去哪一边？
    }
    if (value > root->data) {
        return search(root->left, value);     // 错误区③：比根大应该去哪一边？
    }
    return NULL;
}
```

> 提示：递归到空位时 root 会是 NULL，第一行就访问 root->data 会崩溃——应先判断 root == NULL 返回 NULL；左右两个方向也写反了。

---

## 四、编程题（共3题）

### 12. 基础题：数组版栈

> 用一个数组 + 一个 `top` 变量实现简单栈：依次压入 1、2、3、4、5，再全部弹出打印：
> 
> ```
> 弹出：5
> 弹出：4
> 弹出：3
> 弹出：2
> 弹出：1
> ```

---

### 13. 进阶题：BST 插入 + 中序遍历

> 把 `{7, 3, 9, 1, 5}` 依次插入二叉查找树，再中序遍历打印：
> 
> ```
> 中序遍历：1 3 5 7 9
> ```
> 要求：实现 `createNode`、`insert`、`inorder`、`freeTree`。

---

### 14. 挑战题：BST 查找（返回 0/1）

> 实现 `int contains(TreeNode *root, int value)`（找到返回 1，找不到返回 0）。
> 对第 13 题那棵树：
> 
> ```
> 查找 5：找到了（1）
> 查找 99：没找到（0）
> ```

---

## ✅ 参考答案

<details>
<summary>🔑 点击展开答案</summary>

### 选择题答案

**1. B** — 栈后进先出（叠盘子），队列先进先出（排队），这是两者最本质的区别。

**2. A** — 队列入队 1、2、3 后，队头是 1，dequeue 取走的是 1（先进先出）。

**3. B** — `% MAX` 让下标在 0..MAX-1 间循环，出队空出的格子能被后面入队复用。

**4. C** — BST 左子树都比根小、右子树都比根大，中序"左 根 右"自然输出升序。

**5. A** — 比当前节点小 → 往左走；大 → 往右走；直到 NULL 空位放下新节点。

---

### 填空题答案

**6.** push；pop；enqueue（入队）；dequeue（出队）

**7.** 浪费（用不上）；绕（转）圈

**8.** left；right；叶子（leaf）

**9.** 中序；前序

**10.** 小；大

---

### 改错题答案

**11. 三处错误：**

```c
TreeNode *search(TreeNode *root, int value) {
    if (root == NULL) return NULL;             // 错误1：先判断空树/走到空位，返回 NULL
    if (value == root->data) return root;      // 找到了
    if (value < root->data) {
        return search(root->left, value);      // 错误2：比根小 → 去左边
    }
    return search(root->right, value);         // 错误3：比根大 → 去右边
}
```

> 原代码没有 `root == NULL` 的出口，递归到空时会访问 `NULL->data` 崩溃；并且左右方向写反。

---

### 编程题参考答案

**12. 数组版栈：**

```c
#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;               // 空栈 top = -1

void push(int value) {
    stack[++top] = value;   // top 先 +1，再放值
}

int pop() {
    return stack[top--];    // 取走栈顶，top -1
}

int main() {
    for (int i = 1; i <= 5; i++) {
        push(i);
    }
    while (top != -1) {
        printf("弹出：%d\n", pop());
    }
    return 0;
}
```

---

**13. BST 插入 + 中序遍历：**

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL) return NULL;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *insert(TreeNode *root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void freeTree(TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TreeNode *root = NULL;
    int values[] = {7, 3, 9, 1, 5};
    for (int i = 0; i < 5; i++) {
        root = insert(root, values[i]);
    }
    printf("中序遍历：");
    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
```

---

**14. BST 查找（返回 0/1）：**

```c
int contains(TreeNode *root, int value) {
    if (root == NULL) return 0;              // 走到空：没找到
    if (value == root->data) return 1;       // 找到了
    if (value < root->data) {
        return contains(root->left, value);  // 去左边
    }
    return contains(root->right, value);     // 去右边
}

// main 中用第13题的建树代码：
// int main() { ... 建树 root ...
//     printf("查找 5：%s\n", contains(root, 5) ? "找到了（1）" : "没找到（0）");
//     printf("查找 99：%s\n", contains(root, 99) ? "找到了（1）" : "没找到（0）");
//     freeTree(root); return 0; }
```

</details>

---

> 🎉 **第9章测试完成！**
> 
> 如果答对了80%以上，说明栈、队列与二叉树你已经真正入门了！
> 
> 如果有不会的，回去复习对应的章节吧。
> 
> [← 回到第9章](../README.md)
