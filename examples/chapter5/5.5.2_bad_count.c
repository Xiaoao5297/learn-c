/*
 * 教程来源：chapter5/sections/5.5 综合项目：通讯录存盘.md
 * 示例编号：5.5.2
 * 所在小节：5.5.6 眼见为实：被篡改的文件头
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.5.2_bad_count.c -o demo
 *
 * 预期输出：
 *   文件头不合法：count 是 999
 *   拒绝读取，程序安全退出
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.5.2 bad_count.c
#include <stdio.h>

#define MAX_CONTACTS 100

int main(void)
{
	FILE *fp = fopen("broken.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	fprintf(fp, "999\n");
	fclose(fp);

	fp = fopen("broken.txt", "r");
	if (fp == NULL) {
		return 1;
	}

	int count = 0;
	if (fscanf(fp, "%d", &count) != 1 || count < 0 || count > MAX_CONTACTS) {
		printf("文件头不合法：count 是 %d\n", count);
		printf("拒绝读取，程序安全退出\n");
		fclose(fp);
		return 0;
	}

	fclose(fp);
	printf("读完 %d 个联系人\n", count);

	return 0;
}
