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

共 **89** 个示例，分布在 **4** 个章节。

| 章节 | 示例数 |
|------|--------|
| 第 1 章：认识 C 语言 | 17 |
| 第 2 章：运算符、条件、循环与函数 | 38 |
| 第 3 章：数组与字符串 | 33 |
| 第 4 章：指针与结构体 | 1 |

## 第 1 章：认识 C 语言

| 文件 | 编号 | 出处 |
|------|------|------|
| [1.1.5_hello_preview.c](chapter1/1.1.5_hello_preview.c) | 1.1.5 | [1.1.5 你的第一个程序长什么样](<../chapter1/sections/1.1 C 语言是什么.md>) |
| [1.3.1_hello.c](chapter1/1.3.1_hello.c) | 1.3.1 | [1.3.1 写出 hello.c](<../chapter1/sections/1.3 第一个 C 程序.md>) |
| [1.3.3_escape.c](chapter1/1.3.3_escape.c) | 1.3.3 | [1.3.3 转义字符和 \\n](<../chapter1/sections/1.3 第一个 C 程序.md>) |
| [1.3.4_placeholder.c](chapter1/1.3.4_placeholder.c) | 1.3.4 | [1.3.4 printf 占位符初步](<../chapter1/sections/1.3 第一个 C 程序.md>) |
| [1.4.2_variables.c](chapter1/1.4.2_variables.c) | 1.4.2 | [1.4.2 声明、赋值和初始化](<../chapter1/sections/1.4 变量与数据类型.md>) |
| [1.4.3_sizeof_types.c](chapter1/1.4.3_sizeof_types.c) | 1.4.3 | [1.4.3 基本数据类型](<../chapter1/sections/1.4 变量与数据类型.md>) |
| [1.4.4_printf_formats.c](chapter1/1.4.4_printf_formats.c) | 1.4.4 | [1.4.4 printf 格式符表](<../chapter1/sections/1.4 变量与数据类型.md>) |
| [1.4.5_constants.c](chapter1/1.4.5_constants.c) | 1.4.5 | [1.4.5 常量](<../chapter1/sections/1.4 变量与数据类型.md>) |
| [1.4.6_overflow.c](chapter1/1.4.6_overflow.c) | 1.4.6 | [int 的范围与溢出](<../chapter1/sections/1.4 变量与数据类型.md>) |
| [1.4.7_char_ascii.c](chapter1/1.4.7_char_ascii.c) | 1.4.7 | [char 的真面目：数字](<../chapter1/sections/1.4 变量与数据类型.md>) |
| [1.5.1_scan_two.c](chapter1/1.5.1_scan_two.c) | 1.5.1 | [1.5.1 scanf 的基本用法](<../chapter1/sections/1.5 scanf 与输入.md>) |
| [1.5.2_scan_check.c](chapter1/1.5.2_scan_check.c) | 1.5.2 | [1.5.2 必须检查 scanf 的返回值](<../chapter1/sections/1.5 scanf 与输入.md>) |
| [1.5.3_scan_char_bad.c](chapter1/1.5.3_scan_char_bad.c) | 1.5.3 | [1.5.3 回车残留问题](<../chapter1/sections/1.5 scanf 与输入.md>) |
| [1.5.4_scan_char.c](chapter1/1.5.4_scan_char.c) | 1.5.4 | [解法二：手动读掉残留的回车](<../chapter1/sections/1.5 scanf 与输入.md>) |
| [1.5.5_scan_name.c](chapter1/1.5.5_scan_name.c) | 1.5.5 | [完整示例](<../chapter1/sections/1.5 scanf 与输入.md>) |
| [1.5.6_scan_double.c](chapter1/1.5.6_scan_double.c) | 1.5.6 | [1.5.6 读浮点数](<../chapter1/sections/1.5 scanf 与输入.md>) |
| [1.5.7_scan_loop.c](chapter1/1.5.7_scan_loop.c) | 1.5.7 | [1.5.7 输入校验：不合法就重来](<../chapter1/sections/1.5 scanf 与输入.md>) |

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

## 第 3 章：数组与字符串

| 文件 | 编号 | 出处 |
|------|------|------|
| [3.1.2_array_init.c](chapter3/3.1.2_array_init.c) | 3.1.2 | [3.1.2 声明和初始化数组](<../chapter3/sections/3.1 数组.md>) |
| [3.1.3_array_access.c](chapter3/3.1.3_array_access.c) | 3.1.3 | [3.1.3 下标：从 0 开始](<../chapter3/sections/3.1 数组.md>) |
| [3.1.5_array_traverse.c](chapter3/3.1.5_array_traverse.c) | 3.1.5 | [3.1.5 遍历数组](<../chapter3/sections/3.1 数组.md>) |
| [3.1.6_array_sizeof.c](chapter3/3.1.6_array_sizeof.c) | 3.1.6 | [3.1.6 用 sizeof 计算元素个数](<../chapter3/sections/3.1 数组.md>) |
| [3.1.8_array_stats.c](chapter3/3.1.8_array_stats.c) | 3.1.8 | [3.1.8 统计：求和、平均分、最值](<../chapter3/sections/3.1 数组.md>) |
| [3.1.9_array_reverse.c](chapter3/3.1.9_array_reverse.c) | 3.1.9 | [3.1.9 逆序输出](<../chapter3/sections/3.1 数组.md>) |
| [3.1.10_array_palindrome.c](chapter3/3.1.10_array_palindrome.c) | 3.1.10 | [3.1.10 判断回文](<../chapter3/sections/3.1 数组.md>) |
| [3.2.2_matrix_init.c](chapter3/3.2.2_matrix_init.c) | 3.2.2 | [3.2.2 初始化二维数组](<../chapter3/sections/3.2 二维数组.md>) |
| [3.2.4_matrix_macro.c](chapter3/3.2.4_matrix_macro.c) | 3.2.4 | [3.2.4 用宏定义行数和列数](<../chapter3/sections/3.2 二维数组.md>) |
| [3.2.5_matrix_traverse.c](chapter3/3.2.5_matrix_traverse.c) | 3.2.5 | [3.2.5 嵌套循环遍历](<../chapter3/sections/3.2 二维数组.md>) |
| [3.2.6_matrix_transpose.c](chapter3/3.2.6_matrix_transpose.c) | 3.2.6 | [3.2.6 例：矩阵转置](<../chapter3/sections/3.2 二维数组.md>) |
| [3.2.7_matrix_row_sum.c](chapter3/3.2.7_matrix_row_sum.c) | 3.2.7 | [3.2.7 例：按行求和](<../chapter3/sections/3.2 二维数组.md>) |
| [3.3.2_string_init.c](chapter3/3.3.2_string_init.c) | 3.3.2 | [3.3.2 初始化字符串的几种写法](<../chapter3/sections/3.3 字符串基础.md>) |
| [3.3.3_sizeof_strlen.c](chapter3/3.3.3_sizeof_strlen.c) | 3.3.3 | [3.3.3 sizeof vs strlen](<../chapter3/sections/3.3 字符串基础.md>) |
| [3.3.4_scanf_width.c](chapter3/3.3.4_scanf_width.c) | 3.3.4 | [3.3.4 scanf 读字符串：必须限宽](<../chapter3/sections/3.3 字符串基础.md>) |
| [3.3.5_fgets_demo.c](chapter3/3.3.5_fgets_demo.c) | 3.3.5 | [3.3.5 fgets：推荐的读入方式](<../chapter3/sections/3.3 字符串基础.md>) |
| [3.3.6_strlen_utf8.c](chapter3/3.3.6_strlen_utf8.c) | 3.3.6 | [3.3.6 中文字符串与编码](<../chapter3/sections/3.3 字符串基础.md>) |
| [3.4.2_strlen_chars.c](chapter3/3.4.2_strlen_chars.c) | 3.4.2 | [3.4.2 strlen：求长度](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.4.3_strcpy_demo.c](chapter3/3.4.3_strcpy_demo.c) | 3.4.3 | [3.4.3 strcpy：能复制，但不安全](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.4.4_strncpy_demo.c](chapter3/3.4.4_strncpy_demo.c) | 3.4.4 | [3.4.4 strncpy：有限复制，有坑](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.4.5_snprintf_demo.c](chapter3/3.4.5_snprintf_demo.c) | 3.4.5 | [3.4.5 snprintf：推荐的复制方式](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.4.6_strcat_demo.c](chapter3/3.4.6_strcat_demo.c) | 3.4.6 | [3.4.6 strcat：拼接与它的风险](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.4.7_strncat_demo.c](chapter3/3.4.7_strncat_demo.c) | 3.4.7 | [3.4.7 strncat：带上限的拼接](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.4.8_strcmp_demo.c](chapter3/3.4.8_strcmp_demo.c) | 3.4.8 | [3.4.8 strcmp：比较字符串](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.4.9_strstr_demo.c](chapter3/3.4.9_strstr_demo.c) | 3.4.9 | [3.4.9 strstr：查找子串](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.4.10_my_strlen.c](chapter3/3.4.10_my_strlen.c) | 3.4.10 | [3.4.10 动手实现 mystrlen](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.4.11_my_strcmp.c](chapter3/3.4.11_my_strcmp.c) | 3.4.11 | [3.4.11 动手实现 mystrcmp](<../chapter3/sections/3.4 字符串函数.md>) |
| [3.5.1_array_param.c](chapter3/3.5.1_array_param.c) | 3.5.1 | [3.5.1 数组作参数：退化为指针](<../chapter3/sections/3.5 数组与函数.md>) |
| [3.5.3_array_average.c](chapter3/3.5.3_array_average.c) | 3.5.3 | [3.5.3 一维数组传参示例](<../chapter3/sections/3.5 数组与函数.md>) |
| [3.5.4_matrix_param.c](chapter3/3.5.4_matrix_param.c) | 3.5.4 | [3.5.4 二维数组传参：列数必须写死](<../chapter3/sections/3.5 数组与函数.md>) |
| [3.5.5_bubble_sort.c](chapter3/3.5.5_bubble_sort.c) | 3.5.5 | [3.5.5 冒泡排序](<../chapter3/sections/3.5 数组与函数.md>) |
| [3.5.6_bubble_sort_opt.c](chapter3/3.5.6_bubble_sort_opt.c) | 3.5.6 | [3.5.6 冒泡排序的优化：提前退出](<../chapter3/sections/3.5 数组与函数.md>) |
| [3.5.7_score_stats.c](chapter3/3.5.7_score_stats.c) | 3.5.7 | [3.5.7 综合示例：成绩统计程序](<../chapter3/sections/3.5 数组与函数.md>) |

## 第 4 章：指针与结构体

| 文件 | 编号 | 出处 |
|------|------|------|
| [4.7.1_student_manager_single.c](chapter4/4.7.1_student_manager_single.c) | 4.7.1 | [4.7.2 先看一个单文件版本](<../chapter4/sections/4.7 多文件工程与 Makefile.md>) |

---

示例只保证在 `cc -std=c11 -Wall -Wextra -Werror -pedantic` 下能编译。
涉及输入或外部文件的程序会在 `examples/verify_skip.txt` 中单独列出。
