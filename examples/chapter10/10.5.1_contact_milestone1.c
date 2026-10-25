/*
 * 教程来源：chapter10/sections/10.5 毕业项目：通讯录.md
 * 示例编号：10.5.1
 * 所在小节：10.5.2 里程碑一：添加与显示
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.5.1_contact_milestone1.c -o demo
 *
 * 预期输出：
 *   通讯录是空的
 *   请输入姓名：请输入电话：已添加：xiaoming（13800000001）
 *   请输入姓名：请输入电话：已添加：xiaohong（13800000002）
 *   共 2 人：
 *   1. xiaoming 13800000001
 *   2. xiaohong 13800000002
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.5.1 contact_milestone1.c
#include <stdio.h>
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

int add_contact(void)
{
	if (count >= MAX_CONTACTS) {
		printf("通讯录已满\n");
		return -1;
	}

	printf("请输入姓名：");
	if (scanf("%29s", book[count].name) != 1) {
		printf("姓名读取失败\n");
		return -1;
	}

	printf("请输入电话：");
	if (scanf("%19s", book[count].phone) != 1) {
		printf("电话读取失败\n");
		return -1;
	}

	printf("已添加：%s（%s）\n", book[count].name, book[count].phone);
	count++;
	return 0;
}

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

int main(void)
{
	list_contacts();
	add_contact();
	add_contact();
	list_contacts();

	return 0;
}
