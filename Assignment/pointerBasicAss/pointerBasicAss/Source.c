#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>

//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    int* p = arr;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int* pend = arr + sz - 1;
//
//    while (p <= pend)
//    {
//        printf("%d ", *p);
//        p++;
//    }
//    return 0;
//}
//int main()
//{
//    int i = 0;
//    for (i = 0; i < 100000; i++)
//    {
//        //�ж�i�Ƿ�Ϊ������
//        //1. ����i��λ�� - n
//        int n = 1;
//        int tmp = i;
//        while (tmp / 10)
//        {
//            n++;
//            tmp /= 10;
//        }
//
//        //2.����i��ÿһλ��n�η�֮��
//        tmp = i;
//        int sum = 0;
//        while (tmp)
//        {
//            sum += pow(tmp % 10, n);
//            tmp /= 10;
//        }
//
//        //3.�ж�
//        if (sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}
//void reverse(char* str)
//{
//    int len = strlen(str);
//    char* left = str;
//    char* right = str + len - 1;
//
//    while (left < right)
//    {
//        char tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}
//
//int main()
//{
//    char arr[] = "i am a student";
//    reverse(arr);
//    printf("%s\n", arr);
//    return 0;
//}
//int main()
//{
//    int line = 0;
//    scanf("%d", &line);
//
//    //��ӡ�ϰ벿��
//    int i = 0;
//    for (i = 0; i < line; i++)
//    {
//        //��ӡ�ո�
//        int j = 0;
//        for (j = 0; j < line - 1 - i; j++)
//        {
//            printf(" ");
//        }
//        //��ӡ*
//        for (j = 0; j < 2 * i + 1; j++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//
//    //��ӡ�°벿��
//    for (i = 0; i < line - 1; i++)
//    {
//        //��ӡ�ո�
//        int j = 0;
//        for (j = 0; j <= i; j++)
//        {
//            printf(" ");
//        }
//        //��ӡ*
//        for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}
//int main()
//{
//    int money = 0;
//    scanf("%d", &money);
//    int total = money;
//    int empty = money;
//
//    //����ƿ
//    while (empty >= 2)
//    {
//        total += empty / 2;
//        empty = empty / 2 + empty % 2;
//    }
//    printf("%d", total);
//    return 0;
//}
int main()
{
    int money = 0;
    int total = money;
    scanf("%d", &money);
    if (money > 0)
    {
        total = 2 * money - 1;
    }
    printf("%d", total);
    return 0;
}