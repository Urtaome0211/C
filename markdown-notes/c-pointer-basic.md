---
title: 'C语言-指针初阶'
date: 2022-01-17 19:06:52
tags: [C]
published: true
hideInList: false
feature: /post-images/c-pointer-basic.jpeg
isTop: false
---
# 1. 什么是指针
在计算机科学中，**指针**（Pointer）是编程语言中的一个对象，利用地址，它的值直接指向（points to）存在电脑存储器中另一个地方的地址。由于通过地址能找到所需的变量单元，可以说，地址指向改变量单元。因此，将地址形象化的称为“指针”。意思是通过它能找到以它为地址的内存单元。

**给每个内存单元进行编号 - 就是内存的地址**
有如下代码：
```
int main()
{
    int a = 10;//a占4个字节
    printf("%p", &a);
    //拿到的是a的4个字节中第一个字节的地址

    int *pa = &a;
    //将a的地址存放在pa变量中，pa就是一个指针变量
    return 0;
}
```

**总结**：指针就是变量，用来存放地址的变量。（存放在指针中的值都被当成地址处理）
问题：
```
1.一个小的单元到底是多大？（一个字节）
2.如何编址？
```
经过仔细地计算和权衡，发现一个字节给一个对应地地址是比较合适的。
对于32位机器，假设有32根地址线，那么假设每根地址线在寻址的是产生一个电信号正电/负电（1或者0）
那么32根地址线产生的地址就是：
```
0000 0000 0000 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0001
.....
1111 1111 1111 1111 1111 1111 1111 1111
```
这里就有2的32次方个地址。
每个地址标识一个字节，那么就可以给$2^{32}$Byte == 4GB的空闲空间进行编址。同样的方法，64位机器也是这样编址。
**到这里就明白：**
```
1.在32位机器上。地址就是32个0或1组成的二进制序列，那地址就得用4个字节来存储，所以一个指针变量的大小就是4个字节。
2.同样，64位机器就需要8个字节来存放指针变量。
```
**总结**：
```
1.指针是用来存放地址的，地址是唯一标示一块地址的空间的。
2.指针的大小在32位平台是4个字节，在64位平台是8个字节。
```
# 2. 指针和指针类型
这部分讨论指针的类型。变量有不同的类型，如整型、浮点型等。那么指针又没有类型呢？有的。
当有如下代码：
```
int num = 10;
p = &num;
```
要将&num(num的地址)保存到p中，那么p就是一个指针变量，它是什么类型的呢？需要给指针变量相应的类型。
```
char *pc = NULL;
int *pi = NULL;
short *ps = NULL;
long *pl = NULL;
float *pf = NULL;
double *pd = NULL;
```
这里可以看到，指针的定义方式是：char + * 。其实：char\*类型的指针是为了存放char类型变量的地址。short\*类型的指针是为了存放short类型变量的地址。int\*类型的指针是为了存放int类型变量的地址。
## 2.1 指针类型的意义
### 2.1.1 例1：
```
int main()
{
    int a = 0x11223344;//一个16进制位等于四个2进制位
    char *pc = &a;
    //将整型指针存放在char类型中，只能访问一个字节
    *pc = 0;

    //int *pa = &a;
    //*pa = 0;

    return 0;
}
```
### 2.1.2 指针 +- 整数 - 例2
```
int main()
{
    int arr[10] = { 0 };
    int *p = arr;
    char *pc = arr;

    printf("%p\n", p);
    printf("%p\n", p+1);

    printf("%p\n", pc);
    printf("%p\n", pc+1);
    return 0;
}
```
上述代码打印值为：
```
//int指针+1跳过四个字节
0000003C369CFB18
0000003C369CFB1C

//char指针+1跳过一个字节
0000003C369CFB18
0000003C369CFB19

因为p和pc的类型不同
```
在上述打印值中，char*的指针解引用只能访问一个字节，而int\*的指针解引用能访问四个字节。

**总结：**
1. **指针类型决定了指针解引用的权限有多大。**
2. **指针类型决定了指针走一步能走多远。**

有如下代码：
```
int main()
{
    int arr[10] = { 0 };
    int *p = arr;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        *(p+i) = 1;
        //每循环一次就将其中的一个元素置成1
    }
    return 0;
}
```
p + i 其实是下标为i的地址，每循环一次跳4个字节。
# 3. 野指针
野指针就是指针指向的位置是不可知的（随机的、不正确的、没有明确限制的）
## 3.1 野指针成因
### 3.1.1 指针未初始化
```
int main()
{
    int *p;//局部变量指针未初始化，默认为随机值
    *p = 20;//非法访问内存
    return 0; 
}
```
### 3.1.2 指针越界访问
```
int main()
{
    int arr[10] = { 0 };
    int *p = arr;
    int i = 0;

    for (i = 0; i <= 10; i++)
    {
        //当指针指向的范围超出数组arr的范围时，p就是野指针
        *(p++) = i;
    }
    return 0;
}
```
### 3.1.3 指针指向的空间释放
在动态内存分配详细解释...
这里只作简单解释，有如下代码：
```
int* test()
{
    int a = 10;
    return &a;
}

int main()
{
    int *p = test();
    *p = 20;
    return 0;
}
```
上述代码中，a在test函数中的生命周期在出函数的时候就已经销毁（内存空间已经还给了系统），当在main函数中再去访问的时候这块内存空间已经不属于a了，内存非法访问。
## 3.2 如何规避野指针
1. 指针初始化
2. 小心越界指针
3. 指针指向空间释放即时置NULL（包含在stdio.h中）
4. 指针使用之前检查有效性
# 4. 指针运算
## 4.1 指针 +- 整数
```
#define N_VALUES 5
float values[N_VALUES];
float *vp;
//指针的关系运算
for (vp = &values[0]; vp < &values[N_VALUES]; )
{
    *vp++ = 0;//指针+整数
}
```
## 4.2 指针 - 指针
```
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d\n", &arr[9] - &arr[0]);//10-1=9
    return 0;
}
```
指针-指针得到的是两个指针之间的元素个数。相减的前提是两个指针指向同一块空间。
可以用指针相减的方式来求字符串长度：
```
int my_strlen(char* str)
{
    char* start = str;
    while (*str != '\0')
    {
        str++;
    }
    return str - start;
}

int main()
{
    int len = my_strlen("abc");
    printf("%d\n", len);
    return 0;
}
```
## 4.3 指针的运算关系
```
for (vp = &values[N_VALUES]; vp > &values[0]; )
{
    *--vp = 0;
}
```
上述代码可简化为：
```
for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
{
    *vp = 0;
}
```
这一段代码绝大部分的编译器上是可以顺利完成任务的，然而我们还是应该避免这样写，因为标准并不保证它可行。
**标准规定：**
允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置进行比较。
# 5. 指针和数组
数组名是什么？
**数组名就是数组首元素的地址**
```
int main()
{
    int arr[10] = { 0 };
    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
    return 0;
}
打印值：
000000722BF0FAA8
000000722BF0FAA8
```
那么这样写代码是可行的：
```
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int *p = arr;//p存放的是数组首元素的地址
```
既然可以把数组名当作地址存放到一个指针中，那么使用指针来访问一个就称为可能，如：
```
int main()
{
    int arr[10] = { 0 };
    int *p = arr;
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        printf("%p == %p\n", &arr[i], p + i);
        *(p + i) = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(p + i));
    }
    return 0;
}

打印值：
0000008CF09BF5B8 == 0000008CF09BF5B8
0000008CF09BF5BC == 0000008CF09BF5BC
0000008CF09BF5C0 == 0000008CF09BF5C0
0000008CF09BF5C4 == 0000008CF09BF5C4
0000008CF09BF5C8 == 0000008CF09BF5C8
0000008CF09BF5CC == 0000008CF09BF5CC
0000008CF09BF5D0 == 0000008CF09BF5D0
0000008CF09BF5D4 == 0000008CF09BF5D4
0000008CF09BF5D8 == 0000008CF09BF5D8
0000008CF09BF5DC == 0000008CF09BF5DC

0 1 2 3 4 5 6 7 8 9
```
有如下代码：
```
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = arr;
    //[]是一个操作符，而2和arr是两个操作数
    printf("%d\n", 2[arr]);//3
    printf("%d\n", arr[2]);//3
    printf("%d\n", p[2]);//3 - p[2] --> *(p+2)
    //arr[2]编译器在处理的时候是这样处理的：
    //arr[2] --> *(arr+2)

    //交换律
    //arr[2] == *(arr+2) == *(p+2) == *(2+p) == *(2+arr) == 2[arr]
    //2[arr] == *(2+arr)
    return 0;
}
```
# 6. 二级指针
指针变量也是变量，是变量就有地址，那指针变量的地址存放在哪里？这就是**二级指针**。
```
int main()
{
    int a = 10;
    int *pa = &a;//指针变量，一级指针
    //ppa就是一个二级指针变量
    int **ppa = &pa;//pa也是个变量，*pa取出pa在内存中起始地址
    return 0;
}
```
# 7. 指针数组
指针数组是指针还是数组？
是数组，而且是存放指针的数组，有如下代码：
```
int main()
{
    int arr[10];//整型数组 - 存放整型的数组就是整型数组
    char ch[5];//字符数组 - 存放的是字符
    //指针数组 - 存放指针的数组
    int *parr[5];//整型指针的数组 - 有五个元素，每个元素是一个整型指针
    return 0;
}
```

# 8. 作业
## 8.1 作业1
写一个函数，可以逆序一个字符串的内容：
```
void reverse(char *str)
{
    int len = strlen(str);
    char* left = str;
    char* right = str + len - 1;

    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int main()
{
    char arr[] = "abcdef";
    reverse(arr);
    printf("%s\n", arr);
    return 0;
}
```

## 8.2 作业2
打印菱形
```
int main()
{
    int line = 0;
    scanf("%d", &line);

    //打印上半部分
    int i = 0;
    for (i = 0; i < line; i++)
    {
        //打印空格
        int j = 0;
        for (j = 0; j < line - 1 - i; j++)
        {
            printf(" ");
        }
        //打印*
        for (j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    //打印下半部分
    for (i = 0; i < line - 1; i++)
    {
        //打印空格
        int j = 0;
        for (j = 0; j <= i; j++)
        {
            printf(" ");
        }
        //打印*
        for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
```

## 8.3 作业3
喝汽水，一瓶汽水一块钱，两个空瓶可以换一瓶汽水，给二十块，可以喝多少汽水
```
int main()
{
    int money = 0;
    scanf("%d", &money);
    int total = money;
    int empty = money;

    //换空瓶
    while (empty >= 2)
    {
        total += empty / 2;
        empty = empty / 2 + empty % 2;
    }
    printf("%d", total);
    return 0;
}
```
在不断实验上述代码输出值的过程中可以发现，总是可以和2 * money - 1瓶汽水，所以代码也可以优化为：
```
int main()
{
    int money = 0;
    int total = money;
    scanf("%d", &money);
    if (money > 0)
    {
        total = 2 * money - 1;
    }
    printf("%d", total);
    return 0;
}
```
