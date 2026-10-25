/*
 * 教程来源：chapter3/sections/3.1 数组.md
 * 示例编号：3.1.6
 * 所在小节：3.1.6 用 sizeof 计算元素个数
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.1.6_array_sizeof.c -o demo
 *
 * 预期输出：
 *   整个数组占 20 字节
 *   一个元素占 4 字节
 *   元素个数是 5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.1.6 array_sizeof.c
#include <stdio.h>

int main(void)
{
	int scores[] = {95, 88, 72, 100, 60};

	printf("整个数组占 %zu 字节\n", sizeof(scores));
	printf("一个元素占 %zu 字节\n", sizeof(scores[0]));
	printf("元素个数是 %zu\n", sizeof(scores) / sizeof(scores[0]));

	return 0;
}
