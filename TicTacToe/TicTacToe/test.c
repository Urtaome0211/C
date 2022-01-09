//������Ϸ�߼�
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("***********************************\n");
	printf("**********     1.play    **********\n");
	printf("**********     0.exit    **********\n");
	printf("***********************************\n");
}

void game()
{
	//�洢���� - ��ά����
	char board[ROW][COL];
	//��ʼ������ - ��ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//������Ϸ״̬
	char ret = 0;
	//�˻���ս��������֣� - �ж���Ӯ
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ��ʤ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ��ʤ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��һ�ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	//ʱ��� - �������ֵ
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
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}