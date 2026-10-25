/*
 * 教程来源：chapter9/sections/9.1 栈.md
 * 示例编号：9.1.1
 * 所在小节：9.1.2 用数组实现栈
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.1.1_stack_basic.c -o demo
 *
 * 预期输出：
 *   压入了 10 20 30 40
 *   弹出：40
 *   看一眼栈顶：30
 *   弹出：30
 *   弹出：20
 *   弹出：10
 *   栈已经空了
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.1.1 stack_basic.c
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

struct stack {
	int data[MAX];    /* 存数据的数组 */
	int top;          /* 栈顶下标，空栈时为 -1 */
};

void init(struct stack *s)
{
	s->top = -1;
}

bool is_empty(const struct stack *s)
{
	return s->top == -1;
}

bool is_full(const struct stack *s)
{
	return s->top == MAX - 1;
}

bool push(struct stack *s, int value)
{
	if (is_full(s)) {
		return false;    /* 满了压不进，报告失败 */
	}
	s->top++;
	s->data[s->top] = value;
	return true;
}

bool pop(struct stack *s, int *value)
{
	if (is_empty(s)) {
		return false;    /* 空栈弹不出 */
	}
	*value = s->data[s->top];
	s->top--;
	return true;
}

int main(void)
{
	struct stack s;

	init(&s);

	for (int i = 10; i <= 40; i += 10) {
		push(&s, i);
	}
	printf("压入了 10 20 30 40\n");

	int value;
	pop(&s, &value);
	printf("弹出：%d\n", value);

	printf("看一眼栈顶：%d\n", s.data[s.top]);

	while (pop(&s, &value)) {
		printf("弹出：%d\n", value);
	}

	if (is_empty(&s)) {
		printf("栈已经空了\n");
	}

	return 0;
}
