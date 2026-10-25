/*
 * 教程来源：chapter2/sections/2.3 循环入门.md
 * 示例编号：2.3.3
 * 所在小节：2.3.3 do-while 循环
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.3.3_do_while.c -o demo
 *
 * 预期输出：
 *   执行一次，choice = 0
 *   执行一次，choice = 1
 *   执行一次，choice = 2
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.3.3 do_while.c
#include <stdio.h>

int main(void)
{
	int choice = 0;

	do {
		printf("执行一次，choice = %d\n", choice);
		choice++;
	} while (choice < 3);

	return 0;
}
