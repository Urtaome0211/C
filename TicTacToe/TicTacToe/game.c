//��Ϸ��غ�����ʵ��
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//ʵ�ֳ�ʼ�����̵Ĺ���
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
			//��ʼ��Ϊ�ո�
		}
	}
}

//ʵ�ִ�ӡ���̵Ĺ���
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//��ӡ��i�У���j�е�Ԫ��
			if (j < col - 1)
			//���һ�в���ӡ
			{
				printf("|");
			}
		}
		printf("\n");//ÿ��ӡһ�ξͻ���

		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				//���һ�в���ӡ
				{
					printf("|");
				}
			}
			printf("\n");//ÿ��ӡһ�ξͻ���
		}
	}
}

//ʵ���������Ĺ���
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("���������ӵ����꣺");
		scanf("%d %d", &x, &y);
		//�ж�����ĺϷ���
		//���귶ΧΪ��ά����ķ�Χ
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж������Ƿ�ռ��
			//������еģ�1��1����������ģ�0��0���������ж����Ӧ������д��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
				//�ɹ�����֮������ѭ��
			}
			else
			{
				printf("���걻ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����Ƿ������������룺\n");
		}
	}
}

//ʵ�ֵ�������Ĺ���
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������:\n");
	while (1)
	{
		//ȡģ���������ɷ�ΧΪ0-2
		int x = rand() % row;
		int y = rand() % col;
		//����rand()����֮ǰ�ȵ���srand()����������������

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
			//���ӳɹ�֮������ѭ��
		}
	}
}

//�ж������Ƿ�����
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
				//����û��
			}
		}
	}
	return 1;
	//��������
}

//�ж�ʤ���ĺ���
/*
* �ж�ʤ���ı�׼Ϊ��
* 1.���Ӯ - ���� *
* 2.����Ӯ - ���� #
* 3.ƽ��   - ���� Q
* 4.��Ϸ���� - ���� C
*/
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж�����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}

	//�ж�����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//�ж�ƽ��
	//���������˷���1����û������0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//����
	return 'C';
}