/*
 * 教程来源：chapter10/sections/10.5 毕业项目：通讯录.md
 * 示例编号：10.5.4
 * 所在小节：10.5.5 里程碑四：函数指针数组分发菜单
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.5.4_contact_menu_demo.c -o demo
 *
 * 预期输出：
 *   ====== 我的通讯录 ======
 *   1. 添加联系人
 *   2. 显示全部
 *   0. 退出
 *   请输入姓名：请输入电话：已添加：xiaoming（13800000001）
 *   共 1 人：
 *   1. xiaoming 13800000001
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.5.4 contact_menu_demo.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 3
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

void menu_add(void)
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

void menu_list(void)
{
	list_contacts();
}

int main(void)
{
	void (*actions[])(void) = {menu_add, menu_list};

	printf("====== 我的通讯录 ======\n");
	printf("1. 添加联系人\n");
	printf("2. 显示全部\n");
	printf("0. 退出\n");

	int choice = 1;
	if (choice >= 1 && choice <= 2) {
		actions[choice - 1]();
	}

	choice = 2;
	if (choice >= 1 && choice <= 2) {
		actions[choice - 1]();
	}

	return 0;
}
