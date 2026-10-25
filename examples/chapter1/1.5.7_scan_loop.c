/*
 * 教程来源：chapter1/sections/1.5 scanf 与输入.md
 * 示例编号：1.5.7
 * 所在小节：1.5.7 输入校验：不合法就重来
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.5.7_scan_loop.c -o demo
 *
 * 预期输出：
 *   请输入 0 到 100 之间的整数：输入的不是整数，请重新输入
 *   请输入 0 到 100 之间的整数：成绩是 59
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.5.7 scan_loop.c
#include <stdio.h>

int main(void)
{
	int score = -1;

	while (score < 0 || score > 100) {
		printf("请输入 0 到 100 之间的整数：");

		if (scanf("%d", &score) != 1) {
			printf("输入的不是整数，请重新输入\n");

			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF) {
			}

			score = -1;
		} else if (score < 0 || score > 100) {
			printf("范围不对，请重新输入\n");
		}
	}

	printf("成绩是 %d\n", score);

	return 0;
}
