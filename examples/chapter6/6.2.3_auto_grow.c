/*
 * 教程来源：chapter6/sections/6.2 内存陷阱.md
 * 示例编号：6.2.3
 * 所在小节：6.2.3 realloc 实战：自动扩容的数组
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 6.2.3_auto_grow.c -o demo
 *
 * 预期输出：
 *   容量不够，已扩容到 4
 *   容量不够，已扩容到 8
 *   最终存了 6 个成绩：
 *   88 92 76 100 54 67
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 6.2.3 auto_grow.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int capacity = 2;    /* 当前容量 */
	int count = 0;       /* 已存个数 */
	int *scores = malloc(capacity * sizeof(int));
	if (scores == NULL) {
		printf("内存分配失败\n");
		return 1;
	}

	int input[] = {88, 92, 76, 100, 54, 67};

	for (int i = 0; i < 6; i++) {
		if (count == capacity) {
			int new_capacity = capacity * 2;
			int *tmp = realloc(scores, new_capacity * sizeof(int));
			if (tmp == NULL) {
				printf("扩容失败\n");
				free(scores);
				return 1;
			}
			scores = tmp;
			capacity = new_capacity;
			printf("容量不够，已扩容到 %d\n", capacity);
		}
		scores[count] = input[i];
		count++;
	}

	printf("最终存了 %d 个成绩：\n", count);
	for (int i = 0; i < count; i++) {
		printf("%d ", scores[i]);
	}
	printf("\n");

	free(scores);
	scores = NULL;

	return 0;
}
