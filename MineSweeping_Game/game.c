#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[][COLS], int raws, int cols, char set)
{
	for (int i = 0; i < raws; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[][COLS], int raw, int col)
{
	printf("-----É¨À×ÓÎÏ·-----\n");
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= raw; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}


void SetMine(char mine[][COLS], int raw, int col)
{
	int count = easy_count;
	while (count)
	{
		int x = rand() % raw + 1; // 1-9
		int y = rand() % col + 1; // 1-9
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}

}

int count_mine(char mine[][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] 
		+ mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
}

void SweepMine(char mine[][COLS], char show[][COLS], int raw, int col)
{
	int x, y;
	int count = raw * col - easy_count;
	while (count)
	{
		printf("please enter security coordinates:");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= raw && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("Sorry you were killed!\n");
				DisplayBoard(mine, RAW, COL);
				return;
			}
			else
			{
				int num = count_mine(mine, x, y);
				show[x][y] = num + '0';
				DisplayBoard(show, RAW, COL);
				count--;
			}
		}
		else
		{
			printf("coordinates errors, please re-enter!\n");
		}
	}
	printf("congratulations on passing the game!!\n");
	DisplayBoard(mine, RAW, COL);
}