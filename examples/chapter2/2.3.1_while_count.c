/*
 * 教程来源：chapter2/sections/2.3 循环入门.md
 * 示例编号：2.3.1
 * 所在小节：2.3.1 while 循环
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.3.1_while_count.c -o demo
 *
 * 预期输出：
 *   1
 *   2
 *   3
 *   4
 *   5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.3.1 while_count.c
#include <stdio.h>

int main(void)
{
	int i = 1;

	while (i <= 5) {
		printf("%d\n", i);
		i++;
	}

	return 0;
}
