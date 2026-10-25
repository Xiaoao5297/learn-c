/*
 * 教程来源：chapter2/sections/2.2 条件判断.md
 * 示例编号：2.2.1
 * 所在小节：2.2.1 最基本的 if
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.2.1_basic_if.c -o demo
 *
 * 预期输出：
 *   及格
 *   程序结束
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.2.1 basic_if.c
#include <stdio.h>

int main(void)
{
	int score = 72;

	if (score >= 60) {
		printf("及格\n");
	}

	printf("程序结束\n");

	return 0;
}
