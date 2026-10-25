/*
 * 教程来源：chapter5/sections/5.3 行读写与安全输入.md
 * 示例编号：5.3.2
 * 所在小节：5.3.2 处理 fgets 保留的换行符
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.3.2_strip_newline.c -o demo
 *
 * 预期输出：
 *   去掉换行前：[apple
 *   ]，长度 6
 *   去掉换行后：[apple]，长度 5
 *   去掉换行前：[banana
 *   ]，长度 7
 *   去掉换行后：[banana]，长度 6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.3.2 strip_newline.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char line[64];

	FILE *fp = fopen("words.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	fprintf(fp, "apple\nbanana\n");
	fclose(fp);

	fp = fopen("words.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("去掉换行前：[%s]，长度 %zu\n", line, strlen(line));
		line[strcspn(line, "\n")] = '\0';
		printf("去掉换行后：[%s]，长度 %zu\n", line, strlen(line));
	}
	fclose(fp);

	return 0;
}
