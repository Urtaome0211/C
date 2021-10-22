#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//判断1-100的奇数，并打印
int main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
			printf("%d ", i);
	}
	return 0;
}