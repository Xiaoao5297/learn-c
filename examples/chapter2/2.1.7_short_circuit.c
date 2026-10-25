/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.7
 * 所在小节：短路求值
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.7_short_circuit.c -o demo
 *
 * 预期输出：
 *   不能这么除
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.7 short_circuit.c
#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 0;

	if (b != 0 && a / b > 2) {
		printf("结果大于 2\n");
	} else {
		printf("不能这么除\n");
	}

	return 0;
}
