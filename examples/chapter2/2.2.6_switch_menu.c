/*
 * 教程来源：chapter2/sections/2.2 条件判断.md
 * 示例编号：2.2.6
 * 所在小节：2.2.7 switch 语句
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.2.6_switch_menu.c -o demo
 *
 * 预期输出：
 *   打开文件
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.2.6 switch_menu.c
#include <stdio.h>

int main(void)
{
	int choice = 2;

	switch (choice) {
	case 1:
		printf("新建文件\n");
		break;
	case 2:
		printf("打开文件\n");
		break;
	case 3:
		printf("保存文件\n");
		break;
	default:
		printf("无效选项\n");
		break;
	}

	return 0;
}
