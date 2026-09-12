# 复习 第2节：命名规范 —— 给物品贴对标签

> 💬 **节前语：**
>
> 看这两段代码，哪段好懂？
>
> ```c
> // A：这是什么？
> int a = 18;
> char b[20] = "小明";
> double d = 3.14159;
> int f = 1;
> ```
>
> ```c
> // B：一目了然
> int age = 18;
> char name[20] = "小明";
> double pi = 3.14159;
> int is_logged_in = 1;
> ```
>
> **B！** 这就是好名字的力量——代码自己"会说话"。
>
> 这一节讲C语言的命名规范。没有新语法，只有"贴标签"的智慧。

---

## 一、C语言命名五大原则

### 原则1：见名知意

| ❌ 坏名字 | ✅ 好名字 | 原因 |
|-----------|-----------|------|
| `n` | `student_count` | 什么的数量？ |
| `tmp` | `temp_result` | 临时什么？ |
| `data` | `user_info` | 太笼统 |
| `cal` | `calculate_average` | 算什么东西？ |

### 原则2：使用下划线命名（snake_case）

C语言的主流风格是**小写字母 + 下划线**：

| 风格 | 例子 | C推荐？ |
|------|------|----------|
| 下划线 | `student_count`、`total_score` | ✅ 主流风格 |
| 驼峰 | `studentCount` | ⚠️ 也可以（很多C程序员用） |
| 全大写 | `STUDENTCOUNT` | ❌ 只用于常量和宏 |

```c
// ✅ C 风格变量
int student_count = 0;
double average_score = 0.0;

// ✅ 常量 / 宏：全大写
#define MAX_STUDENTS 100
const double PI = 3.14159;
```

> 📌 **特例：结构体类型名（typedef后）用"大驼峰"，首字母大写：**
> ```c
> typedef struct { ... } Student;    // 类型名大写开头
> Student stu1;                       // 变量名小写下划线
> ```

### 原则3：布尔值用 is / has / can 开头

（C里用 `int` 0/1，或引入 `<stdbool.h>` 用 `bool`）

| ❌ 坏名字 | ✅ 好名字 | 读起来像一句话 |
|-----------|-----------|---------------|
| `login` | `is_logged_in` | "是否已登录？" |
| `key` | `has_key` | "有钥匙吗？" |
| `swim` | `can_swim` | "会游泳吗？" |

```c
int is_adult = 1;        // 是否成年
int has_error = 0;       // 是否有错误
int can_enter = 1;       // 能否进入
```

### 原则4：指针变量加 `p` 前缀（可选但常见）

C程序员常给指针名加个 `p`，让人一眼看出"这是地址"：

| 写法 | 含义 |
|------|------|
| `int *p_num` | 指向 num 的指针 |
| `Student *p_stu` | 指向学生的指针 |
| `int *pa, *pb` | 用 a/b 区分 |

> 💡 不强求，但看到 `*p`、`p->age` 时真的不容易混淆。

### 原则5：避免无意义缩写

| ❌ 坏名字 | ✅ 好名字 | 说明 |
|-----------|-----------|------|
| `usr` | `user` | 没必要缩写 |
| `msg` | `message` | 拼完整 |
| `calc` | `calculate` | 拼完整 |

**可以接受的常见缩写：**
- `id`（标识符）、`num`/`count`（数量）、`str`（字符串）
- `tmp`（临时）、`max`/`min`、`avg`（平均）

---

## 二、函数怎么起名？

**函数是做动作的，名字用动词开头**，一眼看懂"它在干嘛"：

| ❌ 坏名字 | ✅ 好名字 |
|-----------|-----------|
| `data()` | `load_data()` / `save_data()` |
| `a()` | `calculate_average()` |
| `f()` | `find_max()` |
| `show()` | `print_report()` |

```c
int count_pass(int arr[], int n);     // 数及格人数
double calculate_average(int a[], int n);
void print_all(Student arr[], int n);
int find_max(int arr[], int n);
```

> 📌 **读函数名就像读一句话：** `print_all` = "打印所有"，`count_pass` = "数及格"。

---

## 三、练习题

### 练习2：给变量起个好名字

以下代码功能正确，但变量名很差，请重新命名：

```c
#include <stdio.h>
#include <string.h>

int main() {
    char n[20] = "小明";
    int a = 18;
    double s[4] = {85.5, 92.0, 78.5, 96.0};
    int sm = 0;
    int i;
    for (i = 0; i < 4; i++) {
        sm = sm + s[i];
    }
    double av = sm / 4.0;
    int p = 1;      // 表示是否及格
    if (av >= 60) p = 1; else p = 0;
    printf("姓名:%s 年龄:%d 平均:%f 及格:%d\n", n, a, av, p);
    return 0;
}
```

### 练习3：布尔值命名

以下布尔变量（用 int 表示）名字不够清晰，请改写：

```c
int access = 1;       // 表示用户是否有权限
int file = 0;         // 表示文件是否存在
int refresh = 1;      // 表示是否需要刷新
int ok = 1;           // 表示输入是否合法
```

### 练习4：给函数起好名字

以下函数名不够清晰，请重新命名：

```c
int calc(int a[], int n);      // 功能：返回数组和
int get(int a, int b);         // 功能：返回较大的数
void out(Student s);           // 功能：打印一个学生的信息
int chk(int score);            // 功能：score>=60 返回1，否则0
```

---

<details>
<summary>🔑 练习2 参考答案</summary>

```c
#include <stdio.h>
#include <string.h>

int main() {
    char name[20] = "小明";           // n → name
    int age = 18;                     // a → age
    double scores[4] = {85.5, 92.0, 78.5, 96.0};   // s → scores

    double sum = 0;                   // sm → sum
    for (int i = 0; i < 4; i++) {
        sum += scores[i];
    }
    double average = sum / 4.0;       // av → average

    int is_passed = average >= 60;    // p → is_passed（布尔命名）
    printf("姓名:%s 年龄:%d 平均:%.1f 及格:%d\n",
           name, age, average, is_passed);
    return 0;
}
```
</details>

<details>
<summary>🔑 练习3 参考答案</summary>

```c
int has_permission = 1;      // access → has_permission
int file_exists = 0;         // file → file_exists
int needs_refresh = 1;       // refresh → needs_refresh
int is_valid = 1;            // ok → is_valid
```
</details>

<details>
<summary>🔑 练习4 参考答案</summary>

```c
int sum_array(int a[], int n);        // calc → sum_array
int max(int a, int b);                // get → max
void print_student(Student s);        // out → print_student
int is_passed(int score);             // chk → is_passed
```
</details>

---

> 🎓 **第2节完成！** 好名字 = 代码自带说明书。
>
> [下一节：3. 代码组织方法 →](3_code_organization.md)　｜　[← 返回目录](README.md)
