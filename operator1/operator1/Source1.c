#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//int main()
//{
//    int flag = 5;
//    if (flag)
//    {
//        //flag为真，打印hehe
//        printf("hehe\n");
//    }
//    if (!flag)
//    {
//        //flag为假，打印haha
//        printf("haha\n");
//    }
//    return 0;
////}
//int main()
//{
//    int a = 10;
//    char arr[10] = { 0 };
//    printf("%d\n", sizeof(a));//计算a所占空间的大小
//    printf("%d\n", sizeof(arr));
//    return 0;
////}
//int main()
//{
//    int a = 10;
//    int b = a++;//后置++，先使用，后自增1
//    //int b = ++a;//前置++，先自增1，后使用
//    printf("%d\n", a);//11
//    printf("%d\n", b);//10
//    return 0;
////}
//int main()
//{
//    int a = 10;
//    int b = a--;//后置--，先使用，后自减1
//    //int b = --a;//前置--，先自减1，后使用
//    printf("%d\n", a);//10
//    printf("%d\n", b);//9
//    return 0;
//}
//int main()
//{
//    int a = 10;
//    printf("%p\n", &a);//&取地址操作符
//    return 0;
////}
//int main()
//{
//    int a = 10;
//    printf("%p\n", &a);//&取地址操作符
//    int* pa = &a;
//    //pa是用来存放内存单元的地址 - pa就是一个指针变量
//    //指向的对象的类型是int
//    *pa = 20;//解引用操作符 - 或者叫间接访问操作符
//    printf("%d\n", a);
//    return 0;
////}
//
//int main()
//{
//    int a = (int)3.14;
//    //把3.14强制转换成int类型
//    printf("%d\n", a);
//    return 0;
////}
//int main()
//{
//    int i = 0, a = 0, b = 2, c = 3, d = 4;
//    //i = a++ && ++b && d++;
//    i = a++ || ++b || d++;
//    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//    return 0;
//    //程序的输出结果是什么？
//}
//
//int main()
//{
//    int a = 5;
//    int b = 0;
//
//    //三目操作符
//    //a大于5吗？如果大于5，将它的值改为-1，赋给b
//    b = a > 5 ? 1 : -1;
//    printf("%d\n", b);
//    return 0;
//}
int main()
{
    int a = 3;
    int b = 5;
    int c = 0;
    int d = (c = 5, a = c + 3, b = a - 4, c += 5);
    printf("%d\n", d);
    return 0;
}