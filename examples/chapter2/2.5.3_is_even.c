/*
 * 教程来源：chapter2/sections/2.5 函数基础.md
 * 示例编号：2.5.3
 * 所在小节：2.5.3 返回布尔值
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.5.3_is_even.c -o demo
 *
 * 预期输出：
 *   18 是偶数
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.5.3 is_even.c
#include <stdio.h>
#include <stdbool.h>

bool is_even(int number)
{
	return number % 2 == 0;
}

int main(void)
{
	int number = 18;

	if (is_even(number)) {
		printf("%d 是偶数\n", number);
	} else {
		printf("%d 是奇数\n", number);
	}

	return 0;
}
