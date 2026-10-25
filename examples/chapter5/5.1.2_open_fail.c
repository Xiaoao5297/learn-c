/*
 * 教程来源：chapter5/sections/5.1 文件与 FILE.md
 * 示例编号：5.1.2
 * 所在小节：5.1.3 打开失败：永远检查 NULL
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.1.2_open_fail.c -o demo
 *
 * 预期输出：
 *   打开失败，fp 是 NULL
 *   先处理错误，再正常退出
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.1.2 open_fail.c
#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("不存在的目录/data.txt", "r");

	if (fp == NULL) {
		printf("打开失败，fp 是 NULL\n");
		printf("先处理错误，再正常退出\n");
		return 0;
	}

	fclose(fp);
	return 0;
}
