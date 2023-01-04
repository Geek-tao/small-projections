#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include<string.h>
//初始化结构体
void InitContact(Contact* pc)
{
	pc->date = (peoinfo*)malloc(MAX_CAPACITY * sizeof(peoinfo));
	pc->capacity = MAX_CAPACITY;
	pc->sz = 0;
}

static int Search_By_Name(Contact*pc, char* ptr)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->date[i].name, ptr) == 0)
		{
			return i;
		}
	}
	return -1;
}

//增加通讯录
void AddContact(Contact* pc)
{
	if (pc->capacity == pc->sz)
	{
		//通讯录已满，需要扩容
		peoinfo* temp = realloc(pc->date, (MAX_CAPACITY + MAX_ADD_CAPA) * sizeof(peoinfo));
		if (temp)
		{
			pc->date = temp;
			pc->capacity += MAX_ADD_CAPA;
		}
		else
		{
			perror("AddContact");
			printf("扩容失败！\n");
			return;
		}
	}
	printf("请输入姓名：>");
	scanf("%s", pc->date[pc->sz].name);
	printf("请输入年龄：>");
	scanf("%d", &pc->date[pc->sz].age);
	printf("请输入性别：>");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入电话：>");
	scanf("%s", pc->date[pc->sz].tele);
	printf("请输入住址：>");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
}

void PrintContact(Contact* pc)
{
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-10s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-15s\t%-10s\n",
			pc->date[i].name,
			pc->date[i].age,
			pc->date[i].sex,
			pc->date[i].tele,
			pc->date[i].addr);
	}
}

void DelContact(Contact* pc)
{
	char name[MAX_NAME];
	if (pc->sz == 0)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入你要删除的联系人：>");
	scanf("%s", name);
	int pos = Search_By_Name(pc, name);
	if (pos == -1)
	{
		printf("你要删除的人不存在！\n");
		return;
	}
	for (int i = pos; i < pc->sz - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("删除成功！忘了她吧，向前看！\n");
}

void SearchPeoinfo(Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入你想查找的人的名字：\n");
	scanf("%s", name);
	int pos = Search_By_Name(pc, name);
	if (pos == -1)
		printf("你要查找的人不存在！\n");
	else
	{
		printf("%-10s\t%-5d\t%-5s\t%-15s\t%-10s\n",
		pc->date[pos].name,
		pc->date[pos].age,
		pc->date[pos].sex,
		pc->date[pos].tele,
		pc->date[pos].addr);
	}
}

void ModifyContact(Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入你要修改的人的名字：>\n");
	scanf("%s", name);
	int pos = Search_By_Name(pc, name);
	if (pos == -1)
	{
		printf("你要修改的人不存在！>\n");
	}
	else
	{
		printf("请输入姓名：>");
		scanf("%s", pc->date[pos].name);
		printf("请输入年龄：>");
		scanf("%d", &pc->date[pos].age);
		printf("请输入性别：>");
		scanf("%s", pc->date[pos].sex);
		printf("请输入电话：>");
		scanf("%s", pc->date[pos].tele);
		printf("请输入住址：>");
		scanf("%s", pc->date[pos].addr);
		printf("修改成功！\n");
	}
}

void SortContact(Contact* pc)
{
	for (int i = 1; i < pc->sz; i++)
	{
		for (int j = 0; j < pc->sz - i; j++)
		{
			if (strcmp(pc->date[j].name, pc->date[j + 1].name) > 0)
			{
				peoinfo temp = pc->date[j];
				pc->date[j] = pc->date[j+1];
				pc->date[j+1] = temp;
			}
		}
	}
	printf("排序成功！\n");
}


void DestoryContact(Contact* pc)
{
	free(pc->date);
	pc->date = NULL;
	free(pc);
	pc = NULL;
}