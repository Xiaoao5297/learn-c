/*
 * 教程来源：chapter4/sections/4.3 指针与字符串.md
 * 示例编号：4.3.4
 * 所在小节：4.3.4 综合示例：统计元音字母
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.3.4_vowel_count.c -o demo
 *
 * 预期输出：
 *   请输入一行英文：
 *   Hello World 中有 3 个元音字母
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.3.4 vowel_count.c
#include <stdio.h>
#include <string.h>

int count_vowels(const char *s)
{
	int count = 0;

	while (*s != '\0') {
		char lower = *s;
		if (lower >= 'A' && lower <= 'Z') {
			lower = (char)(lower + ('a' - 'A'));
		}
		if (lower == 'a' || lower == 'e' || lower == 'i'
		    || lower == 'o' || lower == 'u') {
			count++;
		}
		s++;
	}

	return count;
}

int main(void)
{
	char line[64];

	printf("请输入一行英文：\n");
	if (fgets(line, sizeof(line), stdin) == NULL) {
		printf("读取失败\n");
		return 1;
	}
	line[strcspn(line, "\n")] = '\0';

	printf("%s 中有 %d 个元音字母\n", line, count_vowels(line));

	return 0;
}
