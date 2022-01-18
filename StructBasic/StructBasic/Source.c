#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//struct B
//{
//    char c;
//    short s;
//    double d;
//};
//
//struct Stu
//{
//    struct B sb;
//    char name[20];
//    int age;
//    char id[20];
//};
//
//int main()
//{
//    struct Stu s = { {'w', 20, 3.14}, "Zhang San", 30, "20220118" };
//    //.
//    printf("%c\n", s.sb.c);
//    printf("%s\n", s.id);
//
//    //->
//    struct Stu* ps = &s;
//    printf("%c\n", ps->sb.c);
//    printf("%s\n", ps->id);
//    return 0;
//}
struct B
{
    char c;
    short s;
    double d;
};

struct Stu
{
    struct B sb;
    char name[20];
    int age;
    char id[20];
};

void print1(struct Stu t)
{
    printf("%c %d %lf %s %d %s\n", t.sb.c, t.sb.s, t.sb.d, t.name, t.age, t.id);
}

void print2(struct Stu* ps)
{
    printf("%c %d %lf %s %d %s\n", ps->sb.c, ps->sb.s, ps->sb.d, ps->name, ps->age, ps->id);
}

int main()
{
    //写一个函数打印s的内容
    struct Stu s = { {'w', 20, 3.14}, "Zhang San", 30, "20220118" };
    print1(s);
    print2(&s);
    return 0;
}