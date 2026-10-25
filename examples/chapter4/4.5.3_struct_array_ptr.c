/*
 * 教程来源：chapter4/sections/4.5 结构体与指针.md
 * 示例编号：4.5.3
 * 所在小节：4.5.3 用指针遍历结构体数组
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 4.5.3_struct_array_ptr.c -o demo
 *
 * 预期输出：
 *   小明 18 岁
 *   小红 17 岁
 *   小刚 18 岁
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 4.5.3 struct_array_ptr.c
#include <stdio.h>

struct student {
	char name[20];
	int age;
};

int main(void)
{
	struct student students[3] = {
		{"小明", 18},
		{"小红", 17},
		{"小刚", 18}
	};

	for (struct student *p = students; p < students + 3; p++) {
		printf("%s %d 岁\n", p->name, p->age);
	}

	return 0;
}
