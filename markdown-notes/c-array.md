---
title: 'C语言-数组'
date: 2022-01-08 18:40:14
tags: [C]
published: true
hideInList: false
feature: /post-images/c-array.png
isTop: false
---
# 1. 一维数组
## 1.1 一维数组的创建和初始化
### 1.1.1 数组的创建
**数组是一组相同类型元素的集合。数组的创建方式：**
```
type_t  arr_name    [const_n];
//type_t 是指数组的元素类型
//const_n 是一个常量表达式，用来指定数组的大小
//C99语法支持[]内为变量
```
数组创建的示例：
```
//code1
int arr1[10];

//code2
int count = 10;
int arr2[count];//C99可以这样做

//code3
char arr3[10];
float arr4[1];
double arr5[20];
```
**注：** 数组创建。\[]中要给一个**常量**才可以，不能使用变量。

### 1.1.2 数组的初始化
数组的初始化是指，在创建数组的同时给数组的内容一些合理初始值（初始化）。看代码：
```
int arr1[10] = {1,2,3,4,5,6,7,8,9,10};//完全初始化
int arr2[10]= {1,2,3,4,5}//不完全初始化
int arr3[]= {1,2,3,4};//整型数组
char arr4[3]= {'a', 98 , 'c' };//字符数组
char arr5[] = {'a', 'b', 'c'};
char arr6[]= "abcdef";
```
数组在创建的时候如果想不指定数组确定的大小就得初始化。数组的元素个数根据初始化的内容来确定。但是对于下面的代码要区分，内存中如何分配。
```
char arr1[] = "abc";
char arr2[3] = {'a', 'b', 'c'};
```

## 1.2 一维数组的使用
对于数组的使用，之前有一个操作符：\[]，下标引用操作符。它其实就是数组访问的操作符，看代码：
```
int main()
{
    int arr[10] = {0};
    arr[4] = 5;
    //printf("%d\n", arr[4]);

    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < sz; i++)
    {
        printf("%d", arr[i]);//访问元素
    }
    return 0;
}
```
1. 数组是使用下标来访问的，下标是从0开始。
2. 数组的大小可以通过计算能得到。

```
int arr[10];
int sz = sizeof(arr) / sizeof(arr[0]);
//总大小除以第一个元素的大小
//数组有十个元素，int类型为4字节，总大小为40字节
```

## 1.3 一维数组在内存中的存储
接下来讨论数组在内存中过的存储：
```
int main()
{
    int arr[10] = {0};
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("&arr[%d] = %p\n", i, &arr[i]);
        //%p-按地址的格式打印，为十六进制
        //每个元素地址之间差四个地址编号
    }
    return 0;
}
```
上述代码打印值为：
```
&arr[0] = 000000B2C8DBFBA8
&arr[1] = 000000B2C8DBFBAC
&arr[2] = 000000B2C8DBFBB0
&arr[3] = 000000B2C8DBFBB4
&arr[4] = 000000B2C8DBFBB8
&arr[5] = 000000B2C8DBFBBC
&arr[6] = 000000B2C8DBFBC0
&arr[7] = 000000B2C8DBFBC4
&arr[8] = 000000B2C8DBFBC8
&arr[9] = 000000B2C8DBFBCC
//可以看到数组在内存中是连续存放的
```
1. 一维数组在内存中是连续存放的
2. 随着数组下标的增长，地址是由低到高变化

而数组名是数组首元素的地址，有以下代码：
```
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int* p = arr;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *p);//1 2 3 4 5 6 7 8 9 10
        p++;
    }
    return 0;
}
```
正是因为**数组在内存中是连续存放的**，所以代码可以这样写。

# 2. 二维数组
## 2.1 二维数组的创建和初始化
### 2.1.1 二维数组的创建
```
//数组创建
int arr[3][4];
char arr[3][4];
double arr[2][4];
```
### 2.1.2 二维数组的初始化
```
//二维数组的初始化
int arr[3][4] = {1,2,3,4};//按顺序存放。不完全初始化，后面补0
int arr[3][4] = {{1,2},{4,5}};//第一行放1 2 0 0，第二行放4 5 0 0
int arr[][4] = {{2,3}, {4,5}};//行数可以省略，列数不可以
```
## 2.2 二维数组的使用
二维数组的使用也是通过下标的方式。看代码：
```
#include<stdio.h>

int main()
{
    int arr[][4] = {{1,2},{3,4},{4,5}};//数组初始化
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++)//行数
    {
        for (j = 0; j < 4; j++)//列数
        {
            printf("%d ", arr[i][j]);
            //通过对应的坐标，打印数值
            //打印第i行，下标为j的元素
        }
        printf("\n");//每打印一行就换一行
    }
    return 0;
}
```
上述代码打印值为：
```
1 2 0 0 
3 4 0 0
4 5 0 0
```

## 2.2 二维数组在内存中过的存储
像一维数组一样，这里尝试打印二维数组的每个元素
```
#include<stdio.h>

int main()
{
    int arr[][4] = {{1,2},{3,4},{4,5}};//数组初始化
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++)//行数
    {
        for (j = 0; j < 4; j++)//列数
        {
            printf("&arr[%d][%d] = %p\n ", i, j, arr[i][j]);
        }
        printf("\n");
    }
    return 0;
    return 0;
}
```
上述代码的打印值为：
```
&arr[0][0] = 000000FD12FBF6F8
&arr[0][1] = 000000FD12FBF6FC
&arr[0][2] = 000000FD12FBF700
&arr[0][3] = 000000FD12FBF704

&arr[1][0] = 000000FD12FBF708
&arr[1][1] = 000000FD12FBF70C
&arr[1][2] = 000000FD12FBF710
&arr[1][3] = 000000FD12FBF714

&arr[2][0] = 000000FD12FBF718
&arr[2][1] = 000000FD12FBF71C
&arr[2][2] = 000000FD12FBF720
&arr[2][3] = 000000FD12FBF724
//与一维数组一样，二位数组在内存中也是连续存放的，每个地址之间差4
//只需要第一个元素的地址，就可以知道其他元素的地址
```
# 3. 数组作为函数参数
在编写代码的时候，会将数组作为参数传给函数。比如：我要实现一个冒泡排序函数将一个整型数组排序。我将会这样使用该函数：
在开始之前，首先说明一下冒泡排序的思想：
```
//冒泡排序是将两个相邻的元素进行比较，并且可能的话需要交换
//例如有一个降序数组，需要重新排序成升序数组，通过冒泡排序就会这样实现：
9 8 7 6 5 4 3 2 1 0
8 9 7 6 5 4 3 2 1 0
8 7 9 6 5 4 3 2 1 0
8 7 6 9 5 4 3 2 1 0 
......
8 7 6 5 4 3 2 1 0 9
//这是一趟冒泡排序，十个数字需要跑九趟
//最终的排序的结果为：
0 1 2 3 4 5 6 7 8 9 10
```
最终实现代码如下：
```
#include<stdio.h>

void bubble_sort(int arr[], int sz)//指针，形参改变实参
{
    int i = 0;
    for (i = 0; i < sz; i++)//确定趟数
    {
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        //一趟冒泡排序的过程
        //十个元素，要跑九趟，有八对数字要比
        //所以循环条件为sz - 1 - i
        {
            if(arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                //若前面一个数大于后面一个数，则互相交换
            }
        }
    }
}

int main()
{
    int i = 0;
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr,sz);//arr传过去的是首元素地址
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);//打印排序后的数组0 1 2 3 4 5 6 7 8 9
    }
    return 0;
}
```
## 3.1 数组名
数组名是数组首元素的地址，但是有两个例外：
```
1.sizeof(数组名) - 数组名表示整个数组 - 计算的是整个数组的大小，单位是字节
2.&数组名 - 数组名表示整个数组 - 取出的是整个数组的地址
```
# 4. 数组的应用实例
👉[三子棋](https://urtaome.com/post/c-tictactoe/)
👉[扫雷](https://urtaome.com/post/minesweeper/)

# 5. 作业
## 作业1
创建一个整型数组，完成对数组的操作
```
1.实现函数init()初始化数组全为0
2.实现print()打印数组的每个元素
3.实现reverse()函数完成数组元素的逆置
```
实现代码如下：
```
void init(int arr[], int sz)
{
    int i = 0;
    for(i = 0; i < sz; i++)
    {
        arr[i] = 0;
    }
}

void print(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;
    while (left < right)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
        //当左下标小于右下标，开始循环并互相调换元素
    }
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr) / sizeof(arr[0]);//计算数组元素个数
    print(arr, sz);//打印数组
    reverse(arr, sz);//逆置数组
    print(arr, sz);
    init(arr, sz);//初始化数组为0
    print(arr, sz);
    return 0;
}
```

## 作业2
交换数组，将数组A中的和数组B中的内容进行交换。（数组一样大）
```
int main()
{
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,4,6,8,10};
    int sz = sizeof(arr1) / sizeof(arr1[0]);//计算数组元素个数

    int i = 0;
    for(i = 0; i < sz; i++)
    {
        int tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;//循环交换数组元素
    }
    
    for(i = 0; i < sz; i++)
    {
        printf("%d ", arr1[i]);
    }//打印交换后的arr1

    for(i = 0; i < sz; i++)
    {
        printf("%d ", arr2[i]);
    }//打印交换后的arr2
    return 0;
}
```
