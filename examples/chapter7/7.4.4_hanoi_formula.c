/*
 * 教程来源：chapter7/sections/7.4 汉诺塔与分治.md
 * 示例编号：7.4.4
 * 所在小节：7.4.4 验证步数公式
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.4.4_hanoi_formula.c -o demo
 *
 * 预期输出：
 *   n = 1：实际 1 步，公式 2^1 - 1 = 1
 *   n = 2：实际 3 步，公式 2^2 - 1 = 3
 *   n = 3：实际 7 步，公式 2^3 - 1 = 7
 *   n = 4：实际 15 步，公式 2^4 - 1 = 15
 *   n = 5：实际 31 步，公式 2^5 - 1 = 31
 *   n = 6：实际 63 步，公式 2^6 - 1 = 63
 *   n = 7：实际 127 步，公式 2^7 - 1 = 127
 *   n = 8：实际 255 步，公式 2^8 - 1 = 255
 *   n = 9：实际 511 步，公式 2^9 - 1 = 511
 *   n = 10：实际 1023 步，公式 2^10 - 1 = 1023
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.4.4 hanoi_formula.c
#include <stdio.h>

int move_count = 0;

void hanoi(int n, char from, char helper, char to)
{
	if (n == 1) {
		move_count++;
		return;
	}
	hanoi(n - 1, from, to, helper);
	move_count++;
	hanoi(n - 1, helper, from, to);
}

int main(void)
{
	for (int n = 1; n <= 10; n++) {
		move_count = 0;
		hanoi(n, 'A', 'B', 'C');

		int formula = 1;
		for (int i = 0; i < n; i++) {
			formula = formula * 2;
		}

		printf("n = %d：实际 %d 步，公式 2^%d - 1 = %d\n",
		       n, move_count, n, formula - 1);
	}

	return 0;
}
