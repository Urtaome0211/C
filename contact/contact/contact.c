#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//������ʵ��

//��ʼ��ͨѶ¼ - ��̬
//void InitContact(Contact* pc)
//{
//	pc -> sz = 0;
//
//	//��memset()������ͨѶ¼�ÿ�
//	memset(pc->data, 0, sizeof(pc->data));
//}

//��ʼ��ͨѶ¼ - ��̬
void InitContact(Contact* pc)
{
	pc->data = (PeopleInfo*)malloc(DEFAULT_SZ * sizeof(PeopleInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;//��ʼ����Ĭ��Ϊ0
	pc->capacity = DEFAULT_SZ;
}

//������Ϣ - ��̬
//void ContactAdd(Contact* pc)
//{
//	if (pc->sz == MAX_PEOPLE)
//	{
//		printf("ͨѶ¼�������޷���ӣ�\n");
//		return;
//	}
//
//	//����һ���˵���Ϣ
//	printf("���������֣�");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("���������䣺");
//	scanf("%d", &(pc->data[pc->sz]).age);
//	printf("�������Ա�");
//	scanf("%s", pc->data[pc->sz].gender);
//	printf("������绰��");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�������ַ��");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("��ӳɹ�\n");
//}

//������Ϣ - ��̬
void ContactAdd(Contact* pc)
{
	//��������
	if (pc->sz == pc->capacity)
	{
		PeopleInfo* ptr = (PeopleInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeopleInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("ContactAdd");
			printf("������ϵ��ʧ��\n");
			return;
		}
		return;
	}

	//����һ���˵���Ϣ
	printf("���������֣�");
	scanf("%s", pc->data[pc->sz].name);
	printf("���������䣺");
	scanf("%d", &(pc->data[pc->sz]).age);
	printf("�������Ա�");
	scanf("%s", pc->data[pc->sz].gender);
	printf("������绰��");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ��");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("��ӳɹ�\n");
}

//��ӡͨѶ¼
void PrintContact(const Contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");

	//��ӡ����
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].gender, pc->data[i].tele, pc->data[i].addr);
	}
}

//�����˵���Ϣ
static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//�Ҳ���
}

//ɾ����Ϣ
void ContactDel(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ����\n");
		return;
	}

	printf("������Ҫɾ�����˵����֣�");
	scanf("%s", name);

	//1. ������Ҫɾ������Ϣ
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}

	//2. ɾ��
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
	
}

//����ָ������Ϣ
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ��˵����֣�");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");

		//��ӡ����
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].gender, pc->data[pos].tele, pc->data[pos].addr);
	}
}

//�޸�ָ������Ϣ
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĵ��˵����֣�");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("���������֣�");
		scanf("%s", pc->data[pos].name);
		printf("���������䣺");
		scanf("%d", &(pc->data[pos]).age);
		printf("�������Ա�");
		scanf("%s", pc->data[pos].gender);
		printf("������绰��");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", pc->data[pos].addr);

		printf("�޸ĳɹ���\n");
	}

}

//����ͨѶ¼
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}