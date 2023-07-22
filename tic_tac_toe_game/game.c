#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[RAW][COL], int raw, int col)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[][COL], int raw, int col)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < raw - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[][COL], int raw, int col)
{
	int x, y;
	while (1)
	{
		printf("please enter coordinates:>");
		scanf("%d%d", &x, &y);
		if (x <= raw && y <= col && board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			break;
		}
		else
		{
			printf("Invaild coordinates,please re-enter!\n");
		}
	}
}

char RawFull(char board[][COL], int raw, int col)
{
	for (int i = 0; i < raw; i++)
	{
		int raw_flag = 1;//默认这一排相同
		char x = board[i][0];
		if (x == ' ')
		{
			raw_flag = 0;
			continue;
		}

		for (int j = 1; j < col; j++)
		{
			if (board[i][j] != x)
			{
				raw_flag = 0;
				break;
			}
		}

		if (raw_flag == 1)
		{
			return x;
		}
	}
	return 0;
}

char ColFull(char board[][COL], int raw, int col)
{
	for (int i = 0; i < col; i++)
	{
		int raw_flag = 1;//默认这一列相同
		char x = board[0][i];
		if (x == ' ')
		{
			raw_flag = 0;
			continue;
		}

		for (int j = 1; j < raw; j++)
		{
			if (board[j][i] != x)
			{
				raw_flag = 0;
				break;
			}
		}

		if (raw_flag == 1)
		{
			return x;
		}
	}
	return 0;
}

char DiagonalFull(char board[][COL], int raw, int col)
{
	char x = board[0][0];
	char y = board[0][col - 1];
	if (x == ' ' && y == ' ')//初步筛选
	{
		return 0;
	}
	int diagonal_flag1 = 1;//默认正对角线相同
	int diagonal_flag2 = 1;//默认反对角线相同
	for (int i = 1; i < raw; i++)
	{
		if (board[i][i] == ' ' || board[i][i] != x)
		{
			diagonal_flag1 = 0;
		}
		if (board[i][col - 1 - i] == ' ' || board[i][col - 1 - i] != y)
		{
			diagonal_flag2 = 0;
		}
		if (diagonal_flag1 == 0 && diagonal_flag2 == 0)
		{
			break;
		}
	}
	if (diagonal_flag1 == 1)
	{
		return x;
	}
	if (diagonal_flag2 == 1)
	{
		return y;
	}
	return 0;
}

int AllFull(char board[][COL], int raw, int col)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

void ComputerMove(char board[][COL], int raw, int col)
{
	while (1)
	{
		int x = rand() % raw;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char IsWin(char board[][COL], int raw, int col)
{
	char x = RawFull(board, RAW, COL);
	char y = ColFull(board, RAW, COL);
	char z = DiagonalFull(board, RAW, COL);
	if (x || y || z) //win
	{
		if (x)
			return x;
		if (y)
			return y;
		return z;
	}
	if (AllFull(board, RAW, COL)) //draw
	{
		return 'D';
	}
	return 'C';//continue
}

//
// * |   |   
//---|---|---
//   | * | *
//---|---|---
//   |   |   
