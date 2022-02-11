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
	exit,
	add,
	del,
	search,
	modify,
	print

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
		case add:
			ContactAdd(&con);
			break;
		case del:
			ContactDel(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case print:
			PrintContact(&con);
			break;
		case exit:
			printf("退出通讯录：");
			break;
		default:
			printf("错误！请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}