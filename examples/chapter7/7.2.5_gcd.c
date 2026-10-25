/*
 * 教程来源：chapter7/sections/7.2 调用栈与栈溢出.md
 * 示例编号：7.2.5
 * 所在小节：7.2.5 最大公约数：另一条收敛路径
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 7.2.5_gcd.c -o demo
 *
 * 预期输出：
 *   gcd(48, 18) = 6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 7.2.5 gcd.c
#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(void)
{
	printf("gcd(48, 18) = %d\n", gcd(48, 18));

	return 0;
}
