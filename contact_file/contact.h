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

typedef struct peoinfo //联系人
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


//初始化通讯录
void InitContact(contact* pc);

//加载通讯录文件信息
void LoadContact(contact* pc);

//增加联系人
void AddContact(contact* pc);

//查看通讯录
void ShowContact(const contact* pc);

//删除联系人
void DelContact(contact* pc);

//查找联系人
void SearchContact(const contact* pc);

//修改联系人
void ModifyContact(contact* pc);

//对通讯录排序
void SortContact(contact* pc);

//保存通讯录
void SaveContact(contact* pc);

//销毁通讯录
void DestroyContact(contact* pc);

//清空通讯录
void ClearContact(contact* pc);