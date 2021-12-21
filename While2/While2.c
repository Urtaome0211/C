#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	char password[20] = { 0 };
	printf("Please keyin password: ");
	scanf("%s", password);
	printf("Comfirm Your Password(Y/N): ");
	//清理缓冲区内的多个字符
	int tmp = 0;
	while (tmp = getchar() != '\n')
	{
		;
	}

	int ch = getchar();

	if (ch == 'Y')
	{
		printf("Suss!");
	}
	else
	{
		printf("Error!");
	}
	return 0;
}