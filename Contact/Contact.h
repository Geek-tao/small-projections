#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 10
#define MAX_CAPACITY 3
#define MAX_ADD_CAPA 2
typedef struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;

typedef struct Contact
{
	peoinfo* date;
	int sz;
	int capacity;
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ӡͨѶ¼
void PrintContact(Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SearchPeoinfo(Contact* pc);

//�޸�ͨѶ¼
void ModifyContact(Contact* pc);

//����������ĸ����
void SortContact(Contact* pc);

//����ͨѶ¼
void DestoryContact(Contact* pc);