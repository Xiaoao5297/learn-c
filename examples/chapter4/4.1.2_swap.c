/*
 * 教程来源：chapter4/sections/4.1 指针基础.md
 * 示例编号：4.1.2
 * 所在小节：4.1.2 用指针交换两个变量
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.1.2_swap.c -o demo
 *
 * 预期输出：
 *   交换前：x = 3, y = 7
 *   交换后：x = 7, y = 3
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.1.2 swap.c
#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int x = 3;
	int y = 7;

	printf("交换前：x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("交换后：x = %d, y = %d\n", x, y);

	return 0;
}
