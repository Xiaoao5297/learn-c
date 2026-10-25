/*
 * 教程来源：chapter3/sections/3.1 数组.md
 * 示例编号：3.1.10
 * 所在小节：3.1.10 判断回文
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.1.10_array_palindrome.c -o demo
 *
 * 预期输出：
 *   是回文
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.1.10 array_palindrome.c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int nums[5] = {1, 2, 3, 2, 1};
	bool is_palindrome = true;

	for (int i = 0; i < 5 / 2; i++) {
		if (nums[i] != nums[5 - 1 - i]) {
			is_palindrome = false;
			break;
		}
	}

	if (is_palindrome) {
		printf("是回文\n");
	} else {
		printf("不是回文\n");
	}

	return 0;
}
