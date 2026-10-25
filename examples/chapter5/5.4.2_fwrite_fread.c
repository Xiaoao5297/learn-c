/*
 * 教程来源：chapter5/sections/5.4 文件定位与二进制.md
 * 示例编号：5.4.2
 * 所在小节：5.4.3 fwrite 和 fread：整块读写
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.4.2_fwrite_fread.c -o demo
 *
 * 预期输出：
 *   (1, 2)
 *   (3, 4)
 *   (5, 6)
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.4.2 fwrite_fread.c
#include <stdio.h>

struct point {
	int x;
	int y;
};

int main(void)
{
	struct point points[3] = {
		{1, 2},
		{3, 4},
		{5, 6},
	};

	FILE *fp = fopen("points.bin", "wb");
	if (fp == NULL) {
		printf("写入打开失败\n");
		return 1;
	}

	size_t written = fwrite(points, sizeof(struct point), 3, fp);
	if (written != 3) {
		printf("写入不完整，只写了 %zu 个\n", written);
		fclose(fp);
		return 1;
	}
	fclose(fp);

	struct point loaded[3];
	fp = fopen("points.bin", "rb");
	if (fp == NULL) {
		printf("读取打开失败\n");
		return 1;
	}

	size_t read = fread(loaded, sizeof(struct point), 3, fp);
	if (read != 3) {
		printf("读取不完整，只读了 %zu 个\n", read);
		fclose(fp);
		return 1;
	}
	fclose(fp);

	for (int i = 0; i < 3; i++) {
		printf("(%d, %d)\n", loaded[i].x, loaded[i].y);
	}

	return 0;
}
