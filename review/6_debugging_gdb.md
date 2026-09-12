# 复习 第6节：调试入门 —— 用 gdb 抓住 bug 🐛

> 💬 **节前语：**
>
> 前几节我们学了"把代码写规范、写整洁"。但现实是——**写出来的程序还是会出 bug**。
>
> 遇到 bug 别慌，也别瞪着屏幕干猜。程序员对付 bug 有三把趁手的工具：
>
> - 🕵️ **看懂编译错误**：编译器其实已经把 bug 的"门牌号"告诉你了
> - 🔍 **gdb 调试器**：让程序"走一步停一步"，随时看看每个变量到底是多少
> - ✅ **assert / 打印**：在代码里埋"检查点"，程序自己喊"我这儿错了！"
>
> 这一节把这三样都教会你。学会调试，写代码的胆量直接翻倍——**因为你知道，出错了总能把它揪出来**。准备好了吗？开始吧！

---

## 一、先分清两种 bug

### 🧱 编译错误（编译时就会报）

代码还没跑起来，编译器就"罢工"了。常见的有：

| 报错长什么样 | 通常原因 |
|--------------|----------|
| `use of undeclared identifier 'x'` | 变量没声明 / 拼错名字 |
| `expected ';' after expression` | 漏了分号 |
| `expected '}' ...` | 括号/大括号没配对 |
| `incompatible types ...` | 类型不匹配 |
| `redefinition of 'main'` | main 重复定义（或两个文件都有 main）|

> 📌 **读编译错误的口诀：从第一条看起。** gcc 会给出 `文件名.c:第几行:第几列: 错误内容`。通常**第一个错误才是真正的错**，后面的往往是被它"带偏"的。

### 💥 运行期 bug（编译能过，跑起来出事）

程序能编译，但运行结果不对，常见症状：

- **直接崩**：`Segmentation fault`（段错误）——多半是空指针/数组越界
- **结果不对**：逻辑算错了、变量没初始化、类型/格式写错
- **卡死**：死循环

> 编译错误编译器会告诉你位置；运行期 bug 就得靠"工具"自己去揪了——这就是 gdb 的用武之地。

---

## 二、编译时先戴上"显微镜"：-Wall -Wextra -g

调试前，编译命令先加两个好东西：

```bash
gcc -Wall -Wextra -g -o 程序名 源文件.c
```

| 选项 | 作用 |
|------|------|
| `-Wall` | 打开**大部分**警告（如"变量未使用""可能未初始化"）|
| `-Wextra` | 再开一批更"挑剔"的警告 |
| `-g` | **生成调试信息**——没有它，gdb 就不知道"第几行"！|

> 🎯 很多 bug 其实在**编译警告**里就被"剧透"了。养成习惯：**让编译器当你的第一个审查员，警告也尽量清零。**

---

## 三、抓崩溃：让 gdb 告诉你"哪一行"

看一个经典"段错误"程序：

```c
#include <stdio.h>

void setValue(int *p, int v) {
    *p = v;          // 往 p 指向的地址写值
}

int main() {
    int *p = NULL;       // 空指针：地址 0
    setValue(p, 10);     // 把 0 传给函数 → *p = 10 → 往地址0写 → 崩！
    printf("完成\n");
    return 0;
}
```

直接运行可能只看到一句：
```
Segmentation fault
```

你不知道崩在哪一行。用 gdb 跑一遍（终端输出已精简）：

```bash
gcc -g -o nully nully.c     # 记得带 -g
gdb ./nully
```

```
(gdb) run
Starting program: ./nully

Program received signal SIGSEGV, Segmentation fault.
0x… in setValue (p=0x0, v=10) at nully.c:4
4       *p = v;
```

> 🎉 **gdb 一句话就告诉你了：崩在 `nully.c` 第 4 行的 `*p = v;`，原因是空指针 `p=0x0`。** 修法：调用前判断 p 是否为空，或别再传 NULL。

> 📌 当 `p=0x0`（地址 0）出现在函数参数里，十有八九是"空指针被解引用"了。

---

## 四、主动下"断点"：走一步、看一步

崩溃能抓，那"结果不对但不崩"的 bug 怎么抓？——**在关键行"踩刹车"，一步步看变量**。

准备一个求 1+2+3+4 的程序：

```c
#include <stdio.h>

int main() {
    int i;
    int sum = 0;
    for (i = 1; i <= 4; i++) {
        sum += i;
    }
    printf("sum=%d\n", sum);
    return 0;
}
```

```bash
gcc -g -o nums nums.c
gdb ./nums
```

常用命令（终端输出已精简）：

```
(gdb) break main        # 在 main 处设断点（也可写 break 行号）
(gdb) run               # 开始运行，遇到断点停下
(gdb) next              # 单步执行一行（n，不进入函数）
(gdb) print i           # 看看 i 现在是几
$1 = 1
(gdb) print sum         # 再看看 sum
$2 = 0
(gdb) continue          # 继续跑到下一个断点（c）
(gdb) quit              # 退出 gdb（q）
```

| 命令 | 缩写 | 干什么 |
|------|------|--------|
| `break 行号/函数名` | `b` | 设断点 |
| `run` | `r` | 运行到断点 |
| `next` | `n` | 单步，**不进入**函数内部 |
| `step` | `s` | 单步，**进入**函数内部 |
| `print 变量` | `p` | 看变量的值 |
| `continue` | `c` | 继续到下一个断点 |
| `list` | `l` | 显示附近源码 |
| `quit` | `q` | 退出 |

> 🎯 **最常用的套路：** `break main` → `run` → `next` 一步步走 → 每走几步 `print` 一下关键变量 → 看它在哪一步开始"变坏"。**找到第一个值不对的地方，bug 基本就在它前一行。**

---

## 五、让程序"会自检"：assert 与打印调试

有时不想开 gdb，也可以在代码里埋"检查点"。

### ✅ assert：不符合预期就当场"爆炸"

```c
#include <stdio.h>
#include <assert.h>

int main() {
    int divisor = 0;
    assert(divisor != 0);    // 条件为假 → 程序立刻终止并报错
    printf("%d\n", 10 / divisor);
    return 0;
}
```

条件不成立时，程序会打印 `Assertion failed` 并指出是哪一行。**适合检查"前置条件"**：除数不为 0、数组下标在范围内、malloc 后指针非空……

> 💡 正式发布时，若不想保留这些检查，在文件开头加 `#define NDEBUG`（No Debug）即可让所有 `assert` 失效。

### 🖨️ printf 打桩

不想装 gdb 的话，最朴素的招就是**在关键位置打印中间值**：

```c
for (i = 1; i <= 4; i++) {
    sum += i;
    printf("[调试] i=%d, sum=%d\n", i, sum);   // 临时打印
}
```

看输出就能知道 sum 是怎么一步步"长"出来的。**定位完记得删掉这些打印。**

> 📌 我们复习第4节讲过的"边界检查"（数组下标、文件是否打开、malloc 是否成功）本质上也是"自检"——**好代码会主动怀疑自己。**

---

## 六、经典 bug 自查清单 🕵️

遇到 bug 先别慌，按这张表对号入座：

| 症状 | 常见原因 | 去哪复习 |
|------|----------|----------|
| 段错误（崩溃）| 空指针解引用 / 数组越界 | 第4章、第6章 |
| 结果差一点点 | `i <= n` 写成了 `i < n`（off-by-one）| 第2章循环 |
| 输入读不对 | 忘写 `&`；`%c` 吃到回车 | 第1.5节 |
| `%d` 打出乱码 | 类型和格式符不匹配（double 用了 %d）| 第1.4节 |
| 变量是垃圾值 | 忘了初始化 | 第1.4节 |
| 改不到外面的变量 | 形参按值传递，忘用指针 | 第4.1节 |
| free 后还用 | 悬垂指针 | 第6.2节 |
| 程序卡死 | 死循环 / 递归没出口 | 第2.3节、第7章 |

> 🧠 **排查心法：复现 → 定位 → 修复。** 让 bug 稳定出现（输入固定、数据固定），再逐步缩小范围——比如"二分注释法"：把代码一半注释掉看还崩不崩，快速锁定区域。

---

## 🎓 本节小结

这一节我们学了：

✅ **两类 bug：** 编译错误（看第一条报错）vs 运行期 bug（用工具抓）

✅ **编译选项：** `-Wall -Wextra -g`——警告当敌人，`-g` 供 gdb 用

✅ **gdb 三连：** `run` 崩溃定位、`break` + `next` + `print` 单步看变量、`continue`/`quit`

✅ **自检：** `assert` 检查前置条件、`printf` 打桩看中间值

✅ **自查清单：** 空指针、越界、忘 `&`、类型不匹配、死循环……

> 💡 **记住：调试不是"浪费时间"，而是编程的正常组成部分。越早学会用工具，越不怕写大程序。**

---

## 练习题

### 练习9：看报错，找行号

下面的编译报错说明问题可能在第几行？为什么"后面的错误常常别急着看"？

```text
demo.c:5:9: error: use of undeclared identifier 'total'
demo.c:8:15: error: use of undeclared identifier 'total'
```

<details>
<summary>🔑 练习9 参考答案</summary>

先看**第一条**（第 5 行）：`total` 没声明。第二条多半是"被第5行带出来的"——变量根本没定义，后面用到它当然也报错。修好第 5 行（声明 `total`）再看。

</details>

### 练习10：gdb 找崩溃

下面程序会段错误，先猜猜为什么，再用 gdb 验证它崩在哪一行：

```c
#include <stdio.h>
#include <string.h>

int main() {
    char *s = NULL;
    strcpy(s, "hello");   // 往 NULL 里拷东西？
    printf("%s\n", s);
    return 0;
}
```

<details>
<summary>🔑 练习10 参考答案</summary>

`s` 是空指针，`strcpy` 往地址 0 写内容 → 段错误。`gcc -g` 后用 gdb `run`，会停在调用 `strcpy` 的那一行。修法：给 `s` 分配足够空间，例如用字符数组 `char s[20];`。

</details>

### 练习11：assert 自检

给下面的函数加一个 `assert`，保证"除数不为 0"，并说出：什么时候它会拦下 bug？

```c
#include <stdio.h>
#include <assert.h>

double divide(int a, int divisor) {
    assert(________);          // 补全
    return (double)a / divisor;
}

int main() {
    printf("%.2f\n", divide(10, 2));
    printf("%.2f\n", divide(10, 0));   // 这行会被拦住吗？
    return 0;
}
```

<details>
<summary>🔑 练习11 参考答案</summary>

`assert(divisor != 0);`。`divide(10, 0)` 传了 0，`assert` 条件为假 → 程序立刻终止并报错，根本不会执行除法。想发布时不检查，在开头加 `#define NDEBUG`。

</details>

### 练习12：用 next + print 抓逻辑错

下面程序想算 `1+2+3+4+5=15`，却输出 20。用 gdb 单步 + `print` 找出哪一步开始错：

```c
#include <stdio.h>

int main() {
    int i;
    int sum = 0;
    for (i = 1; i <= 5; i++) {
        sum += i;
        sum += 1;          // ← 疑点在这？
    }
    printf("sum=%d\n", sum);
    return 0;
}
```

<details>
<summary>🔑 练习12 参考答案</summary>

`sum += i` 之后又多了 `sum += 1`，每次多加了 1，一共 5 次多 5 → 15+5=20。用 `break 8`、`next`、`print sum` 能看到 sum 在每轮比期望大 1。删掉 `sum += 1;` 即可。

</details>

---

> 🎓 **第6节完成！** 会调试，才敢写大程序——现在你手里多了 gdb 这把"手术刀"。
>
> 至此，整个"写出好代码"复习就全部结束啦！
>
> [← 返回复习目录](README.md)　｜　[返回第4章 →](../chapter4/README.md)　｜　[继续第5章 →](../chapter5/README.md)
