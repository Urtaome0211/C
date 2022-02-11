#pragma once
#include <stdio.h>
#include <string.h>


//���š����ͺͺ���������

//���ŵĶ���
#define MAX_NAME 20
#define MAX_GENDER 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_PEOPLE 1000

//�˵���Ϣ�Ķ���
typedef struct PeopleInfo
{
	char name[MAX_NAME];
	char gender[MAX_GENDER];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeopleInfo;

//ͨѶ¼�ṹ��
typedef struct Contact
{
	PeopleInfo data[MAX_PEOPLE];//�����ӽ������˵���Ϣ
	int sz;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
} Contact;

//����������
void InitContact(Contact* pc);//��ʼ��ͨѶ¼

void ContactAdd(Contact* pc);//������Ϣ

void PrintContact(const Contact* pc);//��ӡͨѶ¼

void ContactDel(Contact* pc);//ɾ����Ϣ

void SearchContact(Contact* pc);//����ָ����Ϣ

void ModifyContact(Contact* pc);//�޸�ָ������Ϣ