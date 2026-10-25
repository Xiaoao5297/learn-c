/*
 * 教程来源：chapter9/sections/9.1 栈.md
 * 示例编号：9.1.2
 * 所在小节：9.1.3 慢镜头：top 怎么走
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.1.2_stack_trace.c -o demo
 *
 * 预期输出：
 *   压入 10，top 变成 0
 *   压入 20，top 变成 1
 *   压入 30，top 变成 2
 *   栈满，40 压不进
 *   弹出 30，top 变成 1
 *   弹出 20，top 变成 0
 *   弹出 10，top 变成 -1
 *   栈空，弹不出
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.1.2 stack_trace.c
#include <stdio.h>
#include <stdbool.h>

#define MAX 3

struct stack {
	int data[MAX];
	int top;
};

void init(struct stack *s)
{
	s->top = -1;
}

bool push(struct stack *s, int value)
{
	if (s->top == MAX - 1) {
		printf("栈满，%d 压不进\n", value);
		return false;
	}
	s->top++;
	s->data[s->top] = value;
	printf("压入 %d，top 变成 %d\n", value, s->top);
	return true;
}

bool pop(struct stack *s, int *value)
{
	if (s->top == -1) {
		printf("栈空，弹不出\n");
		return false;
	}
	*value = s->data[s->top];
	s->top--;
	printf("弹出 %d，top 变成 %d\n", *value, s->top);
	return true;
}

int main(void)
{
	struct stack s;

	init(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40);

	int value;
	while (pop(&s, &value)) {
	}

	return 0;
}
