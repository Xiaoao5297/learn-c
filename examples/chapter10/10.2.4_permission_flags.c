/*
 * 教程来源：chapter10/sections/10.2 位运算.md
 * 示例编号：10.2.4
 * 所在小节：10.2.4 掩码：一个 int 管 32 个开关
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.2.4_permission_flags.c -o demo
 *
 * 预期输出：
 *   初始 perm = 3
 *   可以读
 *   可以写
 *   不能执行
 *   打开 EXEC 后 perm = 7
 *   关闭 WRITE 后 perm = 5
 *   切换 READ 后 perm = 4
 *   READ 关了
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.2.4 permission_flags.c
#include <stdio.h>

#define PERM_READ 1
#define PERM_WRITE 2
#define PERM_EXEC 4

int main(void)
{
	unsigned int perm = PERM_READ | PERM_WRITE;

	printf("初始 perm = %u\n", perm);

	if (perm & PERM_READ) {
		printf("可以读\n");
	}
	if (perm & PERM_WRITE) {
		printf("可以写\n");
	}
	if ((perm & PERM_EXEC) == 0) {
		printf("不能执行\n");
	}

	perm |= PERM_EXEC;
	printf("打开 EXEC 后 perm = %u\n", perm);

	perm &= (unsigned int)~PERM_WRITE;
	printf("关闭 WRITE 后 perm = %u\n", perm);

	perm ^= PERM_READ;
	printf("切换 READ 后 perm = %u\n", perm);

	if (perm & PERM_READ) {
		printf("READ 开着\n");
	} else {
		printf("READ 关了\n");
	}

	return 0;
}
