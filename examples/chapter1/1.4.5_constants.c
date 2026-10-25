/*
 * 教程来源：chapter1/sections/1.4 变量与数据类型.md
 * 示例编号：1.4.5
 * 所在小节：1.4.5 常量
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.4.5_constants.c -o demo
 *
 * 预期输出：
 *   圆周率约等于 3.14159
 *   满分是 100
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.4.5 constants.c
#include <stdio.h>

int main(void)
{
	const double PI = 3.14159;
	const int MAX_SCORE = 100;

	printf("圆周率约等于 %.5f\n", PI);
	printf("满分是 %d\n", MAX_SCORE);

	return 0;
}
