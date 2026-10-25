/*
 * 教程来源：chapter10/sections/10.5 毕业项目：通讯录.md
 * 示例编号：10.5.2
 * 所在小节：10.5.3 里程碑二：查找与排序
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.5.2_contact_milestone2.c -o demo
 *
 * 预期输出：
 *   请输入姓名：请输入电话：已添加：carol（13800000003）
 *   请输入姓名：请输入电话：已添加：alice（13800000001）
 *   请输入姓名：请输入电话：已添加：bob（13800000002）
 *   已按姓名排序
 *   共 3 人：
 *   1. alice 13800000001
 *   2. bob 13800000002
 *   3. carol 13800000003
 *   要找谁：找到：alice（13800000001）
 *   要找谁：找到：bob（13800000002）
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.5.2 contact_milestone2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 5
#define NAME_LEN 30
#define PHONE_LEN 20

struct contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
};

struct contact book[MAX_CONTACTS];
int count = 0;

void list_contacts(void)
{
	if (count == 0) {
		printf("通讯录是空的\n");
		return;
	}

	printf("共 %d 人：\n", count);
	for (int i = 0; i < count; i++) {
		printf("%d. %s %s\n", i + 1, book[i].name, book[i].phone);
	}
}

void add_contact(void)
{
	if (count >= MAX_CONTACTS) {
		printf("通讯录已满\n");
		return;
	}

	printf("请输入姓名：");
	if (scanf("%29s", book[count].name) != 1) {
		printf("姓名读取失败\n");
		return;
	}

	printf("请输入电话：");
	if (scanf("%19s", book[count].phone) != 1) {
		printf("电话读取失败\n");
		return;
	}

	printf("已添加：%s（%s）\n", book[count].name, book[count].phone);
	count++;
}

void search_contact(void)
{
	char key[NAME_LEN];

	printf("要找谁：");
	if (scanf("%29s", key) != 1) {
		printf("读取失败\n");
		return;
	}

	for (int i = 0; i < count; i++) {
		if (strcmp(book[i].name, key) == 0) {
			printf("找到：%s（%s）\n", book[i].name, book[i].phone);
			return;
		}
	}

	printf("没有找到 %s\n", key);
}

int compare_by_name(const void *a, const void *b)
{
	const struct contact *ca = (const struct contact *)a;
	const struct contact *cb = (const struct contact *)b;

	return strcmp(ca->name, cb->name);
}

void sort_contacts(void)
{
	qsort(book, (size_t)count, sizeof(struct contact), compare_by_name);
	printf("已按姓名排序\n");
	list_contacts();
}

int main(void)
{
	add_contact();
	add_contact();
	add_contact();
	sort_contacts();
	search_contact();
	search_contact();

	return 0;
}
