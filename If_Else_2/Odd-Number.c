#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//�ж�1-100������������ӡ
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