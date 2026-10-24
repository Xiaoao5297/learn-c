/*
 * 教程来源：chapter2/sections/2.4 循环控制.md
 * 示例编号：2.4.1
 * 所在小节：2.4.1 break：提前结束循环
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.4.1_break.c -o demo
 *
 * 预期输出：
 *   1 2 3 4
 *   循环结束
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.4.1 break.c
#include <stdio.h>

int main(void)
{
	for (int i = 1; i <= 10; i++) {
		if (i == 5) {
			break;
		}
		printf("%d ", i);
	}

	printf("\n循环结束\n");

	return 0;
}
