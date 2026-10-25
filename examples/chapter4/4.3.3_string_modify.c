/*
 * 教程来源：chapter4/sections/4.3 指针与字符串.md
 * 示例编号：4.3.3
 * 所在小节：4.3.3 能修改的字符串和只读的字符串
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.3.3_string_modify.c -o demo
 *
 * 预期输出：
 *   word 变成：Hello
 *   通过指针改：HEllo
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.3.3 string_modify.c
#include <stdio.h>

int main(void)
{
	char word[] = "hello";

	word[0] = 'H';
	printf("word 变成：%s\n", word);

	char *p = word;
	p[1] = 'E';
	printf("通过指针改：%s\n", word);

	return 0;
}
