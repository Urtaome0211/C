#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//���ŵĶ���
#define ROW 3
#define COL 3

//����������
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж�ʤ��
char IsWin(char board[ROW][COL], int row, int col);

//�ж������Ƿ�����
int IsFull(char board[ROW][COL], int row, int col);