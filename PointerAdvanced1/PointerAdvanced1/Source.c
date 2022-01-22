#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//    char str1[] = "Hello World.";
//    char str2[] = "Hello World.";
//    char *str3 = "Hello World.";
//    char *str4 = "Hello World.";
//
//    if (str1 == str2)
//    {
//        printf("str1 and str2 are same\n");
//    }
//    else
//    {
//        printf("str1 and str2 are not same\n");
//    }
//
//    if (str3 == str4)
//    {
//        printf("str3 and str4 are same\n");
//    }
//    else
//    {
//        printf("str3 and str4 are not same\n");
//    }
//    return 0;
//}
//int main()
//{
//    int a[5] = { 1,2,3,4,5 };
//    int b[] = { 2,3,4,5,6 };
//    int c[] = { 3,4,5,6,7 };
//    int* arr[3] = { a, b, c };
//    int i = 0;
//
//    for (i = 0; i < 3; i++)
//    {
//        int j = 0;
//        for (j = 0; j < 5; j++)
//        {
//            printf("%d ", *(arr[i]) + j);
//            //printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//int main()
//{
//    int arr[10] = { 0 };
//    printf("%p\n", arr);
//    printf("%p\n", &arr);
//    return 0;
//}
//int main()
//{
//    int arr[10] = { 0 };
//    int* p1 = arr;
//    int(*p2)[10] = &arr;
//
//    printf("%p\n", p1);
//    printf("%p\n", p1 + 1);
//
//    printf("%p\n", p2);
//    printf("%p\n", p2 + 1);
//    return 0;
//}
//void print1(int arr[3][5], int r, int c)
//{
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < r; i++)
//    {
//        for (j = 0; j < c; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//void print2(int(*p)[5], int r, int c)
//{
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < r; i++)
//    {
//        for (j = 0; j < c; j++)
//        {
//            printf("%d ", *(*(p+i)+j));
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//    int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7} };
//    //print1(arr, 3, 5);
//    print2(arr, 3, 5);
//    return 0;
//}
