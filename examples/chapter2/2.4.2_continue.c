/*
 * 教程来源：chapter2/sections/2.4 循环控制.md
 * 示例编号：2.4.2
 * 所在小节：2.4.2 continue：跳过本次循环
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.4.2_continue.c -o demo
 *
 * 预期输出：
 *   1 3 5 7 9
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.4.2 continue.c
#include <stdio.h>

int main(void)
{
	for (int i = 1; i <= 10; i++) {
		if (i % 2 == 0) {
			continue;
		}
		printf("%d ", i);
	}

	printf("\n");

	return 0;
}
