/*
 * 教程来源：chapter2/sections/2.2 条件判断.md
 * 示例编号：2.2.3
 * 所在小节：2.2.3 else if：多条件判断
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.2.3_grade.c -o demo
 *
 * 预期输出：
 *   良好
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.2.3 grade.c
#include <stdio.h>

int main(void)
{
	int score = 85;

	if (score >= 90) {
		printf("优秀\n");
	} else if (score >= 80) {
		printf("良好\n");
	} else if (score >= 60) {
		printf("及格\n");
	} else {
		printf("不及格\n");
	}

	return 0;
}
