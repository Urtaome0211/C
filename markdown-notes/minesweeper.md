---
title: '数组应用实战-扫雷'
date: 2022-01-10 14:00:43
tags: [C,game]
published: true
hideInList: false
feature: /post-images/minesweeper.png
isTop: false
---
# 1. 扫雷
## 1.1 game.h
此部分符号和函数的声明
```
//包含头文件
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//符号声明
#define ROW 9
#define COL 9//雷场大小为9*9
#define ROWS ROW+2
#define COLS COL+2//防止越界，雷场大小为11*11
#define EASY_COUNT//地雷数

//函数声明
//初始化雷场
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印雷场
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置地雷
void SetMine(char mine[ROWS][COLS], int row ,int col);

//排查地雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
```
## 1.2 test.c
此部分为游戏的主体逻辑，与猜数字和三子棋一样，在主函数内用do-while来实现游戏的运行。
```
#include "game.h"

int main()
{
    srand((unsigned int)time(NULL));
    //时间戳，生成随机值
    int input = 0;

    do
    {
        menu();//打印菜单
        printf("请选择：");
        scanf("%d", &input);

        switch (input)
        {
            case 1:
                printf("开始游戏\n");
                game();//调用game()函数，实现游戏的整体逻辑
                break;
            case 0:
                printf("游戏结束\n");
                break;
            default:
                printf("错误！请重新选择！\n");
                break;
        }
    } while (input);
    return 0;
}
```
menu()函数的实现非常简单，只需将字符打印出来就可以
```
void menu()
{
    printf("*********************************\n");
    printf("***********   1.play   **********\n");
    printf("***********   0.exit   **********\n");
    printf("*********************************\n");
}
```
而game()函数包含了游戏的整体逻辑，通过自定义InitBoard()，DisplayBoard()，SetMine()，FindMine()函数来实现。在这部分生成两个二维数组，一个用来记录布置地雷的信息，另一个用来记录排查地雷的信息。然后将mine数组初始化为字符“0”（无雷），若有雷则为字符“1”；show数组初始化为字符“*”
```
void game()
{
    char mine[ROWS][COLS] = { 0 };//布置雷的信息
    char show[ROWS][COLS] = { 0 };//排查雷的信息

    //初始化棋盘
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');

    //打印雷场
    //以下函数的作用范围都为9*9，但是传参范围为11*11
    DisplayBoard(show, ROW, COL);

    //布置地雷
    SetMine(mine, ROW, COL);
    //DisplayBoard(show, ROW, COL);

    //排查地雷
    FindMine(mine, show, ROW, COL);
}
```
## 1.3 game.c
此部分为自定义函数的实现，需要引头文件game.h
### 1.3.1 初始化雷场
遍历二维数组即可实现，通过char set参数来实现两个数组分别初始化为对应的字符
```
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;

    for (i = 0; i <= rows; i++)
    {
        for (j = 0; j <= cols; j++)
        {
            board[i][j] = set;
            //分别初始化对应的数组
        }
    }
}
```
### 1.3.2 打印雷场
只需打印9*9的棋盘即可，并标明行号和列号方便玩家输入坐标
```
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
    printf("\n");//换行

    //打印雷场主体
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i);//打印行号
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
            //打印初始化后的棋盘
        }
        printf("\n");
    }
    printf("-----------扫雷游戏-----------\n");
}
```
### 1.3.3 布置地雷
设置一个循环，若坐标为字符‘0’就放置地雷，否则重新放置，每放置一个地雷就后置--。
而地雷放置使随机的，放置范围为9*9，通过rand()函数来实现，并模上row(col) + 1来将放置坐标范围限制在1-9
```
void SetMine(char mine[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;//地雷数
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;

        if (mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count--;
            //每放置一次就减一，直至不满足条件跳出循环
        }
    }
}
```
### 1.3.4 排查地雷
通过分支语句判断输入坐标的合法性，若输入坐标为地雷（1）则游戏结束，若不是地雷，则通过getMineCount()函数来统计周围的地雷数量。若将所有不是地雷的坐标找到，则玩家获胜。实现代码为：
```
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;//非地雷的坐标数量

    while (win < row * col - EASY_COUNT)
    {
        printf("请输入要查找的坐标：");
        scanf("%d %d", &x, &y);
        
        //判断坐标的合法性
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '1')
            {
                //踩雷了，游戏结束
                printf("你被炸死了\n");
                printf("要再来一局吗？\n");
                //告知玩家为何踩雷，并跳出循环
                DisplayBoard(mine, row, col);
                break;
            }
            else
            {
                //如果没踩雷，统计周围地雷数量
                int count = getMineCount(mine, x, y);
                show[x][y] = count + '0';//转换成对应字符
                DisplayBoard(show, row, col);
                win++;
                //每排查一个非雷坐标就自增
                //直到排查完所有非雷坐标，玩家获胜
            }
        }
        else
        {
            printf("坐标不合法，请重新输入：\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        printf("你赢了\n");
        DisplayBoard(mine, row, col);
    }
}
```
上述代码中，为何统计地雷数量需要这样写？
原因是数组初始化为字符格式，加上字符'0'就可以知道地雷的数量（ASCII值），示例：
```
ACSII
'0' - 48
'1' - 49
'2' - 50
'3' - 51
...
而
1 = '0' + 1, 1的ASCII码值为49，通过这样的方式来打印对应的字符
```

而统计周围地雷数量可以将周围八个坐标加起来，再减去8 * '0'，就可以得到地雷数量，原理与上述代码相同。因为getMineCount函数是在内部实现，所以无需在game.h中声明。
```
static int getMineCount(char mine[ROWS][COLS], int x, int y)
{
    return mine[x-1][y-1] + mine[x-1][y] + mine[x-1][y+1] + mine[x][y-1] + mine[x][y+1] + mine[x+1][y-1] + mine[x+1][y] + mine[x+1][y+1] - 8 * '0';
}
```
# 2. Github地址
👉[点击这里](https://github.com/Urtaome0211/C_games/tree/main/Minesweeper)