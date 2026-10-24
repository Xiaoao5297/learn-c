/*
 * 教程来源：chapter2/sections/2.3 循环入门.md
 * 示例编号：2.3.5
 * 所在小节：2.3.7 综合示例：倒计时
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.3.5_countdown.c -o demo
 *
 * 预期输出：
 *   5
 *   4
 *   3
 *   2
 *   1
 *   起飞
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.3.5 countdown.c
#include <stdio.h>

int main(void)
{
	for (int i = 5; i >= 1; i--) {
		printf("%d\n", i);
	}

	printf("起飞\n");

	return 0;
}
