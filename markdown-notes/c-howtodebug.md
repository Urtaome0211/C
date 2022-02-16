---
title: 'C语言-调试技巧'
date: 2022-01-19 10:38:18
tags: [C]
published: true
hideInList: false
feature: /post-images/c-howtodebug.png
isTop: false
---
# 1. 什么是bug
Bug，即程序错误，也称为缺陷、臭虫，是指在软件运行中因为程序本身有错误而造成的功能不正常、死机、数据丢失、非正常中断等现象。 早期的计算机由于体积非常庞大，有些小虫子可能会钻入机器内部，造成计算机工作失灵。史上的第一只 "Bug" ，真的是因为一只飞蛾意外走入一电脑而引致故障，因此Bug从原意为臭虫引申为程序错误。 一些有趣的Bug有时也会成为一种乐趣。在电脑游戏中，一些Bug，假如不令游戏出现大错误的话，经常会变成一种玩游戏时的秘技。

# 2. 什么是调试
所有发生的事情都一定有迹可循，如果问心无愧，就不需要掩盖也就没有迹象了；反之若心中有鬼，就必然需要掩盖，那就一定会有迹象，**迹象越多就越容易顺藤而上，这就是推理的途径**。顺着这条途径顺流而下就是犯罪，逆流而上就是真相。**一名优秀的程序员是一名出色的侦探。每一次调试都是尝试破案的过程。**
## 2.1 调试的基本步骤
调试（Debug / Debugging），又称除错，是发现和减少计算机程序或电子仪器设备中程序错误的一个过程。调试的基本步骤如下：
1. 发现程序错误的存在
2. 以隔离、消除等方式对错误进行定位
3. 确定错误产生的原因
4. 提出纠正错误的解决办法
5. 对程序错误予以改正，重新测试

# 3. debug和Release的介绍
1. **Debug通常称为调试版本**，它包含调试信息，并且不作任何优化，便于程序员调试程序。
2. **Release称为发布版本**，它往往是进行了各种优化，使得程序在代码大小和运行速度上都是最优的，以便用于能够很好的使用。

# 4. windows环境调试介绍
```
linux开发环境调试工具是gdb
```
## 4.1 调试环境的准备
![debug.png](https://s2.loli.net/2022/01/19/kAyS7qNIivbEFVp.png)

## 4.2 学会快捷键
![debugHotkey.png](https://s2.loli.net/2022/01/19/4KkxOTQ7clz1eXa.png)

最常用使用的快捷键：
### 4.2.1 F5
启动调试，经常用来直接跳到下一个断点处。
### 4.2.2 F9
创建断点和取消断点，断点的重要作用，可以在程序的任意位置设置断点。这样就可以使得程序在想要的位置随意停止执行，继而一步步执行下去。
### 4.2.3 F10
逐过程，通常用来处理一个过程，一个过程可以是一次函数的调用，或者是一条语句。
### 4.2.4 F11
逐语句，就是每次都执行一条语句，但是这个快捷键可以使我们的执行逻辑进入函数内部。
### 4.2.5 Ctrl + F5
开始执行不调试，如果想让程序直接运行起来而不调试就可以直接使用。

## 4.3 查看临时变量的值
按F10即可查看数组的打印过程
![viewdebug.png](https://s2.loli.net/2022/01/19/v1keHMtryVzN2Bs.png)

## 4.4 调用堆栈
这里写了一个嵌套调用函数的程序：主函数调用test函数，test函数调用test1函数，test1函数调用test2函数，最后打印hehe。
```
void test2()
{
    printf("hehe\n");
}

void test1()
{
    test2();
}

void test()
{
    test1();
}

int main()
{
    test();
    return 0;
}
```
按F10，查看函数调用堆栈：
![stack.png](https://s2.loli.net/2022/01/19/nDEsdkBzgp7fvJw.png)
可以看出函数调用（压栈）的逻辑过程。

## 4.5 查看内存
这里编写了一个打印数组的程序，通过调试来看在程序执行过程中内存是如何变化的：
```
int main()
{
    int arr[10] = { 0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    return 0;
}
```
![memdebug.png](https://s2.loli.net/2022/01/19/JR6DNsgipa9m7fE.png)

## 4.6 查看汇编信息
还是上面的代码，按F10，在任意一行右键点击反汇编即可：
![checkdism.png](https://s2.loli.net/2022/01/19/FB5dlvscuNTzqmO.png)
![dism.png](https://s2.loli.net/2022/01/19/6Fwl1NMVS9J5oIf.png)

# 5. 一些调试的示例
## 5.1 示例1
求1!+2!+3!+...+n!，不考虑溢出，错误代码如下：
```
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int ret = 1;
    int sum = 0;
    int j = 0;
    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= j; i++)
        {
            ret *= i;
        }
        sum += ret;
    }
    printf("%d\n", sum);
    return 0;
}
```
上述代码打印值如下图所示，很显然，计算结果是错误的，对于这种运行时的错误，可以通过调试来解决：
![eg1.png](https://s2.loli.net/2022/01/19/ap7bwYtehRPzVlF.png)
经过调试后发现是因为每一次循环ret没有初始化为1，所以导致计算结果错误：
![ret.png](https://s2.loli.net/2022/01/19/pF3dgwLoO5zRI2N.png)

将ret放至循环内即可正确计算：
```
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int sum = 0;
    int j = 0;
    for (j = 1; j <= n; j++)
    {
        int ret = 1;
        for (i = 1; i <= j; i++)
        {
            ret *= i;
        }
        sum += ret;
    }
    printf("%d\n", sum);
    return 0;
}
```
输出结果如下：
![retdebug.png](https://s2.loli.net/2022/01/19/MOQvzELsix1AIkZ.png)

## 5.2 示例2
有如下代码：
```
int main()
{
    int i = 0;
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

    for (i = 0; i <=12; i++)
    {
        arr[i] = 0;
        printf("hehe\n");
    }
    return 0;
}
```
上述代码是死循环的，为什么？来看调试：
![arrdebug.png](https://s2.loli.net/2022/01/19/PdcwsS4OGZi5VRv.png)
在调试中发现当i=10的时候，arr[10]也被重置为0了，而数组中的元素为0-9，当i=12时再进一步i就会被重置为0从而再次循环，监视发现&i和&arr[12]的地址是一样的，所以导致了程序会死循环。
![debugr.png](https://s2.loli.net/2022/01/19/KRfMXV1n3hLewbF.png)

因为1和arr是局部变量，局部变量是存放在栈区上的，栈区内存是先使用高地址空间，再使用低地址空间。且数组随着下标的增长，地址是由低到高变化的。而在上述代码中，i的地址比arr的地址高，当i为9时，数组再往后访问两个区块时arr[12]恰好访问了i的内存，这时i就被初始化为了0，i=0再次进入循环且永远不会跳出循环，这就是死循环的原因。**只要先定义数组，再定义i就不会死循环，只会报错**。

# 6. 如何写出好（易于调试）的代码
## 6.1 优秀的代码：
```
1. 代码运行正常
2. bug很少
3. 效率高
4. 可读性高
5. 可维护性高
6. 注释清晰
7. 文档齐全
```
## 6.2 常见的coding技巧
```
1. 使用assert
2. 尽量使用const
3. 养成良好的编码风格
4. 添加必要的注释
5. 避免编码的陷阱
```
# 7. 模拟实现字符串相关函数
## 7.1 模拟实现库函数 - strcpy
```
strcpy - 字符串拷贝

char *strcpy( char *strDestination, const char *strSource );

/*

The strcpy function copies strSource, including the terminating null
character, to the location specified by strDestination. No overflow 
checking is performed when strings are copied or appended. 
The behavior of strcpy is undefined if the source and destination 
strings overlap.

wcscpy and _mbscpy are wide-character and multibyte-character versions of
strcpy. The arguments and return value of wcscpy are wide-character strings;
those of _mbscpy are multibyte-character strings. These three functions 
behave identically otherwise.

*/
```
实现代码如下：
```
void my_strcpy(char* dest, char* src)
{
    while (*src != '\0')//不能被拷贝\0
    {
        *dest = *src;
        dest++;
        src++;
        //*dest++ = *src++;
    }
    *dest = *src;//拷贝\0
}

int main()
{
    char arr1[20] = "xxxxxxxxxxx";
    char arr2[] = "hello";
    my_strcpy(arr1, arr2);
    printf("%s\n", arr1);
    return 0;
}
```
可将函数优化为：
```
void my_strcpy(char* dest, char* src)
{
    while (*dest++ = *src++)
    {
       ;
    }
}
```
循环开始h赋给x，ASCII码值不为0，为真，继续循环，当循环到'\0'时，它的ASCII码值为0，为假，循环结束。即拷贝了'\0'，又使得循环停止。
而在传参的时候传的是空指针，而这时程序又无法提示，该怎么做呢？可以使用assert()：
```
#include<assert.h>
void my_strcpy(char* dest, char* src)
{
    assert(src != NULL);
    assert(dest != NULL);//断言
    while (*dest++ = *src++)
    {
       ;
    }
}
```
给一个限制条件，当参数为空指针时就提示错误，就可以很快的找到错误在哪里。
而当你循环判断语句写反时：
```
while (*src++ = *dest++)
```
程序也会给你拷贝字符，但是会报错，这时候就需要在char* src之前加一个const，只要加了const，当反向赋值时编译器就会告诉你哪里有错误，这样就能够快速定位错误。优化完毕后字符拷贝的函数实现代码为：
```
void my_strcpy(char* dest, const char* src)
{
    assert(src != NULL);
    assert(dest != NULL);//断言

    while (*dest++ = *src++)
    {
       ;
    }
}
```
**const放在\*左边的时候，指针的内容不能改变，指针的变量可以改变；而const放在\*右边的时候，指针的内容可以改变，指针的变量不能改变。**
最后，库函数strcpy在文档中的返回类型是char*，只需要将修改后的目标空间的地址返回即可，最终优化的代码如下：
```
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src)
{
    assert(src != NULL);
    assert(dest != NULL);//断言
    char* ret = dest;
    while (*dest++ = *src++)
    {
       ;
    }
    return ret;//返回目标空间起始地址
}

int main()
{
    char arr1[20] = "xxxxxxxxxxx";//目标空间起始地址
    char arr2[] = "hello";//原空间的起始地址
    printf("%s\n", my_strcpy(arr1, arr2));//链式访问
    return 0;
}
```
至此，库函数strcpy模拟实现完成。

## 7.2 模拟实现库函数 - strlen
```
srtlen 计算字符串长度

size_t strlen( const char *string );

/*

Each of these functions returns the number of characters in string, not 
including the terminating null character. wcslen is a wide-character version 
of strlen; the argument of wcslen is a wide-character string. wcslen and 
strlen behave identically otherwise. 

*/
```
实现代码如下：
```
#include<stdio.h>
#include<assert.h>
size_t my_strlen(const char* str)
{
    assert(str != NULL);//断言
    //assert(str);
    size_t count = 0;//计数器
    while (*str != '\0')
    {
        count++;//当字符不为\0时，进行循环
        str++;
    }
    return count;//返回数值
}

int main()
{
    char arr[] = "abc";
    int len = my_strlen(arr);
    printf("%d\n", len);
    return 0;
}
```
# 8. 编程常见错误
## 8.1 编译型错误
直接看编译器错误提示信息，或者凭经验就可以搞定。

## 8.2 链接型错误
看错误信息，主要在代码中找到错误信息中的标识符，然后定位问题所在。一般是**标识符不存在**或者**拼写错误**。

## 8.3 运行时错误
借助调试，逐步定位问题，较难。

# 9. 作业
## 作业1
调整奇偶数顺序
调整数组使奇数全部都位于偶数前面，实现代码如下：
```
void print(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
}

void move(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;
    while (left < right)
    {
        //从前往后找偶数
        while ((left < right) && (arr[left] % 2 == 1))
        {
            left++;
        }

        //从后往前找奇数
        while ((left < right) && (arr[right] % 2 == 0))
        {
            right--;
        }

        //交换
        if (left < right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    move(arr, sz);
    print(arr, sz);
    return 0;
}
```
