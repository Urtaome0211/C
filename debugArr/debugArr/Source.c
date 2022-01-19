#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

//char* my_strcpy(char* dest, const char* src)
//{
//    assert(src != NULL);
//    assert(dest != NULL);//断言
//    char* ret = dest;
//    while (*dest++ = *src++)
//    {
//        ;
//    }
//    return ret;//返回目标空间的起始地址
//}
//
//int main()
//{
//    char arr1[20] = "xxxxxxxxxxx";
//    char arr2[] = "hello";
//    
//    printf("%s\n", my_strcpy(arr1, arr2));
//    return 0;
//}
size_t my_strlen(const char* str)
{
    assert(str != NULL);//断言
    //assert(str);
    size_t count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
int main()
{
    char arr[] = "abc";
    int len = my_strlen(arr);
    printf("%d\n", len);
    return 0;
}