#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//符号和函数的声明

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

//初始化雷场
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印雷场
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置地雷
void SetMine(char mine[ROWS][COLS], int row ,int col);

//排查地雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);