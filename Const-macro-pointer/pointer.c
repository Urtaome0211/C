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
//	//�����ò���
//	//*pa����ͨ��pa��ߵĵ�ַ�ҵ�a
//	//���Բ�ͨ��a���޸ı���ֵ
//	printf("%d\n", a);
//	return 0;
//}
//
//int main()
//{
//	int a = 10;
//	printf("%p\n", a);
//	//pa��������ŵ�ַ�ģ���c�����н�ָ�����
//	int * pa = &a;
//	//*˵��pa��ָ�����
//	//int˵��paָ��Ķ����int����
//	return 0;
//}