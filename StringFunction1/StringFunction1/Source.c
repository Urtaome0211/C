#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//int my_strlen(const char* str)
//{
//    assert(str != NULL);
//    int count = 0;
//    while (*str != '\0')
//    {
//        count++;
//        str++;
//    }
//    return count;
//}
//
//int main()
//{
//    char arr[] = "abc";
//    //char arr[] = { 'a', 'b', 'c' };
//    int len = my_strlen(arr);
//    printf("%d\n", len);
//    return 0;
//}

//char* my_strcat(char* dest, const char* src)
//{
//    char* ret = dest;
//    assert(dest && src);
//    //1. 找到目标字符串中的\0
//    while (*dest != '\0')
//    {
//        dest++;
//    }
//
//    //2. 原数据追加过去， 包含\0
//    while (*dest++ = *src++)
//    {
//        ;
//    }
//    return ret;
//}
//
//int main()
//{
//    char arr1[20] = "hello ";
//    char arr2[] = "world";
//    printf("%s\n", my_strcat(arr1, arr2));
//    return 0;
//}
//int my_strcmp(const char* s1, const char* s2)
//{
//    while (*s1 == *s2)
//    {
//        if (*s1 == '\0')
//        {
//            return 0;
//        }
//        s1++;
//        s2++;
//    }
//
//    return *s1 - *s2;
//}
//
//int main()
//{
//    char* p = "abcdef";
//    char* q = "abqb";
//    int ret = my_strcmp(p, q);
//    if (ret > 0)
//    {
//        printf("p > q\n");
//    }
//    else if (ret < 0)
//    {
//        printf("p < q\n");
//    }
//    else
//    {
//        printf("p == q\n");
//    }
//    return 0;
//}

//int main()
//{
//    char arr1[20] = "abcdef";
//    char arr2[] = "qwer";
//    strncpy(arr1, arr2, 2);
//    printf("%s\n", arr1);//hello
//    return 0;
//}

//int main()
//{
//    char arr1[20] = "hello ";
//    char arr2[] = "world";
//    strncat(arr1, arr2, 3);
//    printf("%s\n", arr1);//hello wor
//    return 0;
//}

//int main()
//{
//    char* p = "abcdef";
//    char* q = "abcdefqwert";
//    int ret = strncmp(p, q, 3);
//    printf("%d\n", ret);//1
//    return 0;
//}
//int main()
//{
//    char arr1[] = "abcdefabcdef";
//    char arr2[] = "bcd";
//    char* ret = strstr(arr1, arr2);
//    if (ret == NULL)
//    {
//        printf("没找到\n");
//    }
//    else
//    {
//        printf("找到了：%s\n", ret);
//    }
//    return 0;
//}

//char* my_strstr(const char* str1, const char* str2)
//{
//    assert(str1 && str2);
//    const char* s1 = str1;
//    const char* s2 = str2;
//    const char* cp = str1;
//
//    while (*cp != '\0')
//    {
//        s1 = cp;//记录起始地址，来实现回退
//        s2 = str2;
//
//        if (*str2 == '\0')
//        {
//            return (char*)str1;
//        }
//
//        while (*s1 && *s2 && (*s1 == *s2))
//        {
//            s1++;
//            s2++;
//        }
//        if (*s2 == '\0')
//        {
//            //找到了
//            return (char*)cp;
//        }
//        cp++;
//    }
//    return NULL;//没找到
//}
//
//int main()
//{
//    char arr1[] = "abbbcdef";
//    char arr2[] = "k";
//    char* ret = my_strstr(arr1, arr2);
//    if (ret == NULL)
//    {
//        printf("没找到\n");
//    }
//    else
//    {
//        printf("找到了：%s\n", ret);
//    }
//    return 0;
//}

//int main()
//{
//    char arr[] = "admin@urtaome.com";
//    char* ret = NULL;
//    ret = strtok(arr, "@.");
//    printf("%s\n", ret);
//
//    ret = strtok(NULL, "@.");
//    printf("%s\n", ret);
//
//    ret = strtok(NULL, "@.");
//    printf("%s\n", ret);
//    return 0;
//}

int main()
{
    char arr[] = "admin@urtaome.com";
    char* ret = NULL;

    for (ret = strtok(arr, "@."); ret != NULL; ret = strtok(NULL, "@."))
    {
        printf("%s\n", ret);
    }
    return 0;
}