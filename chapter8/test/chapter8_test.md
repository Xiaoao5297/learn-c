# 第 8 章测试：排序与查找

> **测试说明**
>
> - 选择题 5 题，填空题 5 题，阅读程序 2 题，编程题 2 题。
> - 建议用时 60 到 90 分钟。
> - 先独立完成，再展开文末答案。
> - 编程题重点看思路和边界，不要求和参考答案逐字相同。

---

## 一、选择题（每题 2 分，共 10 分）

**1. 对数组 `{3, 1, 4, 2}` 做升序冒泡排序，第一趟结束后数组变成？**

A. `1 3 2 4`\
B. `1 2 3 4`\
C. `3 1 4 2`\
D. `2 1 4 3`

---

**2. 选择排序每一趟最多交换几次？**

A. 0 次\
B. 1 次\
C. 2 次\
D. 不确定，取决于数据

---

**3. 二分查找的前提条件是？**

A. 数组没有重复元素\
B. 数组长度是 2 的幂\
C. 数组已经有序\
D. 数组元素都是正数

---

**4. 冒泡排序内层循环的上界写成 `j < count - 1 - i`，原因是？**

A. 防止数组越界\
B. 尾部 `i` 个元素已经归位，不用再比较\
C. 让比较方向从后往前\
D. 数组长度实际上是 `count - 1 - i`

---

**5. 下列哪种算法对"几乎已经有序"的数据最快？**

A. 冒泡排序（不带 `swapped` 优化）\
B. 选择排序\
C. 插入排序\
D. 三者一样快

---

## 二、填空题（每题 4 分，共 20 分）

**6. 冒泡排序用 `swapped` 标志实现提前退出：某一趟一次交换都没发生，说明数组已经\_\_\_\_\_\_\_\_，可以直接结束。**

**7. 选择排序每一趟在未排区里找出最\_\_\_\_\_\_\_\_元素的下标，把它和未排区的第一个元素交换。**

**8. 查找函数找不到目标时通常返回\_\_\_\_\_\_\_\_，因为合法下标从 0 开始，这个值不会和真实位置混淆。**

**9. 二分查找计算中间下标应写成 `left + \_\_\_\_\_\_\_\_`，避免 `left + right` 直接相加导致溢出。**

**10. 快速排序平均时间复杂度约为 O(\_\_\_\_\_\_\_\_)；若基准每次都选到区间的最值，会退化到 O(\_\_\_\_\_\_\_\_)。**

---

## 三、阅读程序（每题 5 分，共 10 分）

**11. 写出下面程序的输出。**

```c
#include <stdio.h>
#include <stdbool.h>

void insertion_sort(int nums[], int count)
{
	for (int i = 1; i < count; i++) {
		int key = nums[i];
		int j = i - 1;

		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];
			j--;
		}

		nums[j + 1] = key;
	}
}

int main(void)
{
	int nums[5] = {4, 1, 3, 1, 2};

	insertion_sort(nums, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d", nums[i]);
		if (i < 4) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
```

---

**12. 下面程序想在有序数组里二分查找，有两处错误，请指出并改正。**

```c
#include <stdio.h>

int binary_search(const int nums[], int count, int target)
{
	int left = 0;
	int right = count - 1;

	while (left < right) {
		int mid = (left + right) / 2;

		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] < target) {
			left = mid;
		} else {
			right = mid;
		}
	}

	return -1;
}

int main(void)
{
	int nums[5] = {2, 4, 6, 8, 10};

	printf("%d\n", binary_search(nums, 5, 8));
	return 0;
}
```

---

## 四、编程题（每题 10 分，共 20 分）

**13. 选择排序降序版**

编写函数 `void selection_sort_desc(int nums[], int count);`，把数组按**从大到小**排序，并在 `main` 里验证。运行效果：

```text
95 88 79 70 62
```

要求：

- 先在未排区找**最大**元素的下标，再交换。
- 打印函数的数组参数加 `const`。
- 使用 `int main(void)`。

---

**14. 快速排序**

编写程序：用快速排序把 `int scores[7] = {73, 91, 66, 85, 78, 60, 88};` 从小到大排好并打印；随后用二分查找报告 85 分的位置（下标和"从低到高的名次"）。运行效果：

```text
快排后：60 66 73 78 85 88 91
85 分的下标是 4，名次第 5
```

要求：

- 快排用"末尾元素当基准 + Lomuto 分区 + 递归"实现，递归出口 `left >= right`。
- 二分查找用 `left + (right - left) / 2` 计算 mid，砍半时排除 mid 本身。
- 交换函数用指针参数实现。
- 使用 `int main(void)`。

---

## 参考答案

<details>
<summary>点击展开答案</summary>

### 一、选择题

1. **A**。第一趟依次比较：(3,1) 交换得 `{1,3,4,2}`，(3,4) 不换，(4,2) 交换得 `{1,3,2,4}`。最大的 4 还没归位——它在这趟只被比较了一次，要到第二趟才冒到末尾。注意"每趟归位的是未排区的最大值"，第一趟结束时最右边是 4，不是最大值 4 吗？是——`{1,3,2,4}` 末尾的 4 恰好就是最大值，它已经归位。选项 A 的 `1 3 2 4` 正确。
2. **B**。每趟先找最小下标、扫完再交换一次，所以最多 1 次（最小值已在开头时 0 次）。
3. **C**。二分每次靠"目标在中间的哪一边"砍半，这依赖有序性；重复元素、长度、正负都不影响可用性。
4. **B**。第 i 趟结束后尾部 i 个元素是未排区前 i 大的数且已归位，后续趟数不必再碰它们，所以边界随 i 收缩。
5. **C**。插入排序每张新牌几乎不用挪，近乎有序时接近 O(n)；选择排序固定约 n²/2；冒泡不加优化也是固定约 n²/2。

### 二、填空题

6. 有序。
7. 小。
8. `-1`。
9. `(right - left) / 2`。
10. `n log n`；`n²`。

### 三、阅读程序

11. 输出：

```text
1 1 2 3 4
```

插入排序把每个元素插进前缀里。两个 1 相等时，后插入的 1 落在前一个 1 的后面（`nums[j] > key` 用 `>`，相等即停），顺序稳定。

12. 两处错误：

- 循环条件 `left < right` 配闭区间会漏查：区间剩一个元素（`left == right`）时不进循环。应改成 `left <= right`。
- 砍半写成了 `left = mid;` 和 `right = mid;`，`nums[mid]` 已经比较过却没被排除，区间可能不再缩小（mid 恰好是左端点时 `left = mid` 不动），死循环。应改成 `left = mid + 1;` 和 `right = mid - 1;`。

另外 `mid = (left + right) / 2` 在本题数据小没有问题，但规范写法是 `left + (right - left) / 2`，建议一并改掉。

### 四、编程题

13. 参考代码：

```c
#include <stdio.h>

void selection_sort_desc(int nums[], int count)
{
	for (int i = 0; i < count - 1; i++) {
		int max_index = i;

		for (int j = i + 1; j < count; j++) {
			if (nums[j] > nums[max_index]) {
				max_index = j;
			}
		}

		if (max_index != i) {
			int temp = nums[i];
			nums[i] = nums[max_index];
			nums[max_index] = temp;
		}
	}
}

void print_array(const int nums[], int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d", nums[i]);
		if (i < count - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

int main(void)
{
	int nums[5] = {88, 62, 95, 70, 79};

	selection_sort_desc(nums, 5);
	print_array(nums, 5);

	return 0;
}
```

14. 参考代码：

```c
#include <stdio.h>

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int nums[], int left, int right)
{
	int pivot = nums[right];
	int i = left - 1;

	for (int j = left; j < right; j++) {
		if (nums[j] <= pivot) {
			i++;
			swap_int(&nums[i], &nums[j]);
		}
	}

	swap_int(&nums[i + 1], &nums[right]);
	return i + 1;
}

void quick_sort(int nums[], int left, int right)
{
	if (left >= right) {
		return;
	}

	int p = partition(nums, left, right);
	quick_sort(nums, left, p - 1);
	quick_sort(nums, p + 1, right);
}

int binary_search(const int nums[], int count, int target)
{
	int left = 0;
	int right = count - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return -1;
}

int main(void)
{
	int scores[7] = {73, 91, 66, 85, 78, 60, 88};

	quick_sort(scores, 0, 6);

	printf("快排后：");
	for (int i = 0; i < 7; i++) {
		printf("%d", scores[i]);
		if (i < 6) {
			printf(" ");
		}
	}
	printf("\n");

	int index = binary_search(scores, 7, 85);
	if (index >= 0) {
		printf("85 分的下标是 %d，名次第 %d\n", index, index + 1);
	} else {
		printf("没有 85 分\n");
	}

	return 0;
}
```

</details>

---

[返回第 8 章导读](../README.md)
