/*
 * 教程来源：chapter1/sections/1.4 变量与数据类型.md
 * 示例编号：1.4.7
 * 所在小节：char 的真面目：数字
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.4.7_char_ascii.c -o demo
 *
 * 预期输出：
 *   字母：A
 *   编码：65
 *   编码 66 对应的字母：B
 *   A 后面一个字母是 B
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.4.7 char_ascii.c
#include <stdio.h>

int main(void)
{
	char letter = 'A';
	int code = letter;

	printf("字母：%c\n", letter);
	printf("编码：%d\n", code);

	code = 66;
	printf("编码 66 对应的字母：%c\n", code);

	char next = letter + 1;
	printf("%c 后面一个字母是 %c\n", letter, next);

	return 0;
}
