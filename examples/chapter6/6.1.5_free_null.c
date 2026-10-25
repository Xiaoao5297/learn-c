/*
 * 教程来源：chapter6/sections/6.1 动态内存.md
 * 示例编号：6.1.5
 * 所在小节：6.1.5 free：归还内存
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.1.5_free_null.c -o demo
 *
 * 预期输出：
 *   释放前：*p = 100
 *   释放后：p 已置为 NULL
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.1.5 free_null.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p = malloc(sizeof(int));
	if (p == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	*p = 100;
	printf("释放前：*p = %d\n", *p);

	free(p);
	p = NULL;

	if (p == NULL) {
		printf("释放后：p 已置为 NULL\n");
	}

	return 0;
}
