/*
 * 教程来源：chapter6/sections/6.2 内存陷阱.md
 * 示例编号：6.2.2
 * 所在小节：6.2.2 realloc：动态扩容
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.2.2_realloc_grow.c -o demo
 *
 * 预期输出：
 *   arr[0] = 1
 *   arr[1] = 2
 *   arr[2] = 3
 *   arr[3] = 40
 *   arr[4] = 50
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.2.2 realloc_grow.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 3;
	int *arr = malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	int new_n = 5;
	int *tmp = realloc(arr, new_n * sizeof(int));
	if (tmp == NULL) {
		printf("扩容失败，继续用原来的数组\n");
		free(arr);
		return 1;
	}
	arr = tmp;
	n = new_n;

	/* 新位置（下标 3、4）的内容不确定，要自己赋值 */
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i < n; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	free(arr);
	arr = NULL;

	return 0;
}
