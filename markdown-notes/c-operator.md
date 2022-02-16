---
title: 'C语言-操作符详解'
date: 2022-01-12 17:18:02
tags: [C]
published: true
hideInList: false
feature: /post-images/c-operator.png
isTop: false
---
# 1. 算术操作符
常见的算术操作符有：
```
+   //加法
-   //减法
*   //乘法
/   //除法
%   //取模（取余数）
```
1. 除了%操作符之外，其他几个操作符都可以作用于整数和浮点数
2. 对于/操作符如果两个操作数都为整数，执行整数除法。而只要有浮点数执行的就是浮点数除法。
3. %操作符的两个操作数必须为整数。返回的是整除之后的余数。

## 1.1 例1 - /操作符示例
```
#include<stdio.h>
int main()
{
    float a = 6.0 / 5.0;
    printf("%f", a);//1.20000
    return 0;
}
``` 
## 1.2 例2 - %操作符
```
#include<stdio.h>
int main()
{
    int a = 7 % 3;
    printf("%d", a);//2
    return 0;
}
```

七除以三的余数为2，取模操作符取的就是这个余数。**%操作符必须都是整数**。
# 2. 移位操作符
移位操作符有两种：
```
<<  //左移操作符
>>  //右移操作符
```
## 2.1 例1 - 左移操作符
```
#include<stdio.h>
int main()
{
    int a = 2;
    int b = a << 1;
    printf("b = %d", b);//b = 4
    return 0;
}
```
向左移动一位，移动的其实是二进制位，上述代码的原理如下：
<font face="微软雅黑">
1. 首先，2在内存中的二进制序列为：0000 0000 0000 0000 0000 0000 0000 0010
2. 序列往左移一位，变成：0000 0000 0000 0000 0000 0000 0000 0100
3. 转换为十进制$2^{2}=4$，所以打印值为4。
</font>

## 2.2 右移操作符
由于二进制第一位为符号位，所以在右移操作过程中会产生问题。右移操作符分为两种：
### 2.2.1 算数右移
右边丢弃，左边补原符号位，看代码：
```
#include<stdio.h>
int main()
{
    int a = 10;
    int b = a >> 1;
    printf("b = %d", b);//b = 5
    return 0;
}
```
若采用算数右移，由于10为正数，所以左边补的是0（1为负数）。
### 2.2.2 逻辑右移
右边丢弃，左边补0。
若采用逻辑右移，不管符号是什么，补的都是0。看代码：
```
#include<stdio.h>
int main()
{
    int a = -1;
    int b = a >> 1;
    printf("b = %d", b);//b = -1，当前右移操作使用的是算术右移
    return 0;
}
```
整数的二进制表示形式有三种：
1. 原码：直接根据数值写出的二进制序列。
2. 反码：原码的符号位不变，其他位按位取反。
3. 补码：反码+1就是补码。
<font face="微软雅黑">
-1在内存中，存放的是二进制的补码
原码：1000 0000 0000 0000 0000 0000 0000 0001
反码：1111 1111 1111 1111 1111 1111 1111 1110
补码：1111 1111 1111 1111 1111 1111 1111 1111
</font>
上述算法是针对负数的，正整数的原码、反码、补码相同。
**注**：移动的位数不能是负数。
# 3. 位操作符
位操作符主要有：
```
&   //按位与
|   //按位或
^   //按位异或
注：他们的操作数必须是整数，且操作的都是二进制序列
```
## 3.1 & 按位与
```
#include<stdio.h>
int main()
{
    int a = 3;
    int b = 5;
    int c = a & b;
    printf("c = %d", c);//c = 1
    return 0;
}
```
上述代码中，3和5的二进制序列分别为：
```
0000 0000 0000 0000 0000 0000 0000 0011
0000 0000 0000 0000 0000 0000 0000 0101
对应的二进制序列相同且都为1才进行按位与操作，操作结果为：
0000 0000 0000 0000 0000 0000 0000 0001
故打印值为1
```
## 3.2 | 按位或
```
#include<stdio.h>
int main()
{
    int a = 3;
    int b = 5;
    int c = a | b;
    printf("c = %d", c);//c = 7
    return 0;
}
```
同3.1，操作过程为：
```
0000 0000 0000 0000 0000 0000 0000 0011
0000 0000 0000 0000 0000 0000 0000 0101
对应的二进制序列只要有一个序列为1就可以进行按位或操作，操作结果为：
0000 0000 0000 0000 0000 0000 0000 0111
故打印值为7
```
## 3.3 ^ 按位异或
```
#include<stdio.h>
int main()
{
    int a = 3;
    int b = 5;
    int c = a ^ b;
    printf("c = %d", c);//c = 6
    return 0;
}
```
上述操作过程为：
```
0000 0000 0000 0000 0000 0000 0000 0011
0000 0000 0000 0000 0000 0000 0000 0101
对应的二进制序列相同为0，相异为1，就可以进行按位或操作，操作结果为：
0000 0000 0000 0000 0000 0000 0000 0110
故打印值为6
```
## 3.4 例题
不创建新的变量，交换两个数，如：a = 3,b = 5。交换后a = 5, b = 3，实现代码为：
```
#include<tdio.h>
int main()
{
    int a = 3;
    int b = 5;
    printf("a = %d b = %d", a, b);
    a = a ^ b;//a = 110B, b = 101B
    b = a ^ b;//a = 110B, b = 011B
    a = a ^ b;//a = 101B, b = 011B
    printf("a = %d b = %d", a, b);
    return 0;
}
```
```
a ^ a = 0
a ^ 0 = a
```
这种方法不会进位，所以没有溢出。

# 4. 赋值操作符
赋值操作符是一个很棒的操作符，他可以让你得到一个你之前不满意的值。也就是你可以给自己重新赋值。常见的赋值操作符有：
```
=   
//以下为复合赋值
+=  -=  *=  /=  >>= <<= %=  &=  |=  ^=
```
有如下代码：
```
int weight = 120;
weight = 89;//重新赋值

double salary = 1000.0;
salary = 10000.0;//重新赋值
```
赋值操作符也可以连续使用：
```
int a = 10;
int x = 0;
int y = 20;
a = x = y + 1;
//连续赋值，a与x的值都是y + 1
```
赋值还可以写成复合的效果：
```
a = a + 10;
a += 10;
//这两种赋值方法是等价的
```
但是这里有一点需要注意：
```
一个“=”为赋值
而两个“==”为判断相等
```
# 5. 单目操作符
主要的单目操作符有：
```
//逻辑反操作
!           

//负值  
-     

//正值       
+     

//取地址     
&       

//操作数的类型长度  
sizeof    

//按位取反
~         

//前置、后置-- 
--        

//前置、后置++
++      

//解引用操作符
*         

//强制类型转换
(类型)     
```
## 5.1 ! 逻辑反操作
真变为假（0），假变为真，看如下代码：
```
#include<stdio.h>
int main()
{
    int flag = 5;
    if (flag)
    {
        //flag为真，打印hehe
        printf("hehe\n");
    }
    if (!flag)
    {
        //flag为假，打印haha
        printf("haha\n");
    }
    return 0;
}
```
## 5.2 - 负值
让数值变为负数
```
int main()
{
    int a = 10;
    a = -a;
    printf("%d\n", a);//-10
    return 0;
}
```
## 5.3 + 正值
让数值变为正数，此种操作符经常省略

## 5.4 sizeof 操作符
sizeof是一个操作符，不是函数，它可以计算所占空间的大小，有如下代码：
```
int main()
{
    int a = 10;
    short = 5;
    char arr[10] = { 0 };
    printf("%d\n", sizeof(a));//计算a所占空间的大小，单位是字节
    printf("%d\n", sizeof a);//4
    printf("%d\n", sizeof(s = a + 2));//2
    printf("%d\n", s);//5

    printf("%d\n", sizeof(arr));
    printf("%d\n", sizeof(char [10]));
    return 0;
}
```
sizeof括号中表达式是不参与运算的

## 5.5 ~ 按位取反
对一个数的二进制位取反
```
int main()
{
    int a = -1;
    int b = ~a;
    printf("%d\n", b);//0
    return 0;
}
```
上述代码中，是如何实现的？
```
-1的
原码为1000 0000 0000 0000 0000 0000 0000 0001
反码为1111 1111 1111 1111 1111 1111 1111 1110
补码为1111 1111 1111 1111 1111 1111 1111 1111
内存中存的就是补码，对补码进行取反：
0000 0000 0000 0000 0000 0000 0000 0000
故打印值为0
```
那么按位操作符有什么用呢？
若a = 13，想要把a的二进制中的第五位置成1，再置成0，实现代码如下：
```
int main()
{
    int a = 13;

    //要把a的二进制中的第五位置成1
    a = a | (1 << 4);
    printf("%d\n", a);

    //要把a的二进制中的第五位置成0
    a = a & a ~ (1 << 4)
    printf("%d\n", a);
    return 0;
}
```

## 5.6 ++ -- 操作符
### 5.6.1 前置、后置++
```
int main()
{
    int a = 10;
    int b = a++;//后置++，先使用，后自增1
    //int b = ++a;//前置++，先自增1，后使用
    printf("%d\n", a);//11, 11
    printf("%d\n", b);//10, 11
    return 0;
}
```
### 5.6.1 前置、后置--
```
int main()
{
    int a = 10;
    int b = a--;//后置--，先使用，后自减1
    //int b = --a;//前置--，先自减1，后使用
    printf("%d\n", a);//9, 9
    printf("%d\n", b);//10, 9

    printf("%d\n", a--);//10
    printf("%d\n", a);//9
    return 0;
}
```
现有的教材中（我不说是哪一本，懂的都懂），写成这样：
```
(++i) + (++i) + (++i)
```
😅😅😅正经人谁这样写啊，狗都不写

## 5.7 & 取地址和 * 解引用操作符
```
int main()
{
    int a = 10;
    printf("%p\n", &a);//&取地址操作符
    int* pa = &a;
    //pa是用来存放内存单元的地址 - pa就是一个指针变量
    //指向的对象的类型是int
    *pa = 20;//解引用操作符 - 或者叫间接访问操作符
    printf("%d\n", a);
    return 0;
}
```

## 5.8 强制类型转换
```
int main()
{
    int a = (int)3.14;
    //把3.14强制转换成int类型
    printf("%d\n", a);
    return 0;
}
```

# 6. 关系操作符
常见的关系操作符有：
```
>
>=
<
<=
!=  //用于测试“不相等”
==  //用于测试“相等”
```
关系操作符没什么好写的，但是要注意使用时候的陷阱，如：
"=="和"="是不一样的，在编写程序时需注意。
# 7. 逻辑操作符
逻辑操作符有两种：
```
&&  //逻辑与
||  //逻辑或
//只判断真假
```
区分逻辑与和按位与，区分逻辑或和按位或：
```
1 & 2 --->0
1 && 2 -->1

1 | 2 ---> 3
1 || 2 --> 1
```
有如下代码：
```
int main()
{
    int a = 3;
    int b = 0;
    if (a && b)
    //有一个为假，不执行判断语句
    {
       printf("hehe\n") ;
    }
    if (a || b)
    //有一个为真，就执行判断语句
    {
        printf("hehe\n") ;
    }
    return 0;
}
```
## 7.1 例题 - 360笔试题
```
int main()
{
    int i = 0, a = 0, b = 2, c = 3, d = 4;
    i = a++ && ++b && d++;
    //i = a++ || ++b || d++;
    printf("a = %d\nb = %d\nc = %\nd = %d\n", a, b, c, d);
    return 0;
    //程序的输出结果是什么？
    //1 2 3 4
}
``` 
 &&语句中：因为a = 0， 为假，所以整条代码没有运行，之后a自增，最后打印结果为1 2 3 4。
 ||语句中：只要有一个为真，整个表达式都为真，最后打印结果为1 3 3 4
# 8. 条件操作符
条件操作符是一个三目操作符，其语法结构为：
```
exp1 ? exp2 : exp3
```
有如下代码：
```
int main()
{
    int a = 5;
    int b = 0;

    //三目操作符
    //a大于5吗？如果大于5，将它的值改为-1，赋给b
    b = a > 5 ? 1 : -1;
    printf("%d\n", b);
    return 0;
}
```
其实就是if-else的逻辑
如果表达式2为真，表达式3不计算，否则就要计算表达式3。
# 9. 逗号操作符
逗号表达式就是用逗号隔开的多个表达式，从左向右以此执行。整个表达式的结果是最后一个表达式的结果。语法为：
```
exp1, exp2, exp3, ..., expN;
```
有如下代码：
```
int main()
{
    int a = 3;
    int b = 5;
    int c = 0;
    int d = (c = 5, a = c + 3, b = a - 4, c += 5);
    printf("%d\n", d);
    return 0;
}
```
从左向右依次计算，最后输出值为10。
# 10. 下标引用、函数调用和结构成员
## 10.1 [] 下标引用操作符
操作数：一个数组名 + 一个索引值
```
int arr[];//创建数组
arr[9] = 10;//使用下标引用操作符
[    ]的两个操作数是arr和9
```
有如下代码：
```
int mian()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d\n", arr[4]);//打印下标为4的元素，5
    return 0;
}
```

## 10.2 （）函数调用操作符
接受一个或多个操作数：第一个操作数是函数名，剩余的操作数就是传递给函数的参数
有如下代码：
```
int Add(int x, int y)
{
    return x + y;
}

int main()
{
    int a = 10;
    int b = 20;
    int ret = Add(a, b);//函数调用操作符，操作数有三个，为Add, a, b
    printf("%d\n", ret);
    return 0;
}
```

## 10.3 结构成员访问操作符
```
.   结构体.成员名
->  结构体指针->成员名
```
有如下代码：
```
struct book
{
    char name[20];
    char id[20];
    int price;
};

int main()
{
    struct book b = {"C语言", "C20220117", 55};
    struct book * pb = &b;
    printf("书名：%s, 书号：%s, 定价：%d\n", b.name, b.id, b.price);
    //结构体变量名.成员名
    printf("书名：%s, 书号：%s, 定价：%d\n", (*pb).name, (*pb).id, (*pb).price);
    printf("书名：%s, 书号：%s, 定价：%d\n", pb->name, pb->id, pb->price);
    //结构体指针操作符->
    return 0;
}
```

# 11. 表达式求值
表达式求值的顺序一部分是由操作符的**优先级和结合性**决定。
同样，有些表达式的操作数在求值的过程中可能需要转换为其他类型。如：
```
int main()
{
    int a = 3;
    int b = 5;
    int c = a + b * 7;
    printf("%d\n", c);//38
    //乘法的优先级比加法高
    return 0;
}
```

# 12. 隐式类型转换
## 12.1 整型提升
C语言的整型算术运算总是至少以缺省整型类型的精度来进行的。
为了获得这个精度，表达式中的字符和短整型操作数在使用之前被转换为普通整型，这种转换成为**整型提升**。
整型提升的意义：
表达式的整型运算要在CPU的相应运算器件内执行，CPU内整型运算器（ALU）的操作数的字节长度一般就是int的字节长度，同时也是CPU的通用寄存器的长度。因此，即使两个char类型的相加，在CPU执行时实际上也要先转换为CPU内整型操作数的标准长度。通用CPU（general-purpose CPU）是难以直接实现两个8比特字节直接相加运算（虽然机器指令中可能有这种字节相加指令）。所有，表达式种各种长度可能小于int长度的整型值，都必须转换为int或unsigned int，然后才能送入CPU中取执行运算。

```
char a, b, c;
...
a = b + c;
```
b和c的值被提升为普通整型，然后再执行加法运算。加法运算完成之后，结果被截断，并储存于a中。
### 12.1.1 如何进行整型提升
整型提升是按照变量的数据类型的符号位来提升的。
看代码：
```
int main()
{
    char a = 3;
    //0000 0000 0000 0000 0000 0000 0000 0011
    //0000 0011 - a

    char b = 127;
    //0000 0000 0000 0000 0000 0000 0111 1111
    //0111 1111 - b

    char c = a + b;
    //0000 0000 0000 0000 0000 0000 0000 0011
    //0000 0000 0000 0000 0000 0000 0111 1111
    //加法运算之后的数值为：
    //0000 0000 0000 0000 0000 0000 1000 0010

    printf("%d\n", c);//-126
    //打印类型为整型，又发生整型提升
    //1111 1111 1111 1111 1111 1111 1000 0010(补码)
    //减一取反得原码，为：
    //1111 1111 1111 1111 1111 1111 1000 0001（反码）
    //1000 0000 0000 0000 0000 0000 0111 1110（原码）
    //转为十进制就为-126
    return 0;
}
```
发现a和b都是char类型，都没有达到一个int的大小，这里就会发生整型提升，运算过程请看注释
注：有符号高位补0或1，无符号永远补0。
整型提升的例子：
```
int main()
{
    char a = 0xb6;
    short b = 0xb600;
    int c = 0xb6000000;

    if (a == 0xb6)
    {
        printf("a");
    }
    if (b == 0xb600)
    {
        printf("b");
    }
    if (c == 0xb6000000)
    {
        printf("c");
    }
    return 0;
}
//c
```
上述代码中，a和b都不是int类型，都发生了整型提升，在后面的比较的时候都不是用一个数了，所以只打印了c。

## 12.2 算术转换
如果某个操作符的各个操作数属于不同类型，那么除非其中一个操作数的转换为另一个操作数的类型，否则操作就无法进行。下面的层次体系称为**寻常算术转换**：
```
long double
double
float
unsigned long int
long int
unsigned int
int
```
如果某个操作数的类型在上面这个列表中排名较低，那么首先要转换为另外一个操作数的类型后执行运算。比如：一个变量为4（int），另一个变量为4.5（float），这时需要把4转换为（4.0，float），向精度更高的去转换。这也是一种隐式类型转换。
**注：算术转换要合理，要不然会有一些潜在的问题。**

# 13. 操作符的属性
复杂表达式的求值有三个影响因素。
```
1.操作符的优先级
2.操作符的结合性
3.是否控制求值顺序
```
相邻的操作符先执行哪一个？取决于他们的优先级，如果两者的优先级相同，取决于他们的结合性。有以下代码：
```
int main()
{
    int a = 4;
    int b = 5;
    int c = a + b * 7;//优先级决定了计算顺序
    int c = a + b+ 7;//优先级不起作用，结合性决定计算顺序
    return 0;
}
```

## 13.1 一些问题表达式
### 13.1.1 例1
```
a*b + c*d + e*f
```
上述表达式中，优先级并不能决定第三个*比第一个+早执行
所以表达式的计算顺序可能是：
```
a*b
c*d
a*b + c*d
e*f
a*b + c*d + e*f

or

a*b
c*d
e*f
a*b + c*d
a*b + c*d + e*f
```
### 13.1.2 例2
```
c + --c
```
上述表达式中，左操作数是在--c之前还是之后求值？所以结果是不可预测的，是有歧义的。

### 13.1.3 例3
```
//非法表达式
int main()
{
    int i = 0;
    i = i-- - --i * ( i = -3 ) * i++ + ++i;
    printf("i = %d\n", i);
    return 0;
}
```
上述代码在不同的编译器中结果都各不相同，只有神经病才会写出这样的代码😅

### 13.1.4 例4
```
int fun()
{
    static int count = 1;
    return ++count;
}

int main()
{
    int answer;
    //2 - 3 * 4 = -10
    answer = fun() - fun() * fun();
    printf("%d\n", answer);
    return 0;
}
```
上述代码有问题，虽然在大多数的编译器上求得的结果都是相同的。

# 14. 作业
## 14.1 作业1
写一个函数，返回参数中二进制中1的个数。
如：
```
15      0000 1111       4个1
```
实现代码如下：
```
int NumberOfOne(int n)
{
    int count = 0;
    while(n)
    {
        if (n % 2 == 1)
        {
            count++;
        }
        n /= 2;
    }
    return count;
}

int main()
{
    int n = 10;
    int ret = NumberOfOne(n);
    printf("%d\n", ret);
    return 0;
}
```
但是上述的代码存在缺陷，无法计算负数的二进制位中的1的个数，修改为如下即可实现负数二进制中1个数的计算：
```
int NumberOfOne(int n)
{
    int count = 0;
    int i = 0;

    for (i = 0; i < 32; i++)
    {
        if (((n >> i) & 1) == 1)
        {
            count++;
        }
    }
    return count;
}
```
利用位操作符“>>”即可，每循环一次判断当前二进制位是否为1，如果是，计数器就加一，当循环完毕之后，return count。

## 14.2 作业2
求两个数二进制中不同位的个数。
两个int(32位)整数m和n的二进制表达中，有多少个位（bit）不同？
如：
```
input:22 33
output:5
```
实现代码如下：
```
int main()
{
    int m = 0;
    int n = 0;
    int i = 0;
    int count = 0;
    scanf("%d %d", &m, &n);
    for (i = 0; i < 32; i++)
    {
        if (((m >> i) & 1) != ((n >> i) & 1))
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
```

## 14.3 作业3
获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列。实现代码如下：
```
int main()
{
    int n = 0;
    scanf("%d", &n);
    //打印偶数位
    int i = 0;
    for (i = 31; i >= 1; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    printf("\n");
    
    //打印奇数位
    for (i = 30; i >= 0; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    return 0;
}
```

## 14.4 作业4 算术转换
计算求和，求Sn=a+aa+aaa+aaaa+aaaaa的前五项之和，其中a是一个数字：
实现代码为：
```
int main()
{
    int a  = 0;
    int n = 0;
    scanf("%d %d", &a, &n);

    int i = 0;
    int sum = 0;
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        ret = ret * 10 + a;
        sum += ret;
    }
    printf("sum = %d\n", sum);
    return 0;
}
```

## 14.5 作业5
写一个函数打印数组arr的内容，不使用数组下标，使用指针，arr是一个整型一维数组。
```
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int *p = arr;
    int sz = sizeof(arr) / sizeof(arr[0]);
    int *pend = arr + sz - 1;

    while (p <= pend)
    {
        printf("%d ", *p);
        p++;
    }
    return 0;
}
```

## 14.6 作业6
打印水仙花数
求出 0~100000之间的所有“水仙花数”并输出
```
#include<math.h>

int main()
{
    int i = 0;
    for (i = 0; i < 100000; i++)
    {
        //判断i是否为自幂数
        //1. 计算i的位数 - n
        int n = 1;
        int tmp = i;
        while (tmp / 10)
        {
            n++;
            tmp /= 10;
        }

        //2.计算i的每一位的n次方之和
        tmp = i;
        int sum = 0;
        while (tmp)
        {
            sum += pow(tmp % 10, n);
            tmp /= 10;
        }

        //3.判断
        if (sum == i)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
```