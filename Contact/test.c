#include"contact.h"

void menu()
{
	printf("********************************\n");
	printf("***** 1. add     2. del    *****\n");
	printf("***** 3. search  4. modify *****\n");
	printf("***** 5. show    6. sort   *****\n");
	printf("***** 0. exit              *****\n");
	printf("********************************\n");
}

enum OPTION
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

void test()
{
	contact con;
	InitContact(&con);
	menu();
	int input = 0;
	do
	{
		printf("��ѡ��> ");
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
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case EXIT:
				DestroyContact(&con);
				printf("�˳��ɹ���\n");
				return;
				break;
			default:
				printf("�����������������룡\n");
				break;
		}
	} while (input);
}


int main()
{
	test();

	return 0;
}