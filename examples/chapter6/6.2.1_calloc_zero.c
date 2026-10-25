/*
 * 教程来源：chapter6/sections/6.2 内存陷阱.md
 * 示例编号：6.2.1
 * 所在小节：6.2.1 calloc：申请并清零
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.2.1_calloc_zero.c -o demo
 *
 * 预期输出：
 *   arr[0] = 0
 *   arr[1] = 0
 *   arr[2] = 0
 *   arr[3] = 0
 *   arr[4] = 0
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.2.1 calloc_zero.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *arr = calloc(5, sizeof(int));
	if (arr == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	for (int i = 0; i < 5; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	free(arr);
	arr = NULL;

	return 0;
}
