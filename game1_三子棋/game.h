#define _CRT_SECURE_NO_WARNINGS 1
#define Row 5
#define Col 5
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game();
void DisplayBoard(char board[Row][Col], int row, int col);
void InitBoard(char board[Row][Col], int row, int col);
void PlayerMove(char board[][Col], int row, int col);
void ComputerMove(char board[][Col], int row, int col);
char IsWin(char board[][Col], int row, int col);