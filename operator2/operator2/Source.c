#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	printf("%d\n", arr[4]);
//
//	return 0;
////}
//
//struct book
//{
//	char name[20];
//	char id[20];
//	int price;
//};
//
//int main()
//{
//	struct book b = {"C语言", "C20220117", 55};
//	struct book * pb = &b;
//	printf("书名：%s, 书号：%s, 定价：%d\n", b.name, b.id, b.price);
//	printf("书名：%s, 书号：%s, 定价：%d\n", (*pb).name, (*pb).id, (*pb).price);
//	printf("书名：%s, 书号：%s, 定价：%d\n", pb->name, pb->id, pb->price);
//	return 0;
////}
//
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a + b * 7;
//	printf("%d\n", c);
//	return 0;
//
//}
//
//int main()
//{
//	char a = 3;
//	char b = 127;
//	char c = a + b;
//	printf("%d\n", c);
//	return 0;
//}
int main()
{
	char a = 0xb6;
	short b = 0xb600;
	int c = 0xb6000000;

	if (a == 0xb6)
	{
		printf("a");
	}
	if (b == 0xb600)
	{
		printf("b");
	}
	if (c == 0xb6000000)
	{
		printf("c");
	}
	return 0;
}