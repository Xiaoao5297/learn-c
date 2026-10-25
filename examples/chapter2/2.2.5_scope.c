/*
 * 教程来源：chapter2/sections/2.2 条件判断.md
 * 示例编号：2.2.5
 * 所在小节：2.2.5 大括号和变量作用域
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.2.5_scope.c -o demo
 *
 * 预期输出：
 *   x = 10, y = 20
 *   x = 10
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.2.5 scope.c
#include <stdio.h>

int main(void)
{
	int x = 10;

	if (x > 0) {
		int y = 20;
		printf("x = %d, y = %d\n", x, y);
	}

	printf("x = %d\n", x);

	return 0;
}
