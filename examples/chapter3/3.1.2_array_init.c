/*
 * 教程来源：chapter3/sections/3.1 数组.md
 * 示例编号：3.1.2
 * 所在小节：3.1.2 声明和初始化数组
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 3.1.2_array_init.c -o demo
 *
 * 预期输出：
 *   scores[0] = 95
 *   partial[2] = 0
 *   zeros[4] = 0
 *   auto_size 有 3 个元素
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 3.1.2 array_init.c
#include <stdio.h>

int main(void)
{
	int scores[5] = {95, 88, 72, 100, 60};
	int partial[5] = {1, 2};
	int zeros[5] = {0};
	int auto_size[] = {10, 20, 30};

	printf("scores[0] = %d\n", scores[0]);
	printf("partial[2] = %d\n", partial[2]);
	printf("zeros[4] = %d\n", zeros[4]);
	printf("auto_size 有 %zu 个元素\n",
	       sizeof(auto_size) / sizeof(auto_size[0]));

	return 0;
}
