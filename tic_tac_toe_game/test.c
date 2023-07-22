#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("***********************\n");
	printf("******  0. exit  ******\n");
	printf("******  1. play  ******\n");
	printf("***********************\n");
}


void game()
{
	char out = 0;
	char board[RAW][COL] = { 0 };
	InitBoard(board, RAW, COL);
	while (1)
	{
		DisplayBoard(board, RAW, COL);
		PlayerMove(board, RAW, COL);
		out = IsWin(board, RAW, COL);
		if (out != 'C')
			break;
		ComputerMove(board, RAW, COL);
		out = IsWin(board, RAW, COL);
		if (out != 'C')
			break;
	}
	DisplayBoard(board, RAW, COL);
	if (out == '*')
	{
		printf("Congratulations on defeating your opponent\n");
		return;
	}
	if (out == '#')
	{
		printf("sorry you lost\n");
		return;
	}
	printf("The two sides are equal\n");
	return;
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("Please choose: >");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Game over!\n");
			break;
		default:
			printf("Input errors, please re-enter!\n");
			break;
		}

	} while (input);
	return 0;
}