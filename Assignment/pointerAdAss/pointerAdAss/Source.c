#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int find_num(int arr[3][3], int* px, int* py, int k)
//{
//    int x = 0;
//    int y = *py - 1;
//
//    while (x < *py && y >= 0)
//    {
//        if (arr[x][y] < k)
//        {
//            x++;
//        }
//        else if (arr[x][y] > k)
//        {
//            y--;
//        }
//        else
//        {
//            *px = x;
//            *py = y;
//            return 1;
//        }
//    }
//    return 0;
//}
//
//int main()
//{
//    int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//    int k = 7;
//
//    int x = 3;
//    int y = 3;
//    //查找一个数字，比如说找7
//    //如果找到返回1，找不到返回0
//    int ret = find_num(arr, &x, &y, k);
//    if (ret == 1)
//    {
//        printf("找到了\n");
//        printf("坐标是：%d %d\n", x, y);
//    }
//    else
//    {
//        printf("找不到");
//    }
//
//    return 0;
//}

//void string_left_rotate(char* str, int k)
//{
//    int i = 0;
//    int n = strlen(str);
//    for (i = 0; i < k; i++)
//    {
//        //每次左旋一个字符
//        char tmp = *str;
//        int j = 0;
//        for (j = 0; j < n - 1; j++)
//        {
//            //后边n-1个字符往前挪动
//            *(str + j) = *(str + j + 1);
//        }
//        //tmp放在最后
//        *(str + n - 1) = tmp;
//    }
//}
//
//int main()
//{
//    char arr[] = "ABCDEF";
//    int k = 2;
//    string_left_rotate(arr, k);
//    printf("%s\n", arr);
//}

int is_string_rotate(char* str1, char* str2)
{
    int i = 0;
    int n = strlen(str1);
    for (i = 0; i < n; i++)
    {
        //每次左旋一个字符
        char tmp = *str1;
        int j = 0;
        for (j = 0; j < n - 1; j++)
        {
            //后边n-1个字符往前挪动
            *(str1 + j) = *(str1 + j + 1);
        }
        //tmp放在最后
        *(str1 + n - 1) = tmp;

        //比较
        if (strcmp(str1, str2) == 0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    char arr1[] = "ABCD";
    char arr2[] = "BCDA";
    int ret = is_string_rotate(arr1, arr2);
    if (ret == 1)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}