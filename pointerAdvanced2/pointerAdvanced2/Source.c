#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void print(int* p, int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", *(p + i));
//    }
//}
//
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int* p = arr;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    //一级指针p，传给函数
//    print(p, sz);
//    return 0;
//}
//void test(int** ptr)
//{
//    printf("num = %d\n", **ptr);
//}
//
//int main()
//{
//    int n = 10;
//    int* p = &n;
//    int** pp = &p;
//    test(pp);
//    test(&p);
//    return 0;
//}
//void test()
//{
//    printf("hehe\n");
//}
//
//int main()
//{
//    printf("%p\n", test);
//    printf("%p\n", &test);
//    return 0;
//}
//int Add(int x, int y)
//{
//    return x + y;
//}
//
//int main()
//{
//    int (*pf)(int, int) = &Add;
//    int ret = (*pf)(3, 5);
//    printf("%d", ret);
//    return 0;
//}
//void menu()
//{
//    printf("*******************************\n");
//    printf("*******1. add     2. sub*******\n");
//    printf("*******3. mul     4. div*******\n");
//    printf("*******      0.exit     *******\n");
//    printf("*******************************\n");
//}
//
//int add(int a, int b)
//{
//    return a + b;
//}
//int sub(int a, int b)
//{
//    return a - b;
//}
//int mul(int a, int b)
//{
//    return a * b;
//}
//int div(int a, int b)
//{
//    return a / b;
//}
//
//int main()
//{
//    int input = 0;
//    do
//    {
//        menu();
//        int (*pfArr[5])(int, int) = { NULL, add, sub, mul, div };
//        int x = 0;
//        int y = 0;
//        int ret = 0;
//        printf("请选择：");
//        scanf("%d", &input);
//        if (input >= 1 && input <= 4)
//        {
//            printf("请输入两个操作数：");
//            scanf("%d %d", &x, &y);
//            ret = (pfArr[input])(x, y);
//            printf("ret = %d\n", ret);
//        }
//        else if (input == 0)
//        {
//            printf("退出程序\n");
//            break;
//        }
//        else
//        {
//            printf("选择错误，重新选择！\n");
//        }
//    } while (input);
//    return 0;
//}
void menu()
{
    printf("*******************************\n");
    printf("*******1. add     2. sub*******\n");
    printf("*******3. mul     4. div*******\n");
    printf("*******      0.exit     *******\n");
    printf("*******************************\n");
}

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int div(int a, int b)
{
    return a / b;
}

int Calc(int (*pf)(int, int))
{
    int x = 0;
    int y = 0;
    printf("请输入两个操作数：");
    scanf("%d %d", &x, &y);
    return pf(x, y);

}

int main()
{
    int input = 0;
    do
    {
        menu();
        int ret = 0;
        
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            ret = Calc(add);
            printf("ret = %d\n", ret);
            break;
        case 2:
            ret = Calc(sub);
            printf("ret = %d\n", ret);
            break;
        case 3:
            ret = Calc(mul);
            printf("ret = %d\n", ret);
            break;
        case 4:
            ret = Calc(div);
            printf("ret = %d\n", ret);
            break;
        case 0:
            printf("退出程序\n");
            break;
        default:
            printf("选择错误，重新选择\n");
            break;
        }
    } while (input);
    return 0;
}