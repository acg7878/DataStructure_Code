# 8642 快速排序

> 时间限制:1000MS 代码长度限制:10KB
> 提交次数:2105 通过次数:1352
> 题型: 编程题 语言: G++;GCC

## Description

用函数实现快速排序，并输出每次分区后排序的结果

## 输入格式

第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据

## 输出格式

每行输出每趟排序的结果，数据之间用一个空格分隔

## 输入样例

10
5 4 8 0 9 3 2 6 7 1

## 输出样例

1 4 2 0 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 3 4 5 9 6 7 8
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 7 6 8 9
0 1 2 3 4 5 6 7 8 9