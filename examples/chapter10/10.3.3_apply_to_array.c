/*
 * 教程来源：chapter10/sections/10.3 函数指针.md
 * 示例编号：10.3.3
 * 所在小节：10.3.3 把函数当参数传：apply 的雏形
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.3.3_apply_to_array.c -o demo
 *
 * 预期输出：
 *   翻倍后：2 4 6 8
 *   平方后：4 16 36 64
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.3.3 apply_to_array.c
#include <stdio.h>

int twice(int x)
{
	return x * 2;
}

int square(int x)
{
	return x * x;
}

void apply(int nums[], int count, int (*fn)(int))
{
	for (int i = 0; i < count; i++) {
		nums[i] = fn(nums[i]);
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
	int nums[4] = {1, 2, 3, 4};

	apply(nums, 4, twice);
	printf("翻倍后：");
	print_array(nums, 4);

	apply(nums, 4, square);
	printf("平方后：");
	print_array(nums, 4);

	return 0;
}
