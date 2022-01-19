#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//    int arr[10] = { 0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        arr[i] = i + 1;
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    
//    int sum = 0;
//    int j = 0;
//    for (j = 1; j <= n; j++)
//    {
//        int ret = 1;
//        for (i = 1; i <= j; i++)
//        {
//            ret *= i;
//        }
//        sum += ret;
//    }
//    printf("%d\n", sum);
////    return 0;
////}
//int main()
//{
//    int i = 0;
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hehe\n");
//    }
//    return 0;
//}
void my_strcpy(char* dest, char* src)
{
    while (*src != '\0')//\0²»ÄÜ±»¿½±´
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = *src;//¿½±´\0
}

int main()
{
    char arr1[20] = "xxxxxxxxxxx";
    char arr2[] = "hello";
    my_strcpy(arr1, arr2);
    printf("%s\n", arr1);
    return 0;
}