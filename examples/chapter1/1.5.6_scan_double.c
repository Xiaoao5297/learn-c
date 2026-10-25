/*
 * 教程来源：chapter1/sections/1.5 scanf 与输入.md
 * 示例编号：1.5.6
 * 所在小节：1.5.6 读浮点数
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.5.6_scan_double.c -o demo
 *
 * 预期输出：
 *   请输入身高（米）：身高是 1.75 米
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.5.6 scan_double.c
#include <stdio.h>

int main(void)
{
	double height = 0.0;

	printf("请输入身高（米）：");
	if (scanf("%lf", &height) != 1) {
		printf("输入格式不对\n");
		return 1;
	}

	printf("身高是 %.2f 米\n", height);

	return 0;
}
