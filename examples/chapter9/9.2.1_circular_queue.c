/*
 * 教程来源：chapter9/sections/9.2 队列.md
 * 示例编号：9.2.1
 * 所在小节：9.2.3 循环队列：让数组首尾相接
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.2.1_circular_queue.c -o demo
 *
 * 预期输出：
 *   入队 1 2 3，size = 3
 *   出队：1
 *   出队：2
 *   又入队 4 5 6，size = 4，tail 绕回了 1
 *   出队：3
 *   出队：4
 *   出队：5
 *   出队：6
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.2.1 circular_queue.c
#include <stdio.h>
#include <stdbool.h>

#define MAX 5

struct queue {
	int data[MAX];
	int head;    /* 队头：下次出队的位置 */
	int tail;    /* 队尾：下次入队的位置 */
	int size;    /* 当前数据个数 */
};

void init(struct queue *q)
{
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}

bool is_empty(const struct queue *q)
{
	return q->size == 0;
}

bool is_full(const struct queue *q)
{
	return q->size == MAX;
}

bool enqueue(struct queue *q, int value)
{
	if (is_full(q)) {
		return false;
	}
	q->data[q->tail] = value;
	q->tail = (q->tail + 1) % MAX;    /* 队尾转圈 */
	q->size++;
	return true;
}

bool dequeue(struct queue *q, int *value)
{
	if (is_empty(q)) {
		return false;
	}
	*value = q->data[q->head];
	q->head = (q->head + 1) % MAX;    /* 队头转圈 */
	q->size--;
	return true;
}

int main(void)
{
	struct queue q;

	init(&q);

	for (int i = 1; i <= 3; i++) {
		enqueue(&q, i);
	}
	printf("入队 1 2 3，size = %d\n", q.size);

	int value;
	dequeue(&q, &value);
	printf("出队：%d\n", value);
	dequeue(&q, &value);
	printf("出队：%d\n", value);

	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);
	printf("又入队 4 5 6，size = %d，tail 绕回了 %d\n", q.size, q.tail);
	while (dequeue(&q, &value)) {
		printf("出队：%d\n", value);
	}

	return 0;
}
