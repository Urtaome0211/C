#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//����������߼�

void menu()
{
	printf("*****************************\n");
	printf("******1. add     2. del******\n");
	printf("******3. search  4. modify***\n");
	printf("******5. print   0. exit*****\n");
	printf("*****************************\n");
}

//ö�ٲ˵�ѡ��
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

	//����ͨѶ¼
	Contact con;

	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��");
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
			printf("�˳�ͨѶ¼��");
			break;
		default:
			printf("����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}