#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//游戏整体逻辑

void menu()
{
	printf("*********************************\n");
	printf("***********   1.play   **********\n");
	printf("***********   0.exit   **********\n");
	printf("*********************************\n");
}

void game()
{
	//生成雷场
	char mine[ROWS][COLS] = { 0 };//布置雷的信息
	char show[ROWS][COLS] = { 0 };//排雷的信息

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	DisplayBoard(show, ROW, COL);
	
	//布置地雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	

	//排查地雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}