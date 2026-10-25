/*
 * 教程来源：chapter4/sections/4.6 const 与多级指针.md
 * 示例编号：4.6.2
 * 所在小节：4.6.2 void ：万能指针
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.6.2_void_pointer.c -o demo
 *
 * 预期输出：
 *   v 指向的整数：42
 *   v 指向的小数：3.14
 *   v 占 8 字节
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.6.2 void_pointer.c
#include <stdio.h>

int main(void)
{
	int i = 42;
	double d = 3.14;

	void *v = &i;
	printf("v 指向的整数：%d\n", *(int *)v);

	v = &d;
	printf("v 指向的小数：%.2f\n", *(double *)v);

	printf("v 占 %zu 字节\n", sizeof(v));

	return 0;
}
