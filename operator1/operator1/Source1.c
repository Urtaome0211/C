#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//int main()
//{
//    int flag = 5;
//    if (flag)
//    {
//        //flagΪ�棬��ӡhehe
//        printf("hehe\n");
//    }
//    if (!flag)
//    {
//        //flagΪ�٣���ӡhaha
//        printf("haha\n");
//    }
//    return 0;
////}
//int main()
//{
//    int a = 10;
//    char arr[10] = { 0 };
//    printf("%d\n", sizeof(a));//����a��ռ�ռ�Ĵ�С
//    printf("%d\n", sizeof(arr));
//    return 0;
////}
//int main()
//{
//    int a = 10;
//    int b = a++;//����++����ʹ�ã�������1
//    //int b = ++a;//ǰ��++��������1����ʹ��
//    printf("%d\n", a);//11
//    printf("%d\n", b);//10
//    return 0;
////}
//int main()
//{
//    int a = 10;
//    int b = a--;//����--����ʹ�ã����Լ�1
//    //int b = --a;//ǰ��--�����Լ�1����ʹ��
//    printf("%d\n", a);//10
//    printf("%d\n", b);//9
//    return 0;
//}
//int main()
//{
//    int a = 10;
//    printf("%p\n", &a);//&ȡ��ַ������
//    return 0;
////}
//int main()
//{
//    int a = 10;
//    printf("%p\n", &a);//&ȡ��ַ������
//    int* pa = &a;
//    //pa����������ڴ浥Ԫ�ĵ�ַ - pa����һ��ָ�����
//    //ָ��Ķ����������int
//    *pa = 20;//�����ò����� - ���߽м�ӷ��ʲ�����
//    printf("%d\n", a);
//    return 0;
////}
//
//int main()
//{
//    int a = (int)3.14;
//    //��3.14ǿ��ת����int����
//    printf("%d\n", a);
//    return 0;
////}
//int main()
//{
//    int i = 0, a = 0, b = 2, c = 3, d = 4;
//    //i = a++ && ++b && d++;
//    i = a++ || ++b || d++;
//    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//    return 0;
//    //�������������ʲô��
//}
//
//int main()
//{
//    int a = 5;
//    int b = 0;
//
//    //��Ŀ������
//    //a����5���������5��������ֵ��Ϊ-1������b
//    b = a > 5 ? 1 : -1;
//    printf("%d\n", b);
//    return 0;
//}
int main()
{
    int a = 3;
    int b = 5;
    int c = 0;
    int d = (c = 5, a = c + 3, b = a - 4, c += 5);
    printf("%d\n", d);
    return 0;
}