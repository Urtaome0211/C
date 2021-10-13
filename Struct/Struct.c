#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//结构体可以让c语言创建新的类型
//创建一个学生

struct Stu
{
	char name[20];
	int age;
	double score;
};

//创建一本书
int main()
{
	struct Stu s = {"Zhang San", 20, 85.5};
	//结构体的创建和初始化
	printf("1: %s %d %lf\n", s.name, s.age, s.score);
	struct Stu * ps = &s;
	printf("2: %s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
	printf("3: %s %d %lf\n", ps->name, ps->age, ps->score);
	return 0;
}