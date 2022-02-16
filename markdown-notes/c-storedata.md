---
title: 'C语言-数据的存储'
date: 2022-01-20 16:49:42
tags: [C]
published: true
hideInList: false
feature: /post-images/c-storedata.jpeg
isTop: false
---
# 1. 数据类型介绍
之前已经学习了基本的内置类型：
```
char        //字符数据类型
short       //短整型
int         //整型
long        //长整型
longlong    //更长的整型
float       //单精度浮点型
double      //双精度浮点型
```
以及他们所占存储空间的大小。**类型的意义**：
1. 使用这个类型开辟内存空间的大小（大小决定了使用范围）。
2. 如何看待内存空间的视角。

# 2. 类型的基本归类
## 2.1 整型家族
```
取值范围定义在limits.h文件中

char
    unsigned char
    signed char
    //ASCII

short
    unsigned short [int]
    signed short [int]

int
    unsigned int
    signed int

long
    unsigned long [int]
    signed long [int]
```

## 2.2 浮点数家族
```
float
double
```

## 2.3 构造类型
```
>数组类型
>结构体类型 struct
>枚举类型 enum
>联合类型 union
```

## 2.4 指针类型
```
int *pi;
char *pc;
float *pf;
void* pv;
```

## 2.5 空类型
```
void表示空类型（无类型）
通常应用于函数的返回类型、函数的参数、指针类型
```
# 3. 整型在内存中的存储
之前介绍过一个变量的创建是要在内存中开辟空间的。空间的大小时根据不同的类型而决定的。那数据在所开辟的内存中到底是如何存储的？如：
```
int a = 20;
int b = -10;
```
我们知道a 分配四个字节的空间，那如何存储？下面来了解原反补的概念：
## 3.1 原码、反码、补码
计算机中有符号的数右三种表示方法，即原码、反码和补码。三种表示方法均有**符号位**和**数值位**两个部分。符号位都是用0表示“正”，用1表示“负”。**而正整数的原反补码相同**。按照数据的数值直接写出的二进制序列就是原码；原码的符号位不变，其他位按位取反，得到的就是反码；反码加一就是补码。

在计算机系统中，数值一律用补码来表示和存储。原因在于使用补码，可以将符号位和数值域统一处理；同时，加法和减法也可以统一处理（**CPU只有加法器**）。此外，补码与原码相互转换，其运算过程是相同的，不需要额外的硬件电路。
## 3.2 大小端介绍
```
int a = -10;
```
上述语句中，a在内存中是这样存放的：
![hex.png](https://s2.loli.net/2022/01/20/wNPLrRHSvEkAhoU.png)
从图中可以看出，数据在内存中是倒着存放的。

### 3.2.1 什么是大小端
1. 大端（存储）模式。是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中。
2. 小端（存储）模式。是指数据的低位保存在内存的低地址中，而数据的高位，保存在内存的高地址中。

### 3.2.2 为什么有大端小端
为什么会有大小端模式之分呢?这是因为在计算机系统中，是以字节为单位的，每个地址单元都对应着一个字节，一个字节为8bit。但是在C语言中除了8bit的char之外，还有16bit的short型，32bit的long（要看具体的编译器）。另外，对于位数大于8位的处理器，例如16位或者32位的处理器，由于寄存器宽度大于一个字节，那么必然存在着一个如何将多个字节安排的问题。因此就导致了大端存储模式和小端存储模式。

例如一个16bit的short型x，在内存中的地址为0x0010，x的值为0x1122，那么0x11为高字节，0x22为低字节。对于大端模式，就将0x11放在低地址中，即0x0010中，0x22放在高地址中，即0x0011中。小端模式，刚好相反。我们常用的x86结构是小端模式，而KEIL C51则为大端模式。很多的ARM，DSP都为小端模式。有些ARM处理器还可以由硬件来选择是大端模式还是小端模式。

### 3.2.3 百度系统工程师笔试题
请简述大端字节序和小端字节序的概念，设计一个小程序来判断当前机器的字节序。实现代码如下：
```
int main()
{
    int a = 1;
    char* p = (char*)&a;

    if(*p == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
    return 0;
}
```

## 3.3 例题
### 3.3.1 例题1
下面的程序输出什么？
```
int main()
{
    char a = -1;
    signed char b = -1;
    unsigned char c = -1;
    printf("a=%d, b=%d, c=%d", a, b, c);
    return 0;
}
```
```
char a = -1;
//11111111 - 补1

signed char b = -1;
//11111111 - 补1

unsigned char c = -1;
//11111111 - 补0
```
由于打印的是整型，补码发生了整型提升，故打印值为：
```
-1  -1  255
```
### 3.3.2 例题2
下面的程序输出什么？
```
int main()
{
    char a = -128;
    printf("%u\n", a);
    return 0;
}
```
原理为：
```
-128：
1000 0000 0000 0000 0000 0000 1000 0000 - 原码
1111 1111 1111 1111 1111 1111 0111 1111 - 反码
1111 1111 1111 1111 1111 1111 1000 0000 - 补码

-128在char 类型中只能存八个比特位：
1000 0000
当以无符号整型打印时，补码发生了整型提升，而char是有符号的，所以高位补1，即：
1111 1111 1111 1111 1111 1111 1000 0000
故打印值为：4294967168
```

### 3.3.3 例题3
```
int main()
{
    char a = 128;
    printf("%u\n", a);
    return 0;
}
```
原理为：
```
128:
0000 0000 0000 0000 0000 0000 1000 0000 - 原反补
char类型只能存放八个字节：
1000 0000
以无符号整型打印，char有符号，高位补1：
1111 1111 1111 1111 1111 1111 1000 0000
故打印值为：4294967168
原理与上题相似
```
有符号的char取值范围是：-128-127。
而无符号char的取值范围是：0-255。

### 3.3.4 例题4
```
int i = -20;
unsigned int j = 10;
printf("%d\n", i + j);//-10
//按照补码的形式运算，最后格式化为有符号的整数
```

### 3.3.5 例题5
```
unsigned int i;
for (i = 9; i >= 0; i--)
{
    printf("%u\n", i);
}
```
上述代码死循环，因为i >= 0恒成立
###  3.3.6 例题6
```
int main()
{
    char a[10000];
    int i;
    for (i = 0; i < 10000; i++)
    {
        a[i] = -1 - i;
    }
    printf("%d", strlen(a));
    return 0;
}
```
```
在循环的时候数组元素为：
-1, -2, -3, ..., -127, -128, 127, 126, 125, ..., 3, 2, 1, 0, -1, -2, ..., -127, -128, 127
```
而strlen在求长度的时候找的是0，而0之前的元素是128+127=255，所以上述代码输出值为255。

###  3.3.7 例题7
```
unsigned char i = 0;
int main()
{
    for (i = 0; i <= 255; i++)
    {
        printf("hello world\n");
    }
    return 0;
}
```
原理与例题5一样，判断条件恒成立。

# 4. 浮点型在内存中的存储
常见的浮点数：
```
3.1415926
1E10//1.0 * 10^10

浮点数家族包括：
float
double
long double

浮点数表示范围：float.h中定义
```

## 4.1 一个例子
浮点数存储的例子
```
int main()
{
    int n = 9;
    float *pFloat = (float *)&n;
    printf("n = %d\n", n);
    printf("*pFloat = %f\n", *pFloat);

    *pFloat = 9.0;
    printf("n = %d\n", n);
    printf("*pFloat = %f\n", *pFloat);
    return 0;
}
```
上述代码输出值为：
```
n = 9
*pFloat = 0.000000

n = 1091567616
*pFloat = 9.000000
```
n和*pFloat在内存中明明是一个数，为什么浮点数和整数的解读结果差别会这么大？那首先需要理解浮点数在计算机内部的表示方法。

根据国际标准IEEE（电气和电子工程协会）754，任意一个二进制浮点数V可以表示成下面的形式：
```
1. (-1)^S * M * 2^E
2. (-1)表示符号位，当s=0，V为正数；当s=1，V为负数
3. M表示有效数字，大于等于1，小于2
4. 2^E表示位数
```
举例来说：
十进制的5.0，写成二进制是101.0，相当于1.01 ✖ 2^2。那么按照上面V的格式，可以得出s=0，M=1.01，E=2。
十进制的-5.0，写成二进制是-101.0，相当于-1.01 ✖ 2^2。那么按照上面V的格式，可以得出s=1，M=1.01，E=2。

**IEEE 754**规定：对于32位的浮点数（float），最高位的1位都是符号位s，接着的8位是指数E，剩下的23位为有效数字M。
![float1.png](https://s2.loli.net/2022/01/21/5qMpiLF9kWEeXIg.png)

而对于64位的浮点数（double），最高的1位是符号位S，接着的11位是指数E，剩下的52位为有效数字M。
![double.png](https://s2.loli.net/2022/01/21/673EcRK9vplJNhA.png)

**IEEE 754对有效数字M和指数E，还有一些特别的规定**。前面说过，1≤M＜2，也就是说，M可以写成1.xxxxxxx的形式，其中xxxxxxx表示小数部分。

IEEE 754规定，在计算机内部保存M时，默认这个数的第一位总是1，因此可以被舍去，只保存后面的xxxxxxx部分。比如保存1.01的时候，只保存01，等到读取的时候，再把第一位的1加上去。这样做的目的，是节省1位有效数字。以32位浮点数为例，留给M的只有23位，将第一个的1舍去以后，等于可以保存24位有效数字。

至于指数E，情况就比较复杂。

**首先，E为一个无符号整数（unsigned int）**。这意味着如果E为8位，它的取值范围为0\~255；如果E为11位，它的取值范围为0\~2047。但是我们知道，科学计数法中的E是可以出现负数的，所以IEEE 754规定，存入内存时E的真实值必须再加上一个中间数，对于8位的E，这个中间数是127；对于11位的E，这个中间数是1023。比如，2^10的E是10，所以保存在32位浮点数时，必须保存成10+127=137，即10001001。
这样描述可能有些复杂，来看代码：
```
int main()
{
    float f = 5.5f;
    return 0;
}
```
变量f在内存中是如何存储的呢？
```
首先来写成科学计数法
5.5 = 101.1 = (-1)^0 * 1.011 * 2 ^2
S = 0, M = 1.011, E = 2//E = 2 + 127 = 129

故5.5在内存中的二进制序列位为：
0100 0000 1011 0000 0000 0000 0000 0000
转为十六进制位就是（四个二进制位就是一个十六进制位）：
40    b0    00    00    
```
真的是这样的吗？来调试看一下：
![f_men.png](https://s2.loli.net/2022/01/21/TpmuYGRJNZXyeDh.png)

可以看出浮点型数据也会遇到大小端的问题。

然后，指数E从内存中取出还可以再分为三种情况：

**E不全为0或不全为1**
这时，浮点数就采用下面的规则表示，即指数E的计算值减去127（或1023），得到真实值，再将有效数字M前加上第一位的1。比如0.5（1/2）的二进制形式位0.1，由于规定正数部分必须为1，即将小数点右移1位，则为1.0 * 2 ^ (-1)，其阶码为-1 + 127 = 126，表示为01111110，而尾数1.0去掉整数部分为0，补齐0到23位，则其二进制表示形式为：
```
0 01111110 00000000000000000000000 
```

**E全为0**
这时浮点数的指数E等于1-127（或者1-1023）即为真实值，有效数字M不再加上第一位的1，而是还原为0.xxxxxx这样的小数。这样做是为了表示±0，以及接近于0的很小的数字。

**E全为1**
这时，如果有效数字M全为0，表示±无穷大（正负取决于符号位s）。

接下来就可以解释4.1开始的代码了
```
int main()
{
    int n = 9;
    float *pFloat = (float *)&n;
    printf("n = %d\n", n);
    printf("*pFloat = %f\n", *pFloat);

    *pFloat = 9.0;
    printf("n = %d\n", n);
    printf("*pFloat = %f\n", *pFloat);
    return 0;
}
```
来分段解析，第一段：
```
int n = 9;
float *pFloat = (float *)&n;
printf("n = %d\n", n);
printf("*pFloat = %f\n", *pFloat);
```
```
9的二进制序列为：
0000 0000 0000 0000 0000 0000 0000 1001

当被强制类型转换为浮点数时并打印时，计算机就认为上述的二进制序列是浮点数类型的：
0 00000000 00000000000000000001001
S E        M
E为全0，直接将M拿出来，第一位补0，即变为0.00000000000000000001001，再乘上2^(-126)，可以看出这是一个非常非常小的数字。而%f只能打印小数点后六位，所以打印值为0.000000

故这一段的输出值为：
9
0.000000
```

第二段解析：
```
*pFloat = 9.0;
printf("n = %d\n", n);
printf("*pFloat = %f\n", *pFloat);
```
```
这时将9.0以浮点数的形式放入*pFloat中，以科学计数法的方式表示为：
(-1)^0 * 1.001 * 2 ^ 3
S = 0, E = 3 + 127 = 130, m = 001
在内存中二进制序列位为：
0 10000010 00100000000000000000000

当以%d打印时，打印有符号整数，上述的二进制补码也就是原码，所以打印值为：1091567616
当以%f打印时，直接打印9.0

故这一段的输出值为：
1091567616
9.000000
```

# 5. 作业
## 5.1 作业1
打印杨辉三角
```
int main()
{
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			if (i == j)
			{
				arr[i][j] = 1;
			}
			if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
```

