/*
 * 教程来源：chapter2/sections/2.2 条件判断.md
 * 示例编号：2.2.4
 * 所在小节：2.2.4 嵌套 if
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.2.4_nested_if.c -o demo
 *
 * 预期输出：
 *   可以入场
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.2.4 nested_if.c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int age = 20;
	bool has_ticket = true;

	if (age >= 18) {
		if (has_ticket) {
			printf("可以入场\n");
		} else {
			printf("需要先买票\n");
		}
	} else {
		printf("未成年，不能入场\n");
	}

	return 0;
}
