/*
 * 教程来源：chapter4/sections/4.1 指针基础.md
 * 示例编号：4.1.1
 * 所在小节：4.1.1 取地址和解引用
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.1.1_first_pointer.c -o demo
 *
 * 预期输出：
 *   a 的值：42
 *   p 指向的值：*p = 42
 *   通过 *p 修改后，a = 100
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.1.1 first_pointer.c
#include <stdio.h>

int main(void)
{
	int a = 42;
	int *p = &a;

	printf("a 的值：%d\n", a);
	printf("p 指向的值：*p = %d\n", *p);

	*p = 100;    /* 通过指针修改 a */
	printf("通过 *p 修改后，a = %d\n", a);

	return 0;
}
