/*
 * 教程来源：chapter4/sections/4.2 指针与数组.md
 * 示例编号：4.2.1
 * 所在小节：4.2.1 数组名的自动转换
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.2.1_array_decay.c -o demo
 *
 * 预期输出：
 *   sizeof(arr) = 20 字节
 *   sizeof(p)   = 8 字节
 *   *p = 10
 *   *arr = 10
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.2.1 array_decay.c
#include <stdio.h>

int main(void)
{
	int arr[5] = {10, 20, 30, 40, 50};
	int *p = arr;

	printf("sizeof(arr) = %zu 字节\n", sizeof(arr));
	printf("sizeof(p)   = %zu 字节\n", sizeof(p));
	printf("*p = %d\n", *p);
	printf("*arr = %d\n", *arr);

	return 0;
}
