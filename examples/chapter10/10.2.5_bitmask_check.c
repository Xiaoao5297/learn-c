/*
 * 教程来源：chapter10/sections/10.2 位运算.md
 * 示例编号：10.2.5
 * 所在小节：10.2.4 掩码：一个 int 管 32 个开关
 * 编译运行：cc -std=c11 -Wall -Wextra -pedantic 10.2.5_bitmask_check.c -o demo
 *
 * 预期输出：
 *   user = 5
 *   订阅邮件：是
 *   绑定手机：否
 *   VIP 会员：是
 *   绑定手机后 user = 7
 *
 * 本文件由 scripts/extract_examples.py 自动生成。
 * 如需修改，请改教程原文后重新生成。
 */
// 10.2.5 bitmask_check.c
#include <stdio.h>

#define FLAG_MAIL 1
#define FLAG_PHONE 2
#define FLAG_VIP 4

int main(void)
{
	unsigned int user = FLAG_MAIL | FLAG_VIP;

	printf("user = %u\n", user);

	printf("订阅邮件：%s\n", (user & FLAG_MAIL) ? "是" : "否");
	printf("绑定手机：%s\n", (user & FLAG_PHONE) ? "是" : "否");
	printf("VIP 会员：%s\n", (user & FLAG_VIP) ? "是" : "否");

	user |= FLAG_PHONE;
	printf("绑定手机后 user = %u\n", user);

	return 0;
}
