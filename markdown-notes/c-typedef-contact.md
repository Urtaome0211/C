---
title: '自定义类型实战 - 通讯录'
date: 2022-02-10 19:16:58
tags: [C]
published: true
hideInList: false
feature: /post-images/c-typedef-contact.png
isTop: false
---
要求：
1. 通讯录中能够存放1000人的信息，每个人的信息（名字、年龄、性别、电话和地址）。
2. 通讯录的增删改查。

与之前的实战项目一样，将文件分为三个，分别是：
1. ```test.c```用于测试通讯录的模块。
2. ```contact.h```用于类型的定义，函数的声明。
3. ```contact.c```用于函数的实现。

# 1. test.c
```
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//程序整体的逻辑

void menu()
{
	printf("*****************************\n");
	printf("******1. add     2. del******\n");
	printf("******3. search  4. modify***\n");
	printf("******5. print   0. exit*****\n");
	printf("*****************************\n");
}

//枚举菜单选项
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	PRINT

};

int main()
{
	int input = 0;

	//创建通讯录
	Contact con;

	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			ContactAdd(&con);
			break;
		case DEL:
			ContactDel(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case EXIT:
			//保存信息到文件
			SaveContact(&con);
			//销毁通讯录
			DestoryContact(&con);
			printf("退出通讯录");
			break;
		default:
			printf("错误！请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}
```
# 2. contact.h
```
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

void SaveContact(Contact* pc);//保存通讯录信息

void DestoryContact(Contact* pc);//销毁通讯录

void LoadContact(Contact* pc);//加载通讯录文件

void CheckCapacity(Contact* pc);//增加容量
```
# 3. contact.c
```
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//函数的实现

//加载通讯录文件
void LoadContact(Contact* pc)
{
	FILE* pf = fopen("Contact.dat", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}

	//读文件
	PeopleInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeopleInfo), 1, pf))
	{
		//检测容量
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

//初始化通讯录 - 动态
void InitContact(Contact* pc)
{
	pc->data = (PeopleInfo*)malloc(DEFAULT_SZ * sizeof(PeopleInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;//初始化后默认为0
	pc->capacity = DEFAULT_SZ;

	//加载文件
	LoadContact(pc);
}

//增容函数
void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeopleInfo* ptr = (PeopleInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeopleInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
		else
		{
			perror("ContactAdd");
			printf("增加联系人失败\n");
			return;
		}
		return;
	}
}

//增加信息 - 动态
void ContactAdd(Contact* pc)
{
	//考虑增容
	CheckCapacity(pc);

	//增加一个人的信息
	printf("请输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->sz]).age);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].gender);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("添加成功\n");
}

//打印通讯录
void PrintContact(const Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");

	//打印数据
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].gender, pc->data[i].tele, pc->data[i].addr);
	}
}

//查找人的信息
static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//找不到
}

//删除信息
void ContactDel(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除！\n");
		return;
	}

	printf("请输入要删除的人的名字：");
	scanf("%s", name);

	//1. 查找需要删除的信息
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}

	//2. 删除
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
	
}

//查找指定的信息
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的人的名字：");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");

		//打印数据
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].gender, pc->data[pos].tele, pc->data[pos].addr);
	}
}

//修改指定的信息
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的人的名字：");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄：");
		scanf("%d", &(pc->data[pos]).age);
		printf("请输入性别：");
		scanf("%s", pc->data[pos].gender);
		printf("请输入电话：");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址：");
		scanf("%s", pc->data[pos].addr);

		printf("修改成功！\n");
	}

}

//保存通讯录信息
void SaveContact(Contact* pc)
{
	//打开文件
	FILE* pf = fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}

	//写文件
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeopleInfo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

//销毁通讯录
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}
```

# 4. 项目地址
👉Github[点击这里](https://github.com/Urtaome0211/C/tree/master/contact)