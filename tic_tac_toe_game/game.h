#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define RAW 3
#define COL 3

//��ʼ������
void InitBoard(char board[][COL], int raw, int col);
//��ӡ����
void DisplayBoard(char board[][COL], int raw, int col);
//�������
void PlayerMove(char board[][COL], int raw, int col);
//��������
void ComputerMove(char board[][COL], int raw, int col);
//�ж���Ӯ
char IsWin(char board[][COL], int raw, int col);