#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	FILE* pf = fopen("test1.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	//fputc('b', pf);
//	//fputc('i', pf);
//	//fputc('t', pf);
//
//	//���ļ�
//	int ret = fgetc(pf);
//	printf("%c", ret);
//
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}

//int main()
//{
//	char arr[10] = "xxxxxxxx";
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//struct S
//{
//	char arr[10];
//	int num;
//	float sc;
//};
//
//int main()
//{
//	struct S s = { 0 };
//
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//���ļ�
//	fread(&s, sizeof(struct S), 1, pf);
//
//	//��ӡ
//	printf("%s %d %f", s.arr, s.num, s.sc);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//struct S
//{
//	char arr[10];
//	int age;
//	float f;
//};
//
//int main()
//{
//	struct S s = { "hello", 20, 5.5f };
//	struct S tmp = { 0 };
//
//	char buf[100] = { 0 };
//	sprintf(buf, "%s %d %f", s.arr, s.age, s.f);
//	printf("%s\n", buf);
//
//	//��buf�ַ����л�ԭ��һ���ṹ��
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.age), &(tmp.f));
//	printf("%s %d %f", tmp.arr, tmp.age, tmp.f);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	//�����ļ�ָ��
//	fseek(pf, -2, SEEK_END);
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//e
//	ch = fgetc(pf);
//	printf("%c\n", ch);//f
//
//	//�鿴ƫ����
//	int ret = ftell(pf);
//	printf("%d\n", ret);//6
//
//	//���ļ�ָ��ص���ʼλ��
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	fwrite(&a, sizeof(int), 1, pf);//�����Ƶ���ʽд���ļ���
//
//	//���ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//��test.txt�ļ�����һ�ݣ�����test2.txt�ļ�
int main()
{
	FILE* pfread = fopen("test.txt", "r");
	if (pfread == NULL)
	{
		return 1;
	}

	FILE* pfwrite = fopen("test2.txt", "w");
	if (pfwrite == NULL)
	{
		fclose(pfread);
		pfread = NULL;
		return 1;
	}//�ļ��򿪳ɹ�

	//��д�ļ�
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF)
	{
		//д�ļ�
		fputc(ch, pfwrite);
	}

	if (feof(pfread))
	{
		printf("�����ļ�������ʾ���ļ���������\n");
	}
	else if (feof(pfread))
	{
		printf("�ļ���ȡʧ�ܽ���\n");
	}

	//�ر��ļ�
	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;
	return 0;
}