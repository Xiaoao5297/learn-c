/*
 * 教程来源：chapter10/sections/10.5 毕业项目：通讯录.md
 * 示例编号：10.5.3
 * 所在小节：10.5.4 里程碑三：存盘与读盘
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.5.3_contact_milestone3.c -o demo
 *
 * 预期输出：
 *   已保存 2 人到 contacts_book.txt
 *   清空内存，count = 0
 *   已从 contacts_book.txt 读回 2 人
 *   共 2 人：
 *   1. xiaoming 13800000001
 *   2. xiaohong 13800000002
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.5.3 contact_milestone3.c
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 5
#define NAME_LEN 30
#define PHONE_LEN 20
#define DATA_FILE "contacts_book.txt"

struct contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
};

struct contact book[MAX_CONTACTS];
int count = 0;

int save_contacts(void)
{
	FILE *fp = fopen(DATA_FILE, "w");

	if (fp == NULL) {
		return -1;
	}

	fprintf(fp, "%d\n", count);
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %s\n", book[i].name, book[i].phone);
	}

	fclose(fp);
	return 0;
}

int load_contacts(void)
{
	FILE *fp = fopen(DATA_FILE, "r");

	if (fp == NULL) {
		return -1;
	}

	int loaded = 0;
	if (fscanf(fp, "%d", &loaded) != 1 || loaded < 0 ||
	    loaded > MAX_CONTACTS) {
		fclose(fp);
		return -1;
	}

	for (int i = 0; i < loaded; i++) {
		if (fscanf(fp, "%29s %19s",
			   book[i].name, book[i].phone) != 2) {
			fclose(fp);
			return -1;
		}
	}

	fclose(fp);
	count = loaded;
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
	book[0] = (struct contact){"xiaoming", "13800000001"};
	book[1] = (struct contact){"xiaohong", "13800000002"};
	count = 2;

	if (save_contacts() != 0) {
		printf("保存失败\n");
		return 1;
	}
	printf("已保存 %d 人到 %s\n", count, DATA_FILE);

	count = 0;
	printf("清空内存，count = %d\n", count);

	if (load_contacts() != 0) {
		printf("加载失败\n");
		return 1;
	}
	printf("已从 %s 读回 %d 人\n", DATA_FILE, count);
	list_contacts();

	return 0;
}
