#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//int main()
//{
//	int a = -10;
//	//ԭ�� - 1000 0000 0000 0000 0000 0000 0000 1010
//	//���� - 1111 1111 1111 1111 1111 1111 1111 0101
//	//���� - 1111 1111 1111 1111 1111 1111 1111 0110
//	//hex -  f    f    f    f    f    f    f    6
//	return 0;
//}
//int main()
//{
//    int a = 1;
//    char* p = (char*)&a;
//
//    if (*p == 1)
//    {
//        printf("С��\n");
//    }
//    else
//    {
//        printf("���\n");
//    }
//    return 0;
//}
int main()
{
    char a = -1;
    signed char b = -1;
    unsigned char c = -1;
    printf("a=%d, b=%d, c=%d", a, b, c);
    return 0;
}