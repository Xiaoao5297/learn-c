/*
 * 教程来源：chapter9/sections/9.2 队列.md
 * 示例编号：9.2.2
 * 所在小节：9.2.5 应用：模拟打印队列
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 9.2.2_print_queue.c -o demo
 *
 * 预期输出：
 *   提交任务 101，排队中（共 1 个）
 *   提交任务 202，排队中（共 2 个）
 *   提交任务 303，排队中（共 3 个）
 *   --- 开始打印 ---
 *   打印任务 101，剩余 2 个
 *   打印任务 202，剩余 1 个
 *   打印任务 303，剩余 0 个
 *   全部打印完成
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 9.2.2 print_queue.c
#include <stdio.h>
#include <stdbool.h>

#define MAX 8

struct queue {
	int task[MAX];    /* 打印任务的编号 */
	int head;
	int tail;
	int size;
};

void init(struct queue *q)
{
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}

bool enqueue(struct queue *q, int task_id)
{
	if (q->size == MAX) {
		return false;
	}
	q->task[q->tail] = task_id;
	q->tail = (q->tail + 1) % MAX;
	q->size++;
	return true;
}

bool dequeue(struct queue *q, int *task_id)
{
	if (q->size == 0) {
		return false;
	}
	*task_id = q->task[q->head];
	q->head = (q->head + 1) % MAX;
	q->size--;
	return true;
}

int main(void)
{
	struct queue q;

	init(&q);

	int new_tasks[] = {101, 202, 303};
	for (int i = 0; i < 3; i++) {
		enqueue(&q, new_tasks[i]);
		printf("提交任务 %d，排队中（共 %d 个）\n",
		       new_tasks[i], q.size);
	}

	printf("--- 开始打印 ---\n");

	int task_id;
	while (dequeue(&q, &task_id)) {
		printf("打印任务 %d，剩余 %d 个\n", task_id, q.size);
	}

	printf("全部打印完成\n");

	return 0;
}
