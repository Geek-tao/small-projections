#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RAW 9
#define COL 9
#define RAWS RAW + 2
#define COLS COL + 2
#define easy_count 80

//��ʼ������
void InitBoard(char board[][COLS], int raws, int cols, char set);
//��ӡ����
void DisplayBoard(char board[][COLS], int raw, int col);
//��������
void SetMine(char mine[][COLS], int raw, int col);
//ɨ��
void SweepMine(char mine[][COLS], char show[][COLS], int raw, int col);