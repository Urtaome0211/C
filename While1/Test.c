#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
		//getchar�Ӽ��̻�ȡ��׼�ַ���Ϊint����
		//��ȡ��ȷʱ����ACSIIֵ
		//�����󷵻�EOF
		//EOF-end of file�ļ�������־
		putchar(ch);
		//���һ���ַ�
	printf("%c\n", ch);
	return 0;
}