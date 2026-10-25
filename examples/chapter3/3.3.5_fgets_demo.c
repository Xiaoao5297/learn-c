/*
 * 教程来源：chapter3/sections/3.3 字符串基础.md
 * 示例编号：3.3.5
 * 所在小节：3.3.5 fgets：推荐的读入方式
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.3.5_fgets_demo.c -o demo
 *
 * 预期输出：
 *   请输入一行文字：
 *   读到的内容：hello world
 *   strlen 是 12
 *   末尾是换行符，去掉它
 *   处理后：[hello world]，长度是 11
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.3.5 fgets_demo.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char line[32];

	printf("请输入一行文字：\n");
	if (fgets(line, sizeof(line), stdin) == NULL) {
		printf("读取失败\n");
		return 1;
	}

	printf("读到的内容：%s", line);
	printf("strlen 是 %zu\n", strlen(line));

	if (line[strlen(line) - 1] == '\n') {
		printf("末尾是换行符，去掉它\n");
		line[strlen(line) - 1] = '\0';
	}

	printf("处理后：[%s]，长度是 %zu\n", line, strlen(line));

	return 0;
}
