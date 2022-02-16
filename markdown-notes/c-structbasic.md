---
title: 'C语言-结构体初阶'
date: 2022-01-18 16:52:59
tags: [C]
published: true
hideInList: false
feature: /post-images/c-structbasic.jpeg
isTop: false
---
# 1. 结构体类型的声明
## 1.1 结构的基础知识
结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。
## 1.2 结构的声明
比如我要描述一个学生：
```
struct Stu
{
    //成员变量
    char name[20];//姓名
    int age;//年龄
    char id[20];//学号
}s1,s2;
//s1和s2也是结构体变量且是全局变量
```
创建对象可以这样创建：
```
int main()
{
    //创建对象
    struct Stu s;
    return 0;
}
```
## 1.3 结构成员的类型
结构的成员可以是标量、数组、指针，甚至是**其他结构体**。如：
```
struct B
{
    char c;
    short s;
    double d;
};

struct Stu
{
    struct B b;
    char name[20];
    int age;
    char id[20];
};
```
# 2. 结构体变量的定义和初始化
有了结构体类型，那么如何定义变量，其实很简单。
```
struct B
{
    char c;
    short s;
    double d;
};

struct Stu
{
    struct B b;
    char name[20];
    int age;
    char id[20];
};

int main()
{
    //结构体嵌套初始化
    struct Stu s = {{'w', 20, 3.14}, "Zhang San", 30, "20220118"};
    return 0;
}
```
# 3. 结构体成员访问
结构体变量的成员是通过点（.）操作符访问的。点操作符接受两个操作数。例如：
```
struct B
{
    char c;
    short s;
    double d;
};

struct Stu
{
    struct B sb;
    char name[20];
    int age;
    char id[20];
};

int main()
{
    struct Stu s = {{'w', 20, 3.14}, "Zhang San", 30, "20220118"};
    //.
    printf("%c\n", s.sb.c);
    printf("%s\n", s.id);

    //->
    struct Stu* ps = &s;
    printf("%c\n", ps->sb.c);
    printf("%s\n", ps->id);
    return 0;
}
```
# 4. 结构体传参
有如下代码：
```
struct B
{
    char c;
    short s;
    double d;
};

struct Stu
{
    struct B sb;
    char name[20];
    int age;
    char id[20];
};

void print1(struct Stu t)
{
    printf("%c %d %lf %s %d %s\n", t.sb.c, t.sb.s, t.sb.d, t.name, t.age, t.id);
}

void print2(struct Stu *ps)
{
    printf("%c %d %lf %s %d %s\n", ps->sb.c, ps->sb.s, ps->sb.d, ps->name, ps->age, ps->id);
}

int main()
{
    //写一个函数打印s的内容
    struct Stu s = {{'w', 20, 3.14}, "Zhang San", 30, "20220118"};
    print1(s);//结构体传参 - 传值调用
    print2(&s);//结构体指针传参 - 传址调用
    return 0;
}
```
上述代码中，print1好还是print2好？print2好。
函数传参的时候，参数是需要压栈的。如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销就比较大，所以会导致性能下降。**最后一点，结构体传参的时候，要传结构体的地址。**
# 5. 课外话 - 栈
那什么是参数压栈呢？
函数调用的参数压栈：
栈，是一种数据结构，先进的后出，后进的先出，而给栈中存放数据叫做压栈，删除数据叫做出栈。有如下代码：
```
int Add(int x, int y)
{
    int z = 0;
    z = x + y;
    return z;
}

int main()
{
    int a = 3;
    int b = 5;
    int c = 0;
    c = Add(a, b);
    return 0;
}
```
上述代码中，每一个函数的调用都会在内存的栈区上开辟一块空间，所以参数传参也叫压栈操作。如果用传递指针的方式，效率就会较高。
