---
title: 'C语言-指针进阶'
date: 2022-01-22 10:19:49
tags: [C]
published: true
hideInList: false
feature: /post-images/c-pointer-advanced.jpeg
isTop: false
---
指针的主题，我们在[指针初阶](https://urtaome.com/post/c-pointer-basic/)的章节已经接触过了，我们知道了指针的概念：
1. 指针就是个变量，用来存放地址，地址唯一标识一块内存空间。
2. 指针的大小是固定的4/8个字节（32位平台/64位平台）。
3. 指针是有类型，指针的类型决定了指针的+-整数的步长，指针解引用操作的时候的权限。
4. 指针的运算。

这个章节，我们继续探讨指针的高级主题。
# 1. 字符指针
在指针的类型中我们知道有一种指针类型为字符指针char*
```
int main()
{
    char ch = 'w';
    char *pc = &ch;
    *pc = 'w';
    return 0;
}
```
还有一种使用方法：
```
int main()
{
    char* pstr = "Hello World.";
    printf("%s\n", pstr);
    return 0;
}
```
代码char* pstr = "Hello World."; 特别容易让初学者以为是把字符串Hello World.放到字符指针pstr 里了，但是本质是把字符串Hello World. 首字符的地址放到了pstr中。上面代码的意思是把一个常量字符串的首字符“H”的地址存放到指针变量pstr 中。
那就有如下的面试题：
```
#include <stdio.h>
int main()
{
    char str1[] = "Hello World.";
    char str2[] = "Hello World.";
    char *str3 = "Hello World.";
    char *str4 = "Hello World.";
    if(str1 ==str2)
    {
        printf("str1 and str2 are same\n");
    }
    else
    {
        printf("str1 and str2 are not same\n");
    }
    if(str3 ==str4)
    {
        printf("str3 and str4 are same\n");
    }
    else
    {
        printf("str3 and str4 are not same\n");
    }
    return 0;
}
```
上述代码的输出值为：
```
str1 and str2 are not same
str3 and str4 are same
```
这里str3和str4指向的是一个同一个常量字符串。C/C++会把常量字符串存储到单独的一个内存区域，当几个指针。指向同一个字符串的时候，他们实际会指向同一块内存。但是用相同的常量字符串去初始化不同的数组的时候就会开辟出不同的内存块。所以str1和str2不同，str3和str4相同。
# 2. 指针数组
在[指针初阶](https://urtaome.com/post/c-pointer-basic/)章节我们也学了指针数组，指针数组是一个存放指针的数组。

# 3. 数组指针
## 3.1 数组指针的定义
数组指针是指针？还是数组？
答案是：指针。
我们已经熟悉： 整形指针： int \* pint; 能够指向整形数据的指针。 浮点型指针： float * pf; 能够指向浮点型数据的指针。
那数组指针应该是：能够指向数组的指针。
下面代码哪个是数组指针？
```
int *p1[10];
int (*p2)[10];
//p1, p2分别是什么？
```
解释：
```
int (*p)[10];
//解释：p先和*结合，说明p是一个指针变量，然后指针指向的是一个大小为10个整型的数组。
所以p是一个指针，指向一个数组，叫数组指针。
//这里要注意：[]的优先级要高于*号的，所以必须加上（）来保证p先和*结合。
```
## 3.2 &数组名 VS 数组名
对于下面的数组：
```
int arr[10];
```
arr 和&arr 分别是什么？
我们知道arr是数组名，数组名表示数组首元素的地址。
那&arr数组名到底是什么？
先来看一段代码：
```
#include <stdio.h>
int main()
{
    int arr[10] = {0};
    printf("%p\n", arr);
    printf("%p\n", &arr);
    return 0;
}

输出结果为：
00EFF920
00EFF920
```
可见数组名和&数组名打印的地址是一样的。
难道两个是一样的吗？
再看一段代码：
```
#include <stdio.h>
int main()
{
    int arr[10] = { 0 };
    printf("arr = %p\n", arr);
    printf("&arr= %p\n", &arr);

    printf("arr+1 = %p\n", arr+1);
    printf("&arr+1= %p\n", &arr+1);
    return 0;
}

输出结果为：
0133FBB0
0133FBB0

0133FBB4
0133FBD8
```
根据上面的代码我们发现，其实&arr和arr，虽然值是一样的，但是意义应该不一样的。
实际上： &arr 表示的是数组的地址，而不是数组首元素的地址。数组的地址+1，跳过整个数组的大小，所以&arr+1 相对于&arr 的差值是40.
## 3.3 数组指针的使用
那数组指针是怎么使用的呢？
既然数组指针指向的是数组，那数组指针中存放的应该是数组的地址。
看代码：
```
#include <stdio.h>
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    int (*p)[10] = &arr;
    //把数组arr的地址赋值给数组指针变量p
    //但是一般很少这样写代码，显得很别扭
    return 0;
}
```
一个数组指针的使用：
```
#include <stdio.h>

void print_arr1(int arr[3][5], int row, int col)
{
    int i = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
}

void print_arr2(int (*arr)[5], int row, int col)
{
    int i = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
}

int main()
{
    int arr[3][5] = {1,2,3,4,5,6,7,8,9,10};
    print_arr1(arr, 3, 5);
    //数组名arr，表示首元素的地址
    //但是二维数组的首元素是二维数组的第一行
    //所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
    //可以数组指针来接收
    print_arr2(arr, 3, 5);
    return 0;
}
```
# 4. 数组参数和指针参数
在写代码的时候难免要把“数组”或者“指针”传给函数，那函数的参数该如何设计呢？
## 4.1 一维数组传参
有如下代码，他们都是正确的吗？
```
#include <stdio.h>

void test(int arr[])//yes
{}

void test(int arr[10])//yes
{}

void test(int *arr)//yes
{}

void test2(int *arr[20])//yes - 20可以省略
{}

void test2(int **arr)//yes - arr2是一级指针
{}

int main()
{
    int arr[10] = {0};
    int *arr2[20] = {0};
    test(arr);
    test2(arr2);
}
```
## 4.2 二维数组传参
```
void test(int arr[3][5])//yes
{}

void test(int arr[][])//no
{}

void test(int arr[][5])//yes
{}
//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
//这样才方便运算。

void test(int *arr)//no
{}

void test(int* arr[5])//no
{}

void test(int (*arr)[5])//yes
{}

void test(int **arr)//no
{}

int main()
{
    int arr[3][5] = {0};
    test(arr);
}
```
## 4.3 一级指针传参
```
#include <stdio.h>
void print(int *p, int sz)
{
    int i = 0;
    for(i=0; i<sz; i++)
    {
        printf("%d ", *(p+i));
    }
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = arr;
    int sz = sizeof(arr)/sizeof(arr[0]);
    //一级指针p，传给函数
    print(p, sz);
    return 0;
}
```
## 4.4 二级指针传参
```
#include <stdio.h>
void test(int** ptr)
{
    printf("num = %d\n", **ptr);
}

int main()
{
    int n = 10;
    int*p = &n;
    int **pp = &p;
    test(pp);
    test(&p);
    return 0;
}
```
# 5. 函数指针
指向函数的指针，使存放函数地址的指针
```
void test()
{
    printf("hehe\n");
}

int Add(int x, int y)
{
    return x + y;
}

int main()
{
    printf("%p\n", test);
    printf("%p\n", &test);

    int (*pf)(int, int) = &Add;//函数指针变量
    return 0;
}
```
上述代码输出值为：
```
00007FF7552F13C5
00007FF7552F13C5
```

两段有趣的代码：
```
//代码1
(*(void (*)())0)();
//代码2
void (*signal(int , void(*)(int)))(int);
```

```
//代码1
(*(void (*)())0)();
把0强制类型转换为void函数指针类型，调用0地址处的函数，该函数无参，返回类型是void
//1. void (*)() - 函数指针类型
//2. (void (*)()0 - 对0进行强制类型转换，被解释为一个函数地址
//3. *((void (*)())0 - 对0地址进行了解引用操作
//4. (*(void (*)())0)() - 调用0地址处的函数
```
```
//代码2
void (*signal(int , void(*)(int)))(int);
//1. signal和()先结合，说明signal是函数名
//2. signal函数的第一个参数是int类型，第二个参数的类型是函数指针，该函数指针指向一个参数为
//   int，返回类型为void的函数

//3. signal函数的返回类型也是一个函数指针，该函数指针也指向一个参数为
//   int，返回类型为void的函数

那么如何简化这段代码呢？
//typedef - 对类型进行重定义
typedef void(*pfun_t)(int);//对void(*)(int)的函数指针类型重命名为pfun_t
pfun_t signal(int, pfun_t)
```
## 5.1 例题1
```
void test(char *str)
{
    ;
}

int main()
{
    void (*pt)(char*) = &test;
    return 0;
}
```
## 5.2 例题2
```
int Add(int x, int y)
{
    return x + y;
}

int main()
{
    int (*pf)(int, int) = &Add;
    int ret = (*pf)(3, 5);
    int ret = pf(3, 5);
    printf("%d", ret);//8
    return 0;
}
```

# 6. 函数指针数组
数组是一个存放相同类型数据的存储空间，那之前已经学习了指针数组， 比如：
```
int *arr[10];
//数组的每个元素是int*
```
那要把函数的地址存到一个数组中，那这个数组就叫函数指针数组，那函数指针的数组如何定义呢？
```
int (*parr1[10])();
int (*pArr[2])(int, int);//函数指针数组
int *parr2[10]();
int (*)() parr3[10];
```
答案是：parr1 parr1 先和[] 结合，说明parr1是数组，数组的内容是什么呢？ 是int (*)() 类型的函数指针。（函数指针数组 - 存放函数指针的数组）
函数指针数组的用途：**转移表**

## 6.1 函数指针数组的运用
实现一个计算器，实现整型变量的加减乘除
```
void menu()
{
    printf("*******************************\n");
    printf("*******1. add     2. sub*******\n");
    printf("*******3. mul     4. div*******\n");
    printf("*******      0.exit     *******\n");
    printf("*******************************\n");
}

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a*b;
}
int div(int a, int b)
{
    return a / b;
}

int main()
{
    int input = 0;
    do
    {
        menu();
        int x = 0;
        int y = 0;
        int ret = 0;
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                printf("请输入两个操作数：");
                scanf("%d %d", &x, &y);
                ret = add(x, y);
                printf("ret = %d\n", ret);
                break;
            case 2:
                printf("请输入两个操作数：");
                scanf("%d %d", &x, &y);
                ret = sub(x, y);
                printf("ret = %d\n", ret);
                break;
            case 3:
                printf("请输入两个操作数：");
                scanf("%d %d", &x, &y);
                ret = mul(x, y);
                printf("ret = %d\n", ret);
                break;
            case 4:
                printf("请输入两个操作数：");
                scanf("%d %d", &x, &y);
                ret = div(x, y);
                printf("ret = %d\n", ret);
                break;
            case 0:
                printf("退出程序\n");
                break;
            default:
                printf("选择错误，重新选择\n");
                break;
        }
    } while(input);
    return 0;
}
```
可以看出上述代码冗余，后期更新和维护较为麻烦，可以用函数指针数组来维护。实现代码为：
```
void menu()
{
    printf("*******************************\n");
    printf("*******1. add     2. sub*******\n");
    printf("*******3. mul     4. div*******\n");
    printf("*******      0.exit     *******\n");
    printf("*******************************\n");
}

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a*b;
}
int div(int a, int b)
{
    return a / b;
}

int main()
{
    int input = 0;
    do
    {
        menu();
        int (*pfArr[5])(int, int) = { NULL, add, sub, mul, div };
        //函数指针数组，将函数调用通过函数指针数组来访问
        //通过数组下标来调用函数
        int x = 0;
        int y = 0;
        int ret = 0;
        printf("请选择：");
        scanf("%d", &input);

        if (input >= 1 && input <= 4)
        {
            printf("请输入两个操作数：");
            scanf("%d %d", &x, &y);
            ret = (pfArr[input])(x, y);
            printf("ret = %d\n", ret);
        }
        else if (input == 0)
        {
            printf("退出程序\n");
            break;
        }
        else
        {
            printf("选择错误，重新选择！\n");
        }
    } while(input);
    return 0;
}
```

# 7. 指向函数指针数组的指针
有如下代码：
```
int (*p)(int, int);//函数指针
int (*p2[4])(int, int);//函数指针的数组
int (*(*p3)[4])(int, int) = &p2//取出的是函数指针数组的地址
//p3就是一个指向函数指针数组的指针
```

# 8. 回调函数
回调函数就是一个通过函数指针调用的函数。如果把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。
还是用上面计算器的代码来举例：
```
void menu()
{
    printf("*******************************\n");
    printf("*******1. add     2. sub*******\n");
    printf("*******3. mul     4. div*******\n");
    printf("*******      0.exit     *******\n");
    printf("*******************************\n");
}

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a*b;
}
int div(int a, int b)
{
    return a / b;
}

int Calc(int (*pf)(int, int))
{
    int x = 0;
    int y = 0;
    printf("请输入两个操作数：");
    scanf("%d %d", &x, &y);
    return = pf(x, y);//将函数地址传给了pf,再去调用所指向的函数
}

int main()
{
    int input = 0;
    do
    {
        menu();
        int ret = 0;
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                ret = Calc(add);
                printf("ret = %d\n", ret);
                break;
            case 2:
                ret = Calc(sub);
                printf("ret = %d\n", ret);
                break;
            case 3:
                ret = Calc(mul);
                printf("ret = %d\n", ret);
                break;
            case 4:
                ret = Calc(div);
                printf("ret = %d\n", ret);
                break;
            case 0:
                printf("退出程序\n");
                break;
            default:
                printf("选择错误，重新选择\n");
                break;
        }
    } while(input);
    return 0;
}
```

## 8.1 qsort函数
首先演示一下qsort函数的使用：
```
#include <stdio.h>
//qosrt函数的使用者得实现一个比较函数

int int_cmp(const void * p1, const void * p2)
{
    return (*( int *)p1 - *(int *) p2);
}
int main()
{
    int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
    int i = 0;
    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);

    for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf( "%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```

这里首先看一下qsort函数的参数有哪些，查看MSDN文档得知参数有：
```
void qsort( void *base, size_t num, size_t width, int ( *compare )(const void *elem1, const void *elem2 ) );

其中：
void *base
//base中存放的是待排序数据中第一个对象的地址

size_t num
//排序数据元素的个数

size_t width
//排序数据中一个元素的大小，单位是字节

int ( *compare )(const void *elem1, const void *elem2 )
//函数指针，用来比较待排序数据中的2个元素的函数
返回值解释：
Return Value            Description 
< 0                  elem1 less than elem2 
= 0                  elem1 equivalent to elem2 
> 0                  elem1 greater than elem2 

```
以下是qsort函数的使用方法的示例：

### 8.1.1 整形排序
```
#include <stdlib.h>

void print_arr(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    print_arr(arr, sz);
    return 0;
}
```

### 8.1.2 结构体排序
```
#include<string.h>
#include<stdlib.h>
struct Stu
{
    char name[20];
    int age;
};

int sort_by_age(const void* e1, const void* e2)
{
    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int sort_by_name(const void* e1, const void* e2)
{
    return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
    //对应位置的ASCII码值
}

int main()
{
    struct Stu s[3] = {{"zhangsan", 30},{"lisi", 34},{"wangwu", 20}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]), sort_by_age);//按年龄排序
    //qsort(s, sz, sizeof(s[0]), sort_by_name);//按名字排序
    return 0;
}
```
若想实现降序，将排序函数的参数调换以下即可。

## 8.2 模仿qsort实现一个冒泡排序通用算法
```
int Swap(char* buf1, char* buf2, int width)
{
    int i = 0;
    for (i = 0; i < width; i++)
    {
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }
}

void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        //趟数
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            //比较
            //只有char*加一的时候才跳过一个字节，字节宽度很通用
            if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
            {
                //交换
                Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
            }
        }
    }
}

void cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

void print_arr(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void test()
{
    int arr[] = {1,3,5,7,9,2,4,6,8,0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
    print_arr(arr, sz);
}

int main()
{
    test();
    return 0;
}
```
# 9. 指针和数组笔试题解析
```
//一维数组
int a[] = {1,2,3,4};
printf("%d\n",sizeof(a));//4 * 4 = 16
printf("%d\n",sizeof(a+0));//4 or 8
printf("%d\n",sizeof(*a));//4 
printf("%d\n",sizeof(a+1));// 4 or 8
printf("%d\n",sizeof(a[1]));//4

printf("%d\n",sizeof(&a));//4 or 8
printf("%d\n",sizeof(*&a));//16
printf("%d\n",sizeof(&a+1));//4 or 8
printf("%d\n",sizeof(&a[0]));//4
printf("%d\n",sizeof(&a[0]+1));//4

//字符数组
char arr[] = {'a','b','c','d','e','f'};
printf("%d\n", sizeof(arr));//6
printf("%d\n", sizeof(arr+0));//4 or 8
printf("%d\n", sizeof(*arr));//1
printf("%d\n", sizeof(arr[1]));//1
printf("%d\n", sizeof(&arr));//4 or 8
printf("%d\n", sizeof(&arr+1));//4 or 8
printf("%d\n", sizeof(&arr[0]+1));//4 or 8

printf("%d\n", strlen(arr));//随机值
printf("%d\n", strlen(arr+0));//随机值
printf("%d\n", strlen(*arr));//error
printf("%d\n", strlen(arr[1]));//error
printf("%d\n", strlen(&arr));//随机值
printf("%d\n", strlen(&arr+1));//随机值
printf("%d\n", strlen(&arr[0]+1));//随机值

char arr[] = "abcdef";
printf("%d\n", sizeof(arr));//7
printf("%d\n", sizeof(arr+0));//4 or 8
printf("%d\n", sizeof(*arr));//1
printf("%d\n", sizeof(arr[1]));//1
printf("%d\n", sizeof(&arr));
printf("%d\n", sizeof(&arr+1));
printf("%d\n", sizeof(&arr[0]+1));

printf("%d\n", strlen(arr));//6
printf("%d\n", strlen(arr+0));//6
printf("%d\n", strlen(*arr));//error
printf("%d\n", strlen(arr[1]));//error
printf("%d\n", strlen(&arr));//6
printf("%d\n", strlen(&arr+1));//随机值
printf("%d\n", strlen(&arr[0]+1));//5

char *p = "abcdef";
printf("%d\n", sizeof(p));//4 or 8
printf("%d\n", sizeof(p+1));//4 or 8
printf("%d\n", sizeof(*p));//1
printf("%d\n", sizeof(p[0]));//1
printf("%d\n", sizeof(&p));//4 or 8
printf("%d\n", sizeof(&p+1));//4 or 8
printf("%d\n", sizeof(&p[0]+1));//4 or 8

printf("%d\n", strlen(p));//6
printf("%d\n", strlen(p+1));//5
printf("%d\n", strlen(*p));//error
printf("%d\n", strlen(p[0]));//error
printf("%d\n", strlen(&p));//随机值
printf("%d\n", strlen(&p+1));//随机值
printf("%d\n", strlen(&p[0]+1));//5

//二维数组
int a[3][4] = {0};
printf("%d\n",sizeof(a));//48
printf("%d\n",sizeof(a[0][0]));//4
printf("%d\n",sizeof(a[0]));//16
printf("%d\n",sizeof(a[0]+1));//4
printf("%d\n",sizeof(*(a[0]+1)));//4
printf("%d\n",sizeof(a+1));//4
printf("%d\n",sizeof(*(a+1)));//16
printf("%d\n",sizeof(&a[0]+1));//4
printf("%d\n",sizeof(*(&a[0]+1)));//16
printf("%d\n",sizeof(*a));//16
printf("%d\n",sizeof(a[3]));//16 不会真正去访问
```
**总结**：
1. sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小。
2. &数组名，这里的数组名表示整个数组，取出的是整个数组的地址。
3. 除此之外所有的数组名都表示首元素的地址。

## 9.1 笔试题解析
### 9.1.1 笔试题1
```
int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    int *ptr = (int *)(&a + 1);
    printf( "%d,%d", *(a + 1), *(ptr - 1));//2  5
    return 0;
}
```

### 9.1.2 笔试题2
```
//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test
{
    int Num;
    char *pcName;
    short sDate;
    char cha[2];
    short sBa[4];
}*p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
int main()
{
    printf("%p\n", p + 0x1);//0x100014
    printf("%p\n", (unsigned long)p + 0x1);//0x100001
    printf("%p\n", (unsigned int*)p + 0x1);//0x100004
    return 0;
}
```

### 9.1.3 笔试题3
```
int main()
{
    int a[4] = { 1, 2, 3, 4 };
    int *ptr1 = (int *)(&a + 1);
    int *ptr2 = (int *)((int)a + 1);//地址向后偏一个字节
    printf( "%x,%x", ptr1[-1], *ptr2);//4 200000
    return 0;
}
```

### 9.1.4 笔试题4
```
#include <stdio.h>
int main()
{
    int a[3][2] = { (0, 1), (2, 3), (4, 5) };
    int *p;
    p = a[0];
    printf( "%d", p[0]);//1 - 逗号表达式
    return 0;
}
```

### 9.1.5 笔试题5
```
int main()
{
    int a[5][5];
    int(*p)[4];
    p = a;
    printf( "%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//FFFFFFFFFFFFFFFC， -4
    return 0;
}
```

### 9.1.6 笔试题6
```
int main()
{
    int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *ptr1 = (int *)(&aa + 1);
    int *ptr2 = (int *)(*(aa + 1));
    printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10, 5
    return 0;
}
```

### 9.1.7 笔试题7
```
#include <stdio.h>

int main()
{
    char *a[] = {"work","at","alibaba"};
    char**pa = a;
    pa++;
    printf("%s\n", *pa);//at
    return 0;
}
```

### 9.1.8 笔试题8
```
int main()
{
    char* c[] = {"ENTER","NEW","POINT","FIRST"};
    char** cp[] = {c+3,c+2,c+1,c};
    char*** cpp = cp;

    printf("%s\n", **++cpp);//POINT
    printf("%s\n", *-- *++cpp + 3);//ER
    printf("%s\n", *cpp[-2] + 3);//ST
    printf("%s\n", cpp[-1][-1] + 1);//EW
    return 0;
}
```

# 10. 作业
## 10.1 作业1
杨氏矩阵
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序再这样的矩阵中查找某个数字是否存在。
要求：时间复杂度小于$o(N)$。例：
```
1 2 3
4 5 6
7 8 9
```
实现代码如下：
每一次都找最右上角的数字，如果这个数字不是我们要找的数字，那就把当前行（列）消去，再次判断，直到找出所要的数字。
```
int find_num(int arr[3][3], int* px, int* py, int k)
{
    int x = 0;
    int y = *py - 1;

    while(x < *py && y >= 0)//防止越界
    {
        if(arr[x][y] < k)
        {
            x++;
        }
        else if(arr[x][y] > k)
        {
            y--;
        }
        else
        {
            *px = x;
            *py = y;
            return 1;//找到了
        }
    }
    return 0;//没找到
}

int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int k = 7;

    int x = 3;
    int y = 3;
    //查找一个数字，比如说找7
    //如果找到返回1，找不到返回0
    int ret = find_num(arr, &x, &y, k);
    if (ret == 1)
    {
        printf("找到了\n");
        printf("坐标是：%d %d\n", x, y);
    }
    else
    {
        printf("找不到");
    }

    return 0;
}
```

## 10.2 作业2
字符串左旋
实现一个函数，可以实现左旋字符串的k个字符。
例如：ABCD左旋一个字符得到BCDA；ABCD左旋两个字符得到CDAB。实现代码如下：
```
void string_left_rotate(char* str, int k)
{
    int i = 0;
    int n = strlen(str);
    for (i = 0; i < k; i++)
    {
        //每次左旋一个字符
        char tmp = *str;
        int j = 0;
        for (j = 0; j < n - 1; j++)
        {
            //后边n-1个字符往前挪动
            *(str + j) = *(str + j + 1);
        }
        //tmp放在最后
        *(str + n - 1) = tmp;
    }
}

int main()
{
    char arr[] = "ABCDEF";
    int k = 2;
    string_left_rotate(arr, k);
    printf("%s\n", arr);
}
```

## 10.3 作业3
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例：
给定s1 = AABCD和s2 = BCDAA，返回1；
给定s1 = abcd和s2 = ABCD，返回0。实现代码如下：
```
#include<string.h>

int is_string_rotate(char* str1, char* str2)
{
    int i = 0;
    int n = strlen(str1);
    for (i = 0; i < n; i++)
    {
        //每次左旋一个字符
        char tmp = *str1;
        int j = 0;
        for (j = 0; j < n - 1; j++)
        {
            //后边n-1个字符往前挪动
            *(str1 + j) = *(str1 + j + 1);
        }
        //tmp放在最后
        *(str1 + n - 1) = tmp;

        //比较
        if(strcmp(str1, str2) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    char arr1[] = "AABCD";
    char arr2[] = "BCDAA";
    int ret = is_string_rotate(arr1, arr2);
    if(ret == 1)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}
```