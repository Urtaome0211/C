#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//int main()
//{
//	//���迪��10�����͵Ŀռ�
//	//int arr[10];
//
//	//��̬�ڴ濪��
//	int* p = (int*)malloc(10 * sizeof(int));
//
//	//�ж��Ƿ񿪱ٳɹ�
//	if (p == NULL)
//	{
//		perror("main");
//		return 0;
//	}
//
//	//ʹ��
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//
//	//���տռ�
//	free(p);
//	p = NULL;//�ֶ���Ϊ��ָ��
//
//	return 0;
//}

//int main()
//{
//	//int* p = (int*)malloc(40);
//	int* p = malloc(10, sizeof(int));
//
//	if (p == NULL)
//	{
//		perror("main");
//		return 0;
//	}
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", *(p + i) = i);
//	}
//
//	int* ptr = realloc(p, 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	free(p); 
//	p == NULL;
//
//	return 0;
//}

//char* GetMemory(char* p)
//{
//    p = (char*)malloc(100);
//    return p;
//}
//
//void Test(void)
//{
//    char* str = NULL;
//    str = GetMemory(str);
//    strcpy(str, "hello world");
//    printf(str);
//    free(str); 
//}
//
//int main()
//{
//    Test();
//    return 0;
//}

typedef struct st_type
{
	int i;
	int a[0];//���������Ա
}type_a;