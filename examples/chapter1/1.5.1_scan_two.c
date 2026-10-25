/*
 * 教程来源：chapter1/sections/1.5 scanf 与输入.md
 * 示例编号：1.5.1
 * 所在小节：1.5.1 scanf 的基本用法
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.5.1_scan_two.c -o demo
 *
 * 预期输出：
 *   请输入两个整数（用空格隔开）：3 + 5 = 8
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.5.1 scan_two.c
#include <stdio.h>

int main(void)
{
	int a = 0;
	int b = 0;

	printf("请输入两个整数（用空格隔开）：");
	if (scanf("%d %d", &a, &b) != 2) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("%d + %d = %d\n", a, b, a + b);

	return 0;
}
