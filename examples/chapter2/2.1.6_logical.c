/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.6
 * 所在小节：2.1.6 逻辑运算符
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.6_logical.c -o demo
 *
 * 预期输出：
 *   可以入场
 *   需要购买普通票
 *   !has_ticket = 0
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.6 logical.c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int age = 20;
	bool has_ticket = true;

	if (age >= 18 && has_ticket) {
		printf("可以入场\n");
	} else {
		printf("不能入场\n");
	}

	if (age < 12 || age >= 65) {
		printf("可以购买优惠票\n");
	} else {
		printf("需要购买普通票\n");
	}

	printf("!has_ticket = %d\n", !has_ticket);

	return 0;
}
