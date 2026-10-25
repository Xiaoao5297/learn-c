/*
 * 教程来源：chapter10/sections/10.3 函数指针.md
 * 示例编号：10.3.4
 * 所在小节：10.3.4 函数指针数组做菜单分发
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.3.4_menu_demo.c -o demo
 *
 * 预期输出：
 *   今天也要加油哦（示例菜单，不含真实时间）
 *   你好，欢迎回来！
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.3.4 menu_demo.c
#include <stdio.h>

void greet(void)
{
	printf("你好，欢迎回来！\n");
}

void show_time_hint(void)
{
	printf("今天也要加油哦（示例菜单，不含真实时间）\n");
}

void farewell(void)
{
	printf("再见！\n");
}

int main(void)
{
	void (*actions[])(void) = {greet, show_time_hint, farewell};

	int choice = 2;

	if (choice >= 1 && choice <= 3) {
		actions[choice - 1]();
	} else {
		printf("没有这个选项\n");
	}

	choice = 1;
	if (choice >= 1 && choice <= 3) {
		actions[choice - 1]();
	}

	return 0;
}
