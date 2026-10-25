/*
 * 教程来源：chapter5/sections/5.5 综合项目：通讯录存盘.md
 * 示例编号：5.5.1
 * 所在小节：5.5.2 保存与加载的完整实现
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 5.5.1_contact_save_load.c -o demo
 *
 * 预期输出：
 *   已保存 3 个联系人
 *   从文件读回 3 个联系人：
 *   xiaoming：13800000001
 *   xiaohong：13800000002
 *   xiaogang：13800000003
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 5.5.1 contact_save_load.c
#include <stdio.h>

#define MAX_CONTACTS 100
#define DATA_FILE "contacts.txt"

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
	struct contact book[MAX_CONTACTS] = {
		{"xiaoming", "13800000001"},
		{"xiaohong", "13800000002"},
		{"xiaogang", "13800000003"},
	};
	int count = 3;

	if (save_contacts(book, count) != 0) {
		printf("保存失败\n");
		return 1;
	}
	printf("已保存 %d 个联系人\n", count);

	struct contact loaded[MAX_CONTACTS];
	int loaded_count = load_contacts(loaded, MAX_CONTACTS);
	if (loaded_count < 0) {
		printf("加载失败\n");
		return 1;
	}

	printf("从文件读回 %d 个联系人：\n", loaded_count);
	for (int i = 0; i < loaded_count; i++) {
		printf("%s：%s\n", loaded[i].name, loaded[i].phone);
	}

	return 0;
}
