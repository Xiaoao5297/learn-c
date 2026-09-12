# 第8章测试：排序与查找

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

**1. 对数组 `{3, 1, 4, 2}` 做冒泡排序，第一趟结束后数组变成：**

A. `1 3 2 4`  
B. `1 2 3 4`  
C. `3 1 4 2`（不变）  
D. `2 1 4 3`

---

**2. 使用二分查找的前提条件是：**

A. 数组无序  
B. 数组已经排好序  
C. 数组没有重复元素  
D. 数组长度是 2 的幂

---

**3. 冒泡、选择、插入三种排序的比较次数大致都属于：**

A. O(n)  
B. O(n²)  
C. O(n log n)  
D. O(log n)

---

**4. 快速排序主要依靠哪种思想：**

A. 从后往前比较  
B. 贪心  
C. 分而治之 + 递归  
D. 穷举所有排列

---

**5. 递归二分查找中，"没找到"的出口条件是：**

A. `low == high`  
B. `low > high`  
C. `mid == 0`  
D. `high == n`

---

## 二、填空题（共5题）

**6. 选择排序每一趟会在"未排区"里挑出最_______的数放到最前面，一趟最多交换_______次。**

**7. 二分查找每次比较都会排除掉候选中的_______，所以效率大约是 O(_______)。**

**8. 快速排序一趟分区能让______元素"归位"（左边全比它小、右边全比它大）。**

**9. 顺序查找对数组是否有序_______要求；而二分查找必须要求数组_______。**

**10. 冒泡排序的内层循环上界写成 `n-1-i`，是因为每排完一趟，末尾就有_______个数已经归位、不用再比。**

---

## 三、改错题（共1题）

**11. 以下二分查找（递归版）有 3 个错误，请找出并改正：**

```c
#include <stdio.h>

int binarySearch(int a[], int low, int high, int target) {
    if (low >= high) return -1;             // 错误区①：区间只剩 1 个数时，还能不能查？
    int mid = (low + high) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] < target) {
        return binarySearch(a, mid, high, target);    // 错误区②：去右半边，mid 要不要排除？
    } else {
        return binarySearch(a, low, mid, target);     // 错误区③：去左半边，mid 要不要排除？
    }
}

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    printf("%d\n", binarySearch(a, 0, n - 1, 30));   // 期望 2
    printf("%d\n", binarySearch(a, 0, n - 1, 50));   // 期望 4
    printf("%d\n", binarySearch(a, 0, n - 1, 99));   // 期望 -1
    return 0;
}
```

> 提示：`low == high` 时中间那个数还没查呢；去左/右半边都要把 `mid` 排除掉（分别 -1 / +1），否则会无限递归。

---

## 四、编程题（共3题）

### 12. 基础题：冒泡排序

> 用冒泡排序把 `{6, 3, 8, 1, 9, 4}` 从小到大排序并打印：
> 
> ```
> 排序后：1 3 4 6 8 9
> ```

---

### 13. 进阶题：递归二分查找

> 在有序数组 `{10, 20, 30, 40, 50}` 里，用递归二分查找分别找 30 和 55：
> 
> ```
> 查找 30：下标 2
> 查找 55：没找到（-1）
> ```

---

### 14. 挑战题：快速排序 + 二分查找

> 先对 `{88, 55, 99, 22, 66}` 做快速排序，再用递归二分查找找 66，输出：
> 
> ```
> 快排后：22 55 66 88 99
> 找到 66，下标 2
> ```
> 
> 要求：自己实现 `quickSort`、`binarySearch`，在 main 里先排序、再查找并打印。

---

## ✅ 参考答案

<details>
<summary>🔑 点击展开答案</summary>

### 选择题答案

**1. A** — 第一趟两两比较：3>1换→`1 3 4 2`；3<4不换；4>2换→`1 3 2 4`，最大数 4 冒到末尾。

**2. B** — 二分查找靠"中间值"判断目标在左还是右，前提是数组有序。

**3. B** — 三者都要比约 n²/2 次，都是 O(n²)。

**4. C** — 快速排序 = 分区（分而治之）+ 递归排左右两半。

**5. B** — 当 `low > high` 说明区间空了、查无可查，返回 -1。

---

### 填空题答案

**6.** 小；1

**7.** 一半；log n（对数）

**8.** 基准（pivot）

**9.** 没有（无）；有序

**10.** i

---

### 改错题答案

**11. 三处错误：**

```c
#include <stdio.h>

int binarySearch(int a[], int low, int high, int target) {
    if (low > high) return -1;                       // 错误1：区间"空了"是 low>high
    int mid = (low + high) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] < target) {
        return binarySearch(a, mid + 1, high, target); // 错误2：右半边从 mid+1 开始
    } else {
        return binarySearch(a, low, mid - 1, target);  // 错误3：左半边到 mid-1 结束
    }
}

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    printf("%d\n", binarySearch(a, 0, n - 1, 30));   // 2
    printf("%d\n", binarySearch(a, 0, n - 1, 50));   // 4
    printf("%d\n", binarySearch(a, 0, n - 1, 99));   // -1
    return 0;
}
```

> 用 `low >= high` 当出口会把"还剩 1 个数"的情况直接判没找到；递归不带 `mid±1` 则永远排除不掉中间，可能无限递归（如找 50 时会在 [3,4] 区间反复卡住）。

---

### 编程题参考答案

**12. 冒泡排序：**

```c
#include <stdio.h>

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int a[] = {6, 3, 8, 1, 9, 4};
    int n = 6;
    bubbleSort(a, n);
    printf("排序后：");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
```

---

**13. 递归二分查找：**

```c
#include <stdio.h>

int binarySearch(int a[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] < target) {
        return binarySearch(a, mid + 1, high, target);
    } else {
        return binarySearch(a, low, mid - 1, target);
    }
}

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    int idx1 = binarySearch(a, 0, n - 1, 30);
    printf("查找 30：");
    if (idx1 != -1) printf("下标 %d\n", idx1);
    else printf("没找到（-1）\n");

    int idx2 = binarySearch(a, 0, n - 1, 55);
    printf("查找 55：");
    if (idx2 != -1) printf("下标 %d\n", idx2);
    else printf("没找到（-1）\n");
    return 0;
}
```

---

**14. 快速排序 + 二分查找：**

```c
#include <stdio.h>

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void quickSort(int a[], int low, int high) {
    if (low >= high) return;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, high);
    int p = i + 1;
    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int binarySearch(int a[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] < target) return binarySearch(a, mid + 1, high, target);
    return binarySearch(a, low, mid - 1, target);
}

int main() {
    int a[] = {88, 55, 99, 22, 66};
    int n = 5;

    quickSort(a, 0, n - 1);
    printf("快排后：");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    int idx = binarySearch(a, 0, n - 1, 66);
    if (idx != -1) printf("找到 66，下标 %d\n", idx);
    else printf("没找到 66\n");
    return 0;
}
```

</details>

---

> 🎉 **第8章测试完成！**
> 
> 如果答对了80%以上，说明排序与查找你已经真正入门了！
> 
> 如果有不会的，回去复习对应的章节吧。
> 
> [← 回到第8章](../README.md)
