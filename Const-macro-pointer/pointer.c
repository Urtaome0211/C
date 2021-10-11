#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	printf("%d\n", sizeof(int *));
	printf("%d\n", sizeof(char *));
	printf("%d\n", sizeof(short *));
	printf("%d\n", sizeof(long *));
	printf("%d\n", sizeof(long long *));
	printf("%d\n", sizeof(float *));
	printf("%d\n", sizeof(double *));

	return 0;
}
//
//int main()
//{
//	int a = 10;
//	int * pa = &a;
//	*pa = 20;
//	//解引用操作
//	//*pa就是通过pa里边的地址找到a
//	//可以不通过a来修改变量值
//	printf("%d\n", a);
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//	printf("%p\n", a);
//	//pa是用来存放地址的，在c语言中叫指针变量
//	int * pa = &a;
//	//*说明pa是指针变量
//	//int说明pa指向的对象的int类型
//	return 0;
//}