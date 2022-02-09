#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//struct S
//{
//    char c;
//    int i;
//}s1, s2;
//
//struct B
//{
//    double d;
//    struct S s;
//    char c;
//};
//
//int main()
//{
//    struct S s3 = { 'x', 20 };//结构体初始化
//    struct B sb = { 3.14, {'w', 100}, 'q' };//结构体嵌套初始化
//    //.结构体变量
//    //->结构体指针
//    printf("%lf %c %d %c\n", sb.d, sb.s.c, sb.s.i, sb.c);
//    return 0;
//}
//struct S
//{
//    int i;
//    char c;
//};
//
//int main()
//{
//    struct S s = { 0 };
//    printf("%d\n", sizeof(s));
//    return 0;
//}

struct S
{
    int i;
    char c;
};

struct S2
{
    char c1;
    int i;
    char c2;
};

int main()
{
    struct S s = { 0 };
    printf("%d\n", sizeof(s));//8

    struct S2 s2 = { 0 };
    printf("%d\n", sizeof(s2));//12
    return 0;
}