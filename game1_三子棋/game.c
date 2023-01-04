#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

int IsFall(char board[][Col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;           //û����
		}
	}
	return 1;                  //�Ҳ����ո�����
}

void game()
{
	char board[Row][Col];
	InitBoard(board, Row, Col);    //��ʼ����ά����
	DisplayBoard(board, Row, Col); //��ӡ����
	char ret;                      //��¼��Ӯ���
	while (1)
	{
		PlayerMove(board,Row,Col);        //�������
		DisplayBoard(board, Row, Col);  //��ӡ����
		ret = IsWin(board, Row, Col);//�ж���Ӯ
		if (ret != 'g')
			break;
		ComputerMove(board, Row, Col);
		DisplayBoard(board, Row, Col);
		ret = IsWin(board, Row, Col);
		if (ret != 'g')
			break;
	}
	if (ret == '*')
		printf("���Ӯ��\n");
	else if (ret == '#')
		printf("����Ӯ��\n");
	else
		printf("ƽ���ˣ�\n");
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
		printf("�����\n");
		printf("�������������꣺>\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�������ѱ�ռ�У����������룺>\n");
		}
		else
			printf("����Ƿ���\n");
	}
}

void ComputerMove(char board[][Col], int row, int col)
{
	printf("������\n");
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

//���Ӯ *
//����Ӯ #
//ƽ�� d
//���� g
char IsWin(char board[][Col], int row, int col)
{
	
	for (int i = 0; i < row; i++)
	{
		int n = 1;//��¼һ����ͬ����
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
		int n = 1;//��¼һ����ͬ����
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
		int n = 1;//��¼���Խ�����ͬ����
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
		int n = 1;//��¼���Խ�����ͬ����
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