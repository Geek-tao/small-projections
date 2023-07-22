#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_NAME 10
#define MAX_SEX 3
#define MAX_TELE 12 
#define MAX_ADDR 10
#define INIT_LEN 3
#define EXPAN_LEN 2

typedef struct peoinfo //��ϵ��
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;


typedef struct con
{
	peoinfo* data;
	int sz;
	int capacity;
}contact;


//��ʼ��ͨѶ¼
void InitContact(contact* pc);

//����ͨѶ¼�ļ���Ϣ
void LoadContact(contact* pc);

//������ϵ��
void AddContact(contact* pc);

//�鿴ͨѶ¼
void ShowContact(const contact* pc);

//ɾ����ϵ��
void DelContact(contact* pc);

//������ϵ��
void SearchContact(const contact* pc);

//�޸���ϵ��
void ModifyContact(contact* pc);

//��ͨѶ¼����
void SortContact(contact* pc);

//����ͨѶ¼
void SaveContact(contact* pc);

//����ͨѶ¼
void DestroyContact(contact* pc);

//���ͨѶ¼
void ClearContact(contact* pc);