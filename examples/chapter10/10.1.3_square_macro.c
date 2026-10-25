/*
 * 教程来源：chapter10/sections/10.1 预处理与宏.md
 * 示例编号：10.1.3
 * 所在小节：10.1.4 带参宏：披着函数外衣的文本替换
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.1.3_square_macro.c -o demo
 *
 * 预期输出：
 *   SQUARE(5) = 25
 *   SQUARE(2+3) = 25
 *   SQUARE(a) = 16
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.1.3 square_macro.c
#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main(void)
{
	int a = 4;

	printf("SQUARE(5) = %d\n", SQUARE(5));
	printf("SQUARE(2+3) = %d\n", SQUARE(2 + 3));
	printf("SQUARE(a) = %d\n", SQUARE(a));

	return 0;
}
