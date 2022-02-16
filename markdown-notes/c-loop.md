---
title: 'C语言-分支语句与循环语句'
date: 2021-12-11 14:14:58
tags: [C]
published: true
hideInList: false
feature: /post-images/c-loop.jpeg
isTop: false
---
# 1.分支语句
## 1.1 if语句

if语句语法结构为：
```
//单分支
if(表达式)
    语句;
```
```
//多分支
//若有多个语句，要用花括号括起来。
if(表达式)
    语句1;
else
    语句2;
```
```
//多分支
if(表达式1)
    语句1;
else if(表达式2)
    语句2;
else
    语句3;
```

### 1.1.1 if多分支语句
```
#include<stdio.h>

int main()
{
    int age = 0;
    scanf("%d\n", &age);

    if ( age < 18 )
        printf("少年\n");
    else if ( age >= 18 && age < 26 )//&&逻辑与（并且）
        printf("青年\n");
    else if ( age >= 26 && age <40 )
        printf("中年\n");
    else if ( age >= 40 && age < 60 )
        printf("壮年\n");
    else if ( age >= 60 && age <= 100 )
        printf("老年\n");
    else
        printf("老不死\n");
    return 0;
}
```
  
### 1.1.2 悬空符else
```
#include<stdio.h>

int main()
{
    int a = 0;
    int b = 2;
    if (a == 1)
        if (b == 2)
            prinf("hehe\n");
    else
        prinf("haha\n");
    return 0;
}
```
else和最近的if进行配对，由于a=0，根本就没有执行if语句，故直接return 0。
  
## 1.2 switch语句
switch语法结构为：
```
switch(整型表达式)
{
    语句项;
}
```
语句项是什么？
```
//是一些case语句，如下：
case 整型常量表达式:
    语句;
    break;
```
有如下代码：
```
switch(day)
{
    case 1:
        printf("Mon\n");
        break;
     case 2:
        printf("Thus\n");
        break;
     case 3:
        printf("Wed\n");
        break;
    case 4;
        printf("Thur\n");
        break;
    case 5:
        printf("Fri\n");
        break;
    case 6:
        printf("Sat\n");
        break;
    case 7:
        printf("Sun\n");
        break;
}
```
每一句条件语句结束都要加上break;跳出，否则会继续往下执行。**break根据实际需求添加。**
  
### 1.2.1 default子句
```
switch(day)
{
    case 1:
        printf("Mon\n");
        break;
     case 2:
        printf("Thus\n");
        break;
     case 3:
        printf("Wed\n");
        break;
    case 4;
        printf("Thur\n");
        break;
    case 5:
        printf("Fri\n");
        break;
    case 6:
        printf("Sat\n");
        break;
    case 7:
        printf("Sun\n");
        break;
    default:
        printf("Error");
        break;
}
```
1. 若有匹配的case值，则从该case语句开始执行，直至出现break或者执行到switch语句的最后一条语句。
2. 若没有匹配的case值，且有default子句，则开始从default语句开始执行，直至出现break或者执行到switch语句的最后一条语句。
3. 若没有匹配的case值，也没有default子句，则跳过switch语句体,什么也不做。

有如下代码：
```
#include<stdio.h>

int main()
{
    int n = 1;
    int m =2;

    switch(n)
    {
        case 1:
            m++;
        case 2:
            n++;
        case 3:
            switch(n)
            {
            case 1:
                 n++;
            case 2:
                m++;
                n++;
                break;
            }
        case 4:
            m++;
            break;
        default:
            break;
    }
    printf("m = %d, n = %d\n", m, n);
    return 0;
}
```
1. 上述代码中，n=1, m=2。
2. 经过case1和case2运算之后，n=2,m=3。
3. 当进入case3时，由于n=2，故直接执行case3中的case2，此时n=3,m=4。
4. 最后进行case运算，m=5。
5. 最后打印数值，m=5,n=3。

## 1.3 goto语句
C语言中提供了可以随意滥用的goto语句和标记跳转的标号。从理论上goto语句是没有必要的，实践中goto语句也可以很容易的写出代码。但是某些场合下goto语句还是用得着的，最常见的用法就是终止程序在某些深度嵌套的结构的处理过程，例如一次跳出两层或多层循环。这种情况使用break是达不到目的的，它是能从最内层循环推出到上一层的循环。下面是goto语句的两个例子：
```
#include<stdio.h>
int main()
{
flag:
    printf("hehe\n");
    printf("hehe\n");
    goto flag;
}
```
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char input[20] = { 0 };
    system("shundown -s -t 60");
again:
    printf("你的电脑将在一分钟后关机，如果输入我好帅，则取消关机");
    scanf("%s", input);
    if(strcmp(input, "我好帅") == 0)
    {
        system("shundown -a");
    }
    else
    {
        goto again;
    }
    return 0;
}
```

# 2. 循环语句
## 2.1 While循环
```
//While循环语法
while(表达式)
    循环语句;
```
有如下代码：
```
#include<stdio.h>

int main()
{
    int i = 1;
    while ( i <= 10)
    {
        printf("%d ", i);
        i++;
    }
    return 0;
}
```
上述代码表示，i从1开始，每打印一次就加一个数，故打印值为1 2 3 4 5 6 7 8 9 10。
  
### 2.1.1 While-continue
```
#include<stdio.h>

int main()
{
    int i = 1;
    while ( i <= 10)
    {
        if (5 == i)
            continue;//跳过判断
        printf("%d ", i);
        i++;
    }
    return 0;
}
```
上述代码，打印1，2，3，4...死循环。
continue的作用是跳过本次循环continue后边的代码。

### 2.1.2 While-break
```
#include<stdio.h>

int main()
{
    int i = 1;
    while ( i <= 10)
    {
        if (5 == i)
            break;
        printf("%d ", i);
        i++;
    }
    return 0;
}
```
在while循环中，break用于永久终止循环。上述代码打印值为1，2，3，4。

### 2.1.3 小例子
**eg1**
```
int main()
{
    int ch = 0;
    while((ch = getchar()) != EOF)
        putchar(ch);
    return 0;
}
```
eg1中，getchar()从键盘（缓冲区）读取字符，putchar()输出字符。EOF表示end of file，为文件结束标志，值为-1。
  
**eg2**
```
int main()
{
    char password[20] = { 0 };
    printf("Please keyin password: ");
    scanf("%s", password);
    printf("Confirm Your Password(Y/N): ");

    //清理缓冲区内多个字符
    int tmp = 0;
    while (tmp = getchar() != '\n' )
    {
        ;
    }

    int ch = getchar();

    if (ch == 'Y')
    {
        printf("Suss!");
    }
    else
    {
        printf("Error!");
    }
    return 0;
}
```
由于getchar()只能清理一个字符，故创建一个临时变量tmp，当getchar()读不到\n时结束循环，即代表缓冲区内没有任何字符。
1. getchar()读取的时字符返回的是整型，且读取的是ASCII码值。
2. EOF值为-1，故返回类型为整型。
  
## 2.2 for循环
for循环的语法结构：
```
for(表达式1; 表达式2; 表达式3)
    循环语句；
```
**表达式1**为初始化部分，用于初始化循环变量。**初始化只会执行一次。**
**表达式2**为条件判断部分，用于判断循环时终止。
**表达式3**为调整部分，用于循环条件的调整，如：i++。

**注**：
1. 不可在for循环体内修改循环变量，防止for循环失去控制。
2. 建议for语句的循环控制变量的取值采用“前闭后开区间”的写法。例：for(i=0; i<10; i++)

```
int main()
{
    int x, y;
    for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
    {
        printf("hehe\n");
    }
    return 0;
}
```
在循环体内可以有两个变量，由于x<2，打印两次hehe。

```
int main()
{
    int i = 0;
    int k = 0;
    for (i = 0, k = 0; k = 0; i++, k++)
    {
        k++;
    }
    return 0;
}
```
一个等号为赋值，将0赋值给k，而0为假，故循环一次都没有执行。
  
### 2.2.1 for-continue
```
int main()
{
    int i = 0;

    for (i = 1; i<= 10; i++)
    {
        if (i == 5)
            continue;

        printf("%d ", i);
    }
    return 0;
}
```
continue在i++之后，与while循环有所区别，当i=5时，跳过打印。故打印值为1 2 3 4 6 7 8 9 10
  
### 2.2.2 for-break
```
int main()
{
    int i = 0;

    for (i = 1; i<= 10; i++)
    {
        if (i == 5)
            break;

        printf("%d ", i);
    }
    return 0;
}
```
break原理与while一致。打印值为1 2 3 4
  
## 2.3 do-while循环
do语句语法
```
do
    循环语句;
while(表达式);
```
表达式为真，执行。
先执行，再判断。

```
int main()
{
    int i = 1;
    do
    {
        printf("%d ", i);
        i++;
    } while (i<=10);

    return 0;
}
```
上述代码中：打印1，自增为2，判断为真，再次循环。以此类推，当i=11时，条件不成立，跳出循环。
do语句的continue和break原理与while循环中的原理一致。

# 3. 作业
## 作业1
计算n的阶乘
**分析**：若要计算n的阶乘，首先要生成n个数字。计算从1开始，故定义一个变量ret，每循环一次执行一次ret=ret * i。代码如下：
```
int main()
{
    int i = 0;
    int n = 0;
    int ret = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
	{
	    ret *= i;//计算n的阶乘
          //ret = ret * i
	}
    printf("%d\n", ret);
    return 0;
}
```

## 作业2
计算1!+2!+3!+...+10!
**分析**：在上面作业的基础之上，再定义一个变量sum和一个新的循环用于计算累加值，并且在每一次循环开始之前初始化。
```
int main()
{
    int i = 0;
    int n = 0;
    int sum = 0;
    int ret = 1;
    for (n = 1; n <= 10; n++)
	{
	    ret = 1;//每次循环之前，将数值初始化
	    for (i = 1; i <= n; i++)
		{
		    ret *= i;//计算n的阶乘
		}
	    sum += ret;//将值累加起来
	}
	
    printf("%d\n", sum);
    return 0;
}
```
但是这种方法极其繁琐，每次运算之前都要重新计算这个数的阶乘。
我们知道$2!=2*1$，$3!=3*2*1=3*2!$。由此可知，只需在此基础上在乘上一个数就变成了下一个数的阶乘。实现代码如下：
```
int main()
{
    int i = 0;
    int n = 0;
    int sum = 0;
    int ret = 1;
    for (n = 1; n <= 10; n++)
	{
	    ret *= n;
	    sum += ret;
	}
	
    printf("%d\n", sum);
    return 0;
}
```

## 作业3
在一个有序数组中查找具体的某个数字n。
  
可以使用**二分查找**来解题：用首下标加末下标除以二来确定数字的位置，每一次遍历都可以去掉一半的数字，相比按序遍历，此方法效率较快。
```
int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int k = 7;//查找7的下标"6"
    int sz = sizeof(arr) / sizeof(arr[0]);//数组的元素个数

    int left = 0;
    int right = sz - 1;

	while (left <= right)
	{
	    int mid = (left + right) / 2;
	    if (arr[mid] < k)
		{
		    left = mid + 1;//若是小于想找的数，则左下标加一
		}
	    else if (arr[mid] > k)
		{
		    right = mid - 1;//若是大于想找的数，则右下标减一
		}
	    else
		{
		    printf("Found the subscript:%d\n", mid);
		    break;
		}
	}
    if (left > right)
	{
	    printf("Cannot found!\n");
	}
    return 0;
}
```
1. 编写代码，演示多个字符从两端移动，从中间汇聚。
示例：
```
//welcome!
//########
//w######!
//we#####e!
//....
//welcome!
```
实现代码如下：
```
#include<stdio.h>
#include<string.h>//使用了strlen()，需引用此头文件

int main()
{
    char arr1[] = "Welcome to my home!";
    char arr2[] = "###################";

    int left = 0;
    int right = strlen(arr1) - 1;//定义数组下标

    while (left <= right)
	{
	    arr2[left] = arr1[left];//arr2的左下标等于arr1左下标
	    arr2[right] = arr1[right];//arr2的右下标等于arr1的右下标
	    printf("%s\n", arr2);
	    left++;
	    right--;//每循环一次左下标加一，右下标减一
	}
    return 0;
}
```
<font face="微软雅黑">while</font>循环的条件为<font face="微软雅黑">left<=right</font>，说明当<font face="微软雅黑">left<=right</font>时，还有字符可以拿下来。
若需要一条一条打印的效果，可使用<font face="微软雅黑">Sleep()</font>函数，并引头文件<font face="微软雅黑">#include<windows.h></font>。优化后的代码如下：
```
#include<stdio.h>
#include<string.h>
#include<windows.h>//使用了Sleep()和system()，需引用此头文件

int main()
{
    char arr1[] = "Welcome to my home!";
    char arr2[] = "###################";

    int left = 0;
    int right = strlen(arr1) - 1;

    while (left <= right)
	{
	    arr2[left] = arr1[left];
	    arr2[right] = arr1[right];
	    printf("%s\n", arr2);
	    Sleep(1000);//睡眠一秒,括号内单位为毫秒
	    system("cls");//每打印一次就清空一次屏幕
	    left++;
	    right--;
	}
    printf("%s\n", arr2);
    return 0;
}
```
  
## 作业4
编写代码，模拟用户登录情景，并只能登陆三次。（只允许输入三次密码，如果密码正确提示登录成功，如果三次均输入错误，则退出程序）
实现代码如下：
```
#include<stdio.h>
#include<string.h>//使用了strcmp()函数，需 引此头文件

int main()
{
    int i = 0;
    char password[20] = { 0 };
    //假设正确密码为123465

    for (i = 0; i < 3; i++)//只能输入三次密码
    {
        printf("Please enter your password: ");
        scanf("%s", password);
	
        if (strcmp(password, "123456") == 0)//字符串之间不能用==来比较，需使用strcmp()函数
	    {
	        printf("Login Suss!");
	        break;
	    }
        else
	    {
	        printf("Wrong password!\n");
	    }
    }
    if (i == 3)
    {
        printf("You have entered the wrong password three times. Exit the program");
    }
    return 0;
}
```

## 作业5
猜数字游戏
   需求：
```
   //产生一个1-100之间的随机数
   //猜数字
   //猜对了。游戏结束
   //猜错了，告诉你猜大了还是小了，继续猜，直到正确为止
   //游戏可以一直玩，无需重启
 ```
   实现代码如下：
```
    #include<stdio.h>
    #include<stdlib.h>//调用了rand()函数
    #include<time.h>//调用了time()函数

    void menu()
    {
	    printf("*********************************\n");
	    printf("***********  1. play  ***********\n");
	    printf("***********  0. exit  ***********\n");
	    printf("*********************************\n");
    }

    void game()
    {
	    //猜数字游戏的实现
	    //1.生成随机数,使用rand()函数
	    //%100的余数是0-99，再加一，范围就是1-100
        //余数总是比除数小，当被除数是100时，余数的范围是0-99
	    int ret = rand() % 100 + 1;
	
	    //2.猜数字
	    int guess = 0;
	    while (1)//选择1时，进入游戏
    	{
		    printf("请猜数字：");
		    scanf("%d", &guess);
	    	if (guess < ret)
	    	{
		    	printf("猜小了\n");
	    	}
	    	else if (guess > ret)
	    	{
		    	printf("猜大了\n");
	    	}
	    	else
	    	{
		    	printf("猜对了！\n");
		    	break;
                //猜对数字时，跳出循环
	    	}
    	}
    }
    int main()
    {
	    //rand()返回了一个0-32767之间的数字
    	//若要纯随机，在调用rand()函数之前，得先调用srand()函数
	    srand((unsigned int)time(NULL));
    	//时间戳，来做到纯随机
    	int input = 0;
    	do
    	{
		    menu();//编写一个menu()函数，来实现菜单功能
	    	printf("请选择：");
	    	scanf("%d", &input);
	    	switch (input)//功能选择
	    	{
	    	case 1:
	    		game();//编写了一个game()函数来实现游戏功能
		    	break;
	    	case 0:
		    	printf("退出游戏\n");
		    	break;
	    	default:
			    printf("选择错误，重新选择\n");
		    	break;
		    }
    	} while (input);

    	return 0;
    }
 ```
   
## 作业6
  
从大到小输出，示例：
```
//输入2 3 1
//输出3 2 1
```
实现代码如下：
```
#include<stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d%d", &a, &b, &c);

    if (a < c)
    {
        int tmp = a;
        a = c;
        c = tmp;
    }
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (b <c)
    {
        int tmp = b;
        b = c;
        c = tmp;
    }
    printf("%d %d %d",a, b, c);
    return 0;
}
```
创建一个临时变量tmp来储存较小的数值，以达到数值调换的效果。

## 作业7
打印1-100内能被3整除的数字。实现代码如下：
```
#include<stdio.h>

int main()
{
    int i = 0;
    for (i=1; i <= 100; i++)
    //for (i=3; i <= 100; i+=3)
    {
        if (i % 3 == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
```
i模3等于0。
另：可将循环体中的<font face="微软雅黑">i++</font>改成<font face="微软雅黑">i+=3</font>，删去判断部分，也可起到相同的效果。

## 作业8
给定两个数，求这两个数的最大公约数。实现代码如下：
```
#include<stdio.h>

int main()
{
    int m = 0;
    int n = 0;
    scanf("%d%d", &m, &n);

    int max = 0;
    //假设最大公约数max是m与n中的较小值。
    if (m > n)
    {
        max = n;
    }
    else
    {
        max = m;
    }
    while (1)
    {
        if (m % max == 0 && n % max == 0)
	    {
            printf("最大公约数是：%d\n", max);
            break;
	    }
        max--;
        //若较小值不能被同时整除，每循环一次就减一，直到能被同时整除为止
        //且那个值一定是最大公约数。
    }
    return 0;
}
```
最大公约数就是最大可以同时除以两个数的值。
然而可以使用辗转相除法来实现更快速的计算，实现代码如下：
```
int main()
{
    int m = 0;
    int n = 0;
    int t = 0;
    scanf("%d%d", &m, &n);

    while (t = m % n)
    {
        m = n;
        n = t;
    }
    printf("最大公约数为：%d\n", n);
    //同理，若要计算最小公倍数
    //最小公倍数=(m*n)/最大公约数
    return 0;
}
```

## 作业9
打印1000-2000年之间的所有闰年
```
#include<stdio.h>

int main()
{
    int year = 0;
    int count = 0;
    for (year = 1000; year <= 2000; year++)
    //生成所有年份
    {
        if(year % 4 == 0 && year % 100 != 0)
        //1.若能被400整除，则为闰年
        //2.能被4整除，且不能被100整除，则为闰年
        {
            printf("%d ", year);
            count++;
        }
        if(year % 400 == 0)
        {
            printf("%d ", year);
            count++;
        }
    }
printf("\ncount = %d ", count);
//count为总共有几个闰年
return 0;
}
```
上述代码还可继续优化，只需使用“||”操作符将循环条件改成以下代码即可：
```
if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
```

## 作业10
打印100-200之间的素数
```
#include<stdio.h>
//#include<math.h>

int main()
{
    int i = 0;
    int count = 0;
    for(i = 100; i <= 200; i++)
    {
        //素数就是质数，只能被1和它本身整除
        int j = 0;
        int flag = 1;//假设i就是素数
        for(j = 2; j < i; j++)
        //for(j = 2; j <= sqrt(i); j++)
        //2到i-1的数字去试除，判断是否能被整除
        {
            if(i % j == 0)//若能被某个数整除，那它就不是素数
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            count++;
            printf("%d ", i);
        }
    }
    printf("\ncount = %d", count);
    return 0;
}
```
在上述代码中，第一层for循环生成了100-200之间的数字，第二层for循环来判断这之中的数字是否为素数。判断条件为：
1. 使用2到i-1的数字去试除，判断是否能被整除，若能被整除，则这个数就不是素数，并将flag赋值为0，不打印。（如：i=100, j=2，能整除，那么100就不是素数）
2. 若不能被整除，那这个数就是素数，并且打印。
   
由于偶数一定不是素数，在循环体中可只生成奇数来达到优化的效果，将第一层for循环的条件改成：
```
for(i = 101; i <= 200; i += 2)
```
## 作业11
数一下1-100的所有整数中出现多少个数字9
```
#include<stdio.h>

int main()
{
    int i = 0;
    int count = 0;
    for (i = 1; 1 <= 100; i++)
    {
        if (i % 10 == 9)
        //个位为9
        {
            count++;
        }
        if (i / 10 == 9)
        //十位为9
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
```

## 作业12
计算1/1 - 1/2 + 1/3 - 1/4 + 1/5......+1/99-1/100的值，打印结果。
```
#include<stdio.h>

int main()
{
    int i = 0;
    double sum = 0.0;
    //和为小数，用双精度浮点数来定义
    int flag = 1;
    for (i = 1; i <= 100; i++)
    {
        sum+=flag * 1.0 / 1;
        flag = -flag;
        //加减交替
    }
    printf("%lf\n", sum);//0.688
    return 0;
}
```

## 作业13
求10个整数中过的最大值
```
#include<stdio.h>

int main()
{
    int arr[] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };
    int max = arr[0];
    //用数组中的元素去比，不可赋值为0
    int i = 0;
    for(i = 1; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Max = %d\n", max);//-1
    return 0;
}
```

## 作业14
在屏幕上输出9*9乘法口诀表
```
#include<stdio.h>

int main()
{
    int i = 0;
    for (i = 1; i < = 9; i++)//行数
    {
        int j = 0;
        for(j = 0; j <= i; j++)//列数
        {
            printf("%d*%d=%-2d ", i, j, i*j);
            //%-2d代表打印两位，左对齐，不够用空格补
            //%2d代表打印两位，右对齐，不够用空格补
        }
        printf("\n");
        //每打印一次换一行
    }
    return 0;
}
```
