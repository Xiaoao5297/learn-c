/*
 * 教程来源：chapter4/sections/4.2 指针与数组.md
 * 示例编号：4.2.3
 * 所在小节：4.2.3 arr[i] 就是 (arr + i)
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.2.3_index_equivalence.c -o demo
 *
 * 预期输出：
 *   arr[2]      = 30
 *   *(arr + 2)  = 30
 *   2[arr]      = 30
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.2.3 index_equivalence.c
#include <stdio.h>

int main(void)
{
	int arr[5] = {10, 20, 30, 40, 50};

	printf("arr[2]      = %d\n", arr[2]);
	printf("*(arr + 2)  = %d\n", *(arr + 2));
	printf("2[arr]      = %d\n", 2[arr]);

	return 0;
}
