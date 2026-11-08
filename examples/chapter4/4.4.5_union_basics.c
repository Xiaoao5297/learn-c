/*
 * 教程来源：chapter4/sections/4.4 结构体.md
 * 示例编号：4.4.5
 * 所在小节：4.4.5 union：成员共用一块内存
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.4.5_union_basics.c -o demo
 *
 * 预期输出：
 *   sizeof(struct box) = 16
 *   sizeof(union value) = 8
 *   v.i = 42
 *   v.d = 3.14
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.4.5 union_basics.c
#include <stdio.h>

struct box {
	int i;
	double d;
};

union value {
	int i;
	double d;
};

int main(void)
{
	union value v;

	printf("sizeof(struct box) = %zu\n", sizeof(struct box));
	printf("sizeof(union value) = %zu\n", sizeof(union value));

	v.i = 42;
	printf("v.i = %d\n", v.i);

	v.d = 3.14;
	printf("v.d = %.2f\n", v.d);

	return 0;
}
