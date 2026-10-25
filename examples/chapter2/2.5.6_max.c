/*
 * 教程来源：chapter2/sections/2.5 函数基础.md
 * 示例编号：2.5.6
 * 所在小节：求最大值
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.5.6_max.c -o demo
 *
 * 预期输出：
 *   8
 *   12
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.5.6 max.c
#include <stdio.h>

int max_int(int a, int b)
{
	if (a > b) {
		return a;
	}
	return b;
}

int main(void)
{
	printf("%d\n", max_int(3, 8));
	printf("%d\n", max_int(12, 5));

	return 0;
}
