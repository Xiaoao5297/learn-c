/*
 * 教程来源：chapter7/sections/7.4 汉诺塔与分治.md
 * 示例编号：7.4.5
 * 所在小节：7.4.5 分而治之
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.4.5_array_sum.c -o demo
 *
 * 预期输出：
 *   总和：24
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.4.5 array_sum.c
#include <stdio.h>

int array_sum(const int a[], int n)
{
	if (n == 0) {
		return 0;
	}
	return a[n - 1] + array_sum(a, n - 1);
}

int main(void)
{
	int a[4] = {3, 5, 7, 9};

	printf("总和：%d\n", array_sum(a, 4));

	return 0;
}
