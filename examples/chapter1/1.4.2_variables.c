/*
 * 教程来源：chapter1/sections/1.4 变量与数据类型.md
 * 示例编号：1.4.2
 * 所在小节：1.4.2 声明、赋值和初始化
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 1.4.2_variables.c -o demo
 *
 * 预期输出：
 *   score = 95
 *   age = 21
 *   pi = 3.141590
 *   grade = A
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 1.4.2 variables.c
#include <stdio.h>

int main(void)
{
	int score;
	int age = 20;
	double pi = 3.14159;
	char grade = 'A';

	score = 95;
	age = age + 1;

	printf("score = %d\n", score);
	printf("age = %d\n", age);
	printf("pi = %f\n", pi);
	printf("grade = %c\n", grade);

	return 0;
}
