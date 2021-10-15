#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int age = 0;
	printf("请输入年龄: ");
	scanf("%d", &age);

	if (age < 18)
		printf("少年\n");
	else if (age >= 18 && age < 26)
		printf("青年\n");
	else if (age >= 26 && age < 40)
		printf("中年\n");
	else if (age >= 40 && age < 60)
		printf("壮年\n");
	else if (age >= 60 && age <= 100)
		printf("老年\n");
	else
		printf("老不死\n");

	//if (age >= 18)
	//	printf("成年\n");
	//else
	//{ 
	//	printf("未成年\n");
	//	printf("不能谈恋爱\n");
	//}
	return 0;
}