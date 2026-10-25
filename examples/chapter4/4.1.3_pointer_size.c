/*
 * 教程来源：chapter4/sections/4.1 指针基础.md
 * 示例编号：4.1.3
 * 所在小节：4.1.3 指针的大小和类型
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.1.3_pointer_size.c -o demo
 *
 * 预期输出：
 *   int * 占 8 字节
 *   double * 占 8 字节
 *   char * 占 8 字节
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.1.3 pointer_size.c
#include <stdio.h>

int main(void)
{
	int a = 1;
	double d = 2.0;
	char c = 'x';

	int *p1 = &a;
	double *p2 = &d;
	char *p3 = &c;

	printf("int * 占 %zu 字节\n", sizeof(p1));
	printf("double * 占 %zu 字节\n", sizeof(p2));
	printf("char * 占 %zu 字节\n", sizeof(p3));

	return 0;
}
