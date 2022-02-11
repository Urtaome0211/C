#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>


//符号、类型和函数的声明

//符号的定义
#define MAX_NAME 20
#define MAX_GENDER 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_PEOPLE 1000
#define DEFAULT_SZ 3
#define INC_SZ 2

//人的信息的定义

//静态版本
typedef struct PeopleInfo
{
	char name[MAX_NAME];
	char gender[MAX_GENDER];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeopleInfo;

//动态版本
typedef struct Contact
{
	PeopleInfo* data;//指向动态申请的空间，用来存放信息
	int sz;//记录当前通讯录中有效信息的个数
	int capacity;//记录当前通讯录最大容量
} Contact;

//通讯录结构体
/*typedef struct Contact
{
	PeopleInfo data[MAX_PEOPLE];//存放添加进来的人的信息
	int sz;//记录当前通讯录中有效信息的个数
} Contact;*/

//函数的声明
void InitContact(Contact* pc);//初始化通讯录

void ContactAdd(Contact* pc);//增加信息

void PrintContact(const Contact* pc);//打印通讯录

void ContactDel(Contact* pc);//删除信息

void SearchContact(Contact* pc);//查找指定信息

void ModifyContact(Contact* pc);//修改指定的信息

void DestoryContact(Contact* pc);//销毁通讯录