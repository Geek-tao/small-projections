#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

void menu()
{
	printf("*******************************\n");
	printf("***** 1.add      2.del    *****\n");
	printf("***** 3.search   4.modify *****\n");
	printf("***** 5.sort     6.print  *****\n");
	printf("*****       0.exit       *****\n");
	printf("*******************************\n");
}

enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};
int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("ÇëÑ¡Ôñ£º>\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchPeoinfo(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			DestoryContact(&con);
			break;
		default:
			printf("ÊäÈë´íÎó£¬ÇëÖØĞÂÊäÈë£º>\n");
		}
	} while (input);
	return 0;
}