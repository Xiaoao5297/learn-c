/*
 * 教程来源：chapter10/sections/10.1 预处理与宏.md
 * 示例编号：10.1.4
 * 所在小节：10.1.4 带参宏：披着函数外衣的文本替换
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.1.4_square_side_effect.c -o demo
 *
 * 预期输出：
 *   SQUARE_BAD(5) = 25
 *   SQUARE_BAD(m + 1) = 11（想要 36）
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.1.4 square_side_effect.c
#include <stdio.h>

#define SQUARE_BAD(x) x *x

int main(void)
{
	int m = 5;

	printf("SQUARE_BAD(5) = %d\n", SQUARE_BAD(5));
	printf("SQUARE_BAD(m + 1) = %d（想要 36）\n", SQUARE_BAD(m + 1));

	return 0;
}
