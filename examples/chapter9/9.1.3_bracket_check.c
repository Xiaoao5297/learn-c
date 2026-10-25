/*
 * 教程来源：chapter9/sections/9.1 栈.md
 * 示例编号：9.1.3
 * 所在小节：9.1.4 应用：括号匹配检查器
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.1.3_bracket_check.c -o demo
 *
 * 预期输出：
 *   (1+2)*[3-{4/5}] ：配对正确
 *   (1+2]           ：配对错误
 *   ([)]            ：配对错误
 *   (1+2))          ：配对错误
 *   ((1+2)          ：配对错误
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.1.3 bracket_check.c
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

struct bracket_stack {
	char data[MAX];
	int top;
};

void init(struct bracket_stack *s)
{
	s->top = -1;
}

bool push(struct bracket_stack *s, char ch)
{
	if (s->top == MAX - 1) {
		return false;
	}
	s->top++;
	s->data[s->top] = ch;
	return true;
}

bool pop(struct bracket_stack *s, char *ch)
{
	if (s->top == -1) {
		return false;
	}
	*ch = s->data[s->top];
	s->top--;
	return true;
}

/* 一对左右括号类型是否配得上 */
bool is_pair(char open, char close)
{
	return (open == '(' && close == ')') ||
	       (open == '[' && close == ']') ||
	       (open == '{' && close == '}');
}

bool is_balanced(const char str[])
{
	struct bracket_stack s;

	init(&s);

	for (int i = 0; str[i] != '\0'; i++) {
		char ch = str[i];

		if (ch == '(' || ch == '[' || ch == '{') {
			push(&s, ch);
		} else if (ch == ')' || ch == ']' || ch == '}') {
			char open;
			if (!pop(&s, &open)) {
				return false;    /* 右括号没人配 */
			}
			if (!is_pair(open, ch)) {
				return false;    /* 类型对不上 */
			}
		}
	}

	return s.top == -1;    /* 左括号全配完才对 */
}

void check(const char str[])
{
	printf("%-16s：%s\n", str,
	       is_balanced(str) ? "配对正确" : "配对错误");
}

int main(void)
{
	check("(1+2)*[3-{4/5}]");
	check("(1+2]");
	check("([)]");
	check("(1+2))");
	check("((1+2)");

	return 0;
}
