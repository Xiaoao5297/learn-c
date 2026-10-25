/*
 * 教程来源：chapter3/sections/3.4 字符串函数.md
 * 示例编号：3.4.9
 * 所在小节：3.4.9 strstr：查找子串
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.4.9_strstr_demo.c -o demo
 *
 * 预期输出：
 *   找到了，从第 7 个字符开始
 *   剩下的内容：C programming
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.4.9 strstr_demo.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char text[] = "I love C programming";
	char word[] = "C";

	char *pos = strstr(text, word);

	if (pos != NULL) {
		printf("找到了，从第 %d 个字符开始\n", (int)(pos - text));
		printf("剩下的内容：%s\n", pos);
	} else {
		printf("没找到\n");
	}

	return 0;
}
