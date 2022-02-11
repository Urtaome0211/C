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
			//����ͨѶ¼
			DestoryContact(&con);
			printf("�˳�ͨѶ¼");
			break;
		default:
			printf("����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}