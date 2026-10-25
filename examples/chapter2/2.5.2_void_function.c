/*
 * 教程来源：chapter2/sections/2.5 函数基础.md
 * 示例编号：2.5.2
 * 所在小节：2.5.2 参数和返回值
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.5.2_void_function.c -o demo
 *
 * 预期输出：
 *   ----------
 *   分隔线上面
 *   ----------
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.5.2 void_function.c
#include <stdio.h>

void print_line(int length)
{
	for (int i = 0; i < length; i++) {
		printf("-");
	}
	printf("\n");
}

int main(void)
{
	print_line(10);
	printf("分隔线上面\n");
	print_line(10);

	return 0;
}
