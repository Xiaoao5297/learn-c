/*
 * 教程来源：chapter4/sections/4.6 const 与多级指针.md
 * 示例编号：4.6.4
 * 所在小节：4.6.3 二级指针
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.6.4_redirect_pointer.c -o demo
 *
 * 预期输出：
 *   p 指向的值：1
 *   重定向后 p 指向的值：2
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.6.4 redirect_pointer.c
#include <stdio.h>

void redirect(int **pp, int *target)
{
	*pp = target;    /* 修改调用方指针的指向 */
}

int main(void)
{
	int a = 1;
	int b = 2;
	int *p = &a;

	printf("p 指向的值：%d\n", *p);

	redirect(&p, &b);
	printf("重定向后 p 指向的值：%d\n", *p);

	return 0;
}
