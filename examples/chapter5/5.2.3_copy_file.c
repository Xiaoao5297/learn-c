/*
 * 教程来源：chapter5/sections/5.2 读写文件.md
 * 示例编号：5.2.3
 * 所在小节：5.2.3 综合示例：复制文件
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.2.3_copy_file.c -o demo
 *
 * 预期输出：
 *   复制完成，共 18 个字符
 *   backup.txt 的内容：line one
 *   line two
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.2.3 copy_file.c
#include <stdio.h>

int main(void)
{
	FILE *src = fopen("origin.txt", "w");
	if (src == NULL) {
		return 1;
	}
	fprintf(src, "line one\n");
	fprintf(src, "line two\n");
	fclose(src);

	src = fopen("origin.txt", "r");
	if (src == NULL) {
		printf("打开源文件失败\n");
		return 1;
	}

	FILE *dest = fopen("backup.txt", "w");
	if (dest == NULL) {
		printf("打开目标文件失败\n");
		fclose(src);
		return 1;
	}

	int ch;
	int count = 0;
	while ((ch = fgetc(src)) != EOF) {
		fputc(ch, dest);
		count++;
	}

	fclose(src);
	fclose(dest);

	printf("复制完成，共 %d 个字符\n", count);

	dest = fopen("backup.txt", "r");
	if (dest == NULL) {
		return 1;
	}
	printf("backup.txt 的内容：");
	while ((ch = fgetc(dest)) != EOF) {
		printf("%c", ch);
	}
	fclose(dest);

	return 0;
}
