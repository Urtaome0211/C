#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void bubble_sort(int arr[], int sz)//ָ�룬�βθı�ʵ��
//{
//    int i = 0;
//    for (i = 0; i < sz - 1; i++)//ȷ������
//    {
//        int j = 0;
//        for (j = 0; j < sz - 1 - i; j++)
//            //һ��ð������Ĺ���
//            //ʮ��Ԫ�أ�Ҫ�ܾ��ˣ��а˶�����Ҫ��
//            //����ѭ������Ϊsz - 1 - i
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//                //��ǰ��һ�������ں���һ���������ཻ��
//            }
//        }
//    }
//}
//
//int main()
//{
//    int i = 0;
//    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    bubble_sort(arr, sz);//arr����ȥ������Ԫ�ص�ַ
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);//��ӡ����������0 1 2 3 4 5 6 7 8 9
//    }
//    return 0;
//}

//void print_arr(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//void cmp_int(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//    int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    qsort(arr, sz, sizeof(arr[0]), cmp_int);
//    print_arr(arr, sz);
//    return 0;
//}
//struct Stu
//{
//    char name[20];
//    int age;
//};
//
//int sort_by_age(const void* e1, const void* e2)
//{
//    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//    return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//int main()
//{
//    struct Stu s[3] = { {"zhangsan", 30},{"lisi", 34},{"wangwu", 20} };
//    int sz = sizeof(s) / sizeof(s[0]);
//    //qsort(s, sz, sizeof(s[0]), sort_by_age);
//    qsort(s, sz, sizeof(s[0]), sort_by_name);
//    return 0;
//}
//int Swap(char* buf1, char* buf2, int width)
//{
//    int i = 0;
//    for (i = 0; i < width; i++)
//    {
//        char tmp = *buf1;
//        *buf1 = *buf2;
//        *buf2 = tmp;
//        buf1++;
//        buf2++;
//    }
//}
//
//void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
//{
//    int i = 0;
//    for (i = 0; i < sz - 1; i++)
//    {
//        //����
//        int j = 0;
//        for (j = 0; j < sz - 1 - i; j++)
//        {
//            //�Ƚ�
//            if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//            {
//                //����
//                Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//            }
//        }
//    }
//}
//
//void cmp_int(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//void print_arr(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//void test()
//{
//    int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//    print_arr(arr, sz);
//}
//
//int main()
//{
//    test();
//    return 0;
//}
int main()
{
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a + 0));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(a[1]));
	printf("%d\n", sizeof(&a));
	printf("%d\n", sizeof(*&a));
	printf("%d\n", sizeof(&a + 1));
	printf("%d\n", sizeof(&a[0]));
	printf("%d\n", sizeof(&a[0] + 1));
	return 0;
}