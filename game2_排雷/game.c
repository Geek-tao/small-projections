#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[Rows][Cols], int row, int col, char c)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			board[i][j] = c;
		}
	}
}

int ShowMine(char mine[Rows][Cols], int x, int y)
{
	return
		mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void DisplayBoard(char show[Rows][Cols], int row, int col)
{
	printf("---- ɨ����Ϸ�� ----\n");
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
	printf("---- ɨ����Ϸ�� ----\n");
}

void SetMine(char mine[Rows][Cols], int row, int col)
{
	int count = set_count_mine;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[Rows][Cols], char show[Rows][Cols] ,int row, int col)
{
	int win = row * col - set_count_mine;
	while (win)
	{
		printf("���������꣺>\n");
		int x = 0, y = 0;
		scanf("%d%d", &x, &y);
		if (mine[x][y] == '1')
		{
			printf("�����������ը���ˣ�\n");
			DisplayBoard(mine, Row, Col);
			return;
		}
		else
		{
			int n = ShowMine(mine, x, y);
			show[x][y] = n + '0';
			DisplayBoard(show, Row, Col);
			win--;
		}
	}
	printf("��ϲͨ�أ����ֱ������ţ�\n");
	DisplayBoard(mine, Row, Col);
}
