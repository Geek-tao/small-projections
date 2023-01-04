#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

int IsFall(char board[][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;           //没有满
		}
	}
	return 1;                  //找不到空格，已满
}

void game()
{
	char board[Row][Col];
	InitBoard(board, Row, Col);    //初始化二维数组
	DisplayBoard(board, Row, Col); //打印棋盘
	char ret;                      //记录输赢情况
	while (1)
	{
		PlayerMove(board,Row,Col);        //玩家下棋
		DisplayBoard(board, Row, Col);  //打印棋盘
		ret = IsWin(board, Row, Col);//判断输赢
		if (ret != 'g')
			break;
		ComputerMove(board, Row, Col);
		DisplayBoard(board, Row, Col);
		ret = IsWin(board, Row, Col);
		if (ret != 'g')
			break;
	}
	if (ret == '*')
		printf("玩家赢！\n");
	else if (ret == '#')
		printf("电脑赢！\n");
	else
		printf("平局了！\n");
}

void DisplayBoard(char board[Row][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void InitBoard(char board[Row][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void PlayerMove(char board[][Col], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("玩家走\n");
		printf("请输入棋盘坐标：>\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标已被占有，请重新输入：>\n");
		}
		else
			printf("坐标非法！\n");
	}
}

void ComputerMove(char board[][Col], int row, int col)
{
	printf("电脑走\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//玩家赢 *
//电脑赢 #
//平局 d
//继续 g
char IsWin(char board[][Col], int row, int col)
{
	
	for (int i = 0; i < row; i++)
	{
		int n = 1;//记录一行相同个数
		if (board[i][0] != ' ')
		{
			char temp = board[i][0];
			for (int j = 1; j < col; j++)
			{
				if (board[i][j] == temp)
				{
					n++;
					if (n == col)
						return temp;
				}
			}
		}
	}

	for (int i = 0; i < col; i++)
	{
		int n = 1;//记录一列相同个数
		if (board[0][i] != ' ')
		{
			char temp = board[0][i];
			for (int j = 1; j < row; j++)
			{
				if (board[j][i] == temp)
				{
					n++;
					if (n == row)
						return temp;
				}
			}
		}
	}

	for (int i = 1; i < col; i++)
	{
		int n = 1;//记录正对角线相同个数
		if (board[0][0] != ' ')
		{
			char temp = board[0][0];
				if (board[i][i] == temp)
				{
					n++;
					if (n == row)
						return temp;
				}
		}
	}

	for (int i = 1; i < col; i++)
	{
		int n = 1;//记录反对角线相同个数
		if (board[0][col-1] != ' ')
		{
			char temp = board[0][col-1];
			if (board[i][col-1-i] == temp)
			{
				n++;
				if (n == row)
					return temp;
			}
		}
	}

	int a = IsFall(board, Row, Col);
	if (a)
		return 'd';
	else
		return 'g';
}