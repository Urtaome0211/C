//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//
////int main()
////{
////	int i = 0;
////	int count = 0;
////	for (i = 100; i <= 200; i++)
////	{
////		int j = 0;
////		int flag = 1;
////		for (j = 2; j < i; j++)
////		{
////			if (i % j == 0)
////			{
////				flag = 0;
////				break;
////			}
////		}
////		if (flag == 1)
////		{
////			count++;
////			printf("%d ", i);
////		}
////	}
////	printf("\ncount = %d", count);
////	return 0;
////}
//
//int main()
//{
//    int i = 0;
//    int count = 0;
//    for (i = 101; i <= 200; i += 2)
//    {
//        //素数就是质数，只能被1和它本身整除
//        int j = 0;
//        int flag = 1;//假设i就是素数
//        for (j = 2; j <= sqrt(i); j++)
//            //2到i-1的数字去试除，判断是否能被整除
//        {
//            if (i % j == 0)//若能被某个数整除，那它就不是素数
//            {
//                flag = 0;
//                break;
//            }
//        }
//        if (flag == 1)
//        {
//            count++;
//            printf("%d ", i);
//        }
//    }
//    printf("\ncount = %d", count);
//	return 0;
//}