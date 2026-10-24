/*
 * 教程来源：chapter2/sections/2.2 条件判断.md
 * 示例编号：2.2.7
 * 所在小节：break 的作用
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.2.7_switch_fallthrough.c -o demo
 *
 * 预期输出：
 *   一
 *   二
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.2.7 switch_fallthrough.c
#include <stdio.h>

int main(void)
{
	int choice = 1;

	switch (choice) {
	case 1:
		printf("一\n");
	case 2:
		printf("二\n");
		break;
	default:
		printf("其他\n");
		break;
	}

	return 0;
}
