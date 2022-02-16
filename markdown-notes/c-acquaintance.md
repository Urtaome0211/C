---
title: '初识C语言'
date: 2021-12-10 15:35:23
tags: [C]
published: true
hideInList: false
feature: /post-images/c-acquaintance.jpeg
isTop: false
---
# 一、主体  

```
#include<stdio.h>
int main()
{
    printf("Hello World!");
    return 0;
}
```
上述代码：  
1. 第一行#include<stdio.h>，其中stdio表示standard input output，包括一个stdio.h的头文件。  
2. main为主函数，为程序的入口，有且仅有一个。
3. printf为打印函数，scanf为输出函数。
4. return 0返回一个整型。

# 二、数据类型  

顾名思义，数据类型用来说明数据的类型，确定了数据的解释方式，让计算机和程序员不会产生歧义。在C语言中，有多种数据类型，如：  
  
字符串|整型|短整型|长整型|更长的整形|单精度浮点|双精度浮点
:-:|:-:|:-:|:-:|:-:|:-:|:-:
char|int|short|long|longlong|float|double  
  
另外，输出的格式字符有：  
|格式字符|意义|  
-|:-
|%d|以十进制形式输出带符号整数（正数不输出符号）|  
|%o|以八进制形式输出无符号整数（不输出前缀0）|  
|%x|以十六进制形式输出无符号整数（不输出前缀oX）|  
|%u|以十进制形式输出无符号整数|  
|%f|以小数形式输出单、双精度实数|  
|%e|以指数形式输出单、双精度实数|  
|%g|以%f或%e中较短的输出宽度，输出单、双精度实数|  
|%c|输出单个字符|  
|%s|输出字符串|  
|%p|以地址形式打印|  
  
**注1**:在计算机中，一个字节（byte）等于八个比特位（bit）。  
**注2**:若使用的IDE为Visual Studio，直接使用$printf$或者$scanf$命令会报错，请在源文件第一行添加预处理命令：  
```
#define _CRT_SECURE_NO_WARNINGS 1
```
  
**Q1**：为什么要定义这么多数据类型？
**A1**：不同的数据类型向内存申请的空间是不同的，可以使用sizeof来查看。代码如下：  
```
#include<stdio.h>

int main()
{
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(short));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(longlong));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));
    return 0;
}
```

计算机中的数据储存在硬盘、内存、高速缓存、寄存器中。空间越小，速度越快，造价越高。

# 三、变量  
  
现实生活中我们会找一个小箱子来存放物品，一来显得不那么凌乱，二来方便以后找到。计算机也是这个道理，我们需要先在内存中找一块区域，规定用它来存放整数，并起一个好记的名字，方便以后查找。这块区域就是“小箱子”，我们可以把整数放进去了。  

例：  
```
int  a;
a = 1000;
```
这条语句的意思是在内存中划出一个空间给变量a（变量名称可以随意取，关键字除外），在里面存放整数1000。  因为a的值可以改变，所以称为变量。同时也可在定义的同时进行初始化：  
```
int a = 1000;
```
**变量也分全局变量和局部变量，当局部变量和全局变量同名时，优先使用局部变量。**  

# 四、常量

常量的概念是：不会变化的量，如一个人的身份、血型。  
一般来说，凡是被编程者定义的量都是变量。 但是有几种特殊情况为常量：
## 1. Const修饰的常变量。  
```
#include<stdio.h>

int main
{
    const int num = 4;
    printf("%d\n", num);
    num = 8;
    printf("%d\n", num);
    return 0;
}
```
上述代码运行之后输出结果为4，因为num还是一个变量，只是具有了一个常属性。
  
## 2. #define定义的标识符常量
```
#include<stdio.h>

int main()

#define MAX 10//定义的标识符常量
{
    int arr[MAX] = {0}; //数组初始化为0
    printf("%d\n", MAX);//输出10
    return 0;
}
```
  
## 3. 枚举常量（一一列举）
```
#include<stdio.h>

enum Sex
{
    Male,//0
    Female,//1
    Secret//2
};//枚举enumerate，代码块内为枚举常量。
int main()
{
    //enum Sex s = Male;
    printf("%d\n", Male);
    printf("%d\n", Feale);
    printf("%d\n", Secret);//输出值为0，1，2
    return 0;
}

```

# 五、作用域
  
作用域（scope），指一段程序代码中所用到的名字并不总是有效和可用的，而限定这个名字的可用性的代码范围就是这个名字的作用域。
1. 局部变量的作用域是变量所在的局部范围。
2. 全局变量作用域是整个工程。
   
# 六、生命周期
  
生命周期是变量的创建到销毁之间的一个时间段。
1. 局部变量的生命周期：进入作用域生命周期开始，出作用域生命周期结束。
2. 全局变量生命周期：整个程序的生命周期。

# 七、字符串
```
"Hello World.\n"
```
这种由双引号引起来的一串字符称为字符串字面值，简称字符串。
其中\0为结束符，只算结束标志，不算内容。
**例1**
```
#include<stdio.h>

int main()
{
    char arr1[] = "abc";
    char arr2[] = {'a', 'b', 'c', 0};
    printf("%s\n", arr1);
    printf("%s\n", arr2);
    return 0;
}
```
在例1的代码中，数组arr1内，字符串由双引号引起，内容不只是只有"abc"，在最后其实还有一个0。而数组arr2的每一个字符都由单引号引起，故在最后要添0作结束符号。详情见例2：

**例2**
```
#include<stdio.h>

int main()
{
    char arr1[] = "abc";
    char arr2[] = {'a', 'b', 'c'};
    printf("%d\n", strlen (arr1));//strlen为string length计算字符长度。
    printf("%d\n", strlen (arr2));
    return 0;
}
```
上述代码中，数组arr2在最后没有添加0作为结束符号，故在输出完c之后，后面都是随机值，直到输出0结束统计。
  
# 八、转义字符
  
转义字符，就是转变了原来的意思“ \ ”。  

**例1**
```
#include<stdio.h>

int main()
{
    printf("c:\test\test.c");
    return 0;
}
```
例1中输出值为c:     est     est.c。因为在字符串中出现了“ \t ”。这个代表的是水平制表符。只需再加一个反斜杠，变成“ \ \t ”转义一下即可。

**例2**
```
#include<stdio.h>

int main()
{
    printf("(are you ok??)");
    return 0;
}
```
在VC6.0中，“？？）”会被转义成“]”，而在新的编译器中则不会出现这种情况。

**例3**
```
#include<stdio.h>

int main()
{
    printf("%c\n", '\130');
    return 0;
}
```
上述代码输出值为X。因为\130是八进制数字，在编译时先转换成十进制：  
$1\cdot 8^{2}+3\cdot 8^{1}+0\cdot 8^{0}=64+24=88$  
而输出的类型是单个字符，88的ASCII码值为X，故最后输出X。

**常见的转义字符有**
\\?|在书写连续多个问号时使用，防止他们被解析成三个字母
:-:|:-
\\'|用于表示字符常量
\\"|用于表示一个字符串内部的双引号
\\|用于表示一个反斜杠，防止它被解释为一个转义序列符
\a|警告字符，蜂鸣
\b|退格符
\f|换页，将当前位置移到下一页的开头
\n|换行
\r|回车
\t|水平制表符
\v|垂直制表符
\ddd|ddd表示1~3个八进制数字。如\130
\xdd|dd表示2个十六进制数字。如x30

**例4**
```
#include<stdio.h>

int main()
{
    printf("%d\n", srtlen("c:\test\328\test.c"));
    return 0;
}
```
上述代码输出结果为14。因为在八进制中，不可能出现“8”，故\32为一个字符，最后输出结果为14。

# 九、注释
  
注释是用来解释复杂代码的
```
//
or
/* xxxxx */
```
//是C++的注释风格，而$/* */$是C语言的注释风格，但是此注释方法有缺点，不支持嵌套。

# 十、选择语句
  
```
#include<stdio.h>
//#include<string.h>

int main()
{
   int input = 0;
   printf("要好好学习吗？（1/0）");
   scanf("%d", &input);//&为取地址符号

   if(input == 1)
   {
       printf("拿到好offer\n");
   }
   else
   {
       printf("回家种田\n");
   }
   return 0;
}
```
if....else为分支语句，&为取址符号，分支语句可以放入大括号内。

# 十一、循环语句

```
#include<stdio.h>

int main()
{
    int line = 0;
    while (line < 30000)
    {
        printf("coding:%d\n", line);
        line++；
    }
    if(line == 30000)
    {
        printf("Congrats! Good offer!");
    }
    return 0;
}
```
上述代码使用的是while循环，i++代表每循环以此就自增一次，当行数等于30000行是就打印字符串。
  

# 十二、函数
  
```
#include<stdio.h.>

int Add(int x, int y)
{
    int z = 0;
    z = x+ y;
    return z;
}

int main()
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d%d", &num1, &num2);
    int sum = Add(num1, num2);
    printf("%d\n", sum);
    return 0;
}
```
上述代码编写了一个简单加法函数Add，将num1和num2的数据传递给x和y，在Add中进行数据运算，运算完成后再传递给sum，最后打印数据。

# 十三、数组
  数组是一组相同类型的元素的集合。  

**例1**
```
#include<stdio.h>

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    char ch[5] = {'a', 'b', 'c'};
    return 0;
}
```
上述代码中，数组arr\[10]表示，定义一个整型数组，最多放十个元素。
数组ch\[5]表示，定义一个字符串数组，有五个值，但是只放了三个。为不完全初始化，后面的值默认为0。
  
**例2**
```
#include<stdio.h>

int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int  i = 0;
    while(i < 10)
    {
        printf("%d", arr[i]);
        i++;
    }
    return 0;
}
```
上述代码表示，循环从0开始，每循环一次就加1，数组中，下标从0开始，最后输出值为12345678910。

# 十四、操作符
## 1. 算数操作符
```
+       -       *       /       %
//%为取模，即取余
```
## 2. 移位操作符
```
>>      <<
```
**注**:移动的是二进制位。  


```
#include<stdio.h>

int main()
{
    int a = 2;
    int b = a << 1;
    printf("%d\n", b);
    return 0;
}
```
在上述代码中，对2进行移位操作。
1. 首先，2的二进制数为10，整型在内存中为4个字节，32个比特位，在内存中表示为：
   0000 0000 0000 0000 0000 0000 0000 0010
2. 接下来序列向左移一位，变成：  
   0000 0000 0000 0000 0000 0000 0000 0100
3. 而二进制数$100=1\cdot 2^{2}+0\cdot 2^{1}+0\cdot 2^{0}=4$，故输出值为4.

## 3. 位操作符
```
&：按位与
|：按位或
^：按位异或
```
  
## 4. 赋值操作符
```
=       +=    -=     *=     /=   &=     ^=       !=      >>=    <<=
```
  
## 5. 单目操作符
!|逻辑反操作
:-:|:-
\-|负值
\+|正值
&|取地址
sizeof|操作数的类型长度（以字节为单位）
~|对一个属的二进制按位取反
--|前置、后置--
++|前置、后置++
\*|简介访问操作符（解引用操作符）
（类型）|强制类型转换

**注1**:逻辑反操作符！的意义是把假变成真，真变成假，0表示假，非0表示真。
**注2**:sizeof不是函数。  
**注3**:以“+”为例：a+b，“+”有两个操作数，即为双目操作符。单目操作符只有一个操作数。
  
### ①sizeof
```
#include<stdio.h>

int main()
{
    int arr[10] = { 0 };
    printf("%d\n", sizeof(arr));
    printf("%d\n", sizeof(arr[0]));
    int sz = sizeof(arr) / sizeof(arr[0]);//计算数组内有多少个元素
    printf("%d\n", sz);
    return 0;
}
```
上述代码表示，数组arr内有十个元素均为整型，总大小为40bytes。数组arr\[0]内有一个元素，为整型，总大小为4bytes。最后的运算$40/4=10$，即数组内有十个元素。故输出40，4，10。
  
### ②按位取反“~”
```
#include<stdio.h>

int main()
{
    int a = 0;
    printf("%d\n", ~a);
    return 0;
}
```
在计算机中，一个整数在二进制中有三种表示方法，分别为：**原码、反码和补码**。  
在上述的代码中，对0进行按位取反，即按二进制位取反。
1. 首先，0在内存中的序列位为：
   0000 0000 0000 0000 0000 0000 0000 0000（原码）
2. 进行按位取反，变成：
   1111 1111 1111 1111 1111 1111 1111 1111（反码）
3. 减去一，得到补码：
   1111 1111 1111 1111 1111 1111 1111 1110（补码）
4. 再次取反得原码：
   1000 0000 0000 0000 0000 0000 0000 0001
   最高位1代表是负数，二进制数1，最后输出值为-1。
**注1**:%d打印的是原码，但是数据在内存中是以补码形式存放的。
**注2**:正整数的原码、反码、补码相同。

### ③前置、后置++
```
#include<stdio.h>

int main()
{
    int a = 10;
    int b = ++a;
    printf("%d\n", b);
    printf("%d\n", a);
    return 0;
}
```
上述代码中，前置++是先自增，后使用。
1. 打印b时,a先完成自增再赋值给b，故打印值为11。
2. 打印a时，a已完成自增，故打印值也是11。
  

```
#include<stdio.h>

int main()
{
    int a = 10;
    int b = a++;
    printf("%d\n", b);
    printf("%d\n", a);
    return 0;
}
```
上述代码中，后置++的运算规则时先使用，再自增。
1. 打印b时，由于后置++的运算规则，a不作运算，故打印值为10。
2. 打印a时，a++进行了运算，故打印值为11。
  
###  ④（类型）转换
```
#include<stdio.h>

int main()
{
    int a = (int)3.14;
    printf("%d\n", a);
    return 0;
}
```
上述代码中，3.14是double类型，从double转到int会丢失精度。可在3.14前加入(int)来强制将double转换成int类型。最后输出数值为3。
  
## 6.关系操作符
```
>       >=      <       <=      !=      ==
//!=  用于测试“不相等”
//==  用于测试“相等”
```
  
## 7.逻辑操作符
```
&&      //逻辑与
||      //逻辑或
```
### ①逻辑与
```
#include<stdio.h>

int main()
{
    int a = 3;
    int b = 5;
    int c = a && b;
    printf("%d\n", c);
    return 0;
}
```
上述代码表示，a为真，b也为真，c = a并且b，c为真，故输出c = 1。在进行逻辑与运算时，若是其中有一个数为假，那么就都为假。
 
### ②逻辑或
```
#include<stdio.h>

int main()
{
    int a = 3;
    int b = 0;
    int c = a || b;
    printf("%d\n", c);
    return 0;
}
```
在逻辑或运算中，a和b有一个为真，则输出值为真，若两个数都为假，则输出假。
  
## 8. 条件操作符
```
exp1 ? exp2 : exp3
//为三目操作符
```

```
#include<stdio.h>

int main()
{
    int a = 0;
    int b = 3;
    int max = 0;
    max = a > b ? a : b;
    printf("%d\n", max);
}
```
使用条件操作符运算时：
1. exp1成立，exp2计算，整个表达式的结果是exp2的结果。
2. exp1不成立，exp3计算，整个表达式的结果是exp3的结果。
故输出结果为3。
  
## 9. 逗号表达式
用逗号隔开的一串表达式。
```
exp1, exp2, exp3, ... expN
```

```
#include<stdio.h>

int main()
{
    int a = 0;
    int b = 3;
    int c = 5;
    int d = (a = b + 2, c = a - 4, b = c + 2);
    printf("%d\n", d);
    return 0;
}
```
1. 逗号表达式从左至右依次计算。
2. 整个表达式的结果是最后一个表达式的结果。
  
## 10. 下标引用、函数调用和结构成员

```
[]  下标引用
()  函数调用
.   //后面说明
->  //后面说明
```

```
#include<stdio.h>

int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    printf("%d\n", arr[5]);
    return 0;
}
```
\[]为下标引用，上述代码打印数组内第六个数字。输出6。

```
#include<stdio.h>

int main()
{
    printf("hehe\n");
    return 0;
}
```
调用函数的时候，函数名后边的()就是函数调用的操作符。
  
# 十五、常见关键字
**关键字C语言提供的，不能自己创建关键字**
**变量名不能用关键字**

常见的关键字有：
```
auto    break   case    char    const   continue    default     
do  double  else    enum    extern  float   for goto    
if  int long    register    return  short   signed  sizeof  
static  struct  switch  typedef union   unsigned    
void    volatile    while
```
  
## 1. 关键字typedef
typedef为类型重定义，或叫类型重命名。

```
typedef unsigned int u_int
int main()
{
    u_int num = 100;
    return 0;
}
```
上述代码将unsigned int重定义成u_int，之后调用u_int即可。
  
## 2. 关键字static
### ① 修饰局部变量

```
#include<stdio.h>

void test()
{
    int a = 1;
    a++;
    printf("%d ", a);
}
int main()
{
    int i = 0;
    while(i < 10)
    {
        test();
        i++;
    }
    return 0;
}
```
上述代码表示，程序从main进入，当调用test()函数时，执行a++运算，打印2，之后程序循环执行10次，故打印值为十个二。若使用static修饰局部变量时：

```
#include<stdio.h>

void test()
{
    static int a = 1;
    a++;
    printf("%d ", a);
}
int main()
{
    int i = 0;
    while(i < 10)
    {
        test();
        i++;
    }
    return 0;
}
```
当调用函数时，执行a++运算，输出2。但是a出范围时，并没有销毁，故当再次执行循环时会在此基础上执行a++，在循环十次之后，打印的数值为2，3，4，5，6，7，8，9，10，11。

内存中有三个区域：
1. 栈区：存放局部变量、函数的参数等
2. 堆区：动态内存分配
3. 静态区：全局变量、static修饰的静态变量等

**注**：static修饰局部变量，改变了局部变量的生命周期，本质是改变了变量的存储类型。
  
### ② 修饰全局变量
```
//Source1.c
#include<stdio.h>
extern int g_val;
//extern申明外部符号

int main()
{
    printf("%d\n", g_val);
    return 0;
}
```
```
//Source2.c
//全局变量
static int g_val = 20;
```
static修饰的全局变量，只能在当前源文件内使用，其他源文件不可使用。
全局变量在其他源文件内部可以被使用，是因为其具有外部链接属性。但是一旦被static修饰之后，就变成了内部链接属性，其他源文件就不可链接了。
  
### ③ 修饰函数
```
//Source1.c
#include<stdio.h>
extern int Add(int x, int y);

int main()
{
    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("sum is = %d\n", sum);
    return 0;
}
```
```
//Source2.c
static int Add(int x, int y)
{
    return x + y;
}
```
static修饰函数，使得函数能在当前源文件内部使用，原理与修饰全局变量类似。
  

# 十六、define定义常量和宏
define是一个预处理指令
```
#include<stdio.h>

#define ADD(X,Y) X+Y //若要输出20，将X+Y用小括号括起来

int main()
{
    printf("%d\n", 4*ADD(2, 3));
    return 0;
}
```
上述代码输出值为11
**Q:为什么输出的是11不是20？**
**A:传输的数据被替换成4\*2+3而不是4\*(2+3)**
