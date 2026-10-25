/*
 * 教程来源：chapter7/sections/7.4 汉诺塔与分治.md
 * 示例编号：7.4.3
 * 所在小节：7.4.3 递归解法
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.4.3_hanoi.c -o demo
 *
 * 预期输出：
 *   第 1 步：盘子 1 A -> C
 *   第 2 步：盘子 2 A -> B
 *   第 3 步：盘子 1 C -> B
 *   第 4 步：盘子 3 A -> C
 *   第 5 步：盘子 1 B -> A
 *   第 6 步：盘子 2 B -> C
 *   第 7 步：盘子 1 A -> C
 *   共 7 步，正好是 2^3 - 1 = 7
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.4.3 hanoi.c
#include <stdio.h>

int steps = 0;

void hanoi(int n, char from, char helper, char to)
{
	if (n == 1) {
		steps++;
		printf("第 %d 步：盘子 1 %c -> %c\n", steps, from, to);
		return;
	}
	hanoi(n - 1, from, to, helper);
	steps++;
	printf("第 %d 步：盘子 %d %c -> %c\n", steps, n, from, to);
	hanoi(n - 1, helper, from, to);
}

int main(void)
{
	hanoi(3, 'A', 'B', 'C');
	printf("共 %d 步，正好是 2^3 - 1 = 7\n", steps);

	return 0;
}
