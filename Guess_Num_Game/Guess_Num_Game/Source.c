#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void menu()
{
	printf("*********************************\n");
	printf("***********  1. play  ***********\n");
	printf("***********  0. exit  ***********\n");
	printf("*********************************\n");
}

void game()
{
	int guess = 0;

	int ret = rand() % 100 + 1;
	while (1)
	{
		printf("���������֣�");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´��ˡ�\n");
		}
		else if (guess < ret)
		{
			printf("��С�ˡ�\n");
		}
		else
		{
			printf("�¶��ˡ�\n");
			break;
		}
	}

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;

	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default :
				printf("ѡ���������ѡ��\n");
				break;
		}
		
	} while (input);
	return 0;
}