#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("***********************\n");
	printf("*****   0.exit    *****\n");
	printf("*****   1.play    *****\n");
	printf("***********************\n");
}

void game()
{
	char mine[RAWS][COLS];  //记录地雷的分布
	char show[RAWS][COLS];  //展示排查地雷的信息
	InitBoard(mine, RAWS, COLS, '0');
	InitBoard(show, RAWS, COLS, '*');
	SetMine(mine, RAW, COL);
	DisplayBoard(mine, RAW, COL);
	DisplayBoard(show, RAW, COL);
	SweepMine(mine, show, RAW, COL);
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("please choose :>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("successfully exited the game!\n");
			break;
		default:
			printf("input errors, please re-enter!\n");
			break;
		}
	} while (input);

	return 0;
}