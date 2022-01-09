//游戏相关函数的实现
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//实现初始化棋盘的功能
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
			//初始化为空格
		}
	}
}

//实现打印棋盘的功能
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//打印第i行，第j列的元素
			if (j < col - 1)
			//最后一列不打印
			{
				printf("|");
			}
		}
		printf("\n");//每打印一次就换行

		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				//最后一列不打印
				{
					printf("|");
				}
			}
			printf("\n");//每打印一次就换行
		}
	}
}

//实现玩家下棋的功能
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("请输入棋子的坐标：");
		scanf("%d %d", &x, &y);
		//判断坐标的合法性
		//坐标范围为二维数组的范围
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标是否被占用
			//玩家眼中的（1，1）就是数组的（0，0），所以判断语句应该这样写：
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
				//成功落子之后跳出循环
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法！请重新输入：\n");
		}
	}
}

//实现电脑下棋的功能
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑落子:\n");
	while (1)
	{
		//取模，坐标生成范围为0-2
		int x = rand() % row;
		int y = rand() % col;
		//调用rand()函数之前先调用srand()函数，在主函数中

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
			//落子成功之后跳出循环
		}
	}
}

//判断棋盘是否填满
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
				//棋盘没满
			}
		}
	}
	return 1;
	//棋盘满了
}

//判断胜负的函数
/*
* 判断胜负的标准为：
* 1.玩家赢 - 返回 *
* 2.电脑赢 - 返回 #
* 3.平局   - 返回 Q
* 4.游戏继续 - 返回 C
*/
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}

	//判断三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断平局
	//若棋盘满了返回1，若没满返回0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//继续
	return 'C';
}