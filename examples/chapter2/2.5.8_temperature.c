/*
 * 教程来源：chapter2/sections/2.5 函数基础.md
 * 示例编号：2.5.8
 * 所在小节：温度转换
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 2.5.8_temperature.c -o demo
 *
 * 预期输出：
 *   25.0 摄氏度 = 77.0 华氏度
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 2.5.8 temperature.c
#include <stdio.h>

double celsius_to_fahrenheit(double celsius)
{
	return celsius * 9.0 / 5.0 + 32.0;
}

int main(void)
{
	double c = 25.0;

	printf("%.1f 摄氏度 = %.1f 华氏度\n",
	       c, celsius_to_fahrenheit(c));

	return 0;
}
