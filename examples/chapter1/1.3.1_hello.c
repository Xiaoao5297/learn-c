/*
 * 教程来源：chapter1/sections/1.3 第一个 C 程序.md
 * 示例编号：1.3.1
 * 所在小节：1.3.1 写出 hello.c
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.3.1_hello.c -o demo
 *
 * 预期输出：
 *   你好，世界
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.3.1 hello.c
#include <stdio.h>

int main(void)
{
	printf("你好，世界\n");
	return 0;
}
