#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("************************************\n");
	printf("**********    1.play   *************\n");
	printf("**********    0.exit   *************\n");
	printf("************************************\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do 
	{
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();   //����Ϸ
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룺\n");
			break;
		}
	} while (input);
	return 0;
}