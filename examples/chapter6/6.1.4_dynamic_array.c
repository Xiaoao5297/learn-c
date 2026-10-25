/*
 * 教程来源：chapter6/sections/6.1 动态内存.md
 * 示例编号：6.1.4
 * 所在小节：6.1.4 动态数组：运行时定大小
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.1.4_dynamic_array.c -o demo
 *
 * 预期输出：
 *   arr[0] = 10
 *   arr[1] = 20
 *   arr[2] = 30
 *   arr[3] = 40
 *   arr[4] = 50
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.1.4 dynamic_array.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 5;    /* 真实场景里 n 可能来自用户输入或文件 */

	int *arr = malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = (i + 1) * 10;
	}

	for (int i = 0; i < n; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	free(arr);
	arr = NULL;

	return 0;
}
