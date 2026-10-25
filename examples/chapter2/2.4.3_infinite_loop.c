/*
 * 教程来源：chapter2/sections/2.4 循环控制.md
 * 示例编号：2.4.3
 * 所在小节：2.4.3 无限循环
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.4.3_infinite_loop.c -o demo
 *
 * 预期输出：
 *   第 0 次循环
 *   第 1 次循环
 *   第 2 次循环
 *   退出循环
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.4.3 infinite_loop.c
#include <stdio.h>

int main(void)
{
	int count = 0;

	while (1) {
		printf("第 %d 次循环\n", count);
		count++;

		if (count == 3) {
			break;
		}
	}

	printf("退出循环\n");

	return 0;
}
