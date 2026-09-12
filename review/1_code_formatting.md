# 复习 第1节：代码规范与格式化 —— 把字写工整

> 💬 **节前语：**
>
> 想象你读两篇文章：
>
> **文章A：**
> ```
> 今天天气很好我去了公园玩公园里有
> 很多人在散步还有小孩在跑着我觉得
> 心情很好
> ```
>
> **文章B：**
> ```
> 今天天气很好。
> 我去了公园玩。
> 公园里有很多人：
>   - 在散步的大人
>   - 在跑着的小孩
> 我觉得心情很好。
> ```
>
> 哪篇读起来舒服？**当然是B！** 代码也是如此。
>
> 这一节，我们把代码"写工整"。没有新语法，只有规范和让你更省事的工具。

---

## 一、糟糕的代码 vs 规范的代码

**糟糕的代码：**
```c
#include <stdio.h>
int main(){
int a=10;int b=20;int c=a+b;
printf("和：%d\n",c);
int d=a*b;printf("积：%d\n",d);return 0;}
```

**规范的代码：**
```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    int c = a + b;
    printf("和：%d\n", c);

    int d = a * b;
    printf("积：%d\n", d);

    return 0;
}
```

**功能一模一样，但第二种一眼能看懂。** 这就是规范的力量。

---

## 二、C代码规范速查表

| 规范 | 规则 | 示例 |
|------|------|------|
| **缩进** | 每级缩进 **4个空格**（或用Tab并统一） | 大括号里的代码缩进4格 |
| **大括号** | `{` 和语句在**同一行**，`}` 独占一行 | `int main() {` ✅<br>`int main()`<br>`{` ❌ |
| **空行** | 不同逻辑块之间空一行 | 变量声明和运算之间空一行 |
| **空格** | 运算符两侧加空格 | `a + b` ✅，`a+b` ❌ |
| **逗号/分号** | 逗号后面加空格 | `printf("%d %d", a, b);` ✅ |
| **行长度** | 建议不超过 **80~100字符** | 太长就换行 |
| **语句结尾** | C语句以 `;` 结束，别忘了 | `printf("hi\n");` |

---

## 三、便捷工具：clang-format 一键格式化

> 💡 手动排版太麻烦？C语言圈有个神器叫 **clang-format**，一条命令自动排版！它和 Go 的 `go fmt`、Python 的 `black` 是同类工具。

```bash
# 检查是否已安装
clang-format --version

# 没有就安装（Debian/Ubuntu）
sudo apt install clang-format

# 格式化文件（-i = 直接修改原文件 in-place）
clang-format -i main.c
```

**效果对比：** 无论你之前写得再乱，一条命令之后：

```c
// 执行前
int main(){int a=1;int b=2;printf("%d\n",a+b);return 0;}

// 执行 clang-format -i main.c 之后（自动排版）
int main() {
    int a = 1;
    int b = 2;
    printf("%d\n", a + b);
    return 0;
}
```

> 📌 **使用流程建议：** 写完代码 → `clang-format -i 文件名.c` → 再看一眼逻辑。排版的事交给工具，把精力留给思考！

---

## 四、练习题

### 练习1：找出格式错误

以下代码有 **8处格式问题**，请一一找出并改正：

```c
#include <stdio.h>
#include <string.h>

int main(){
char name[]="  Hello World  ";
char trimmed[100];
strcpy(trimmed,name);
printf("原始：%s\n",name);
int length=strlen(trimmed);
printf("长度：%d\n",length);
if(length>10){printf("有点长\n");}
return 0;}

```

> 提示：从这几个方向找——`{` 的位置、运算符/逗号两侧的空格、逻辑块之间的空行、最后的 `}`。

---

<details>
<summary>🔑 练习1 参考答案</summary>

**8处问题（见修复版注释）：**
```c
#include <stdio.h>
#include <string.h>

int main() {                                    // 1. { 应和 main() 同行
    char name[] = "  Hello World  ";
    char trimmed[100];
    strcpy(trimmed, name);

    printf("原始：%s\n", name);                  // 2. 逗号后加空格

    int length = strlen(trimmed);                // 3. 运算符两侧空格
    printf("长度：%d\n", length);                 // 4. 逗号后空格

    if (length > 10) {                           // 5. 空格；{ 同行
        printf("有点长\n");
    }

    return 0;                                    // 6. 与上面逻辑块之间空行
}                                                // 7. } 独占一行，顶格
                                                 // 8. 文件末尾另起一行
```

> 💡 用 `clang-format -i` 可以立刻验证——它格式化后的样子，就是标准答案！
</details>

---

> 🎓 **第1节完成！** 排版工整是"好代码"的第一步。
>
> [下一节：2. 命名规范 →](2_naming_conventions.md)　｜　[← 返回目录](README.md)
