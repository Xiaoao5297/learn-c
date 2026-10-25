/*
 * 教程来源：chapter3/sections/3.1 数组.md
 * 示例编号：3.1.3
 * 所在小节：3.1.3 下标：从 0 开始
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.1.3_array_access.c -o demo
 *
 * 预期输出：
 *   第一个元素：95
 *   第二个元素：90
 *   最后一个元素：60
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.1.3 array_access.c
#include <stdio.h>

int main(void)
{
	int scores[5] = {95, 88, 72, 100, 60};

	scores[1] = 90;

	printf("第一个元素：%d\n", scores[0]);
	printf("第二个元素：%d\n", scores[1]);
	printf("最后一个元素：%d\n", scores[4]);

	return 0;
}
