---
title: 'C语言 - 动态内存管理'
date: 2022-02-11 09:52:11
tags: [C]
published: true
hideInList: false
feature: /post-images/c-malloc.png
isTop: false
---
# 1. 为什么存在动态内存分配
我们已经掌握的内存开辟方式有：
```
int val = 20;//在栈空间上开辟四个字节
char arr[10] = {0};//在栈空间上开辟10个字节的连续空间
```
但是上述的开辟空间的方式有两个特点：
1. 空间开辟大小是固定的。
2. 数组在申明的时候，必须指定数组的长度，它所需要的内存在编译时分配。

但是对于空间的需求，不仅仅是上述的情况。有时候我们需要的空间大小在程序运行的时候才能知道，那数组的编译时开辟空间的方式就不能满足了。 这时候就只能试试动态存开辟了。

# 2. 动态内存函数的介绍
## 2.1 malloc和free
C语言提供了一个动态内存开辟的函数：
```
void* malloc (size_t size);
```
这个函数向内存申请一块**连续可用**的空间，并返回指向这块空间的指针。

1. 如果开辟成功，则返回一个指向开辟好空间的指针。
2. 如果开辟失败，则返回一个```NULL```指针，因此```malloc```的返回值一定要做检查。
3. 返回值的类型是```void*``` ，所以```malloc```函数并不知道开辟空间的类型，具体在使用的时候使用者自己来决定。
4. 如果参数```size``` 为```0```，```malloc```的行为是标准是未定义的，取决于编译器。

C语言提供了另外一个函数```free```，专门是用来做动态内存的释放和回收的，函数原型如下：
```
void free (void* ptr);
```
```free```函数用来释放动态开辟的内存。
1. 如果参数```ptr``` 指向的空间不是动态开辟的，那```free```函数的行为是未定义的。
2. 如果参数```ptr``` 是```NULL```指针，则函数什么事都不做。

```malloc```和```free```都声明在```stdlib.h``` 头文件中。 举个例子：
```
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
	//假设开辟10个整型的空间
	//int arr[10];

	//动态内存开辟
	int* p = (int*)malloc(10 * sizeof(int));

	//判断是否开辟成功
	if (p == NULL)
	{
		perror("main");
		return 0;
	}

	//使用
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}

	//回收空间
	free(p);
	p = NULL;//手动置为空指针

	return 0;
}
```

## 2.2 calloc
C语言还提供了一个函数叫```calloc``` ， ```calloc``` 函数也用来动态内存分配。原型如下：
```
void* calloc (size_t num, size_t size);
```
1. 函数的功能是为```num``` 个大小为```size``` 的元素开辟一块空间，并且把空间的每个字节初始化为0。
2. 与函数```malloc``` 的区别只在于```calloc``` 会在返回地址之前把申请的空间的每个字节初始化为全0。 举个例子：

```
int main()
{
	//int* p = (int*)malloc(40);
	int* p = calloc(10, sizeof(int));

	if (p == NULL)
	{
		perror("main");
		return 0;
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i));// 0 0 0 0 0 0 0 0 0
	}

	free(p); 
	p == NULL;

	return 0;
}
```
所以如何我们对申请的内存空间的内容要求初始化，那么可以很方便的使用calloc函数来完成任务。

## 2.3 realloc
realloc函数的出现让动态内存管理更加灵活。
1. 有时会我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间过大了，那为了合理的时候内存，
2. 我们一定会对内存的大小做灵活的调整。那realloc 函数就可以做到对动态开辟内存大小的调整。 函数原型如下：

```
void* realloc (void* ptr, size_t size);
```
1. ```ptr``` 是要调整的内存地址
2. ```size``` 调整之后新大小
3. 返回值为调整之后的内存起始位置。
4. 这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到```新```的空间。
5. ```realloc```在调整内存空间的是存在两种情况：
    情况1：原有空间之后有足够大的空间
    情况2：原有空间之后没有足够大的空间

当是情况1 的时候，要扩展内存就直接原有内存之后直接追加空间，原来空间的数据不发生变化。 
当是情况2 的时候，原有空间之后没有足够多的空间时，扩展的方法是：在堆空间上另找一个合适大小的连续空间来使用。这样函数返回的是一个新的内存地址。 由于上述的两种情况，realloc函数的使用就要注意一些。 举个例子：
```
#include <stdio.h>
int main()
{
	//int* p = (int*)malloc(40);
	int* p = malloc(10, sizeof(int));

	if (p == NULL)
	{
		perror("main");
		return 0;
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", *(p + i) = i);
	}

	int* ptr = (int*)realloc(p, 20 * sizeof(int));
	if (ptr != NULL)
	{
        //如果不是空指针，将新的地址赋值给p
		p = ptr;
	}
	free(p); 
	p == NULL;

	return 0;
}
```
```realloc```在单独使用的时候可以实现```malloc```的效果。

# 3. 常见的动态内存错误
## 3.1 对NULL指针的解引用操作
```
void test()
{
    int *p = (int *)malloc(INT_MAX/4);
    *p = 20;//如果p的值是NULL，就会有问题
    free(p);
}
```

## 3.2 对动态开辟空间的越界访问
```
void test()
{
    int i = 0;
    int *p = (int *)malloc(10*sizeof(int));
    if(NULL == p)
    {
        exit(EXIT_FAILURE);
    }

    for(i=0; i<=10; i++)
    {
        *(p+i) = i;//当i是10的时候越界访问
    }

    free(p);
}
```

## 3.3 对非动态开辟内存使用free释放
```
void test()
{
    int a = 10;
    int *p = &a;
    free(p);//ok? - NO
}
```

## 3.4 使用free释放一块动态开辟内存的一部分
```
void test()
{
    int *p = (int *)malloc(100);
    p++;
    free(p);//p不再指向动态内存的起始位置
}
```

## 3.5 对同一块动态内存多次释放
```
void test()
{
    int *p = (int *)malloc(100);
    free(p);//p = NULL;
    free(p);//重复释放
}
```

## 3.6 动态开辟内存忘记释放（内存泄漏）
```
void test()
{
    int *p = (int *)malloc(100);
    if(NULL != p)
    {
        *p = 20;
    }
}

int main()
{
    test();
    while(1);
}
```
**忘记释放不再使用的动态开辟的空间会造成内存泄漏。** 切记： ```动态开辟的空间一定要释放，并且正确释放。```

# 4. 经典笔试题
## 4.1  题目1
```
void GetMemory(char *p)
{
    p = (char *)malloc(100);
}

void Test(void)
{
    char *str = NULL;
    GetMemory(str);
    strcpy(str, "hello world");
    printf(str);
}
```
```str```传给```GetMemory```函数的时候是值传递，所以```GetMemory```函数的形参```p```是```str```的一份临时拷贝。在```GetMemory```函数内部动态申请空间的地址，存放在```p```中，不会影响外边的```str```，所以当```GetMemory```函数返回之后，```str```依然是空指针，所以```strcpy```会失败。当```GetMemory```函数返回之后，形参```p```销毁，使得动态开辟的```100```个字节存在内存泄漏。正确的做法为：
```
char* GetMemory(char* p)
{
    p = (char*)malloc(100);
    return p;//将p返回
}

void Test(void)
{
    char* str = NULL;
    str = GetMemory(str);
    strcpy(str, "hello world");
    printf(str);
    free(str);
    str = NULL;//释放str并置为空指针
}

int main()
{
    Test();
    return 0;
}
```

## 4.2  题目2
```
char *GetMemory(void)
{
    char p[] = "hello world";
    return p;
}

void Test(void)
{
    char *str = NULL;
    str = GetMemory();
    printf(str);
}
```
```GetMemory```函数内部创建的数组是在栈区创建的，出了函数，```p```数组的空间就还给了操作系统，返回其地址是没有任何意义的，如果通过返回的地址去访问内存就是非法访问内存。

## 4.3  题目3
```
void GetMemory(char **p, int num)
{
    *p = (char *)malloc(num);
}

void Test(void)
{
    char *str = NULL;
    GetMemory(&str, 100);
    strcpy(str, "hello");
    printf(str);
}
```
没有释放动态内存开辟的空间，```free```释放即可。

## 4.4  题目4
```
void Test(void)
{
    char *str = (char *) malloc(100);
    strcpy(str, "hello");
    free(str);
    if(str != NULL)
    {
        strcpy(str, "world");
        printf(str);
    }
}
```
内存空间已经释放且未置成空指针，内存非法访问。

# 5. C/C++程序的内存开辟
![malloc.png](https://s2.loli.net/2022/02/11/9KXtsIYioqxpQVN.png)

C/C++程序内存分配的几个区域：
1. 栈区（```stack```）：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些
存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有
限。 栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返回地址等。
2. 堆区（```heap```）：一般由程序员分配释放， 若程序员不释放，程序结束时可能由操作系统回收 。分配方式类似于链表。
3. 数据段（静态区）（```static```）存放全局变量、静态数据。程序结束后由系统释放。
4. 代码段：存放函数体（类成员函数和全局函数）的二进制代码。

有了上图，就可以更好的理解在[C语言初识](https://urtaome.com/post/c-acquaintance/)中讲的```static```关键字修饰局部变量的例子了。
实际上普通的局部变量是在**栈区**分配空间的，栈区的特点是在上面创建的变量出了作用域就销毁。但是被```static```修饰的变量存放在**数据段（静态区）**，数据段的特点是在上面创建的变量，直到程序结束才销毁所以生命周期变长。


# 6. 柔性数组
也许你从来没有听说过**柔性数组**（```flexible array```）这个概念，但是它确实是存在的。 C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员。

例如：
```
typedef struct st_type
{
    int i;
    int a[0];//柔性数组成员
}type_a;
```
有些编译器会报错无法编译可以改成：
```
typedef struct st_type
{
    int i;
    int a[];//柔性数组成员
}type_a;
```

## 6.1 柔性数组的特点
1. 结构中的柔性数组成员前面必须至少一个其他成员。
2. ```sizeof``` 返回的这种结构大小不包括柔性数组的内存。
3. 包含柔性数组成员的结构用```malloc()```函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。

例如：
```
typedef struct st_type
{
    int i;
    int a[0];//柔性数组成员
}type_a;

printf("%d\n", sizeof(type_a));//输出的是4
```

## 6.2 柔性数组的使用
```
//code1
int i = 0;
type_a *p = (type_a*)malloc(sizeof(type_a)+100*sizeof(int));

p->i = 100;
for(i=0; i<100; i++)
{
    p->a[i] = i;
}
free(p);
```
这样柔性数组成员a，相当于获得了100个整型元素的连续空间。

## 6.3 柔性数组的优势
上述的```type_a```结构也可以设计为：
```
//code2
typedef struct st_type
{
    int i;
    int *p_a;
}type_a;

type_a *p = malloc(sizeof(type_a));
p->i = 100;
p->p_a = (int *)malloc(p->i*sizeof(int));

for(i=0; i<100; i++)
{
    p->p_a[i] = i;
}

//释放空间
free(p->p_a);
p->p_a = NULL;
free(p);
p = NULL;
```
上述```code1```和```code2```可以完成同样的功能，但是```code1```的实现有两个好处： 
**第一个好处是**：方便内存释放
如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。用
户调用```free```可以释放结构体，但是用户并不知道这个结构体内的成员也需要```free```，所以你不能指望用户来发
现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体
指针，用户做一次```free```就可以把所有的内存也给释放掉。

**第二个好处是**：这样有利于访问速度
连续的内存有益于提高访问速度，也有益于减少内存碎片。

# 7. C语言结构体里的数组和指针
拓展阅读，👉[点击这里](https://coolshell.cn/articles/11377.html)

# 8. 作业
## 8.1 作业1
模拟实现函数```atoi```
实现代码如下：
```
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

enum State
{
	INVALID,//0 - 非法
	VALID//1 - 合法
};
//记录的是my_atoi返回的值是合法转化的值，还是非法的状态
enum State state = INVALID;

int my_atoi(const char* s)
{
	int flag = 1;
	//空指针的问题
	if (s == NULL)
	{
		return 0;
	}

	//空字符串
	if (*s == '\0')
	{
		return 0;
	}

	//跳过空白字符
	while (isspace(*s))
	{
		s++;
	}
	
	//处理正负号的问题
	if (*s == '+')
	{
		flag = 1;
		s++;
	}
	else if (*s == '-')
	{
		flag = -1;
		s++;
	}

	//处理数字字符的转换
	long long n = 0;
	while (isdigit(*s))
	{
		n = n * 10 + (*s - '0') * flag;
		if (n > INT_MAX || n < INT_MIN)
		{
			return 0;
		}
		s++;
	}

	if (*s == '\0')
	{
		state = VALID;
		return (int)n;
	}
	else
	{
		return (int)n;
	}
}

int main()
{
	//1. 空指针
	//2. 空字符串
	//3. 遇到非法数字字符
	//4. 超出整型的范围
	const char* p = "1231111";
	int ret = my_atoi(p);
	if (state == VALID)
	{
		printf("正常的转换：%d\n", ret);
	}
	else
	{
		printf("非法的转换：%d\n", ret);
	}
	return 0;
}
```

## 8.2 作业2
寻找单身狗
一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
编写一个函数找出这两个只出现一次的数字。
```
void Find(int* arr, int sz, int *px, int *py)
{
	//1. 异或所有数字
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}

	//2. 计算ret的哪一位为1
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}

	//把从低位向高的第pos位为1的放在一个组，为0的放在另外一个组
	int num1 = 0;
	int num2 = 0;
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			num1 ^= arr[i];
		}
		else
		{
			num2 ^= arr[i];
		}
	}
	*px = num1;
	*py = num2;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	int y = 0;
	Find(arr, sz, &x, &y);
	printf("%d %d", x, y);
	return 0;
}
```