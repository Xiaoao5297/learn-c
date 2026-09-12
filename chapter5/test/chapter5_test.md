# 第5章测试：文件读写与实战

> 📋 **测试说明：**
> 
> - 📝 **选择题（5题）：** 每题考查一个核心概念
> - 📝 **填空题（5题）：** 考查记忆和理解
> - 📝 **改错题（1题）：** 考查代码调试能力
> - 📝 **编程题（3题）：** 考查综合运用能力
> 
> 💡 **建议：** 先独立完成后，再对照参考答案检查。
> 
> ⚠️ **提示：** 编程题请在**自己的电脑上**运行验证（会生成真实文件）。

---

## 一、选择题（共5题）

**1. `fopen` 打开文件失败时会返回：**

A. `0`  
B. `-1`  
C. `NULL`  
D. `EOF`

---

**2. 想"保留文件原有内容，只在末尾追加"，应该用哪个模式：**

A. `"r"`  
B. `"w"`  
C. `"a"`  
D. `"r+"`

---

**3. 判断 `fgetc` 是否读到文件末尾，需要判断返回值是否等于：**

A. `0`  
B. `'\0'`  
C. `NULL`  
D. `EOF`

---

**4. 读取一整行文本（含空格）最合适的函数是：**

A. `fscanf(fp, "%s", buf)`  
B. `fgets(buf, 大小, fp)`  
C. `fgetc(fp)`  
D. `fread(buf, 1, 大小, fp)`

---

**5. 想把一个结构体数组整体存成二进制文件，正确的写法是：**

A. `fprintf(fp, "%s", arr)`  
B. `fwrite(arr, sizeof(类型), 个数, fp)`  
C. `fputs(arr, fp)`  
D. `fputc(arr, fp)`

---

## 二、填空题（共5题）

**6. 用"状态码 + 指针"设计函数时，函数用_______表示成功/失败，结果通过指针参数带出去。**

**7. 打印上次错误的具体原因，可以用函数_______（它会输出 "你的话: 错误描述"）。**

**8. 想回到文件开头重新读，可以调用函数_______。**

**9. 把内存数据存进文件、让程序重启后还能读回，这种思想叫"_______"。**

**10. `main(int argc, char *argv[])` 中，`argv[0]` 通常是_______。**

---

## 三、改错题（共1题）

**11. 以下程序想把两个整数写入文件并读回求和，有4个错误，请逐一找出并改正：**

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("num.txt", "w");      // 错误区①：没检查是否 NULL
    fprintf(fp, "7\n13\n");
    fclose(fp);
    
    fp = fopen("num.txt", "r");            // 错误区②：模式错误？r 是对的，请检查别处
    int a, b;
    fscanf(fp, "%d %d", a, b);             // 错误区③：缺 & 符号
    fclose(fp);
    
    printf("和：%d\n", a + b);
    return 0;
}
```

> 提示：除了 fopen 后检查 NULL 和 fscanf 缺 `&`，还可以思考：如果文件里数字多于2个，只读两个够吗？以及好的习惯是检查 fscanf 的返回值。

---

## 四、编程题（共3题）

### 12. 基础题：追加日志

> 编写程序，用 `"a"` 模式往 `log.txt` 追加一行：`第N次运行`（N 每次加1）。
> 
> 运行两次后，`log.txt` 内容类似：
> ```
> 第1次运行
> 第2次运行
> ```
> 
> 提示：先读旧内容数出已有几行，再追加下一行；或更简单——先运行两次分别写固定递增文本（用两次不同常量）。

---

### 13. 进阶题：逐行打印文件

> 编写程序用 `fgets` 一行行读取 `poem.txt` 并加上行号打印。
> 
> 假设 `poem.txt`：
> ```
> 床前明月光
> 疑是地上霜
> ```
> 
> 输出：
> ```
> 1: 床前明月光
> 2: 疑是地上霜
> ```

---

### 14. 挑战题：学生成绩存档系统（简化版）

> 定义一个 `Student` 结构体（姓名、成绩），编写两个函数：
> 
> ```c
> int saveToFile(Student arr[], int count);   // 存到 scores.txt，成功0/失败-1
> int loadFromFile(Student arr[], int max);   // 读回，返回人数
> ```
> 
> 在 main 中：先把 2 个学生存盘，再读回打印。
> 
> 预期输出：
> ```
> 读回的学生：
> 小明：95.0分
> 小红：72.5分
> ```

---

## ✅ 参考答案

<details>
<summary>🔑 点击展开答案</summary>

### 选择题答案

**1. C** — `fopen` 失败返回 `NULL`。

**2. C** — 追加用 `"a"`；`"w"` 会清空旧内容。

**3. D** — `fgetc` 读到末尾返回 `EOF`（-1）。

**4. B** — `fgets` 读一整行（含空格）；`%s` 遇空格就停。

**5. B** — `fwrite(数组, sizeof(类型), 个数, fp)`。

---

### 填空题答案

**6.** 返回值（0/-1）

**7.** `perror`

**8.** `rewind`

**9.** 持久化

**10.** 程序自己的名字（`./程序名`）

---

### 改错题答案

**11. 四处错误：**

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("num.txt", "w");
    if (fp == NULL) {          // 错误1：检查 fopen 是否成功
        perror("写入失败");
        return 1;
    }
    fprintf(fp, "7\n13\n");
    fclose(fp);
    
    fp = fopen("num.txt", "r");
    if (fp == NULL) {          // 顺手检查读取也一样重要
        perror("读取失败");
        return 1;
    }
    int a, b;
    if (fscanf(fp, "%d %d", &a, &b) != 2) {   // 错误2：变量前加 &；错误3/4：检查 fscanf 返回值
        printf("读取失败或格式不对\n");
        fclose(fp);
        return 1;
    }
    fclose(fp);
    
    printf("和：%d\n", a + b);
    return 0;
}
```

---

### 编程题参考答案

**12. 追加日志：**

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("log.txt", "a");   // 追加模式
    if (fp == NULL) {
        perror("打开失败");
        return 1;
    }
    
    fprintf(fp, "第1次运行\n");   // 第一次运行时写这行
    fclose(fp);
    
    return 0;
}
```

> 运行两次时，可把"第1次运行"改成"第2次运行"再运行第二次，验证是否保留旧内容、只在末尾追加。

---

**13. 逐行打印文件：**

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("poem.txt", "r");
    if (fp == NULL) {
        perror("打开失败");
        return 1;
    }
    
    char line[200];
    int lineNumber = 1;
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%d: %s", lineNumber, line);
        lineNumber++;
    }
    
    fclose(fp);
    return 0;
}
```

---

**14. 学生成绩存档系统（简化版）：**

```c
#include <stdio.h>

typedef struct {
    char name[20];
    double score;
} Student;

int saveToFile(Student arr[], int count) {
    FILE *fp = fopen("scores.txt", "w");
    if (fp == NULL) {
        perror("保存失败");
        return -1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %.1f\n", arr[i].name, arr[i].score);
    }
    fclose(fp);
    return 0;
}

int loadFromFile(Student arr[], int max) {
    FILE *fp = fopen("scores.txt", "r");
    if (fp == NULL) {
        return 0;
    }
    int count = 0;
    while (count < max &&
           fscanf(fp, "%s %lf", arr[count].name, &arr[count].score) == 2) {
        count++;
    }
    fclose(fp);
    return count;
}

int main() {
    Student class[2] = {{"小明", 95.0}, {"小红", 72.5}};
    
    if (saveToFile(class, 2) != 0) {
        printf("保存失败！\n");
        return 1;
    }
    
    Student loaded[2];
    int count = loadFromFile(loaded, 2);
    
    printf("读回的学生：\n");
    for (int i = 0; i < count; i++) {
        printf("%s：%.1f分\n", loaded[i].name, loaded[i].score);
    }
    return 0;
}
```

</details>

---

> 🎉 **第5章测试完成！**
> 
> 如果答对了80%以上，说明你已经掌握C语言的错误处理和文件读写！
> 
> 如果有不会的，回去复习对应的章节吧。
> 
> [← 回到第5章](../README.md)
