#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//int main()
//{
//	//假设开辟10个整型的空间
//	//int arr[10];
//
//	//动态内存开辟
//	int* p = (int*)malloc(10 * sizeof(int));
//
//	//判断是否开辟成功
//	if (p == NULL)
//	{
//		perror("main");
//		return 0;
//	}
//
//	//使用
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
//	//回收空间
//	free(p);
//	p = NULL;//手动置为空指针
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
	int a[0];//柔性数组成员
}type_a;