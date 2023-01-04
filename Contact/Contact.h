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

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//打印通讯录
void PrintContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找联系人
void SearchPeoinfo(Contact* pc);

//修改通讯录
void ModifyContact(Contact* pc);

//按姓名首字母排序
void SortContact(Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);