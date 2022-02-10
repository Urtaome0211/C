#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//练习1
//struct S3
//{
//    double d;
//    char c;
//    int i;
//};
//
////练习2-结构体嵌套问题
//struct S4
//{
//    char c1;
//    struct S3 s3;
//    double d;
//};
//
//int main()
//{
//    printf("%d\n", sizeof(struct S3));
//    printf("%d\n", sizeof(struct S4));
//
//    return 0;
//}

//把默认对齐数改为2

//#pragma pack(2)
//
//struct S
//{
//    char c1;
//    int i;
//    char c2;
//};
//
//#pragma pack()
//
//int main()
//{
//    printf("%d\n", sizeof(struct S));
//    return 0;
//}
//struct A
//{
//    int _a : 2;
//    int _b : 5;
//    int _c : 10;
//    int _d : 30;
//};
//
//int main()
//{
//    printf("%d\n", sizeof(struct A));
//    return 0;
//}
//struct S
//{
//    char a : 3;
//    char b : 4;
//    char c : 5;
//    char d : 4;
//};
//
//int main()
//{
//    struct S s = { 0 };
//    s.a = 10;
//    s.b = 12;
//    s.c = 3;
//    s.d = 4;
//    return 0;
////}
//union Un
//{
//    char c;
//    int i;
//};
//
//int main()
//{
//    union Un un;
//    //printf("%p\n", &un);
//    //printf("%p\n", &(un.i));
//    //printf("%p\n", &(un.c));
//
//    un.i = 0x11223344;
//    un.c = 0x55;
//    printf("%x\n", un.i);
//    return 0;
//}

union Un1
{
    char c[5];
    int i;
};
union Un2
{
    short c[7];
    int i;
};

int main()
{
    printf("%d\n", sizeof(union Un1));
    printf("%d\n", sizeof(union Un2));
    return 0;
}