#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��Ϸ�����߼�

void menu()
{
	printf("*********************************\n");
	printf("***********   1.play   **********\n");
	printf("***********   0.exit   **********\n");
	printf("*********************************\n");
}

void game()
{
	//�����׳�
	char mine[ROWS][COLS] = { 0 };//�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//���׵���Ϣ

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	DisplayBoard(show, ROW, COL);
	
	//���õ���
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	

	//�Ų����
	FindMine(mine, show, ROW, COL);
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
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}