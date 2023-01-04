#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include<string.h>
//��ʼ���ṹ��
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

//����ͨѶ¼
void AddContact(Contact* pc)
{
	if (pc->capacity == pc->sz)
	{
		//ͨѶ¼��������Ҫ����
		peoinfo* temp = realloc(pc->date, (MAX_CAPACITY + MAX_ADD_CAPA) * sizeof(peoinfo));
		if (temp)
		{
			pc->date = temp;
			pc->capacity += MAX_ADD_CAPA;
		}
		else
		{
			perror("AddContact");
			printf("����ʧ�ܣ�\n");
			return;
		}
	}
	printf("������������>");
	scanf("%s", pc->date[pc->sz].name);
	printf("���������䣺>");
	scanf("%d", &pc->date[pc->sz].age);
	printf("�������Ա�>");
	scanf("%s", pc->date[pc->sz].sex);
	printf("������绰��>");
	scanf("%s", pc->date[pc->sz].tele);
	printf("������סַ��>");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
}

void PrintContact(Contact* pc)
{
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-10s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("��������Ҫɾ������ϵ�ˣ�>");
	scanf("%s", name);
	int pos = Search_By_Name(pc, name);
	if (pos == -1)
	{
		printf("��Ҫɾ�����˲����ڣ�\n");
		return;
	}
	for (int i = pos; i < pc->sz - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ����������ɣ���ǰ����\n");
}

void SearchPeoinfo(Contact* pc)
{
	char name[MAX_NAME];
	printf("������������ҵ��˵����֣�\n");
	scanf("%s", name);
	int pos = Search_By_Name(pc, name);
	if (pos == -1)
		printf("��Ҫ���ҵ��˲����ڣ�\n");
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
	printf("��������Ҫ�޸ĵ��˵����֣�>\n");
	scanf("%s", name);
	int pos = Search_By_Name(pc, name);
	if (pos == -1)
	{
		printf("��Ҫ�޸ĵ��˲����ڣ�>\n");
	}
	else
	{
		printf("������������>");
		scanf("%s", pc->date[pos].name);
		printf("���������䣺>");
		scanf("%d", &pc->date[pos].age);
		printf("�������Ա�>");
		scanf("%s", pc->date[pos].sex);
		printf("������绰��>");
		scanf("%s", pc->date[pos].tele);
		printf("������סַ��>");
		scanf("%s", pc->date[pos].addr);
		printf("�޸ĳɹ���\n");
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
	printf("����ɹ���\n");
}


void DestoryContact(Contact* pc)
{
	free(pc->date);
	pc->date = NULL;
	free(pc);
	pc = NULL;
}