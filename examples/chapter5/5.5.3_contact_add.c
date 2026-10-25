/*
 * 教程来源：chapter5/sections/5.5 综合项目：通讯录存盘.md
 * 示例编号：5.5.3
 * 所在小节：5.5.7 添加联系人：一个能交互的小工具
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.5.3_contact_add.c -o demo
 *
 * 预期输出：
 *   没有数据文件，先放入 2 个初始联系人
 *   请输入新联系人的姓名：请输入新联系人的电话：已保存，通讯录现在有 3 个联系人：
 *   xiaoming：13800000001
 *   xiaohong：13800000002
 *   laowang：13900000009
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.5.3 contact_add.c
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define DATA_FILE "contacts_add.txt"

struct contact {
	char name[30];
	char phone[20];
};

int save_contacts(const struct contact list[], int count)
{
	FILE *fp = fopen(DATA_FILE, "w");
	if (fp == NULL) {
		return -1;
	}

	fprintf(fp, "%d\n", count);
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %s\n", list[i].name, list[i].phone);
	}

	fclose(fp);
	return 0;
}

int load_contacts(struct contact list[], int max)
{
	FILE *fp = fopen(DATA_FILE, "r");
	if (fp == NULL) {
		return -1;
	}

	int count = 0;
	if (fscanf(fp, "%d", &count) != 1 || count < 0 || count > max) {
		fclose(fp);
		return -1;
	}

	for (int i = 0; i < count; i++) {
		if (fscanf(fp, "%29s %19s", list[i].name, list[i].phone) != 2) {
			fclose(fp);
			return -1;
		}
	}

	fclose(fp);
	return count;
}

int main(void)
{
	struct contact book[MAX_CONTACTS];
	int count = load_contacts(book, MAX_CONTACTS);

	if (count < 0) {
		printf("没有数据文件，先放入 2 个初始联系人\n");
		strcpy(book[0].name, "xiaoming");
		strcpy(book[0].phone, "13800000001");
		strcpy(book[1].name, "xiaohong");
		strcpy(book[1].phone, "13800000002");
		count = 2;
	} else {
		printf("已读入 %d 个联系人\n", count);
	}

	if (count >= MAX_CONTACTS) {
		printf("通讯录已满，不能添加\n");
		return 1;
	}

	char name[30];
	char phone[20];

	printf("请输入新联系人的姓名：");
	if (scanf("%29s", name) != 1) {
		printf("姓名读取失败\n");
		return 0;
	}

	printf("请输入新联系人的电话：");
	if (scanf("%19s", phone) != 1) {
		printf("电话读取失败\n");
		return 0;
	}

	strcpy(book[count].name, name);
	strcpy(book[count].phone, phone);
	count++;

	if (save_contacts(book, count) != 0) {
		printf("保存失败\n");
		return 1;
	}

	printf("已保存，通讯录现在有 %d 个联系人：\n", count);
	for (int i = 0; i < count; i++) {
		printf("%s：%s\n", book[i].name, book[i].phone);
	}

	return 0;
}
