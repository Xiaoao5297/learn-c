/*
 * 教程来源：chapter3/sections/3.3 字符串基础.md
 * 示例编号：3.3.6
 * 所在小节：3.3.6 中文字符串与编码
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.3.6_strlen_utf8.c -o demo
 *
 * 预期输出：
 *   sizeof(en) = 4
 *   strlen(en) = 3
 *   sizeof(zh) = 7
 *   strlen(zh) = 6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.3.6 strlen_utf8.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char en[] = "abc";
	char zh[] = "中文";

	printf("sizeof(en) = %zu\n", sizeof(en));
	printf("strlen(en) = %zu\n", strlen(en));
	printf("sizeof(zh) = %zu\n", sizeof(zh));
	printf("strlen(zh) = %zu\n", strlen(zh));

	return 0;
}
