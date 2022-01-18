#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    printf("%d\n", &arr[9] - &arr[0]);
//    return 0;
//}
//int my_strlen(char* str)
//{
//    char* start = str;
//    while (*str != '\0')
//    {
//        str++;
//    }
//    return str - start;
//}
//
//int main()
//{
//    int len = my_strlen("abc");
//    printf("%d\n", len);
//    return 0;
//}
//int main()
//{
//    int arr[10] = { 0 };
//    printf("%p\n", arr);
//    printf("%p\n", &arr[0]);
//    return 0;
//}
int main()
{
    int arr[10] = { 0 };
    int* p = arr;
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        printf("%p == %p\n", &arr[i], p + i);
        *(p + i) = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(p + i));
    }
    return 0;
}