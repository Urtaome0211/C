#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//extern�����ⲿ����
//extern int g_val;
extern int Add(int x, int y);
int main()
{
	int a = 10;
	int b = 20;
	int sum = Add(a, b);
	printf("sum is = %d\n", sum);
	//printf("%d\n", g_val);
	return 0;
}
//typedef unsigned int u_int;
//void test()
//{
//	static int a = 1;
//	a++;
//	printf("%d ", a);
//}
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		test();
//		i++;
//	}
//	return 0;
	//u_int num = 100;
	//return 0;
	//printf("hehe\n");
	//���ú������Ǻ󣬺�������ߵ�()���Ǻ������õĲ�����
	//return 0;
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//printf("%d\n", arr[5]);
	//int a = 0;
	//int b = 3;
	//int c = 5;
	//int d = (a = b + 2, c = a - 4, b = c + 2);
	//printf("%d\n", d);
	//return 0;
	////int a = 0;
	//int b = 3;
	//int max = 0;
	//max = a > b ? a : b;
	//printf("%d\n", max);
	//int a = 3;
	//int b = 0;
	//int c = a || b;
	//printf("%d\n", c);
	//return 0;
	//int a = 3;
	//int b = 5;
	//int c = a && b;
	//printf("%d\n", c);
	//return 0;
//}
//int main()
//{
//	int a = (int)3.14;
//	printf("%d\n", a);
//	return 0;
//	//int a = 10;
//	//int b = a++;
//	//printf("%d\n", b);
//	//printf("%d\n", a);
//	//return 0;
//}
////

////int main()
//{
//	int a = 10;
//	int b = ++a;// ǰ��++
//	printf("%d\n", b);
//	printf("%d\n", a);
//	return 0;
//}