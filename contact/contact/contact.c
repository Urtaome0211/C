#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//函数的实现

//初始化通讯录 - 静态
//void InitContact(Contact* pc)
//{
//	pc -> sz = 0;
//
//	//用memset()函数将通讯录置空
//	memset(pc->data, 0, sizeof(pc->data));
//}

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
}

//增加信息 - 静态
//void ContactAdd(Contact* pc)
//{
//	if (pc->sz == MAX_PEOPLE)
//	{
//		printf("通讯录已满，无法添加！\n");
//		return;
//	}
//
//	//增加一个人的信息
//	printf("请输入名字：");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入年龄：");
//	scanf("%d", &(pc->data[pc->sz]).age);
//	printf("请输入性别：");
//	scanf("%s", pc->data[pc->sz].gender);
//	printf("请输入电话：");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入地址：");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("添加成功\n");
//}

//增加信息 - 动态
void ContactAdd(Contact* pc)
{
	//考虑增容
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

//销毁通讯录
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}