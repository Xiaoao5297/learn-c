/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.3
 * 所在小节：2.1.3 取余的用途
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.3_modulo.c -o demo
 *
 * 预期输出：
 *   17 是奇数
 *   17 除以 5 的余数是 2
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.3 modulo.c
#include <stdio.h>

int main(void)
{
	int number = 17;

	if (number % 2 == 0) {
		printf("%d 是偶数\n", number);
	} else {
		printf("%d 是奇数\n", number);
	}

	printf("17 除以 5 的余数是 %d\n", 17 % 5);

	return 0;
}
