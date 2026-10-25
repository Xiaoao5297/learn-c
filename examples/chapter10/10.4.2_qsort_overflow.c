/*
 * 教程来源：chapter10/sections/10.4 qsort 与比较器.md
 * 示例编号：10.4.2
 * 所在小节：10.4.2 比较器：三条约定
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.4.2_qsort_overflow.c -o demo
 *
 * 预期输出：
 *   INT_MAX = 2147483647，INT_MIN = -2147483648
 *   直接相减会溢出：2147483647 - -2147483648 的结果用 long long 算是 4294967295
 *   真正的差远超 int 范围，返回值符号可能错乱
 *   (big > small) - (big < small) = 1
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.4.2 qsort_overflow.c
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int big = INT_MAX;
	int small = INT_MIN;

	printf("INT_MAX = %d，INT_MIN = %d\n", big, small);
	printf("直接相减会溢出：%d - %d 的结果用 long long 算是 %lld\n",
	       big, small, (long long)big - (long long)small);
	printf("真正的差远超 int 范围，返回值符号可能错乱\n");
	printf("(big > small) - (big < small) = %d\n",
	       (big > small) - (big < small));

	return 0;
}
