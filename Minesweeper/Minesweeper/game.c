#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//函数的定义

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		} 
	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----------扫雷游戏-----------\n");
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----------扫雷游戏-----------\n");
}

//布置地雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//统计坐标周围地雷数量
//内部调用，无需在头文件中声明
static int getMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x-1][y-1] +
		   mine[x-1][y] +
		   mine[x-1][y+1] +
		   mine[x][y-1] +
		   mine[x][y+1] +
		   mine[x+1][y-1] +
		   mine[x+1][y] +
		   mine[x+1][y+1] - 8 * '0';
}

//排查地雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要查找的坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("\n");
				printf("你被炸死了\n");
				printf("\n");
				printf("要再来一局吗？\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = getMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入：\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("\n");
		printf("你赢了\n");
		printf("\n");
		DisplayBoard(mine, row, col);
	}
}