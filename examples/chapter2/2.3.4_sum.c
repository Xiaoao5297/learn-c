/*
 * 教程来源：chapter2/sections/2.3 循环入门.md
 * 示例编号：2.3.4
 * 所在小节：2.3.4 用循环做累加
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.3.4_sum.c -o demo
 *
 * 预期输出：
 *   1 到 100 的和是 5050
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.3.4 sum.c
#include <stdio.h>

int main(void)
{
	int sum = 0;

	for (int i = 1; i <= 100; i++) {
		sum += i;
	}

	printf("1 到 100 的和是 %d\n", sum);

	return 0;
}
