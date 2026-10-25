/*
 * 教程来源：chapter1/sections/1.5 scanf 与输入.md
 * 示例编号：1.5.4
 * 所在小节：解法二：手动读掉残留的回车
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.5.4_scan_char.c -o demo
 *
 * 预期输出：
 *   请输入年龄：请输入 y 或 n：age = 25, choice = y
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.5.4 scan_char.c
#include <stdio.h>

int main(void)
{
	int age = 0;
	char choice = 0;

	printf("请输入年龄：");
	scanf("%d", &age);

	printf("请输入 y 或 n：");
	scanf(" %c", &choice);

	printf("age = %d, choice = %c\n", age, choice);

	return 0;
}
