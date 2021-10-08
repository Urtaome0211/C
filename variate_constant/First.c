#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()

{
	char arr1[] = "abc";
	char arr2[] = { 'a', 'b', 'c', '\0'};
	printf("%d\n", strlen(arr1));// srting length ¼ÆËã×Ö·û³¤¶È
	printf("%d\n",strlen(arr2));
	return 0;
}

//enum Color
//{
//	red,
//	blue,
//	yellow
//};
//
//int main()
//
//{
//	enum Color color = blue;
//	return 0;
//}
//
//enum Sex
//{
//	Male,
//	Female,
//	Secret
//};
//
//int main()
//{
//	//enum Sex s = Male;
//	printf("%d\n", Male);
//	printf("%d\n", Female);
//	printf("%d\n", Secret);
//	return 0;
//}

//int main()
//
//#define MAX 10
//{
//	int arr[MAX] = {0};
//	printf("%d\n", MAX);
//	return 0;
//}

//int main()
//
//{
//	const int n = 0;
//	int arr[n] = { 0 };
//	return 0;
//}

//int main()
//
//{
//	const int num = 4;
//	printf("%d\n", num);
//	num = 8;
//	printf("%d\n", num);
//	return 0;
//}
//int main()
//{
//	printf("Hello World");
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	return 0;
//}