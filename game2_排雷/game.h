#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Row 9
#define Col 9
#define Rows Row + 2
#define Cols Col + 2
#define set_count_mine 10
//��ʼ������
void InitBoard(char board[Rows][Cols], int row, int col, char c);
//��ӡ����
void DisplayBoard(char show[Rows][Cols], int row, int col);
//������
void SetMine(char mine[Rows][Cols], int row, int col);
//�Ų���
void FindMine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col);
