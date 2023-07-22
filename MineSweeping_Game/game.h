#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RAW 9
#define COL 9
#define RAWS RAW + 2
#define COLS COL + 2
#define easy_count 80

//初始化棋盘
void InitBoard(char board[][COLS], int raws, int cols, char set);
//打印雷区
void DisplayBoard(char board[][COLS], int raw, int col);
//布置雷区
void SetMine(char mine[][COLS], int raw, int col);
//扫雷
void SweepMine(char mine[][COLS], char show[][COLS], int raw, int col);