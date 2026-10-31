# 第 8 章编程题参考答案

> 先自己写、自己跑，再对照。你的解法和参考答案不同很正常，只要满足要求、通过编译、结果正确就好。

## 8.1 体育课排队（与题面一致）

**思路**：标准冒泡排序，外层控制趟数、内层只扫未排好的前缀，`swapped` 为假时整趟零交换即提前退出。

```c
#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int nums[], int count)
{
	for (int i = 0; i < count - 1; i++) {
		bool swapped = false;

		for (int j = 0; j < count - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				swapped = true;
			}
		}

		if (!swapped) {
			break;
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
	int heights[5] = {156, 172, 149, 180, 163};

	printf("排序前：");
	print_array(heights, 5);

	bubble_sort(heights, 5);

	printf("排序后：");
	print_array(heights, 5);

	return 0;
}
```

**示例运行**：

```text
排序前：156 172 149 180 163
排序后：149 156 163 172 180
```

---

## 8.2 水果摊选苹果（与题面一致）

**思路**：从末尾开始排的选择排序：每趟在未排区 `nums[0..end]` 里找最大值的下标，和 `nums[end]` 交换，`end` 每趟减 1。`end` 就是这一趟归位到的下标，先打印再交换即可。

```c
#include <stdio.h>

void selection_sort(int nums[], int count)
{
	for (int end = count - 1; end > 0; end--) {
		int max_index = 0;

		for (int j = 1; j <= end; j++) {
			if (nums[j] > nums[max_index]) {
				max_index = j;
			}
		}

		printf("第 %d 趟：最大值 %d 换到下标 %d\n",
		       count - end, nums[max_index], end);

		if (max_index != end) {
			int temp = nums[end];
			nums[end] = nums[max_index];
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
	int sweetness[5] = {35, 12, 88, 45, 29};

	selection_sort(sweetness, 5);

	printf("排序后：");
	print_array(sweetness, 5);

	return 0;
}
```

**示例运行**：

```text
第 1 趟：最大值 88 换到下标 4
第 2 趟：最大值 45 换到下标 3
第 3 趟：最大值 35 换到下标 2
第 4 趟：最大值 29 换到下标 1
排序后：12 29 35 45 88
```

---

## 8.3 插入排序的移位账本（与题面一致）

**思路**：把插入排序包成返回移位次数的函数：`while` 循环每执行一次 `nums[j + 1] = nums[j]` 就计一次数。逆序数组每个元素都要挪到最前，移位约 n²/2；近乎有序的数组只有个别元素挪一两步。

```c
#include <stdio.h>

int insertion_sort(int nums[], int count)
{
	int moves = 0;

	for (int i = 1; i < count; i++) {
		int key = nums[i];
		int j = i - 1;

		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];
			j--;
			moves++;
		}

		nums[j + 1] = key;
	}

	return moves;
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
	int a[5] = {9, 7, 5, 3, 1};
	int b[7] = {1, 2, 4, 3, 5, 7, 6};

	int moves_a = insertion_sort(a, 5);
	printf("A 排序后：");
	print_array(a, 5);
	printf("A 移位 %d 次\n", moves_a);

	int moves_b = insertion_sort(b, 7);
	printf("B 排序后：");
	print_array(b, 7);
	printf("B 移位 %d 次\n", moves_b);

	printf("结论：越有序的数组，插入排序移位越少\n");

	return 0;
}
```

**示例运行**：

```text
A 排序后：1 3 5 7 9
A 移位 10 次
B 排序后：1 2 3 4 5 6 7
B 移位 2 次
结论：越有序的数组，插入排序移位越少
```

---

## 8.4 二分查找过程回放（与题面一致）

**思路**：标准二分循环里，每次进入循环先打印当前区间和 `mid`，比较结果分三种情况各打印一句话；`left > right` 时循环退出，补一句"区间空了"。

```c
#include <stdio.h>

int binary_search(const int nums[], int count, int target)
{
	int left = 0;
	int right = count - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		printf("范围 [%d, %d]，mid = %d，值 %d 与 %d 比较\n",
		       left, right, mid, nums[mid], target);

		if (nums[mid] == target) {
			printf("命中，下标 %d\n", mid);
			return mid;
		} else if (nums[mid] < target) {
			printf("往右\n");
			left = mid + 1;
		} else {
			printf("往左\n");
			right = mid - 1;
		}
	}

	printf("区间空了，没找到\n");
	return -1;
}

int main(void)
{
	int nums[8] = {3, 8, 15, 22, 31, 40, 56, 67};

	printf("查找 40：\n");
	binary_search(nums, 8, 40);

	printf("查找 50：\n");
	binary_search(nums, 8, 50);

	return 0;
}
```

**示例运行**：

```text
查找 40：
范围 [0, 7]，mid = 3，值 22 与 40 比较
往右
范围 [4, 7]，mid = 5，值 40 与 40 比较
命中，下标 5
查找 50：
范围 [0, 7]，mid = 3，值 22 与 50 比较
往右
范围 [4, 7]，mid = 5，值 40 与 50 比较
往右
范围 [6, 7]，mid = 6，值 56 与 50 比较
往左
区间空了，没找到
```

说明：题面示例为了简洁把比较结果和结论合并在一行，参考答案分两行打印，两者表达的过程一致；只要每一步的范围、mid 和走向都打印清楚，就满足要求。

---

## 8.5 输入成绩查名次（与题面一致）

**思路**：先插入排序，再用标准二分查找定位输入的成绩。排名 = 排好后的下标 + 1。

```c
#include <stdio.h>

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
	int scores[6] = {88, 62, 95, 70, 79, 55};

	insertion_sort(scores, 6);

	printf("排序后：");
	for (int i = 0; i < 6; i++) {
		printf("%d", scores[i]);
		if (i < 5) {
			printf(" ");
		}
	}
	printf("\n");

	printf("要查的成绩：");
	int target = 0;
	if (scanf("%d", &target) != 1) {
		printf("读取失败\n");
		return 1;
	}

	int index = binary_search(scores, 6, target);
	if (index >= 0) {
		printf("%d 分升序排第 %d\n", target, index + 1);
	} else {
		printf("没有 %d 分\n", target);
	}

	return 0;
}
```

**示例运行**（输入 `79`）：

```text
排序后：55 62 70 79 88 95
要查的成绩：79 分升序排第 4
```

---

## 8.6 三种排序比比较次数（与题面一致）

**思路**：给三种排序各加一个比较计数器，凡进入 `if` 比较一次就加 1。冒泡和选择的比较次数固定约 n(n-1)/2 = 15；插入排序看数据脸色，这组数据只比 10 次。

```c
#include <stdio.h>

void copy_array(const int src[], int dst[], int count)
{
	for (int i = 0; i < count; i++) {
		dst[i] = src[i];
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
}

int bubble_sort(int nums[], int count)
{
	int compares = 0;

	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			compares++;
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}

	return compares;
}

int selection_sort(int nums[], int count)
{
	int compares = 0;

	for (int i = 0; i < count - 1; i++) {
		int min_index = i;

		for (int j = i + 1; j < count; j++) {
			compares++;
			if (nums[j] < nums[min_index]) {
				min_index = j;
			}
		}

		if (min_index != i) {
			int temp = nums[i];
			nums[i] = nums[min_index];
			nums[min_index] = temp;
		}
	}

	return compares;
}

int insertion_sort(int nums[], int count)
{
	int compares = 0;

	for (int i = 1; i < count; i++) {
		int key = nums[i];
		int j = i - 1;

		while (j >= 0) {
			compares++;
			if (nums[j] > key) {
				nums[j + 1] = nums[j];
				j--;
			} else {
				break;
			}
		}

		nums[j + 1] = key;
	}

	return compares;
}

int main(void)
{
	int original[6] = {38, 27, 43, 3, 9, 82};
	int nums[6];

	copy_array(original, nums, 6);
	int c1 = bubble_sort(nums, 6);
	printf("冒泡排序：");
	print_array(nums, 6);
	printf("，比较 %d 次\n", c1);

	copy_array(original, nums, 6);
	int c2 = selection_sort(nums, 6);
	printf("选择排序：");
	print_array(nums, 6);
	printf("，比较 %d 次\n", c2);

	copy_array(original, nums, 6);
	int c3 = insertion_sort(nums, 6);
	printf("插入排序：");
	print_array(nums, 6);
	printf("，比较 %d 次\n", c3);

	return 0;
}
```

**示例运行**：

```text
冒泡排序：3 9 27 38 43 82，比较 15 次
选择排序：3 9 27 38 43 82，比较 15 次
插入排序：3 9 27 38 43 82，比较 10 次
```

---

## 8.7 换个基准的分区（与题面一致）

**思路**：基准取 `nums[left]`。`i` 初值为 `left`，表示"小于基准那一段"的右边界；`j` 从 `left + 1` 巡逻，`nums[j] < pivot` 就先 `i++` 再交换。扫完后基准和 `nums[i]` 交换，归位到 `i`。最后再各扫一遍左右两侧做性质验证。

```c
#include <stdio.h>
#include <stdbool.h>

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition_first(int nums[], int left, int right)
{
	int pivot = nums[left];
	int i = left;

	for (int j = left + 1; j <= right; j++) {
		if (nums[j] < pivot) {
			i++;
			swap_int(&nums[i], &nums[j]);
		}
	}

	swap_int(&nums[i], &nums[left]);
	return i;
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
	int nums[6] = {5, 3, 8, 4, 2, 7};

	int p = partition_first(nums, 0, 5);

	printf("分区结果：");
	print_array(nums, 6);
	printf("基准 %d 归位到下标 %d\n", nums[p], p);

	bool left_ok = true;
	for (int i = 0; i < p; i++) {
		if (nums[i] >= nums[p]) {
			left_ok = false;
		}
	}

	bool right_ok = true;
	for (int i = p + 1; i < 6; i++) {
		if (nums[i] < nums[p]) {
			right_ok = false;
		}
	}

	printf("左边全小于基准：%s\n", left_ok ? "是" : "否");
	printf("右边全大于等于基准：%s\n", right_ok ? "是" : "否");

	return 0;
}
```

**示例运行**：

```text
分区结果：2 3 4 5 8 7
基准 5 归位到下标 3
左边全小于基准：是
右边全大于等于基准：是
```

---

## 8.8 旋转数组里找最小值（与题面一致）

**思路**：闭区间 `[left, right]` 里，若 `nums[mid] > nums[right]`，说明 mid 在"被搬上去的前一段"，最小值必在 mid 右边，`left = mid + 1`；否则最小值在 mid 及其左边，`right = mid`（注意这里**不能**减 1，因为 mid 本身可能就是最小值——但这不会死循环：进入这个分支时 `nums[mid] <= nums[right]`，区间每轮至少缩一格，靠 `right = mid` 收敛）。区间剩一个元素时它就是答案。

```c
#include <stdio.h>

int find_min_rotated(const int nums[], int count)
{
	int left = 0;
	int right = count - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] > nums[right]) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	return nums[left];
}

void print_array(const int nums[], int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d", nums[i]);
		if (i < count - 1) {
			printf(" ");
		}
	}
}

int main(void)
{
	int rotated[7] = {40, 56, 67, 88, 12, 23, 35};
	int sorted[5] = {1, 2, 3, 4, 5};

	printf("旋转数组 {");
	print_array(rotated, 7);
	printf("} 的最小值是 %d\n", find_min_rotated(rotated, 7));

	printf("未旋转数组 {");
	print_array(sorted, 5);
	printf("} 的最小值是 %d\n", find_min_rotated(sorted, 5));

	return 0;
}
```

**示例运行**：

```text
旋转数组 {40 56 67 88 12 23 35} 的最小值是 12
未旋转数组 {1 2 3 4 5} 的最小值是 1
```

---

## 8.9 稳定的光荣榜（与题面一致）

**思路**：降序插入排序，`while` 条件用 `nums[j].score < key.score`：只有前面的分数**严格更小**才挪动，同分（`==`）立即停，新牌插在同分者的后面，先录入的保持在前——稳定性由此保证。

```c
#include <stdio.h>

struct student {
	int id;
	int score;
};

void insertion_sort_desc(struct student list[], int count)
{
	for (int i = 1; i < count; i++) {
		struct student key = list[i];
		int j = i - 1;

		while (j >= 0 && list[j].score < key.score) {
			list[j + 1] = list[j];
			j--;
		}

		list[j + 1] = key;
	}
}

int main(void)
{
	struct student list[6] = {
		{101, 85},
		{102, 92},
		{103, 85},
		{104, 78},
		{105, 92},
		{106, 88},
	};

	insertion_sort_desc(list, 6);

	for (int i = 0; i < 6; i++) {
		printf("%d %d\n", list[i].id, list[i].score);
	}

	return 0;
}
```

**示例运行**：

```text
102 92
105 92
106 88
101 85
103 85
104 78
```

---

## 8.10 图书馆书号查询系统（与题面一致）

**思路**：快排先整理书号；二分查找每次比较前计数加 1，找到返回下标、没找到返回 -1，比较次数通过指针参数带回（一种自然的写法）。主循环读入、判断 0、分发查询。

```c
#include <stdio.h>
#include <stdbool.h>

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

int binary_search(const int nums[], int count, int target, int *compares)
{
	int left = 0;
	int right = count - 1;
	*compares = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		(*compares)++;

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
	int books[8] = {1002, 1007, 1001, 1009, 1004, 1008, 1003, 1006};

	quick_sort(books, 0, 7);

	printf("排序后：");
	print_array(books, 8);

	int running = 1;

	while (running) {
		printf("要查的书号（0 结束）：");
		int target = 0;
		if (scanf("%d", &target) != 1) {
			printf("读取失败\n");
			return 1;
		}

		if (target == 0) {
			printf("查询结束\n");
			running = 0;
		} else {
			int compares = 0;
			int index = binary_search(books, 8, target, &compares);
			if (index >= 0) {
				printf("书号 %d 在第 %d 格，比较 %d 次\n",
				       target, index + 1, compares);
			} else {
				printf("没有书号 %d，比较 %d 次\n",
				       target, compares);
			}
		}
	}

	return 0;
}
```

**示例运行**（输入 `1004`、`1050`、`1001`、`0`）：

```text
排序后：1001 1002 1003 1004 1006 1007 1008 1009
要查的书号（0 结束）：1004
书号 1004 在第 4 格，比较 1 次
要查的书号（0 结束）：1050
没有书号 1050，比较 4 次
要查的书号（0 结束）：1001
书号 1001 在第 1 格，比较 3 次
要查的书号（0 结束）：0
查询结束
```

（提示语和输入连在一行是正常现象。）

---
