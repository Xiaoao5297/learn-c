/*
 * 教程来源：chapter7/sections/7.1 递归入门.md
 * 示例编号：7.1.1
 * 所在小节：7.1.1 第一个递归程序
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.1.1_countdown.c -o demo
 *
 * 预期输出：
 *   3 2 1 发射！
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.1.1 countdown.c
#include <stdio.h>

void count_down(int n)
{
	if (n == 0) {
		printf("发射！\n");
		return;
	}
	printf("%d ", n);
	count_down(n - 1);
}

int main(void)
{
	count_down(3);

	return 0;
}
