/*
 * 教程来源：chapter10/sections/10.5 毕业项目：通讯录.md
 * 示例编号：10.5.5
 * 所在小节：10.5.6 完整版：毕业项目
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.5.5_contact_full.c -o demo
 *
 * 预期输出：
 *   没有可用数据文件，从空通讯录开始
 *   
 *   ====== 我的通讯录 ======
 *   1. 添加联系人
 *   2. 显示全部
 *   3. 按姓名查找
 *   4. 按姓名排序
 *   5. 删除联系人
 *   6. 保存到文件
 *   7. 从文件读取
 *   0. 退出
 *   请选择：请输入姓名：请输入电话：已添加：xiaoming（13800000001）
 *   
 *   ====== 我的通讯录 ======
 *   1. 添加联系人
 *   2. 显示全部
 *   3. 按姓名查找
 *   4. 按姓名排序
 *   5. 删除联系人
 *   6. 保存到文件
 *   7. 从文件读取
 *   0. 退出
 *   请选择：请输入姓名：请输入电话：已添加：carol（13800000003）
 *   
 *   ====== 我的通讯录 ======
 *   1. 添加联系人
 *   2. 显示全部
 *   3. 按姓名查找
 *   4. 按姓名排序
 *   5. 删除联系人
 *   6. 保存到文件
 *   7. 从文件读取
 *   0. 退出
 *   请选择：请输入姓名：请输入电话：已添加：alice（13800000001）
 *   
 *   ====== 我的通讯录 ======
 *   1. 添加联系人
 *   2. 显示全部
 *   3. 按姓名查找
 *   4. 按姓名排序
 *   5. 删除联系人
 *   6. 保存到文件
 *   7. 从文件读取
 *   0. 退出
 *   请选择：共 3 人：
 *   1. xiaoming 13800000001
 *   2. carol 13800000003
 *   3. alice 13800000001
 *   
 *   ====== 我的通讯录 ======
 *   1. 添加联系人
 *   2. 显示全部
 *   3. 按姓名查找
 *   4. 按姓名排序
 *   5. 删除联系人
 *   6. 保存到文件
 *   7. 从文件读取
 *   0. 退出
 *   请选择：已按姓名排序
 *   共 3 人：
 *   1. alice 13800000001
 *   2. carol 13800000003
 *   3. xiaoming 13800000001
 *   
 *   ====== 我的通讯录 ======
 *   1. 添加联系人
 *   2. 显示全部
 *   3. 按姓名查找
 *   4. 按姓名排序
 *   5. 删除联系人
 *   6. 保存到文件
 *   7. 从文件读取
 *   0. 退出
 *   请选择：已自动保存 3 人，再见
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.5.5 contact_full.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 30
#define PHONE_LEN 20
#define DATA_FILE "contacts_book.txt"

struct contact {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
};

struct contact book[MAX_CONTACTS];
int count = 0;

/* ---------- 基础功能 ---------- */

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
		printf("通讯录已满，不能再添加\n");
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

void menu_search(void)
{
	char key[NAME_LEN];

	printf("要找谁：");
	if (scanf("%29s", key) != 1) {
		printf("读取失败\n");
		return;
	}

	for (int i = 0; i < count; i++) {
		if (strcmp(book[i].name, key) == 0) {
			printf("找到：%s（%s）\n",
			       book[i].name, book[i].phone);
			return;
		}
	}

	printf("没有找到 %s\n", key);
}

void menu_delete(void)
{
	char key[NAME_LEN];

	printf("要删谁：");
	if (scanf("%29s", key) != 1) {
		printf("读取失败\n");
		return;
	}

	for (int i = 0; i < count; i++) {
		if (strcmp(book[i].name, key) == 0) {
			for (int j = i; j < count - 1; j++) {
				book[j] = book[j + 1];
			}
			count--;
			printf("已删除 %s\n", key);
			return;
		}
	}

	printf("没有找到 %s\n", key);
}

/* ---------- qsort 比较器（10.4） ---------- */

int compare_by_name(const void *a, const void *b)
{
	const struct contact *ca = (const struct contact *)a;
	const struct contact *cb = (const struct contact *)b;

	return strcmp(ca->name, cb->name);
}

void menu_sort(void)
{
	qsort(book, (size_t)count, sizeof(struct contact), compare_by_name);
	printf("已按姓名排序\n");
	list_contacts();
}

/* ---------- 存盘与读盘（第 5 章） ---------- */

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

void menu_save(void)
{
	if (save_contacts() != 0) {
		printf("保存失败，请检查磁盘和权限\n");
		return;
	}
	printf("已保存 %d 人到 %s\n", count, DATA_FILE);
}

void menu_load(void)
{
	if (load_contacts() != 0) {
		printf("加载失败（文件不存在或内容不合法）\n");
		return;
	}
	printf("已从 %s 读入 %d 人\n", DATA_FILE, count);
	list_contacts();
}

/* ---------- 菜单主循环 ---------- */

void show_menu(void)
{
	printf("\n====== 我的通讯录 ======\n");
	printf("1. 添加联系人\n");
	printf("2. 显示全部\n");
	printf("3. 按姓名查找\n");
	printf("4. 按姓名排序\n");
	printf("5. 删除联系人\n");
	printf("6. 保存到文件\n");
	printf("7. 从文件读取\n");
	printf("0. 退出\n");
}

int read_choice(void)
{
	int choice = -1;

	if (scanf("%d", &choice) != 1) {
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF) {
		}
		return -1;
	}

	return choice;
}

int main(void)
{
	void (*actions[])(void) = {
		menu_add,     /* 1 */
		list_contacts,/* 2 */
		menu_search,  /* 3 */
		menu_sort,    /* 4 */
		menu_delete,  /* 5 */
		menu_save,    /* 6 */
		menu_load,    /* 7 */
	};

	int saved = load_contacts();
	if (saved == 0) {
		printf("已从 %s 读入 %d 人\n", DATA_FILE, count);
	} else {
		printf("没有可用数据文件，从空通讯录开始\n");
	}

	int running = 1;

	while (running) {
		show_menu();
		printf("请选择：");

		int choice = read_choice();
		if (choice == 0) {
			if (save_contacts() != 0) {
				printf("退出前保存失败，数据可能丢失\n");
			} else {
				printf("已自动保存 %d 人，再见\n", count);
			}
			running = 0;
		} else if (choice >= 1 && choice <= 7) {
			actions[choice - 1]();
		} else {
			printf("没有这个选项，请输入 0 到 7\n");
		}
	}

	return 0;
}
