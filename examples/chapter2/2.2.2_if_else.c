/*
 * 教程来源：chapter2/sections/2.2 条件判断.md
 * 示例编号：2.2.2
 * 所在小节：2.2.2 if-else
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.2.2_if_else.c -o demo
 *
 * 预期输出：
 *   17 是奇数
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.2.2 if_else.c
#include <stdio.h>

int main(void)
{
	int number = 17;

	if (number % 2 == 0) {
		printf("%d 是偶数\n", number);
	} else {
		printf("%d 是奇数\n", number);
	}

	return 0;
}
