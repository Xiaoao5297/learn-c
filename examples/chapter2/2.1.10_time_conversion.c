/*
 * 教程来源：chapter2/sections/2.1 运算符.md
 * 示例编号：2.1.10
 * 所在小节：2.1.9 综合示例：秒数换算
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.1.10_time_conversion.c -o demo
 *
 * 预期输出：
 *   3725 秒 = 1 小时 2 分 5 秒
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.1.10 time_conversion.c
#include <stdio.h>

int main(void)
{
	int total_seconds = 3725;
	int hours = total_seconds / 3600;
	int minutes = (total_seconds % 3600) / 60;
	int seconds = total_seconds % 60;

	printf("%d 秒 = %d 小时 %d 分 %d 秒\n",
	       total_seconds, hours, minutes, seconds);

	return 0;
}
