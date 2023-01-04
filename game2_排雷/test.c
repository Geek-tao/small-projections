#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("*****     0.exit    *******\n");
	printf("*****     1.play    *******\n");
	printf("***************************\n");

}

void game()
{
	char mine[Rows][Cols] = { 0 };
	char show[Rows][Cols] = { 0 };
	InitBoard(mine, Row, Col, '0');
	InitBoard(show, Row, Col, '*');
	DisplayBoard(show, Row, Col);
	//DisplayBoard(mine, Row, Col);
	SetMine(mine, Row, Col);
	//DisplayBoard(mine, Row, Col);
	FindMine(mine,show, Row, Col);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入：>\n");
			break;
		}
	} while (input);
	return 0;
}