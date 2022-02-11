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