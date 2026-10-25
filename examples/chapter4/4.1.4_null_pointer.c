/*
 * 教程来源：chapter4/sections/4.1 指针基础.md
 * 示例编号：4.1.4
 * 所在小节：4.1.4 NULL：空指针
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.1.4_null_pointer.c -o demo
 *
 * 预期输出：
 *   p 还没有指向任何地方
 *   现在可以放心使用 *p：5
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.1.4 null_pointer.c
#include <stdio.h>

int main(void)
{
	int *p = NULL;

	if (p == NULL) {
		printf("p 还没有指向任何地方\n");
	}

	int x = 5;
	p = &x;

	if (p != NULL) {
		printf("现在可以放心使用 *p：%d\n", *p);
	}

	return 0;
}
