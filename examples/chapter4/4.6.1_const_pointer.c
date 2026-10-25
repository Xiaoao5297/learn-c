/*
 * 教程来源：chapter4/sections/4.6 const 与多级指针.md
 * 示例编号：4.6.1
 * 所在小节：4.6.1 const 与指针的四种组合
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.6.1_const_pointer.c -o demo
 *
 * 预期输出：
 *   *p1 = 20
 *   x = 30
 *   *p3 = 30
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.6.1 const_pointer.c
#include <stdio.h>

int main(void)
{
	int x = 10;
	int y = 20;

	/* 指向 const 的指针：数据不能改，指针可以改指向 */
	const int *p1 = &x;
	p1 = &y;
	printf("*p1 = %d\n", *p1);

	/* const 指针：指针不能改指向，数据可以改 */
	int *const p2 = &x;
	*p2 = 30;
	printf("x = %d\n", x);

	/* 都不能改 */
	const int *const p3 = &x;
	printf("*p3 = %d\n", *p3);

	return 0;
}
