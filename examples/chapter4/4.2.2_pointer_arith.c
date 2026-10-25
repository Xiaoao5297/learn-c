/*
 * 教程来源：chapter4/sections/4.2 指针与数组.md
 * 示例编号：4.2.2
 * 所在小节：4.2.2 指针算术
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.2.2_pointer_arith.c -o demo
 *
 * 预期输出：
 *   p 指向：10
 *   p++ 后指向：20
 *   *(p + 2)：40
 *   p + 2 == &arr[3] 吗：1
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.2.2 pointer_arith.c
#include <stdio.h>

int main(void)
{
	int arr[5] = {10, 20, 30, 40, 50};
	int *p = arr;

	printf("p 指向：%d\n", *p);

	p++;
	printf("p++ 后指向：%d\n", *p);
	printf("*(p + 2)：%d\n", *(p + 2));
	printf("p + 2 == &arr[3] 吗：%d\n", p + 2 == &arr[3]);

	return 0;
}
