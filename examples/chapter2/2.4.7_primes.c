/*
 * 教程来源：chapter2/sections/2.4 循环控制.md
 * 示例编号：2.4.7
 * 所在小节：2.4.6 综合示例：找出素数
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.4.7_primes.c -o demo
 *
 * 预期输出：
 *   2 3 5 7 11 13 17 19 23 29
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.4.7 primes.c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	for (int n = 2; n <= 30; n++) {
		bool is_prime = true;

		for (int d = 2; d * d <= n; d++) {
			if (n % d == 0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime) {
			printf("%d ", n);
		}
	}

	printf("\n");

	return 0;
}
