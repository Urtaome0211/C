#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//1. ����������������С������
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int i = 1;
//	for (i = 1; ; i++)
//	{
//		if (a * i % b == 0)
//		{
//			printf("%d", a*i);
//			break;
//		}
//	}
//	return 0;
//}

//2.�ַ�������
//i like beijing
//beijing like i

void reverse(char* left, char* right)
{
	while (left < right)
	{
		char tmp = 0;
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[100] = { 0 };
	gets(arr);
	int len = strlen(arr);
	//���������ַ���
	reverse(arr, arr + len - 1);

	char* start = arr;
	while (*start)
	{
		char* end = start;
		while (*end != ' ' && *end != '\0')
		{
			//�ҿո��\0��־�������Ǿ�������ֱ���ҵ�һ�������ĵ���
			end++;
		}
		//���򵥸�����
		reverse(start, end - 1);
		if (*end == ' ')
		{
			start = end + 1;
		}
		else
		{
			start = end;//���*endλ\0��������+1
		}
	}
	printf("%s\n", arr);
	return 0;
}