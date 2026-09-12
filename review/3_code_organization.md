# 复习 第3节：代码组织方法 —— 把房间整理整齐

> 💬 **节前语：**
>
> 想象你的房间：
> - 东西全堆在地上 → 找不到东西，走路还绊脚
> - 分类放进柜子、抽屉、架子 → 一目了然
>
> 代码也是如此。一个 100 行的 `main` 就像堆满杂物的房间。
>
> 这一节教你三个"整理房间"的方法：**函数拆分**、**注释分块**、**结构体打包**。全部用前4章的知识，没有新语法。

---

## 方法1：函数拆分（最核心技能）

**拆分前（一个大函数做所有事）：**

```c
#include <stdio.h>

typedef struct {
    char name[20];
    double scores[3];
} Student;

int main() {
    Student students[3] = {
        {"小明", {85.5, 92.0, 78.5}},
        {"小红", {96.0, 88.5, 91.0}},
        {"小刚", {72.0, 65.0, 80.5}}
    };

    // 1. 打印每个学生的平均分（10行）
    printf("各学生平均分：\n");
    for (int i = 0; i < 3; i++) {
        double sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].scores[j];
        }
        printf("%s：%.1f分\n", students[i].name, sum / 3);
    }

    // 2. 打印每门课的平均分（10行）
    printf("\n各科目平均分：\n");
    for (int j = 0; j < 3; j++) {
        double sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += students[i].scores[j];
        }
        printf("第%d科：%.1f分\n", j + 1, sum / 3);
    }

    // 3. 找平均分最高的学生（10行）
    double best_avg = 0;
    int best_index = 0;
    for (int i = 0; i < 3; i++) {
        double sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].scores[j];
        }
        if (sum / 3 > best_avg) {
            best_avg = sum / 3;
            best_index = i;
        }
    }
    printf("\n平均分最高的学生：%s（%.1f分）\n",
           students[best_index].name, best_avg);

    return 0;
}
```

**问题：** 平均分算了3遍（重复代码），main 又长又乱，改一个功能要到处找。

**拆分后（每个功能一个函数，main 像目录一样清晰）：**

```c
#include <stdio.h>

typedef struct {
    char name[20];
    double scores[3];
} Student;

// === 小工具：算一个学生的平均分 ===
double student_average(const Student *s) {
    double sum = 0;
    for (int j = 0; j < 3; j++) {
        sum += s->scores[j];
    }
    return sum / 3;
}

// === 打印每个学生的平均分 ===
void print_all_average(const Student arr[], int n) {
    printf("各学生平均分：\n");
    for (int i = 0; i < n; i++) {
        printf("%s：%.1f分\n", arr[i].name, student_average(&arr[i]));
    }
}

// === 打印每门课的平均分 ===
void print_course_average(const Student arr[], int n) {
    printf("\n各科目平均分：\n");
    for (int j = 0; j < 3; j++) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i].scores[j];
        }
        printf("第%d科：%.1f分\n", j + 1, sum / n);
    }
}

// === 找平均分最高的学生（返回下标） ===
int best_student(const Student arr[], int n) {
    int best = 0;
    double best_avg = student_average(&arr[0]);
    for (int i = 1; i < n; i++) {
        double avg = student_average(&arr[i]);
        if (avg > best_avg) {
            best_avg = avg;
            best = i;
        }
    }
    return best;
}

// === 主程序：清爽的"目录" ===
int main() {
    Student students[3] = {
        {"小明", {85.5, 92.0, 78.5}},
        {"小红", {96.0, 88.5, 91.0}},
        {"小刚", {72.0, 65.0, 80.5}}
    };

    print_all_average(students, 3);
    print_course_average(students, 3);

    int best = best_student(students, 3);
    printf("\n平均分最高的学生：%s（%.1f分）\n",
           students[best].name, student_average(&students[best]));

    return 0;
}
```

> 💡 **看到了吗？** main 现在像**目录**一样，一眼就知道程序做了什么！"算平均分"只写一次，到处复用。

### 📐 函数拆分的黄金法则

| 法则 | 说明 | 比喻 |
|------|------|------|
| **单一职责** | 一个函数只做一件事 | 一个厨师只负责一道菜 |
| **不超过30行** | 超过就考虑拆分 | 一页纸写满了就换下一页 |
| **函数名动词开头** | `print_`、`calculate_`、`load_` | 告诉别人这个函数"做什么" |
| **参数别太多** | 超过3~4个就封装成结构体 | 拿的东西多了，用个袋子装 |

---

## 方法2：用注释分块

当 `main` 要"指挥"几步时，用注释把流程分成段落，像一份"执行计划"：

```c
int main() {
    // ========== 1. 载入数据 ==========
    int count = load_students(students, MAX_STUDENTS);

    // ========== 2. 统计 ==========
    double avg = calculate_average(students, count);

    // ========== 3. 打印报告 ==========
    print_report(students, count, avg);

    return 0;
}
```

> 📌 **注释写"为什么"和"分块"，别写废话。** 下面这种注释没意义：
> ```c
> i = i + 1;   // 把 i 加 1        ← 废话，代码自己会说话
> ```

---

## 方法3：用结构体打包相关数据（告别"散装变量"）

**拆分前（一个人的信息散落在4个变量里）：**
```c
char name[20] = "小明";
int age = 20;
double scores[3] = {85, 92, 78};
int is_graduated = 0;
// 第二个学生？又得再来4个变量...
```

**拆分后（打包成一份"档案"）：**
```c
typedef struct {
    char name[20];
    int age;
    double scores[3];
    int is_graduated;
} Student;

Student stu1 = {"小明", 20, {85, 92, 78}, 0};
Student class[50];   // 再来50个学生都行，还是一个名字管理
```

---

## 方法4：多文件组织（选读，开阔视野）

当一个 `.c` 文件超过几百行，可以拆成多个文件：

```
myproject/
├── main.c          # 程序入口（main）
├── student.h       # 结构体定义 + 函数声明（"目录"）
├── student.c       # 学生相关的函数实现
├── file_io.c       # 文件读写函数
└── utils.c         # 通用小工具
```

> 💡 **原则：一个文件只负责一类事情。** `.h` 放"有哪些函数"（声明），`.c` 放"函数怎么写"（实现）。这是C项目组织的标配。等学了第5节 Makefile，多文件编译就一点不麻烦了！

---

## 练习题

### 练习5：函数拆分

把下面这个大 `main` 拆成多个小函数，使 main 不超过 6 行：

```c
#include <stdio.h>

int main() {
    int scores[] = {85, 92, 78, 65, 100, 54, 88, 76};
    int n = sizeof(scores) / sizeof(scores[0]);

    // 打印
    for (int i = 0; i < n; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    // 求平均
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    double avg = (double)sum / n;
    printf("平均分：%.1f\n", avg);

    // 找最高最低
    int max = scores[0], min = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] > max) max = scores[i];
        if (scores[i] < min) min = scores[i];
    }
    printf("最高：%d 最低：%d\n", max, min);
    return 0;
}
```

> 提示：拆成 `print_scores`、`average_of`、`print_min_max` 三个函数。

### 练习6：用结构体组织数据

以下代码用一堆散装变量描述两本书，请用结构体重构（能用数组更好）：

```c
int main() {
    char book1_title[50] = "C语言入门";
    double book1_price = 49.9;
    int book1_pages = 320;

    char book2_title[50] = "数据结构";
    double book2_price = 59.8;
    int book2_pages = 400;

    printf("《%s》%.1f元 %d页\n", book1_title, book1_price, book1_pages);
    printf("《%s》%.1f元 %d页\n", book2_title, book2_price, book2_pages);
    return 0;
}
```

---

<details>
<summary>🔑 练习5 参考答案</summary>

```c
#include <stdio.h>

void print_scores(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double average_of(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

void print_min_max(int arr[], int n) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("最高：%d 最低：%d\n", max, min);
}

int main() {
    int scores[] = {85, 92, 78, 65, 100, 54, 88, 76};
    int n = sizeof(scores) / sizeof(scores[0]);

    print_scores(scores, n);
    printf("平均分：%.1f\n", average_of(scores, n));
    print_min_max(scores, n);
    return 0;
}
```
</details>

<details>
<summary>🔑 练习6 参考答案</summary>

```c
#include <stdio.h>

typedef struct {
    char title[50];
    double price;
    int pages;
} Book;

int main() {
    Book books[2] = {
        {"C语言入门", 49.9, 320},
        {"数据结构", 59.8, 400}
    };

    for (int i = 0; i < 2; i++) {
        printf("《%s》%.1f元 %d页\n", books[i].title, books[i].price, books[i].pages);
    }
    return 0;
}
```
</details>

---

> 🎓 **第3节完成！** 会拆函数的程序员，写多大程序都不怕。
>
> [下一节：4. 工程好习惯 →](4_good_habits.md)　｜　[← 返回目录](README.md)
