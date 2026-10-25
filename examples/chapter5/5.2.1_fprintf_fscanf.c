/*
 * 教程来源：chapter5/sections/5.2 读写文件.md
 * 示例编号：5.2.1
 * 所在小节：5.2.1 fprintf 和 fscanf：带格式的读写
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.2.1_fprintf_fscanf.c -o demo
 *
 * 预期输出：
 *   语文：92
 *   数学：85
 *   总分：177
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.2.1 fprintf_fscanf.c
#include <stdio.h>

int main(void)
{
	int chinese = 0;
	int math = 0;

	FILE *fp = fopen("scores.txt", "w");
	if (fp == NULL) {
		printf("写入打开失败\n");
		return 1;
	}
	fprintf(fp, "%d %d\n", 92, 85);
	fclose(fp);

	fp = fopen("scores.txt", "r");
	if (fp == NULL) {
		printf("读取打开失败\n");
		return 1;
	}
	if (fscanf(fp, "%d %d", &chinese, &math) != 2) {
		printf("文件格式不对，读不到两个整数\n");
		fclose(fp);
		return 1;
	}
	fclose(fp);

	printf("语文：%d\n", chinese);
	printf("数学：%d\n", math);
	printf("总分：%d\n", chinese + math);

	return 0;
}
