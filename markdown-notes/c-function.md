---
title: 'C语言-函数'
date: 2021-12-21 14:21:17
tags: [C]
published: true
hideInList: false
feature: /post-images/c-function.jpeg
isTop: false
---
# 1. 什么是函数
<font face="微软雅黑">在计算机中，函数（function）或叫子程序，它是一个大型程序中的某部分代码，由一个或多个语句块组成。它负责完成某项特定任务，而且相较于其他代码，具备相对的独立性。函数一般会有输入参数并有返回值，提供对过程的封装和细节的隐藏。</font>

## 1.1 C语言中的函数分类
1. 库函数
2. 自定义函数

# 2. 库函数
1. <font face="微软雅黑">在学习C语言的过程中，总是在一个代码完成编写之后迫不及待地想知道结果，想把这个结果打印到我们地屏幕上看看。这个时候会频繁地使用一个功能：将信息按照一定地格式打印到屏幕上（printf）。</font>
2. <font face="微软雅黑">或者做一些字符串地拷贝工作（strcpy）。</font>
3. <font face="微软雅黑">或者计算n的k次方这样的运算（pow）。</font>

<font face="微软雅黑">像上述描述的基础功能，它们不是业务性的代码。我们在开发过程中每个程序员都可能用得到，为了支持可移植性和提高程序的效率，所以C语言的基础库中提供了一系列类似的库函数，方便程序员进行开发。</font>
**注**：若要使用库函数，必须包含<font face="微软雅黑">#include对应的头文件。这里可以对照[文档](http://cplusplus.com)来学习库函数。或者使用MSDN来查看，点击[此处]( https://pan.baidu.com/s/1My9i_cTu3jJ2CbVPDX1Cpw)来下载，提取码: esu9。</font>

<font face="微软雅黑">简单的总结，C语言的常用库函数有：</font>
<font face="微软雅黑">
1. IO函数：printf(), scanf(), getchar(), putchar()...
2. 字符串操作函数：strcmp(), strlen()...
3. 字符操作函数：toupper()...
4. 内存操作函数：memcpy(), memcmp(), memset()...
5. 时间/日期函数：time()...
6. 数学函数：sqrt(), pow()...
7. 其它库函数
</font>

<font face="微软雅黑">下面举两个例子，用查看文档的方式来学习库函数：</font>
## 2.1 例1-strcpy()
<font face="微软雅黑">strcpy()，Copy string.
Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point).</font>
```
char *strcpy( char *strDestination, const char *strSource );
```

```
#include<stdio.h>
#include<string.h>

int main()
{
    char arr1[20] = { 0 };
    char arr2[] = "Hello World";
    strcpy(arr1, arr2);//将arr2中的字符拷贝到arr1中
    printf("%s", arr1);
    return 0;
}
```
## 2.2 例2-memset()
<font face="微软雅黑">memset(), Fill block of memory
Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
</font>
```
void * memset ( void * ptr, int value, size_t num );
```
```
#include<stdio.h>
#include<string.h>

int main()
{
    char arr[] = "Hello World";
    memset(arr, 'x', 5);
    //将数组arr中的前五个字符换成x
    printf("%s", arr);
    return 0;
}
//打印值为xxxxx World
```

# 3. 自定义函数
<font face="微软雅黑">自定义函数和库函数一样，有函数名，返回值类型和函数参数。但是不一样的是这些都是程序员自己来设计和实现的，有很大的发挥空间。</font>

<font face="微软雅黑">函数的组成：</font>
```
ret_type fun_name(para1, *)
{
    statement;//语句项，函数体
}
ret-type 返回类型
fun_name 函数名
para1 函数参数
```

<font face="微软雅黑">接下来举两个例子：</font>
## 3.1 例1
<font face="微软雅黑">写出一个函数，来找出两个整数中的最大值。</font>
```
#include<stdio.h>

int get_max(in x, int y)
//返回类型为整数，故定义为int类型
{
    int z = 0;
    if (x > y)
    {
        z = x;
    }
    else
    {
        z = y;
    }
    //数值的比较
    return z;
    //返回较大值
}

int main()
{
    int a = 10;
    int b =20;
    int max = get_max(a, b);
    //调用函数
    //将函数返回的值存放至max中，并打印
    printf("%d\n", max);
    return 0;
}
```

## 3.2 例2
<font face="微软雅黑">写一个函数可以交换两个整型变量的内容</font>
```
#include<stdio.h>

void Swap1(int x, int y)
//若调用Swap1函数，无法实现调换数字
//因为申请的内存空间不是同一个
{
    int z = 0;
    z = x;
    x = y;
    y = z;
}

void Swap2(int* pa, int* pb)
//void表示函数无返回类型，也无需返回
//利用指针建立联系
{
    int z = 0;
    z = *pa;
    *pa = *pb;
    *pb = z;
}

int main()
{
    int a = 10;
    int b = 20;
    Swap1(a, b);//函数调用
    printf("交换前：a=%d, b=%d\n", a, b);
    Swap2(&a, &b);//函数调用
    //取地址，将a与b的地址传给Swap2
    printf("交换后：a=%d, b=%d\n", a, b);
    return 0;
}
```
<font face="微软雅黑">由于主函数中的a，b和Swap函数中的参数向内存申请的空间不是同一个，所以需要使用指针来传参。Swap1中，其在被调用时，实参传给形参，其实形参是实参的一份临时拷贝，改变形参，不能改变实参，故Swap1函数失效。</font>

# 4. 函数参数
## 4.1 实际参数（实参）
<font face="微软雅黑">真实传给函数的参数，叫实参。实参可以是：常量、变量、表达式、函数等。无论实参是何种类型的量，在进行函数调用时，它们都必须有确定的值，以便把这些值传送给形参。</font>

## 4.2 形式参数（形参）
<font face="微软雅黑">形式参数是指函数名后括号中的变量，因为形式参数只有在函数被调用的过程中才实例化（分配内存单元），所以叫形式参数。形式参数当函数调用完成之后就自动销毁了。因此形式参数只在函数中有效。</font>

<font face="微软雅黑">在上述代码例2中，Swap1和Swap2函数中的参数x, y, pa, pb都是形式参数。在main函数中传给Swap1的a, b和传给Swap2函数的&a, &b都是实际参数。</font>

# 5. 函数调用
## 5.1 传值调用
<font face="微软雅黑">函数的形参和实参分别占有不同的内存块，对形参的修改不会影响实参。</font>

## 5.2 传址调用
<font face="微软雅黑">1. 传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式。</font>
<font face="微软雅黑">2. 这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数内部可以直接操作函数外部的变量。</font>

## 5.3 练习
### 5.3.1 函数调用-例1
<font face="微软雅黑">写一个函数可以判断一个数是不是素数。</font>
```
#include<stdio.h>

int is_prime(int n)
{
    int j = 0;
    for (j = 2; j < n; j++)
    //用2到n-1的数去试除，若能被整除则不是素数，返回0。
    {
        if(n % j == 0)
        {
            return 0;
        }
    }
    //若不能整除，则为素数，返回1，并打印
    return 1;
}

int main()
{
    int i = 0;
    int count = 0;
    for (i = 100; i <= 200; i++)
    {
        if(is_prime(i) == 1)
        //创建一个名为is_prime的函数来判断一个数是不是素数
        {
            count++;
            printf("%d ", i);
        }
    }
    printf("\nCount=%d", count);
    return 0;
}
```
### 5.3.2 函数调用-例2
<font face="微软雅黑">写一个函数判断一年是不是闰年。</font>
```
#include<stdio.h>

int is_leap_year(int x)
{
    if ((x % 4 == 0) && (x % 100 != 0) || (x % 400 == 0))
    {
        return 1;//是闰年返回1
    }
    else
    {
        return 0;//不是闰年返回0
    }
}

int main()
{
    int year = 0;
    for (year = 1000; year <= 2000; year++)
    {
        if (is_leap_year(year) == 1)
        //创建一个名为is_leap_year的函数来判断是否为闰年
        {
            printf("%d ", year);
        }
    }
    return 0;
}
```
### 5.3.3 函数调用-例3
<font face="微软雅黑">写一个函数，实现一个整型有序数组的二分查找。</font>
```
#include<stdio.h>

int binary_search(int arr[], int k, int s)
{
    int left = 0;
    //左下标为0
    int right = s - 1;
    //右下标为数组元素个数减一
    while(left <= right)
    //当左下标小于右下标时进行循环
    {
        int mid = (left + right) / 2;
        if (arr[mid] > k)
        {
            right = mid - 1;
            //若折半后的下标大于要查找的下标，则右下标减一
        }
        else if (arr[mid] < k)
        {
            left = mid + 1;
            //若折半后的下标小于要查找的下标，则左下标加一
        }
        else
        {
            return mid;
            //当左下标等于右下标时，找到了，返回下标值
        }
        //二分查找
    }
    return -1;
    //找不到，返回负一
}

int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    //定义有序数组
    int key = 7;
    //查找数组的下标为6
    int sz = sizeof(arr) / sizeof(arr[0]);
    //定义数组元素个数
    int ret = binary_search(arr, key, sz);
    //创建一个名为binary_search的函数，将它的返回值存入ret中。

    if (ret == -1)
    {
        printf("cannot found.\n");
        //返回值为负一时，打印找不到
    }
    else
    {
        printf("found: \n", ret);
        //找到下标并打印下标值，为6
    }
    return 0;
}
```
<font face="微软雅黑">上述代码中，函数在传参的过程中，传递过去的数组其实是数组内第一个元素的地址，所以要计算数组元素个数，必须在函数外部进行。</font>
### 5.3.4 函数调用-例4
<font face="微软雅黑">写一个函数，每调用一次这个函数，就会将num的值增加1</font>
```
#include<stdio.h>

void Add(int* p)
{
    (*p)++;
}

int main()
{
    int num = 0;
    Add(&num);
    printf("%d\n", num);//1

    Add(&num);
    printf("%d\n", num);//2

    Add(&num);
    printf("%d\n", num);//3
}
```

# 6. 函数的嵌套调用和链式访问
<font face="微软雅黑">函数和函数之间是可以有机组合的</font>
## 6.1 嵌套调用
<font face="微软雅黑">函数可以嵌套调用，但是不能嵌套定义。有以下举例：</font>
```
#include<stdio.h>

void new_line()
{
    printf("hehe\n");
}

void three_line()
{
    int i = 0;
    for (i = 0; i <3; i++)
    {
        new_line();//执行三次new_line()函数
    }
}

int main()
{
    three_line();//调用three_line()函数
    return 0;
}
```

## 6.2 链式访问
<font face="微软雅黑">把一个函数的返回值作为另外一个函数的参数。有以下举例：</font>
```
#include<stdio.h>
#include<string.h>

int main()
{
    int len = strlen("abc");
    printf("%d\n", len);

    printf("%d\n", strlen("abc"));
    //将strlen()中的值传递给printf()，这就叫链式访问
    return 0;
}
```
或
```
#include<stdio.h>
#include<string.h>

int main()
{
    char arr1[20] = { 0 };
    char arr2[] = 'hello';
    strcpy(arr1, arr2);
    printf("%s\n", arr1);

    printf("%d\n", strcpy(arr1, arr2));
    //strcpy作为参数，传给了printf()
    return 0;
}
```
<font face="微软雅黑">有以下举例：</font>
```
printf("%d", printf("%d", printf("%d", 43)));
//打印值为4321
```
<font face="微软雅黑">查看MSDN文档可知，printf()函数返回的是打印在屏幕上的字符的个数。首先最里面的打印43，为两个字符，返回2；接下来第二个printf打印2，为一个字符，返回1；再由第一个printf打印。故打印值为4321。</font>

# 7. 函数的声明和定义
## 7.1 函数声明
<font face="微软雅黑">1. 告诉编译器有一个函数叫什么，参数是什么，返回类型是什么。但是具体是不是存在，无关紧要。</font>
<font face="微软雅黑">2. 函数的声明一般出现在函数的使用之前，要满足**先声明后使用**。</font>
<font face="微软雅黑">3. 函数的声明一般要放在头文件中的。</font>
```
#include<stdio.h>

int main()
{
    int a = 20;
    int b = 10;
    //声明函数-告知
    int Add(int, int);
    
    int c = Add(a, b);
    printf("%d\n", c);
    return 0;
}
//函数的定义
int Add(int x, int y)
{
    return x + y;
}
```
由于程序是从上而下执行的，若没有声明函数，会出现警告。若自定义函数再主函数之后，则需要声明。也可以将自定义函数放至主函数之前，这样就无需声明。
```
//add.h
int Add(int x, int y);
```
```
//add.c
int Add(int x, int y)
{
    return x + y;
}
```
```
#include<stdio.h>
#include "add.h"

int main()
{
    int a = 10;
    int b = 20;
    int c = Add(a, b);
    printf("%d\n", c);
}
```
<font face="微软雅黑">函数的声明最好放在头文件中进行，而函数的定义要在对应的.c文件中。可以用生成静态库的方式来防止代码的泄露，静态库用#pragma comment (lib, "xxx.lib")命令来导入。</font>

## 7.2 函数定义
<font face="微软雅黑">函数的定义是指函数的具体实现，交代函数的功能实现。</font>

# 8. 函数递归
<font face="微软雅黑"></font>
## 8.1 什么是函数递归
<font face="微软雅黑">程序调用自身的编程技巧称为递归（recursion）。递归作为一种算法在程序设计语言中广泛应用。一个过程或者函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的问题层转化为一个与原问题相似的规模较小的问题来求解，递归策略只需少量的程序就可以描述出解题过程所需要的多次重复计算，大大地减少了程序的代码量。**递归的主要思考方式在于：把大事化小。**</font>

## 8.2 递归的两个必要条件
<font face="微软雅黑">1. 存在限制条件，当满足这个限制条件的时候，递归便不再继续。</font>
<font face="微软雅黑">2. 每次递归调用之后越来越接近这个限制条件。</font>

## 8.3 练习
### 8.3.1 例1
<font face="微软雅黑">接受一个整型值（无符号），按照顺序打印它的每一位。例如：</font>
```
输入：1234
输出：1 2 3 4
```
<font face="微软雅黑">实现代码如下：</font>
```
#include<stdio.h>

void print(unsigned int n)
{
    if (n > 9)
    {
        print(n / 10);
    }
    printf("%d ", n % 10);
}

int main()
{
    unsigned int num = 0;
    scanf("%u", num);//1234
    print(num);
    //print函数可以返回参数部分数字的每一位
    return 0;
}
```

### 8.3.2 例2
<font face="微软雅黑">编写函数不允许创建临时变量，求字符串长度。</font>
```
#include<stdio.h>
#include<string.h>

int my_strlen(char* str)
//将数组内第一个元素的地址传过来
{
    if (*str != '\0')
    //若数组内元素不等于\0，进入判断语句
    {
        return 1 + my_strlen(str + 1);
        //判断结束之后，返回1+函数，并且指针指向的数组的地址向右移一位
        //再次调用函数并判断-递归
        //直到数组内元素内容为\0时，结束递归，返回字符串长度
    }
    else
    {
        return 0;
    }
}

int main()
{
    char arr[] = "hello";
    printf("%d\n", my_strlen(arr));
    return 0;
}
```

### 8.3.3 递归与迭代 例3
<font face="微软雅黑">求n的阶乘（不考虑溢出）</font>
<font face="微软雅黑">迭代指重复做同一件事，目的通常是为了逼近所需目标或结果。</font>
```
#include<stdio.h>

int Fac(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * Fac(n - 1);
        //例：5 * 4! = 5!
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int ret = Fac(n);
    printf("%d\n", ret);
    return 0;
}
```
### 8.3.4 递归与迭代 例4
<font face="微软雅黑">求第n个斐波那契数列。（不考虑溢出）</font>
<font face="微软雅黑">斐波那契数列指的是这样一个数列：</font>
```
0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,....
//这个数列从第3项开始，每一项都等于前两项之和。
```

```
#include<stdio.h>
int Fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return Fib(n - 1) + Fib(n - 2);
        //这个数列从第3项开始，每一项都等于前两项之和。
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int ret = Fib(n);
    printf("%d\n", ret);
    return 0;
}
```
<font face="微软雅黑">但是上述的代码会产生大量重复的计算，效率极差。若使用循环，效率将会大大的提高，但是由于int类型存放的数据有限，得到的结果是错误的。实现代码如下：</font>
```
#include<stdio.h>
int Fib(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;
    while (n > 2)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}
```

# 9. 作业
## 作业1 汉诺塔
<font face = "微软雅黑">思路：首先将n-1个盘子放到b座上，再将A座上剩下的盘子挪到C座上，最后将n-1个盘子从b座挪到C座上。实现代码如下：</font>
```
#include<stdio.h>

void move(char pos1, char pos2)
{
    printf(" %c->%c ", pos1, pos2);
}

void hanoi(int n, char source, char tmp, char des)
{
    //source表示起始位置
    //tmp表示中转位置
    //des表示目的位置
    if (n == 1)
    {
        move(source, des);
        //若只有一个盘子，直接从A座挪到C座
        //!!!此语句为递归的限制条件!!!
    }
    else
    {
        //递归
        hanoi(n - 1, source, des, tmp);
        //将n-1个盘子通过C座放到B座上
        move(source, des);
        //将A座剩下的盘子挪到C座上
        hanoi(n - 1, tmp, source, des);
        //将n-1个盘子通过A座挪到C座上
    }
}
int main()
{
    int n = 0;
    printf("请输入盘子个数：");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');//传参
    return 0;
}
```

## 作业2
<font face = "微软雅黑">实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定。</font>
```
#include<stdio.h>

void print_table(int n)
{
    int i = 0;
    for (i = 1; i <= n; i++)
    //指定行数
    {
        int j = 0;
        for (j = 1; j <= i; j++)
        //指定列数
        {
            printf("%d*%d=%-2d", i, j, i * j);
        }
        printf("\n");//每打印一行就换行
    }
}

int main()
{
    int n  = 0;
    scanf("%d", &n);
    print_table(n);
    return 0;
}
```

## 作业3
编写一个函数reverse_string(char * string)
实现：将参数字符串中的字符反向排列，不是逆序打印。
要求：不能使用C函数库中的字符串操作函数。递归实现
```
#include<stdio.h>

int my_strlen(char* srt)
{
    //计算字符串长度
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;//寻找下一个字符
    }
    return count;
}

void reverse_string(char* str)
{
    char tmp = *str;
    int len = my_strlen(str);
    *str = *(str + len - 1);//将a与f交换,f的地址就为str + len - 1
    *(str + len - 1) = '\0';//将\0赋值给最后一个字符，这样才可以逆序中间的字符

    if (my_strlen(str + 1) >= 2)
    //剩下字符大于两个时，进行递归
    {
        reverse_string(str + 1);
    }
    *(str + len - 1) = tmp;//中间的字符逆序完成之后，再将a的值放回去
    //总体的思路为：两端两个字符的交换加上中间字符的逆序
}

int main()
{
    char arr[] = "abcdef";
    reverse_string(arr);
    printf("%s\n", arr);//fedcba
    return 0;
}
```
若用循环来解题会更加容易理解：
```
void reverse_string(char* str)
{
    int left = 0;
    int right = my_strlen(str) - 1;//右下标，通过my_strlen()函数求得

    while (left < right)//当左下标小于右下标时进行循环
    {
        char tmp = str[left];//创建一个临时变量来进行逆序
        str[left] = str[right];
        str[right] = tmp;
        left++;
        right--;//每循环一次，左下标加一，右下标减一
    }
}
```

## 作业4
写一个递归函数DigitSum(n)，输入一个非负整数，返回组成他的数字之和，例：
```
调用DigitSum(1729),则返回1+7+2+9，它的和是19
输入：1729
输出：19
```
思路为：
```
1729 % 10 =172 + 9
172 % 10 = 17 + 2 + 9
17%10 = 1 + 7 + 2 + 9
```
实现代码为：
```
#include<stdio.h>

int DigitSum(int n)
{
    if (n > 9)
    {
        return DigitSum(n / 10) + n % 10;
        //每次递归模上10，将每一个数字拆下来
        //当为个位数时，递归结束
    }
    else
    {
        return n;
    }
}

int main()
{
    int num = 1729;
    int sum = DigitSum(num);

    printf("%d\n", sum);
    return 0;
}
```

## 作业5
编写一个函数，递归实现n的k次方
```
#include<stdio.h>

double Pow(int n, int k)
{
    if (k == 0)
    {
        return 1.0;
        //任何数的0次方都是1
    }
    else if (k > 0)
    {
        return n * Pow(n, k - 1);
        //当k大于0时的情况
    }
    else
    {
        return 1.0 / (Pow(n, -k));
        //当k小于0时的情况
    }
}

int main()
{
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    double ret = Pow(n, k);
    printf("%lf\n", ret);
    return 0;
}
```

