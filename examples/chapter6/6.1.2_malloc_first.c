/*
 * 教程来源：chapter6/sections/6.1 动态内存.md
 * 示例编号：6.1.2
 * 所在小节：6.1.2 malloc：申请内存
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.1.2_malloc_first.c -o demo
 *
 * 预期输出：
 *   *p = 42
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.1.2 malloc_first.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p = malloc(sizeof(int));
	if (p == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	*p = 42;
	printf("*p = %d\n", *p);

	free(p);
	p = NULL;

	return 0;
}
