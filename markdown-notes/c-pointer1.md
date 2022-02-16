---
title: 'C语言-初识指针'
date: 2021-12-11 13:45:36
tags: [C]
published: true
hideInList: false
feature: /post-images/c-pointer1.jpeg
isTop: false
---
# 1.内存
内存是电脑上特别重要的存储器，计算机中所有运行的程序都是在内存中进行的。所以为了有效地使用内存，就把内存分为一个个小地单元，每一个内存单元的大小是**一个字节**。为了有效访问每个单元，就给内存单元编号，这些编号成为**内存单元的地址**。
  
**Q**：内存是如何编号的？
**A**：在32位机器中，是32根地址线，在通电时产生电信号（1和0），电信号转成数字信号，即1和0的二进制序列，有32个二进制位，大小为32个比特位（4个字节）。故64位机器中的大小就是64个比特位（8个字节）

```
#include<stdio.h>

int main()
{
    int a = 10;
    printf("%p\n", a);
    int * pa = &a;
    return 0;
}

```
1. pa是用来存放地址的，在C语言中叫指针变量。
2. *说明pa是指针变量。
3. int说明pa指向的对象为int类型。
4. %p为打印地址的格式，**从内存中取地址只会取第一个字节的地址**。
  
## ①解引用操作“*”
```
#include<stdio.h>

int main()
{
    int a = 10;
    int * pa = &a;
    *pa = 20;
    printf("%d\n", a);
    return 0;
}
```
上述代码的输出值为20。
“*”是解引用操作，\*pa就是就是通过pa里边的地址找到a，这样就可以不通过a来修改变量值。
  
**注**：指针就是地址。

# 2.指针的大小
可使用sizeof来查看指针的大小
```
#include<stdio.h>

int main()
{
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(char *));
    printf("%d\n", sizeof(short *));
    printf("%d\n", sizeof(long *));
    printf("%d\n", sizeof(long long *));
    printf("%d\n", sizeof(float *));
    printf("%d\n", sizeof(double *));
    return 0;
}
```
1. 指针是用来存放地址的。
2. 指针需要多大的空间，取决于地址的存储需要多大空间。
3. **指针大小在32位平台上是4个字节，64位平台是8个字节。**
   
# 3.结构体
结构体可以让C语言创建新的类型出来。
```
#include<stdio.h>

struct Stu{
    char name[20];
    int age;
    double score;
};

int main()
{
    struct Stu s = {"Zhang San", 20, 85.5};
    //结构体的创建和初始化

    printf("%s %d %lf", s.name, s.age, s.score);
    return 0;
}
```
上述代码中，s.name, s.age, s.score表示结构体变量.变量成员。“.”为操作符。%lf为打印双精度浮点型。同样，也可以使用指针来进行打印操作：
```
#include<stdio.h>

struct Stu{
    char name[20];
    int age;
    double score;
};

int main()
{
    struct Stu s = {"Zhang San", 20, 85.5};
    //结构体的创建和初始化
    printf("1: %s %d %lf\n", s.name, s.age, a.score);
    struct Stu * ps = &s;
    printf("2: %s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
    printf("3: %s %d %lf\n", ps->name, ps->age, ps->score);
    return 0;
}
```
结构体指针->成员变量名


