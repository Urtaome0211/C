#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//#define SWAP(N) ((num & 0xaaaaaaaa) >> 1) + ((num & 0x55555555) << 1)
//int main()
//{
//	int num = 10;
//	int ret = SWAP(num);
//	printf("%d\n", ret);
//	return 0;
//}

#define OFFSETOF(struct_name, member_name) (int)&(((struct_name*)0)->member_name)

struct A
{
	int a;
	short b;
	int c;
	char d;
};

int main()
{
	printf("%d\n", OFFSETOF(struct A, a));
	printf("%d\n", OFFSETOF(struct A, b));
	printf("%d\n", OFFSETOF(struct A, c));
	printf("%d\n", OFFSETOF(struct A, d));

	return 0;
}