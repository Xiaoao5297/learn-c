/*
 * 教程来源：chapter2/sections/2.2 条件判断.md
 * 示例编号：2.2.8
 * 所在小节：2.2.8 综合示例：简单菜单
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.2.8_menu.c -o demo
 *
 * 预期输出：
 *   1. 开始游戏
 *   2. 读取存档
 *   3. 退出
 *   请选择：再见
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.2.8 menu.c
#include <stdio.h>

int main(void)
{
	int choice = 3;

	printf("1. 开始游戏\n");
	printf("2. 读取存档\n");
	printf("3. 退出\n");
	printf("请选择：");

	switch (choice) {
	case 1:
		printf("开始新游戏\n");
		break;
	case 2:
		printf("读取存档\n");
		break;
	case 3:
		printf("再见\n");
		break;
	default:
		printf("无效选项\n");
		break;
	}

	return 0;
}
