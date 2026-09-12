# 复习 第5节：编写 Makefile —— 告别手敲 gcc

> 💬 **节前语：**
>
> 想一想，你每次编译是不是都要敲这一长串：
>
> ```bash
> gcc -Wall -std=c99 main.c tools.c -o app
> ```
>
> 程序只有一个文件还好，文件一多、又要重新编译时，手敲命令又累又容易错。
>
> 而且还有一个痛点：**我只改了一个文件，为什么要把所有文件重新编一遍？**
>
> **Makefile** 就是来解决这个问题的：它是写给 `make` 工具的"菜谱"，让你一条命令 `make` 自动编译，还能**只重新编译改动过的部分**。
>
> > 📌 make 和 gcc 一样是"编译工具链"的一部分：Linux 装 `build-essential`、Mac 装 Command Line Tools 时都会带上，无需另外安装。先验证一下：
> > ```bash
> > make --version
> > ```

---

## 一、Makefile 长什么样？

一个 Makefile 由一条条 **规则（rule）** 组成：

```
目标(target): 依赖(prerequisites)
<TAB>命令(recipe)
```

| 部分 | 含义 | 比喻 |
|------|------|------|
| **目标** | 要"做出来"的东西（通常是文件名） | 成品菜 |
| **依赖** | 做目标需要的东西 | 食材 |
| **命令** | 怎么做（真正执行的shell命令） | 烹饪步骤 |

> 🚨 **最重要的坑：命令前面必须是一个 Tab 键，不能是空格！** 这是新手 100% 会踩的坑。
> ```
> 正确：␉gcc hello.c -o hello      ← 前面是 Tab
> 错误：    gcc hello.c -o hello    ← 前面是空格 → make 报错
> ```

---

## 二、第一个 Makefile：单文件

写一个 `hello.c`：

```c
#include <stdio.h>

int main(void) {
    printf("Hello, Make!\n");
    return 0;
}
```

在**同目录**新建一个文件，名字就叫 `Makefile`（没有扩展名），内容：

```makefile
hello: hello.c
	gcc -Wall hello.c -o hello

clean:
	rm -f hello

.PHONY: clean
```

### 🎬 然后怎么用？

```bash
make        # 编译（默认找第一个目标 hello）
./hello     # 运行 → Hello, Make!
make clean  # 删掉编译产物 hello
```

**运行 `make` 时发生的事：**
1. make 看第一个目标 `hello`
2. 发现依赖 `hello.c`
3. 如果 `hello` 不存在，或 `hello.c` 比 `hello` **更新**（改过）
4. 就执行命令 `gcc -Wall hello.c -o hello`

> 📌 **这就是 make 的聪明之处——"增量编译"。**
> 你再运行一次 `make`，会发现它说 `make: 'hello' is up to date.`（已经是最新），**啥也不干**，因为没改动！只有你改了 `hello.c`，它才会重新编译。

### 补充解释：clean 和 .PHONY

- `clean` 是"删掉产物"的规则，方便清理：`make clean`
- `.PHONY: clean` 告诉 make："clean 不是个文件，别去找它是否最新"，每次都执行

---

## 三、用变量，少重复

编译选项写死很丑，用**变量**管理：

```makefile
CC = gcc              # 编译器
CFLAGS = -Wall -std=c99   # 编译选项

hello: hello.c
	$(CC) $(CFLAGS) hello.c -o hello

clean:
	rm -f hello

.PHONY: clean
```

> 📌 定义：`变量名 = 值`；使用：`$(变量名)`。
> - `CC`：编译器（改成 clang 只需改一行）
> - `CFLAGS`：编译参数（想加 `-g` 调试、`-O2` 优化，改这里就行）

**想换编译器、加优化，都只改顶部，不用动下面的命令！**

```makefile
CC = clang              # 换成 clang
CFLAGS = -Wall -O2      # 加优化 -O2
```

---

## 四、多文件工程：先编译 .o 再链接

当项目有多个 `.c` 文件，标准做法是：**每个 .c 单独编译成 .o（目标文件），最后再把所有 .o 链接成可执行文件**。

### 📝 一个三文件小项目

**tools.h（函数声明——"目录"）：**
```c
#ifndef TOOLS_H
#define TOOLS_H

int add(int a, int b);
int max(int a, int b);

#endif
```

> 📌 `#ifndef ... #endif` 叫"头文件守卫"，防止同一个头文件被重复包含导致重复声明报错。**每个头文件都应该加。**

**tools.c（函数实现）：**
```c
#include "tools.h"

int add(int a, int b) {
    return a + b;
}

int max(int a, int b) {
    return a > b ? a : b;
}
```

**main.c（入口）：**
```c
#include <stdio.h>
#include "tools.h"

int main(void) {
    printf("2 + 3 = %d\n", add(2, 3));
    printf("max(4, 9) = %d\n", max(4, 9));
    return 0;
}
```

### 📝 对应的 Makefile

```makefile
CC = gcc
CFLAGS = -Wall -std=c99

# 最终目标：链接所有 .o 成可执行文件 app
app: main.o tools.o
	$(CC) $(CFLAGS) main.o tools.o -o app

# 每个 .c 单独编译成 .o；依赖它对应的 .c 和 .h
main.o: main.c tools.h
	$(CC) $(CFLAGS) -c main.c

tools.o: tools.c tools.h
	$(CC) $(CFLAGS) -c tools.c

clean:
	rm -f app main.o tools.o

.PHONY: clean
```

> 📌 `-c` 表示"只编译，不链接"，生成 `.o` 文件。最后一步 `app: main.o tools.o` 把两个 `.o` 链接成可执行文件 `app`。

### 🎬 使用

```bash
make          # 依次生成 main.o、tools.o、app
./app         # 运行
make clean    # 清理所有编译产物
```

**增量编译的威力：** 如果你只改了 `main.c`，再执行 `make`，它会发现 `tools.o` 没变、**只重新编译 `main.c`**，然后重新链接。大项目里这能省下几十分钟！

---

## 五、偷懒技巧：自动变量

make 提供了一些"快捷方式"变量，少打很多字：

| 自动变量 | 含义 | 例子 |
|----------|------|------|
| `$@` | 当前**目标**名 | 目标 `app` 时，`$@` = `app` |
| `$^` | **所有**依赖 | 依赖 `main.o tools.o` 时，`$^` = `main.o tools.o` |
| `$<` | **第一个**依赖 | 依赖 `main.c tools.h` 时，`$<` = `main.c` |

用自动变量改写上面的 Makefile：

```makefile
CC = gcc
CFLAGS = -Wall -std=c99

app: main.o tools.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c tools.h
	$(CC) $(CFLAGS) -c $< -o $@

tools.o: tools.c tools.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f app *.o

.PHONY: clean
```

> 💡 `$@` 和 `$<` 写起来像乱码，但见多了就习惯了——它们让规则变得"模板化"，新增一个 xxx.o 只需照抄一行。

---

## 六、最常用模板（背下来直接套）

**单文件版：**
```makefile
CC = gcc
CFLAGS = -Wall -std=c99

app: app.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f app

.PHONY: clean
```

**多文件版（可无限加 .c）：**
```makefile
CC = gcc
CFLAGS = -Wall -std=c99
OBJS = main.o tools.o utils.o     # 每加一个源文件，往这里加一个 .o

app: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f app $(OBJS)

.PHONY: clean
```

> 📌 这里出现一个"模式规则" `%.o: %.c`——意思是"任意的 .o 都由同名的 .c 编译而来"，一个规则覆盖所有源文件！以后加 `utils.c`，只需改 `OBJS` 那一行。

---

## 练习题

### 练习9：给第4节的"练习8答案"写一个 Makefile

假设你把练习8的程序保存为 `report.c`，请为它写一个 Makefile，要求：

- 可执行文件叫 `report`
- 开启 `-Wall` 警告
- 提供 `clean` 目标删除编译产物

### 练习10：补全多文件 Makefile

下面是一个**不完整**的多文件 Makefile（两个源文件 `main.c`、`tools.c`），补全空缺，并说明第2条规则依赖里为什么要有 `tools.h`：

```makefile
CC = gcc
CFLAGS = -Wall -std=c99

app: main.o tools.o
	$(CC) $(CFLAGS) _____ -o $@

main.o: main.c tools.h
	$(CC) $(CFLAGS) -c $< -o $@

tools.o: tools.c tools.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f app _____ 

.PHONY: clean
```

---

<details>
<summary>🔑 练习9 参考答案</summary>

```makefile
CC = gcc
CFLAGS = -Wall -std=c99

report: report.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f report

.PHONY: clean
```

保存为 `Makefile` 后：
```bash
make        # 编译出 report
./report    # 运行（还会生成 report.txt）
make clean  # 删除 report
```
</details>

<details>
<summary>🔑 练习10 参考答案</summary>

```makefile
CC = gcc
CFLAGS = -Wall -std=c99

app: main.o tools.o
	$(CC) $(CFLAGS) main.o tools.o -o $@    # 补：列出所有 .o（也可写 $^）

main.o: main.c tools.h
	$(CC) $(CFLAGS) -c $< -o $@

tools.o: tools.c tools.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f app main.o tools.o                 # 补：清掉 app 和所有 .o

.PHONY: clean
```

**为什么 `main.o` 的依赖里要有 `tools.h`？**
因为 `main.c` 里 `#include "tools.h"`——它用到头文件里的声明。如果哪天你改了 `tools.h`，但 Makefile 没把依赖写全，make 就**不知道要重编** `main.o`，会出现"改了声明、程序却还是旧行为"的诡异bug。**依赖写得越全，增量编译越可靠。**
</details>

---

> 🎓 **第5节完成！** 学会 Makefile，你就从"手动敲命令"进化到"一键构建"了。以后的大项目、开源代码，几乎都靠它（或它的兄弟们 CMake）来编译。
>
> [下一节：6. 调试入门 →](6_debugging_gdb.md)　｜　[← 返回复习目录](README.md)
