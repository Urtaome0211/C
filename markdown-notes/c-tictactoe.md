---
title: '数组应用实战-三子棋'
date: 2022-01-09 12:23:21
tags: [C,game]
published: true
hideInList: false
feature: /post-images/c-tictactoe.png
isTop: false
---
# 1. 三子棋
这里将三子棋分为三个模块：

## 1.1 game.h
```
//关于游戏相关的函数声明，符号声明以及头文件的包含
#pragma once
#include<stdio.h>
#inlcude<stdlib.h>
#include<time.h>

//定义符号
//三行三列的棋盘
#define ROW 3
#define COL 3

//函数的声明
//1.初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//2.打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//3.玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//4.电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//5.判断胜负
char IsWin(char board[ROW][COL], int row, int col);

//6.判断棋盘是否填满
int IsFull(char board[ROW][COL], int row, int col);
```

## 1.2 test.c
```
//测试游戏的逻辑
#include "game.h"

void menu()
//menu()函数，打印菜单
{
    printf("***********************************\n");
    printf("**********     1.play    **********\n");
    printf("**********     0.exit    **********\n");
    printf("***********************************\n");
}

void game()
{
    //存储数据 - 二维数组
    char board[ROW][COL];

    //调用InitBoard()函数来初始化数组
    InitBoard(board, ROW, COL);

    //调用DisplayBoard()函数来打印棋盘
    DisplayBoard(board, ROW, COL);

    //接收游戏状态
    char ret = 0;

    //人机对战 - 判断输赢
    while (1)
    {
        //玩家下棋
        PlayerMove(board, ROW, COL);
        DisplayerBoard(board, ROW, COL);
        //判断玩家是否获胜
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
        {
            break;
        }

        //电脑下棋
        ComputerMove(board, ROW, COL);
        DisplayerBoard(board, ROW, COL);
        //判断电脑是否获胜
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
        {
            break;
        }
    }
    if(ret == '*')
    {
        printf("玩家获胜");
    }
    else if(ret == '#')
    {
        printf("电脑获胜");
    }
    else
    {
        printf("平局");
    }
    DisplayerBoard(board, ROW, COL);
}

int main()
{
    //时间戳 - 生成随机值
    srand((unsigned int)time(NULL));

    int input = 0;
    do
    {
        menu();
        printf("请选择: ");
        scanf("%d", &input);

        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择：\n");
                break;
        }
    } while (input);
    return 0;
}
```
## 1.3 game.c
### 1.3.1 初始化棋盘
在游戏开始之前首先将数组进行初始化，做法是用for循环遍历整个数组，将其中的元素都初始化为空格。
```
//游戏相关函数的实现
#include "game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0;i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            board[i][j] = ' ';
            //将所有元素初始化为空格
        }
    }
}
```
### 1.3.2 打印棋盘
棋盘的四周是没有“|”和“---”的，可以通过if语句来实现:
```
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i <= row; i++)
    {
        int j = 0;
        for (j = 0; j <= col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            //将“ %c |”看成一组
            {
                printf("|");
                //最后不打印“|”
            }
        }
        printf("\n");
        //每打印一行就换行

        if (i < row - 1)
        {
            int j = 0;
            for (j = 0; j < col; j++)
            {
                printf("---");
                if(j < col - 1)
                {
                    printf("|");
                }
            }
            printf("\n");
            //原理同上
        }
    }
}
```
### 1.3.3 玩家下棋
在普通玩家眼中，坐标（1，1）就相当于二维数组中的（0，0），所以落子的坐标需进行处理：
```
board[x - 1][y - 1]
```
若当前坐标元素为空格，则落子，实现代码如下：
```
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;

    while (1)
    {
        printf("请输入棋子的坐标：");
        scanf("%d %d", &x, &y);

        //判断坐标的合法性
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            //判断坐标是否被占用
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
```
### 1.3.4 电脑下棋
通过调用srand()和rand()函数来使电脑达到随机落子的效果，由于之前已经定义过ROW和COL，对其取模就可以达到将其生成范围限制在0-2之间的效果。
```
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
    printf("电脑落子:\n");
    while (1)
    {
        //取模，坐标生成范围为0-2
        //调用rand()函数之前先调用srand()函数，在主函数中
        int x = rand() % row;
        int y = rand() % col;

        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
            //落子成功之后跳出循环
        }
    }
}
```
### 1.3.5 判断棋盘是否填满
采用for循环遍历整个数组，若发现空格就是没填满，返回0；否则就是填满，返回1。
```
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
                //棋盘没填满
            }
        }
    }
    return 1;
    //棋盘满了
}
```
### 1.3.6 判断胜负
通过判断每行、每列、每个对角线元素是否相等来实现。
此部分代码已将条件限制死，若想实现五（n）子棋，则需要优化代码。循环？
```
//判断胜负
//判断胜负的标准为：
//1.玩家赢 - 返回 *
//2.电脑赢 - 返回 #
//3.平局   - 返回 Q
//4.游戏继续 - 返回 C

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
```
### 1.3.7判断是否平局
调用IsFull()函数来实现
```
   //判断平局
   //若棋盘满了返回1，若没满返回0
   int ret = IsFull(board, row, col);
   if (ret == 1)
   {
       return 'Q';
   }
```

### 1.3.8 游戏继续
```
return 'C';
```
# 2. Github地址
👉[点击这里](https://github.com/Urtaome0211/C_games/tree/main/TicTacToe)
