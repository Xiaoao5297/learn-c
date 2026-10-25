/*
 * 教程来源：chapter7/sections/7.2 调用栈与栈溢出.md
 * 示例编号：7.2.3
 * 所在小节：7.2.3 打印放在哪，顺序就反了
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.2.3_print_order.c -o demo
 *
 * 预期输出：
 *   1 2 3 4 5
 *   5 4 3 2 1
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.2.3 print_order.c
#include <stdio.h>

void print_up(int n)
{
	if (n == 0) {
		return;
	}
	print_up(n - 1);
	printf("%d ", n);
}

void print_down(int n)
{
	if (n == 0) {
		return;
	}
	printf("%d ", n);
	print_down(n - 1);
}

int main(void)
{
	print_up(5);
	printf("\n");
	print_down(5);
	printf("\n");

	return 0;
}
