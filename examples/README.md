# 教程示例代码

本目录由 [`scripts/extract_examples.py`](../scripts/extract_examples.py) 自动生成，
收录教程中带编号、可以独立编译运行的完整 C 程序。

## 怎么用

```bash
# 编译全部示例（输出到 examples/build/）
make -C examples

# 只编译某一章
make -C examples build/chapter2/2.1.1_arithmetic

# 运行某个示例
./examples/build/chapter2/2.1.1_arithmetic

# 编译并核对教程里写的输出
python3 scripts/verify_examples.py

# 清理编译产物
make -C examples clean
```

每个 `.c` 文件顶部都有教程出处、示例编号、所在小节和预期输出。
代码第一行的注释保留了示例编号和文件名。

> 本目录是自动生成的。想改示例，请改教程原文，然后运行：
>
> ```bash
> python3 scripts/extract_examples.py
> ```

## 示例总览

共 **39** 个示例，分布在 **2** 个章节。

| 章节 | 示例数 |
|------|--------|
| 第 2 章：运算符、条件、循环与函数 | 38 |
| 第 4 章：指针与结构体 | 1 |

## 第 2 章：运算符、条件、循环与函数

| 文件 | 编号 | 出处 |
|------|------|------|
| [2.1.1_arithmetic.c](chapter2/2.1.1_arithmetic.c) | 2.1.1 | [2.1.1 算术运算符](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.2_integer_division.c](chapter2/2.1.2_integer_division.c) | 2.1.2 | [2.1.2 整数除法和浮点数除法](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.3_modulo.c](chapter2/2.1.3_modulo.c) | 2.1.3 | [2.1.3 取余的用途](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.4_increment.c](chapter2/2.1.4_increment.c) | 2.1.4 | [2.1.4 自增和自减](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.5_compare.c](chapter2/2.1.5_compare.c) | 2.1.5 | [2.1.5 比较运算符](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.6_logical.c](chapter2/2.1.6_logical.c) | 2.1.6 | [2.1.6 逻辑运算符](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.7_assignment.c](chapter2/2.1.7_assignment.c) | 2.1.7 | [2.1.7 赋值运算符](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.8_precedence.c](chapter2/2.1.8_precedence.c) | 2.1.8 | [2.1.8 运算符优先级](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.9_time_conversion.c](chapter2/2.1.9_time_conversion.c) | 2.1.9 | [2.1.9 综合示例：秒数换算](<../chapter2/sections/2.1 运算符.md>) |
| [2.2.1_basic_if.c](chapter2/2.2.1_basic_if.c) | 2.2.1 | [2.2.1 最基本的 if](<../chapter2/sections/2.2 条件判断.md>) |
| [2.2.2_if_else.c](chapter2/2.2.2_if_else.c) | 2.2.2 | [2.2.2 if-else](<../chapter2/sections/2.2 条件判断.md>) |
| [2.2.3_grade.c](chapter2/2.2.3_grade.c) | 2.2.3 | [2.2.3 else if：多条件判断](<../chapter2/sections/2.2 条件判断.md>) |
| [2.2.4_nested_if.c](chapter2/2.2.4_nested_if.c) | 2.2.4 | [2.2.4 嵌套 if](<../chapter2/sections/2.2 条件判断.md>) |
| [2.2.5_scope.c](chapter2/2.2.5_scope.c) | 2.2.5 | [2.2.5 大括号和变量作用域](<../chapter2/sections/2.2 条件判断.md>) |
| [2.2.6_switch_menu.c](chapter2/2.2.6_switch_menu.c) | 2.2.6 | [2.2.7 switch 语句](<../chapter2/sections/2.2 条件判断.md>) |
| [2.2.7_switch_fallthrough.c](chapter2/2.2.7_switch_fallthrough.c) | 2.2.7 | [break 的作用](<../chapter2/sections/2.2 条件判断.md>) |
| [2.2.8_menu.c](chapter2/2.2.8_menu.c) | 2.2.8 | [2.2.8 综合示例：简单菜单](<../chapter2/sections/2.2 条件判断.md>) |
| [2.3.1_while_count.c](chapter2/2.3.1_while_count.c) | 2.3.1 | [2.3.1 while 循环](<../chapter2/sections/2.3 循环入门.md>) |
| [2.3.2_for_count.c](chapter2/2.3.2_for_count.c) | 2.3.2 | [2.3.2 for 循环](<../chapter2/sections/2.3 循环入门.md>) |
| [2.3.3_do_while.c](chapter2/2.3.3_do_while.c) | 2.3.3 | [2.3.3 do-while 循环](<../chapter2/sections/2.3 循环入门.md>) |
| [2.3.4_sum.c](chapter2/2.3.4_sum.c) | 2.3.4 | [2.3.4 用循环做累加](<../chapter2/sections/2.3 循环入门.md>) |
| [2.3.5_countdown.c](chapter2/2.3.5_countdown.c) | 2.3.5 | [2.3.7 综合示例：倒计时](<../chapter2/sections/2.3 循环入门.md>) |
| [2.4.1_break.c](chapter2/2.4.1_break.c) | 2.4.1 | [2.4.1 break：提前结束循环](<../chapter2/sections/2.4 循环控制.md>) |
| [2.4.2_continue.c](chapter2/2.4.2_continue.c) | 2.4.2 | [2.4.2 continue：跳过本次循环](<../chapter2/sections/2.4 循环控制.md>) |
| [2.4.3_infinite_loop.c](chapter2/2.4.3_infinite_loop.c) | 2.4.3 | [2.4.3 无限循环](<../chapter2/sections/2.4 循环控制.md>) |
| [2.4.4_nested_loop.c](chapter2/2.4.4_nested_loop.c) | 2.4.4 | [2.4.4 嵌套循环](<../chapter2/sections/2.4 循环控制.md>) |
| [2.4.5_triangle.c](chapter2/2.4.5_triangle.c) | 2.4.5 | [直角三角形](<../chapter2/sections/2.4 循环控制.md>) |
| [2.4.6_hollow_square.c](chapter2/2.4.6_hollow_square.c) | 2.4.6 | [空心正方形](<../chapter2/sections/2.4 循环控制.md>) |
| [2.4.7_primes.c](chapter2/2.4.7_primes.c) | 2.4.7 | [2.4.6 综合示例：找出素数](<../chapter2/sections/2.4 循环控制.md>) |
| [2.5.1_add.c](chapter2/2.5.1_add.c) | 2.5.1 | [2.5.1 定义和调用](<../chapter2/sections/2.5 函数基础.md>) |
| [2.5.2_void_function.c](chapter2/2.5.2_void_function.c) | 2.5.2 | [2.5.2 参数和返回值](<../chapter2/sections/2.5 函数基础.md>) |
| [2.5.3_is_even.c](chapter2/2.5.3_is_even.c) | 2.5.3 | [2.5.3 返回布尔值](<../chapter2/sections/2.5 函数基础.md>) |
| [2.5.4_prototype.c](chapter2/2.5.4_prototype.c) | 2.5.4 | [2.5.4 函数声明](<../chapter2/sections/2.5 函数基础.md>) |
| [2.5.5_scope.c](chapter2/2.5.5_scope.c) | 2.5.5 | [2.5.5 变量的作用域](<../chapter2/sections/2.5 函数基础.md>) |
| [2.5.6_max.c](chapter2/2.5.6_max.c) | 2.5.6 | [求最大值](<../chapter2/sections/2.5 函数基础.md>) |
| [2.5.7_factorial.c](chapter2/2.5.7_factorial.c) | 2.5.7 | [计算阶乘](<../chapter2/sections/2.5 函数基础.md>) |
| [2.5.8_temperature.c](chapter2/2.5.8_temperature.c) | 2.5.8 | [温度转换](<../chapter2/sections/2.5 函数基础.md>) |
| [2.5.9_calculator.c](chapter2/2.5.9_calculator.c) | 2.5.9 | [2.5.8 综合示例：简易计算器](<../chapter2/sections/2.5 函数基础.md>) |

## 第 4 章：指针与结构体

| 文件 | 编号 | 出处 |
|------|------|------|
| [4.7.1_student_manager_single.c](chapter4/4.7.1_student_manager_single.c) | 4.7.1 | [4.7.2 先看一个单文件版本](<../chapter4/sections/4.7 多文件工程与 Makefile.md>) |

---

示例只保证在 `cc -std=c11 -Wall -Wextra -Werror -pedantic` 下能编译。
涉及输入或外部文件的程序会在 `examples/verify_skip.txt` 中单独列出。
