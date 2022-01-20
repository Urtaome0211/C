#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//int NumberOfOne(int n)
//{
//    int count = 0;
//    int i = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if (((n >> i) & 1) == 1)
//        {
//            count++;
//        }
//    }
//    return count;
//}
//int main()
//{
//    int n = -1;
//    int ret = NumberOfOne(n);
//    printf("%d\n", ret);
//    return 0;
//}
//int main()
//{
//    int m = 0;
//    int n = 0;
//    int i = 0;
//    int count = 0;
//    scanf("%d %d", &m, &n);
//    int ret = m ^ n;
//    for (i = 0; i < 32; i++)
//    {
//        if (((m >> i) & 1) != ((n >> i) & 1))
//        {
//            count++;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}
int main()
{
    int n = 0;
    scanf("%d", &n);
    //打印偶数位
    int i = 0;
    for (i = 31; i >= 1; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    printf("\n");
    //打印奇数位
    for (i = 30; i >= 0; i -= 2)
    {
        printf("%d ", (n >> i) & 1);
    }
    return 0;
}