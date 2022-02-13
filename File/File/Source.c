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
//	//关文件
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
//	//写文件
//	//fputc('b', pf);
//	//fputc('i', pf);
//	//fputc('t', pf);
//
//	//读文件
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
//	//读文件
//	fread(&s, sizeof(struct S), 1, pf);
//
//	//打印
//	printf("%s %d %f", s.arr, s.num, s.sc);
//
//	//关闭文件
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
//	//从buf字符串中还原出一个结构体
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
//	//读取文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	//调整文件指针
//	fseek(pf, -2, SEEK_END);
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//e
//	ch = fgetc(pf);
//	printf("%c\n", ch);//f
//
//	//查看偏移量
//	int ret = ftell(pf);
//	printf("%d\n", ret);//6
//
//	//让文件指针回到起始位置
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//关闭文件
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
//	//写文件
//	fwrite(&a, sizeof(int), 1, pf);//二进制的形式写到文件中
//
//	//关文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//把test.txt文件拷贝一份，生成test2.txt文件
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
	}//文件打开成功

	//读写文件
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF)
	{
		//写文件
		fputc(ch, pfwrite);
	}

	if (feof(pfread))
	{
		printf("遇到文件结束表示，文件正常结束\n");
	}
	else if (feof(pfread))
	{
		printf("文件读取失败结束\n");
	}

	//关闭文件
	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;
	return 0;
}