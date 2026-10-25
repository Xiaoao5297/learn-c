/*
 * 教程来源：chapter4/sections/4.6 const 与多级指针.md
 * 示例编号：4.6.3
 * 所在小节：4.6.3 二级指针
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.6.3_double_pointer.c -o demo
 *
 * 预期输出：
 *   x     = 5
 *   *p    = 5
 *   **pp  = 5
 *   修改后 x = 8
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.6.3 double_pointer.c
#include <stdio.h>

int main(void)
{
	int x = 5;
	int *p = &x;
	int **pp = &p;

	printf("x     = %d\n", x);
	printf("*p    = %d\n", *p);
	printf("**pp  = %d\n", **pp);

	**pp = 8;
	printf("修改后 x = %d\n", x);

	return 0;
}
