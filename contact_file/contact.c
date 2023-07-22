#include"contact.h"

int Expansion(contact* pc)
{
	peoinfo* temp = (peoinfo*)realloc(pc->data, sizeof(peoinfo) * (EXPAN_LEN + pc->capacity));
	if (temp == NULL)
	{
		perror("Expansion:");
		return -1;
	}
	pc->data = temp;
	pc->capacity += EXPAN_LEN;
	return 1;
}

void LoadContact(contact* pc)
{
	FILE* pfread = fopen("contact.txt", "rb");
	if (pfread == NULL)
	{
		perror("fopen");
		printf("初始化失败！\n");
		return;
	}
	peoinfo temp = { 0 };
	while (fread(&temp, sizeof(peoinfo), 1, pfread) == 1)
	{
		pc->data[pc->sz] = temp;
		pc->sz++;
		if (pc->sz == pc->capacity)
		{
			Expansion(pc);
		}
	}
	printf("初始化成功！\n");
	fclose(pfread);
	pfread = NULL;
}

//动态版本
void InitContact(contact* pc)
{
	pc->data = (peoinfo*)malloc(INIT_LEN * sizeof(peoinfo));
	if (pc->data == NULL)
	{
		perror("InitContact:");
		return;
	}
	memset(pc->data, 0, sizeof(pc->data));
	pc->sz = 0;
	pc->capacity = INIT_LEN;
}


void AddContact(contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		int ret = Expansion(pc);
		if (ret == 1)
			printf("增容成功！\n");
		else
		{
			printf("增容失败，无法添加联系人！\n");
			return;
		}
	}
	printf("请输入添加联系人的姓名：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入添加联系人的年龄：");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入添加联系人的性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入添加联系人的电话：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入添加联系人的住址：");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功!\n");
}

void ShowContact(const contact* pc)
{
	if (pc->sz == 0)
	{
		printf("没有联系人！\n");
		return;
	}
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-10s %-5d %-5s %-15s %-10s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

int FindByName(const contact* pc, char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空！\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入你要删除的联系人：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("联系人不存在！\n");
		return;
	}
	for (int i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功！\n");
}


void SearchContact(const contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入你要查找的联系人：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("你要查找的人不存在！\n");
		return;
	}
	printf("%-10s %-5d %-5s %-15s %-10s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}


void ModifyContact(contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入你要修改的联系人：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("你要修改的人不存在！\n");
		return;
	}
	printf("请输入新联系人的姓名：");
	scanf("%s", pc->data[pos].name);
	printf("请输入新联系人的年龄：");
	scanf("%d", &pc->data[pos].age);
	printf("请输入新联系人的性别：");
	scanf("%s", pc->data[pos].sex);
	printf("请输入新联系人的电话：");
	scanf("%s", pc->data[pos].tele);
	printf("请输入新联系人的住址：");
	scanf("%s", pc->data[pos].addr);
	printf("修改成功!\n");
}

void menu1()
{
	printf("*****************************\n");
	printf("***** 0. name  1. age  ******\n");
	printf("***** 2. tele  3. addr ******\n");
	printf("*****************************\n");
}

enum cau
{
	NAME,
	AGE,
	TELE,
	ADDR
};

int cmp_age(const void* a, const void* b)
{
	return (*(peoinfo*)a).age - (*(peoinfo*)b).age;
}

int cmp_name(const void* a, const void* b)
{
	char* s1 = ((peoinfo*)a)->name;
	char* s2 = ((peoinfo*)b)->name;
	return strcmp(s1, s2);
}

int cmp_tele(const void* a, const void* b)
{
	char* s1 = ((peoinfo*)a)->tele;
	char* s2 = ((peoinfo*)b)->tele;
	return strcmp(s1, s2);
}

int cmp_addr(const void* a, const void* b)
{
	char* s1 = ((peoinfo*)a)->addr;
	char* s2 = ((peoinfo*)b)->addr;
	return strcmp(s1, s2);
}

void SortContact(contact* pc)
{
	menu1();
	int input = 0;
	int (*p[4])(const void*, const void*) = { cmp_name, cmp_age, cmp_tele, cmp_addr };//函数指针数组
	while (1)
	{
		printf("请选择以什么属性排序：> ");
		scanf("%d", &input);
		if (input == 0 || input == 1 || input == 2 || input == 3)
		{
			qsort(pc->data, pc->sz, sizeof(pc->data[0]), p[input]);
			printf("排序成功！\n");
			return;
		}
		else
		{
			printf("输入错误，请重新输入！\n");
		}
	}
}

void SaveContact(contact* pc)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		printf("保存失败！\n");
		return;
	}
	size_t ret = fwrite(pc->data, sizeof(peoinfo), pc->sz, pf);
	if (ret == pc->sz)
	{
		printf("保存成功！\n");
	}
	fclose(pf);
	pf = NULL;
}

void DestroyContact(contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

void ClearContact(contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	InitContact(pc);
	printf("清空成功！\n");
}