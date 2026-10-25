/*
 * 教程来源：chapter1/sections/1.3 第一个 C 程序.md
 * 示例编号：1.3.3
 * 所在小节：1.3.3 转义字符和 \n
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.3.3_escape.c -o demo
 *
 * 预期输出：
 *   第一行
 *   第二行
 *   姓名	年龄
 *   张三	20
 *   他说："C 语言很有用"
 *   反斜杠本身是：\
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.3.3 escape.c
#include <stdio.h>

int main(void)
{
	printf("第一行\n第二行\n");
	printf("姓名\t年龄\n");
	printf("张三\t20\n");
	printf("他说：\"C 语言很有用\"\n");
	printf("反斜杠本身是：\\\n");

	return 0;
}
