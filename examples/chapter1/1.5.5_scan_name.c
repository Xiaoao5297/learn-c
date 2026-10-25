/*
 * 教程来源：chapter1/sections/1.5 scanf 与输入.md
 * 示例编号：1.5.5
 * 所在小节：完整示例
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.5.5_scan_name.c -o demo
 *
 * 预期输出：
 *   请输入名字：你好，小明
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.5.5 scan_name.c
#include <stdio.h>

int main(void)
{
	char name[32];

	printf("请输入名字：");
	if (scanf("%31s", name) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("你好，%s\n", name);

	return 0;
}
