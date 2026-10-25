/*
 * 教程来源：chapter1/sections/1.5 scanf 与输入.md
 * 示例编号：1.5.2
 * 所在小节：1.5.2 必须检查 scanf 的返回值
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.5.2_scan_check.c -o demo
 *
 * 预期输出：
 *   请输入年龄：明年你 21 岁
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.5.2 scan_check.c
#include <stdio.h>

int main(void)
{
	int age = 0;

	printf("请输入年龄：");
	if (scanf("%d", &age) != 1) {
		printf("这不是一个整数\n");
		return 1;
	}

	if (age < 0 || age > 150) {
		printf("年龄应该在 0 到 150 之间\n");
		return 1;
	}

	printf("明年你 %d 岁\n", age + 1);

	return 0;
}
