/*
 * 教程来源：chapter10/sections/10.1 预处理与宏.md
 * 示例编号：10.1.1
 * 所在小节：10.1.2 常量宏：编译前就替换掉的文本
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.1.1_include_macro.c -o demo
 *
 * 预期输出：
 *   共有 5 个成绩
 *   88 及格
 *   45 不及格
 *   92 及格
 *   60 及格
 *   73 及格
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.1.1 include_macro.c
#include <stdio.h>

#define MAX_SCORES 5
#define PASS_LINE 60

int main(void)
{
	int scores[MAX_SCORES] = {88, 45, 92, 60, 73};

	printf("共有 %d 个成绩\n", MAX_SCORES);

	for (int i = 0; i < MAX_SCORES; i++) {
		if (scores[i] >= PASS_LINE) {
			printf("%d 及格\n", scores[i]);
		} else {
			printf("%d 不及格\n", scores[i]);
		}
	}

	return 0;
}
