#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//int main()
//{
//	int a = 10;
//	printf("%p", &a);
//	return 0;
////}
//
//int main()
//{
//    int arr[10] = { 0 };
//    int* p = arr;
//    char* pc = arr;
//
//    printf("%p\n", p);
//    printf("%p\n", p + 1);
//
//    printf("%p\n", pc);
//    printf("%p\n", pc + 1);
//    return 0;
//}
int main()
{
    int arr[10] = { 0 };
    int *p = arr;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        *(p+i) = 1;
        //ÿѭ��һ�ξͽ����е�һ��Ԫ���ó�1
    }
    return 0;
}