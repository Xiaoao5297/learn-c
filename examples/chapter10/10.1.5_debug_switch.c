/*
 * 教程来源：chapter10/sections/10.1 预处理与宏.md
 * 示例编号：10.1.5
 * 所在小节：10.1.5 多行宏与 do-while(0)
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.1.5_debug_switch.c -o demo
 *
 * 预期输出：
 *   开始计算
 *   [调试] 当前 total = 42
 *   计算完成，结果是 42
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.1.5 debug_switch.c
#include <stdio.h>

#define DEBUG

int main(void)
{
	int total = 42;

	printf("开始计算\n");

#ifdef DEBUG
	printf("[调试] 当前 total = %d\n", total);
#endif

	printf("计算完成，结果是 %d\n", total);

	return 0;
}
