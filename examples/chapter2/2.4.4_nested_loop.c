/*
 * 教程来源：chapter2/sections/2.4 循环控制.md
 * 示例编号：2.4.4
 * 所在小节：2.4.4 嵌套循环
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.4.4_nested_loop.c -o demo
 *
 * 预期输出：
 *   1×1=1
 *   1×2=2 2×2=4
 *   1×3=3 2×3=6 3×3=9
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.4.4 nested_loop.c
#include <stdio.h>

int main(void)
{
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d×%d=%d ", j, i, i * j);
		}
		printf("\n");
	}

	return 0;
}
