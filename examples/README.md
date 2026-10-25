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

共 **203** 个示例，分布在 **10** 个章节。

| 章节 | 示例数 |
|------|--------|
| 第 1 章：认识 C 语言 | 17 |
| 第 2 章：运算符、条件、循环与函数 | 39 |
| 第 3 章：数组与字符串 | 33 |
| 第 4 章：指针与结构体 | 25 |
| 第 5 章：文件读写与实战 | 14 |
| 第 6 章：动态内存与链表 | 11 |
| 第 7 章：递归 | 17 |
| 第 8 章：排序与查找 | 11 |
| 第 9 章：数据结构入门 | 12 |
| 第 10 章：C 语言收官 | 24 |

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
| [2.1.7_short_circuit.c](chapter2/2.1.7_short_circuit.c) | 2.1.7 | [短路求值](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.8_assignment.c](chapter2/2.1.8_assignment.c) | 2.1.8 | [2.1.7 赋值运算符](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.9_precedence.c](chapter2/2.1.9_precedence.c) | 2.1.9 | [2.1.8 运算符优先级](<../chapter2/sections/2.1 运算符.md>) |
| [2.1.10_time_conversion.c](chapter2/2.1.10_time_conversion.c) | 2.1.10 | [2.1.9 综合示例：秒数换算](<../chapter2/sections/2.1 运算符.md>) |
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
| [4.1.1_first_pointer.c](chapter4/4.1.1_first_pointer.c) | 4.1.1 | [4.1.1 取地址和解引用](<../chapter4/sections/4.1 指针基础.md>) |
| [4.1.2_swap.c](chapter4/4.1.2_swap.c) | 4.1.2 | [4.1.2 用指针交换两个变量](<../chapter4/sections/4.1 指针基础.md>) |
| [4.1.3_pointer_size.c](chapter4/4.1.3_pointer_size.c) | 4.1.3 | [4.1.3 指针的大小和类型](<../chapter4/sections/4.1 指针基础.md>) |
| [4.1.4_null_pointer.c](chapter4/4.1.4_null_pointer.c) | 4.1.4 | [4.1.4 NULL：空指针](<../chapter4/sections/4.1 指针基础.md>) |
| [4.2.1_array_decay.c](chapter4/4.2.1_array_decay.c) | 4.2.1 | [4.2.1 数组名的自动转换](<../chapter4/sections/4.2 指针与数组.md>) |
| [4.2.2_pointer_arith.c](chapter4/4.2.2_pointer_arith.c) | 4.2.2 | [4.2.2 指针算术](<../chapter4/sections/4.2 指针与数组.md>) |
| [4.2.3_index_equivalence.c](chapter4/4.2.3_index_equivalence.c) | 4.2.3 | [4.2.3 arr\[i\] 就是 (arr + i)](<../chapter4/sections/4.2 指针与数组.md>) |
| [4.2.4_array_param.c](chapter4/4.2.4_array_param.c) | 4.2.4 | [4.2.4 数组作为函数参数](<../chapter4/sections/4.2 指针与数组.md>) |
| [4.3.1_char_star_string.c](chapter4/4.3.1_char_star_string.c) | 4.3.1 | [4.3.1 char 与字符串字面量](<../chapter4/sections/4.3 指针与字符串.md>) |
| [4.3.2_my_strlen.c](chapter4/4.3.2_my_strlen.c) | 4.3.2 | [4.3.2 遍历字符串：以 '\\0' 为终点](<../chapter4/sections/4.3 指针与字符串.md>) |
| [4.3.3_string_modify.c](chapter4/4.3.3_string_modify.c) | 4.3.3 | [4.3.3 能修改的字符串和只读的字符串](<../chapter4/sections/4.3 指针与字符串.md>) |
| [4.3.4_vowel_count.c](chapter4/4.3.4_vowel_count.c) | 4.3.4 | [4.3.4 综合示例：统计元音字母](<../chapter4/sections/4.3 指针与字符串.md>) |
| [4.4.1_struct_basic.c](chapter4/4.4.1_struct_basic.c) | 4.4.1 | [4.4.1 定义和使用结构体](<../chapter4/sections/4.4 结构体.md>) |
| [4.4.2_struct_array.c](chapter4/4.4.2_struct_array.c) | 4.4.2 | [4.4.2 结构体数组](<../chapter4/sections/4.4 结构体.md>) |
| [4.4.3_struct_nested.c](chapter4/4.4.3_struct_nested.c) | 4.4.3 | [4.4.3 嵌套结构体](<../chapter4/sections/4.4 结构体.md>) |
| [4.4.4_struct_assign.c](chapter4/4.4.4_struct_assign.c) | 4.4.4 | [4.4.4 结构体赋值：整包复制](<../chapter4/sections/4.4 结构体.md>) |
| [4.5.1_arrow_operator.c](chapter4/4.5.1_arrow_operator.c) | 4.5.1 | [4.5.1 箭头运算符 -](<../chapter4/sections/4.5 结构体与指针.md>) |
| [4.5.2_struct_param.c](chapter4/4.5.2_struct_param.c) | 4.5.2 | [4.5.2 函数传结构体：传值还是传指针](<../chapter4/sections/4.5 结构体与指针.md>) |
| [4.5.3_struct_array_ptr.c](chapter4/4.5.3_struct_array_ptr.c) | 4.5.3 | [4.5.3 用指针遍历结构体数组](<../chapter4/sections/4.5 结构体与指针.md>) |
| [4.5.4_top_student.c](chapter4/4.5.4_top_student.c) | 4.5.4 | [4.5.4 综合示例：找出最高分学生](<../chapter4/sections/4.5 结构体与指针.md>) |
| [4.6.1_const_pointer.c](chapter4/4.6.1_const_pointer.c) | 4.6.1 | [4.6.1 const 与指针的四种组合](<../chapter4/sections/4.6 const 与多级指针.md>) |
| [4.6.2_void_pointer.c](chapter4/4.6.2_void_pointer.c) | 4.6.2 | [4.6.2 void ：万能指针](<../chapter4/sections/4.6 const 与多级指针.md>) |
| [4.6.3_double_pointer.c](chapter4/4.6.3_double_pointer.c) | 4.6.3 | [4.6.3 二级指针](<../chapter4/sections/4.6 const 与多级指针.md>) |
| [4.6.4_redirect_pointer.c](chapter4/4.6.4_redirect_pointer.c) | 4.6.4 | [4.6.3 二级指针](<../chapter4/sections/4.6 const 与多级指针.md>) |
| [4.7.1_student_manager_single.c](chapter4/4.7.1_student_manager_single.c) | 4.7.1 | [4.7.2 先看一个单文件版本](<../chapter4/sections/4.7 多文件工程与 Makefile.md>) |

## 第 5 章：文件读写与实战

| 文件 | 编号 | 出处 |
|------|------|------|
| [5.1.1_first_write.c](chapter5/5.1.1_first_write.c) | 5.1.1 | [5.1.2 打开与关闭：fopen 和 fclose](<../chapter5/sections/5.1 文件与 FILE.md>) |
| [5.1.2_open_fail.c](chapter5/5.1.2_open_fail.c) | 5.1.2 | [5.1.3 打开失败：永远检查 NULL](<../chapter5/sections/5.1 文件与 FILE.md>) |
| [5.1.3_modes_demo.c](chapter5/5.1.3_modes_demo.c) | 5.1.3 | [5.1.4 打开模式：r、w、a 和带 + 的模式](<../chapter5/sections/5.1 文件与 FILE.md>) |
| [5.2.1_fprintf_fscanf.c](chapter5/5.2.1_fprintf_fscanf.c) | 5.2.1 | [5.2.1 fprintf 和 fscanf：带格式的读写](<../chapter5/sections/5.2 读写文件.md>) |
| [5.2.2_fgetc_count.c](chapter5/5.2.2_fgetc_count.c) | 5.2.2 | [5.2.2 fgetc 和 fputc：一个字符一个字符处理](<../chapter5/sections/5.2 读写文件.md>) |
| [5.2.3_copy_file.c](chapter5/5.2.3_copy_file.c) | 5.2.3 | [5.2.3 综合示例：复制文件](<../chapter5/sections/5.2 读写文件.md>) |
| [5.3.1_fgets_lines.c](chapter5/5.3.1_fgets_lines.c) | 5.3.1 | [5.3.1 fgets：从文件读一行](<../chapter5/sections/5.3 行读写与安全输入.md>) |
| [5.3.2_strip_newline.c](chapter5/5.3.2_strip_newline.c) | 5.3.2 | [5.3.2 处理 fgets 保留的换行符](<../chapter5/sections/5.3 行读写与安全输入.md>) |
| [5.3.3_fputs_write.c](chapter5/5.3.3_fputs_write.c) | 5.3.3 | [5.3.3 fputs：往文件写一行](<../chapter5/sections/5.3 行读写与安全输入.md>) |
| [5.4.1_fseek_ftell.c](chapter5/5.4.1_fseek_ftell.c) | 5.4.1 | [5.4.1 文件位置：ftell、fseek、rewind](<../chapter5/sections/5.4 文件定位与二进制.md>) |
| [5.4.2_fwrite_fread.c](chapter5/5.4.2_fwrite_fread.c) | 5.4.2 | [5.4.3 fwrite 和 fread：整块读写](<../chapter5/sections/5.4 文件定位与二进制.md>) |
| [5.5.1_contact_save_load.c](chapter5/5.5.1_contact_save_load.c) | 5.5.1 | [5.5.2 保存与加载的完整实现](<../chapter5/sections/5.5 综合项目：通讯录存盘.md>) |
| [5.5.2_bad_count.c](chapter5/5.5.2_bad_count.c) | 5.5.2 | [5.5.6 眼见为实：被篡改的文件头](<../chapter5/sections/5.5 综合项目：通讯录存盘.md>) |
| [5.5.3_contact_add.c](chapter5/5.5.3_contact_add.c) | 5.5.3 | [5.5.7 添加联系人：一个能交互的小工具](<../chapter5/sections/5.5 综合项目：通讯录存盘.md>) |

## 第 6 章：动态内存与链表

| 文件 | 编号 | 出处 |
|------|------|------|
| [6.1.2_malloc_first.c](chapter6/6.1.2_malloc_first.c) | 6.1.2 | [6.1.2 malloc：申请内存](<../chapter6/sections/6.1 动态内存.md>) |
| [6.1.4_dynamic_array.c](chapter6/6.1.4_dynamic_array.c) | 6.1.4 | [6.1.4 动态数组：运行时定大小](<../chapter6/sections/6.1 动态内存.md>) |
| [6.1.5_free_null.c](chapter6/6.1.5_free_null.c) | 6.1.5 | [6.1.5 free：归还内存](<../chapter6/sections/6.1 动态内存.md>) |
| [6.2.1_calloc_zero.c](chapter6/6.2.1_calloc_zero.c) | 6.2.1 | [6.2.1 calloc：申请并清零](<../chapter6/sections/6.2 内存陷阱.md>) |
| [6.2.2_realloc_grow.c](chapter6/6.2.2_realloc_grow.c) | 6.2.2 | [6.2.2 realloc：动态扩容](<../chapter6/sections/6.2 内存陷阱.md>) |
| [6.2.3_auto_grow.c](chapter6/6.2.3_auto_grow.c) | 6.2.3 | [6.2.3 realloc 实战：自动扩容的数组](<../chapter6/sections/6.2 内存陷阱.md>) |
| [6.3.3_create_node.c](chapter6/6.3.3_create_node.c) | 6.3.3 | [6.3.3 创建节点](<../chapter6/sections/6.3 链表.md>) |
| [6.3.6_list_basic.c](chapter6/6.3.6_list_basic.c) | 6.3.6 | [6.3.6 遍历：顺着 next 走](<../chapter6/sections/6.3 链表.md>) |
| [6.4.1_list_find.c](chapter6/6.4.1_list_find.c) | 6.4.1 | [6.4.1 查找](<../chapter6/sections/6.4 链表进阶.md>) |
| [6.4.3_list_delete.c](chapter6/6.4.3_list_delete.c) | 6.4.3 | [6.4.3 删除的完整演示](<../chapter6/sections/6.4 链表进阶.md>) |
| [6.4.4_score_list.c](chapter6/6.4.4_score_list.c) | 6.4.4 | [6.4.4 综合项目：成绩单链表](<../chapter6/sections/6.4 链表进阶.md>) |

## 第 7 章：递归

| 文件 | 编号 | 出处 |
|------|------|------|
| [7.1.1_countdown.c](chapter7/7.1.1_countdown.c) | 7.1.1 | [7.1.1 第一个递归程序](<../chapter7/sections/7.1 递归入门.md>) |
| [7.1.3_factorial.c](chapter7/7.1.3_factorial.c) | 7.1.3 | [7.1.3 阶乘：返回值的递归](<../chapter7/sections/7.1 递归入门.md>) |
| [7.1.4_sum_power.c](chapter7/7.1.4_sum_power.c) | 7.1.4 | [7.1.4 两个基础例：求和与幂](<../chapter7/sections/7.1 递归入门.md>) |
| [7.2.3_print_order.c](chapter7/7.2.3_print_order.c) | 7.2.3 | [7.2.3 打印放在哪，顺序就反了](<../chapter7/sections/7.2 调用栈与栈溢出.md>) |
| [7.2.4_digits.c](chapter7/7.2.4_digits.c) | 7.2.4 | [7.2.4 拆数字：各位和与倒序打印](<../chapter7/sections/7.2 调用栈与栈溢出.md>) |
| [7.2.5_gcd.c](chapter7/7.2.5_gcd.c) | 7.2.5 | [7.2.5 最大公约数：另一条收敛路径](<../chapter7/sections/7.2 调用栈与栈溢出.md>) |
| [7.3.2_fib_naive.c](chapter7/7.3.2_fib_naive.c) | 7.3.2 | [7.3.2 递归版：照着公式抄](<../chapter7/sections/7.3 斐波那契与递归代价.md>) |
| [7.3.3_fib_cost.c](chapter7/7.3.3_fib_cost.c) | 7.3.3 | [7.3.3 代价：同一个子问题算了一遍又一遍](<../chapter7/sections/7.3 斐波那契与递归代价.md>) |
| [7.3.4_fib_memo.c](chapter7/7.3.4_fib_memo.c) | 7.3.4 | [7.3.4 记忆化：算过的存起来](<../chapter7/sections/7.3 斐波那契与递归代价.md>) |
| [7.3.5_fib_loop.c](chapter7/7.3.5_fib_loop.c) | 7.3.5 | [7.3.5 循环版：从前往后推](<../chapter7/sections/7.3 斐波那契与递归代价.md>) |
| [7.4.3_hanoi.c](chapter7/7.4.3_hanoi.c) | 7.4.3 | [7.4.3 递归解法](<../chapter7/sections/7.4 汉诺塔与分治.md>) |
| [7.4.4_hanoi_formula.c](chapter7/7.4.4_hanoi_formula.c) | 7.4.4 | [7.4.4 验证步数公式](<../chapter7/sections/7.4 汉诺塔与分治.md>) |
| [7.4.5_array_sum.c](chapter7/7.4.5_array_sum.c) | 7.4.5 | [7.4.5 分而治之](<../chapter7/sections/7.4 汉诺塔与分治.md>) |
| [7.5.2_list_print.c](chapter7/7.5.2_list_print.c) | 7.5.2 | [7.5.2 递归遍历：正序与逆序打印](<../chapter7/sections/7.5 递归操作链表.md>) |
| [7.5.3_list_stats.c](chapter7/7.5.3_list_stats.c) | 7.5.3 | [7.5.3 计数与求和](<../chapter7/sections/7.5 递归操作链表.md>) |
| [7.5.4_list_free.c](chapter7/7.5.4_list_free.c) | 7.5.4 | [7.5.4 递归查找与整链释放](<../chapter7/sections/7.5 递归操作链表.md>) |
| [7.5.5_list_tools.c](chapter7/7.5.5_list_tools.c) | 7.5.5 | [7.5.5 综合实战：递归链表工具箱](<../chapter7/sections/7.5 递归操作链表.md>) |

## 第 8 章：排序与查找

| 文件 | 编号 | 出处 |
|------|------|------|
| [8.1.1_bubble_sort.c](chapter8/8.1.1_bubble_sort.c) | 8.1.1 | [8.1.3 基本实现](<../chapter8/sections/8.1 冒泡排序.md>) |
| [8.1.2_bubble_sort_opt.c](chapter8/8.1.2_bubble_sort_opt.c) | 8.1.2 | [8.1.5 提前退出：swapped 标志](<../chapter8/sections/8.1 冒泡排序.md>) |
| [8.2.1_selection_sort.c](chapter8/8.2.1_selection_sort.c) | 8.2.1 | [8.2.2 实现](<../chapter8/sections/8.2 选择排序.md>) |
| [8.2.2_selection_desc.c](chapter8/8.2.2_selection_desc.c) | 8.2.2 | [8.2.4 变一变方向：从大到小](<../chapter8/sections/8.2 选择排序.md>) |
| [8.3.1_insertion_sort.c](chapter8/8.3.1_insertion_sort.c) | 8.3.1 | [8.3.2 实现](<../chapter8/sections/8.3 插入排序.md>) |
| [8.4.1_linear_search.c](chapter8/8.4.1_linear_search.c) | 8.4.1 | [8.4.1 线性查找：从头找到尾](<../chapter8/sections/8.4 线性查找与二分查找.md>) |
| [8.4.2_binary_search.c](chapter8/8.4.2_binary_search.c) | 8.4.2 | [8.4.2 二分查找：每次砍掉一半](<../chapter8/sections/8.4 线性查找与二分查找.md>) |
| [8.4.3_sort_then_search.c](chapter8/8.4.3_sort_then_search.c) | 8.4.3 | [8.4.4 先排序，再二分：黄金搭档](<../chapter8/sections/8.4 线性查找与二分查找.md>) |
| [8.5.1_partition.c](chapter8/8.5.1_partition.c) | 8.5.1 | [8.5.2 一趟分区：Lomuto 写法](<../chapter8/sections/8.5 综合项目：快速排序.md>) |
| [8.5.2_quick_sort.c](chapter8/8.5.2_quick_sort.c) | 8.5.2 | [8.5.3 加上递归，快排完成](<../chapter8/sections/8.5 综合项目：快速排序.md>) |
| [8.5.3_score_system.c](chapter8/8.5.3_score_system.c) | 8.5.3 | [8.5.6 综合项目：成绩排序加查找小系统](<../chapter8/sections/8.5 综合项目：快速排序.md>) |

## 第 9 章：数据结构入门

| 文件 | 编号 | 出处 |
|------|------|------|
| [9.1.1_stack_basic.c](chapter9/9.1.1_stack_basic.c) | 9.1.1 | [9.1.2 用数组实现栈](<../chapter9/sections/9.1 栈.md>) |
| [9.1.2_stack_trace.c](chapter9/9.1.2_stack_trace.c) | 9.1.2 | [9.1.3 慢镜头：top 怎么走](<../chapter9/sections/9.1 栈.md>) |
| [9.1.3_bracket_check.c](chapter9/9.1.3_bracket_check.c) | 9.1.3 | [9.1.4 应用：括号匹配检查器](<../chapter9/sections/9.1 栈.md>) |
| [9.2.1_circular_queue.c](chapter9/9.2.1_circular_queue.c) | 9.2.1 | [9.2.3 循环队列：让数组首尾相接](<../chapter9/sections/9.2 队列.md>) |
| [9.2.2_print_queue.c](chapter9/9.2.2_print_queue.c) | 9.2.2 | [9.2.5 应用：模拟打印队列](<../chapter9/sections/9.2 队列.md>) |
| [9.3.1_build_tree.c](chapter9/9.3.1_build_tree.c) | 9.3.1 | [9.3.3 造一棵树：先手动接线](<../chapter9/sections/9.3 二叉树.md>) |
| [9.3.2_traversals.c](chapter9/9.3.2_traversals.c) | 9.3.2 | [9.3.4 三种遍历](<../chapter9/sections/9.3 二叉树.md>) |
| [9.3.3_tree_tools.c](chapter9/9.3.3_tree_tools.c) | 9.3.3 | [9.3.5 递归小工具：计数、深度、释放](<../chapter9/sections/9.3 二叉树.md>) |
| [9.4.1_bst_insert.c](chapter9/9.4.1_bst_insert.c) | 9.4.1 | [9.4.2 插入：一路走到空位](<../chapter9/sections/9.4 二叉查找树项目.md>) |
| [9.4.2_bst_project.c](chapter9/9.4.2_bst_project.c) | 9.4.2 | [9.4.4 完整项目：一棵会排序、会查找的树](<../chapter9/sections/9.4 二叉查找树项目.md>) |
| [9.5.1_bst_delete.c](chapter9/9.5.1_bst_delete.c) | 9.5.1 | [9.5.5 完整实现：一个函数吃下三种情况](<../chapter9/sections/9.5 BST 的删除.md>) |
| [9.5.2_bst_delete_demo.c](chapter9/9.5.2_bst_delete_demo.c) | 9.5.2 | [9.5.6 一次删完三种情况的演示](<../chapter9/sections/9.5 BST 的删除.md>) |

## 第 10 章：C 语言收官

| 文件 | 编号 | 出处 |
|------|------|------|
| [10.1.1_include_macro.c](chapter10/10.1.1_include_macro.c) | 10.1.1 | [10.1.2 常量宏：编译前就替换掉的文本](<../chapter10/sections/10.1 预处理与宏.md>) |
| [10.1.2_macro_vs_const.c](chapter10/10.1.2_macro_vs_const.c) | 10.1.2 | [10.1.3 常量宏还是 const](<../chapter10/sections/10.1 预处理与宏.md>) |
| [10.1.3_square_macro.c](chapter10/10.1.3_square_macro.c) | 10.1.3 | [10.1.4 带参宏：披着函数外衣的文本替换](<../chapter10/sections/10.1 预处理与宏.md>) |
| [10.1.4_square_side_effect.c](chapter10/10.1.4_square_side_effect.c) | 10.1.4 | [10.1.4 带参宏：披着函数外衣的文本替换](<../chapter10/sections/10.1 预处理与宏.md>) |
| [10.1.5_debug_switch.c](chapter10/10.1.5_debug_switch.c) | 10.1.5 | [10.1.5 多行宏与 do-while(0)](<../chapter10/sections/10.1 预处理与宏.md>) |
| [10.2.1_binary_basics.c](chapter10/10.2.1_binary_basics.c) | 10.2.1 | [10.2.1 二进制速成：把数摊开成位](<../chapter10/sections/10.2 位运算.md>) |
| [10.2.2_six_operators.c](chapter10/10.2.2_six_operators.c) | 10.2.2 | [10.2.2 六个位运算符](<../chapter10/sections/10.2 位运算.md>) |
| [10.2.3_shift_rules.c](chapter10/10.2.3_shift_rules.c) | 10.2.3 | [10.2.3 移位：左移翻倍，右移减半（有前提）](<../chapter10/sections/10.2 位运算.md>) |
| [10.2.4_permission_flags.c](chapter10/10.2.4_permission_flags.c) | 10.2.4 | [10.2.4 掩码：一个 int 管 32 个开关](<../chapter10/sections/10.2 位运算.md>) |
| [10.2.5_bitmask_check.c](chapter10/10.2.5_bitmask_check.c) | 10.2.5 | [10.2.4 掩码：一个 int 管 32 个开关](<../chapter10/sections/10.2 位运算.md>) |
| [10.3.1_first_function_pointer.c](chapter10/10.3.1_first_function_pointer.c) | 10.3.1 | [10.3.1 声明、赋值、调用](<../chapter10/sections/10.3 函数指针.md>) |
| [10.3.2_op_table.c](chapter10/10.3.2_op_table.c) | 10.3.2 | [10.3.2 函数指针数组：按下标选函数](<../chapter10/sections/10.3 函数指针.md>) |
| [10.3.3_apply_to_array.c](chapter10/10.3.3_apply_to_array.c) | 10.3.3 | [10.3.3 把函数当参数传：apply 的雏形](<../chapter10/sections/10.3 函数指针.md>) |
| [10.3.4_menu_demo.c](chapter10/10.3.4_menu_demo.c) | 10.3.4 | [10.3.4 函数指针数组做菜单分发](<../chapter10/sections/10.3 函数指针.md>) |
| [10.4.1_qsort_int.c](chapter10/10.4.1_qsort_int.c) | 10.4.1 | [10.4.3 第一个实战：int 数组排序](<../chapter10/sections/10.4 qsort 与比较器.md>) |
| [10.4.2_qsort_overflow.c](chapter10/10.4.2_qsort_overflow.c) | 10.4.2 | [10.4.2 比较器：三条约定](<../chapter10/sections/10.4 qsort 与比较器.md>) |
| [10.4.3_qsort_desc_double.c](chapter10/10.4.3_qsort_desc_double.c) | 10.4.3 | [10.4.3 第一个实战：int 数组排序](<../chapter10/sections/10.4 qsort 与比较器.md>) |
| [10.4.4_qsort_struct.c](chapter10/10.4.4_qsort_struct.c) | 10.4.4 | [10.4.4 给结构体排序](<../chapter10/sections/10.4 qsort 与比较器.md>) |
| [10.4.5_qsort_two_keys.c](chapter10/10.4.5_qsort_two_keys.c) | 10.4.5 | [10.4.5 多关键字比较：总分相同比语文](<../chapter10/sections/10.4 qsort 与比较器.md>) |
| [10.5.1_contact_milestone1.c](chapter10/10.5.1_contact_milestone1.c) | 10.5.1 | [10.5.2 里程碑一：添加与显示](<../chapter10/sections/10.5 毕业项目：通讯录.md>) |
| [10.5.2_contact_milestone2.c](chapter10/10.5.2_contact_milestone2.c) | 10.5.2 | [10.5.3 里程碑二：查找与排序](<../chapter10/sections/10.5 毕业项目：通讯录.md>) |
| [10.5.3_contact_milestone3.c](chapter10/10.5.3_contact_milestone3.c) | 10.5.3 | [10.5.4 里程碑三：存盘与读盘](<../chapter10/sections/10.5 毕业项目：通讯录.md>) |
| [10.5.4_contact_menu_demo.c](chapter10/10.5.4_contact_menu_demo.c) | 10.5.4 | [10.5.5 里程碑四：函数指针数组分发菜单](<../chapter10/sections/10.5 毕业项目：通讯录.md>) |
| [10.5.5_contact_full.c](chapter10/10.5.5_contact_full.c) | 10.5.5 | [10.5.6 完整版：毕业项目](<../chapter10/sections/10.5 毕业项目：通讯录.md>) |

---

示例只保证在 `cc -std=c11 -Wall -Wextra -Werror -pedantic` 下能编译。
涉及输入或外部文件的程序会在 `examples/verify_skip.txt` 中单独列出。
