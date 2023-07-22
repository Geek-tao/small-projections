#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define RAW 3
#define COL 3

//初始化棋盘
void InitBoard(char board[][COL], int raw, int col);
//打印棋盘
void DisplayBoard(char board[][COL], int raw, int col);
//玩家下棋
void PlayerMove(char board[][COL], int raw, int col);
//电脑下棋
void ComputerMove(char board[][COL], int raw, int col);
//判断输赢
char IsWin(char board[][COL], int raw, int col);