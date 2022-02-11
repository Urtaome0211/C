#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>


//���š����ͺͺ���������

//���ŵĶ���
#define MAX_NAME 20
#define MAX_GENDER 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_PEOPLE 1000
#define DEFAULT_SZ 3
#define INC_SZ 2

//�˵���Ϣ�Ķ���

//��̬�汾
typedef struct PeopleInfo
{
	char name[MAX_NAME];
	char gender[MAX_GENDER];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeopleInfo;

//��̬�汾
typedef struct Contact
{
	PeopleInfo* data;//ָ��̬����Ŀռ䣬���������Ϣ
	int sz;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰͨѶ¼�������
} Contact;

//ͨѶ¼�ṹ��
/*typedef struct Contact
{
	PeopleInfo data[MAX_PEOPLE];//�����ӽ������˵���Ϣ
	int sz;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
} Contact;*/

//����������
void InitContact(Contact* pc);//��ʼ��ͨѶ¼

void ContactAdd(Contact* pc);//������Ϣ

void PrintContact(const Contact* pc);//��ӡͨѶ¼

void ContactDel(Contact* pc);//ɾ����Ϣ

void SearchContact(Contact* pc);//����ָ����Ϣ

void ModifyContact(Contact* pc);//�޸�ָ������Ϣ

void DestoryContact(Contact* pc);//����ͨѶ¼