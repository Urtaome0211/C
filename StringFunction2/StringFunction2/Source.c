#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>

//int main()
//{
//    printf("%s\n", strerror(0));
//    printf("%s\n", strerror(1));
//    printf("%s\n", strerror(2));
//    printf("%s\n", strerror(3));
//    printf("%s\n", strerror(4));
//    printf("%s\n", strerror(5));
//    return 0;
//}

//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//	memcpy(arr2, arr1, 20);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	
//	return 0;
//}

//void* my_memcpy(void* dest, const void* src, unsigned int num)
//{
//    void* ret = dest;
//    assert(dest && src);
//    while (num--)
//    {
//        *(char*)dest = *(char*)src;
//        dest = (char*)dest + 1;
//        src = (char*)src + 1;
//    }
//    return dest;
//}
//
//int main()
//{
//    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int arr2[10] = { 0 };
//
//    my_memcpy(arr2, arr1, 20);
//    int i = 0;
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr2[i]);//1 2 3 4 5
//    }
//    return 0;
//}

//int main()
//{
//    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//    memmove(arr1 + 2, arr1, 20);
//    return 0;
//}
//void* my_memmove(void* dest, const void* src, unsigned int num)
//{
//    void* ret = dest;
//    assert(dest && src);
//    if (dest < src)
//    {
//        //从前向后拷贝
//        while (num--)
//        {
//            *(char*)dest = *(char*)src;
//            dest = (char*)dest + 1;
//            src = (char*)src + 1;
//        }
//    }
//    else
//    {
//        //从后向前拷贝
//        while (num--)
//        {
//            *((char*)dest + num) = *((char*)src + num);
//        }
//    }
//    return ret;
//}
//
//int main()
//{
//    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//    //my_memmove(arr1 + 2, arr1, 20);
//    my_memmove(arr1, arr1 + 2, 20);
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//    return 0;
//}

//int main()
//{
//    float arr1[] = { 1.0, 2.0, 3.0, 4.0 };
//    float arr2[] = { 1.0, 3.0 };
//    int ret = memcmp(arr1, arr2, 4);
//    printf("%d\n", ret);
//    return 0;
//}

int main()
{
    int arr[10] = { 0 };
    memset(arr, 1, 20);//将前20个字节全部设置成1
    return 0;
}