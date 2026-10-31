/*
 * 教程来源：chapter3/sections/3.3 字符串基础.md
 * 示例编号：3.3.4
 * 所在小节：3.3.4 scanf 读字符串：必须限宽
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.3.4_scanf_width.c -o demo
 *
 * 预期输出：
 *   请输入你的名字（一个单词）：
 *   你好，张三！
 *   长度是 6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.3.4 scanf_width.c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char name[20];

	printf("请输入你的名字（一个单词）：\n");
	if (scanf("%19s", name) != 1) {
		printf("读取失败\n");
		return 1;
	}

	printf("你好，%s！\n", name);
	printf("长度是 %zu\n", strlen(name));

	return 0;
}
