---
title: 'C语言-字符串函数和内存函数'
date: 2022-02-06 20:02:15
tags: [C]
published: true
hideInList: false
feature: /post-images/c-stringfunction.jpeg
isTop: false
---
# 前言
C语言中对字符和字符串的处理很是频繁，但是C语言本身是没有字符串类型的，字符串通常放在常量字符串中或者字符数组中。字符串常量适用于那些对它不做修改的字符串函数。

# 1. 函数介绍
## 1.1 求字符串长度
### 1.1.1 strlen
```
size_t strlen ( const char * str );
```

<font face="微软雅黑">Get the length of a string.
Each of these functions returns the number of characters in string, not including the terminating null character. wcslen is a wide-character version of strlen; the argument of wcslen is a wide-character string. wcslen and strlen behave identically otherwise. </font>


1. 字符串已经```'\0' ```作为结束标志，```strlen```函数返回的是在字符串中```'\0' ```前面出现的字符个数（不包含```'\0' ```)。
2. 参数指向的字符串必须要以```'\0'```结束。
3. 注意函数的返回值为```size_t```，是无符号的（易错）。
4. 学会```strlen```函数的模拟实现。

注：
```
int main()
{
    const char* str1 = "abcdef";
    const char* str2 = "bbb";
    if (strlen(str2) - strlen(str1) > 0)
    {
        printf("str2 > str1\n");
    }
    else
    {
        printf("srt1 > str2\n");
    }
    return 0;
}
```
**上述代码输出值为str2>str1，因为strlen()这个函数的返回值是无符号整数。**
  
## 1.2 长度不受限制的字符串函数
### 1.2.1 strcpy
```
char* strcpy(char * destination, const char * source );
```
<font face="微软雅黑">Copy a string.
The strcpy function copies strSource, including the terminating null character, to the location specified by strDestination. No overflow checking is performed when strings are copied or appended. The behavior of strcpy is undefined if the source and destination strings overlap.

wcscpy and _mbscpy are wide-character and multibyte-character versions of strcpy. The arguments and return value of wcscpy are wide-character strings; those of _mbscpy are multibyte-character strings. These three functions behave identically otherwise.</font>

1. Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point).
2. 源字符串必须以```'\0'``` 结束。
3. 会将源字符串中的```'\0'``` 拷贝到目标空间。
4. 目标空间必须足够大，以确保能存放源字符串。
5. 目标空间必须可变。
6. 学会模拟实现。

使用案例：
```
int main()
{
    char arr1[20] = "########";
    char arr2[] = "hello";
    strcpy(arr1, arr2);
    printf("%s\n", arr1);//hello
    return 0;
}
```
  
### 1.2.2 strcat
```
char * strcat ( char * destination, const char * source );
```
<font face="微软雅黑">Append a string.
The strcat function appends strSource to strDestination and terminates the resulting string with a null character. The initial character of strSource overwrites the terminating null character of strDestination. No overflow checking is performed when strings are copied or appended. The behavior of strcat is undefined if the source and destination strings overlap.

wcscat and _mbscat are wide-character and multibyte-character versions of strcat. The arguments and return value of wcscat are wide-character strings; those of _mbscat are multibyte-character strings. These three functions behave identically otherwise.</font>

1. Appends a copy of the source string to the destination string. The terminating null character in
destination is overwritten by the first character of source, and a null-character is included at the end of
the new string formed by the concatenation of both in destination.
2. 源字符串必须以```'\0'``` 结束。
3. 目标空间必须有足够的大，能容纳下源字符串的内容。
4. 目标空间必须可修改。
5. 字符串自己给自己追加?（不可，若要实现，请使用strncat()函数）
   
使用案例：
```
int main()
{
    char arr1[20] = "hello ";
    char arr2[] = "world";
    strcat(arr1, arr2);
    printf("%s\n", arr1);//hello world
    return 0;
}
```
  
### 1.2.3 strcmp
```
int strcmp( const char *string1, const char *string2 );
```

<font face="微软雅黑">Compare strings.
The strcmp function compares string1 and string2 lexicographically and returns a value indicating their relationship. wcscmp and _mbscmp are wide-character and multibyte-character versions of strcmp. The arguments and return value of wcscmp are wide-character strings; those of _mbscmp are multibyte-character strings. _mbscmp recognizes multibyte-character sequences according to the current multibyte code page and returns _NLSCMPERROR on an error. (For more information, see Code Pages.) These three functions behave identically otherwise.</font>

1. This function starts comparing the first character of each string. If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.
2. 第一个字符串大于第二个字符串，则返回大于0的数字
3. 第一个字符串等于第二个字符串，则返回0
4. 第一个字符串小于第二个字符串，则返回小于0的数字
5. 那么如何判断两个字符串？

比较对应字符ASCII码值
使用案例：
```
int main()
{
    int ret = strcmp("abbb", "abq");
    printf("%d\n", ret );//-1
    return 0;
}
```

## 1.3 长度受限制的字符串函数介绍
### 1.3.1 strncpy
```
char * strncpy ( char * destination, const char * source, size_t num );
```

1. Copies the first num characters of source to destination. If the end of the source C string (which is signaled by a null-character) is found before num characters have been copied, destination is padded with zeros until a total of num characters have been written to it.
2. 拷贝num个字符从源字符串到目标空间。
3. 如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后边追加0，直到num个。

使用案例：
```
int main()
{
    char arr1[20] = "abcdef";
    char arr2[] = "qwer";
    strncpy(arr1, arr2, 2);
    printf("%s\n", arr1);//qwcdef - 覆盖前两个字符
    return 0;
}
```
### 1.3.2 strncat
```
char * strncat ( char * destination, const char * source, size_t num );
```
1. Appends the first num characters of source to destination, plus a terminating null-character.
2. If the length of the C string in source is less than num, only the content up to the terminating nullcharacter is copied.

使用案例：
```
int main()
{
    char arr1[20] = "hello ";
    char arr2[] = "world";
    strncat(arr1, arr2, 3);
    printf("%s\n", arr1);//hello wor
    return 0;
}
```

### 1.3.3 strncmp
```
int strncmp ( const char * str1, const char * str2, size_t num );
```
使用案例：
```
#include <stdio.h>
#include <string.h>

int main ()
{
    char* p = "abcdef";
    char* q = "abcdefqwert";
    int ret = strncmp(p, q, 3);//最后一个参数是比较的字符数
    printf("%d\n", ret);//0
    return 0;
}
```
**比较到出现另个字符不一样或者一个字符串结束或者num个字符全部比较完。**

## 1.4 字符串查找
### 1.4.1 strstr
```
char * strstr ( const char *, const char * );
```
Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.在一个字符串中找另一个字符串。

使用案例：
```
#include <stdio.h>
#include <string.h>

int main ()
{
    char arr1[] = "abcdefabcdef";
    char arr2[] = "bcd";
    char* ret = strstr(arr1, arr2);
    if (ret == NULL)
    {
        printf("没找到\n");
    }
    else
    {
        printf("找到了：%s\n", ret);
    }
    return 0;
}
```

### 1.4.2 strtok
```
char * strtok ( char * str, const char * sep );
```

1. sep参数是个字符串，定义了用作分隔符的字符集合。
2. 第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
3. strtok函数找到str中的下一个标记，并将其用\0 结尾，返回一个指向这个标记的指针。（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
4. strtok函数的第一个参数不为NULL ，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
5. strtok函数的第一个参数为NULL ，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
6. 如果字符串中不存在更多的标记，则返回NULL 指针。

使用案例：
```
#include <stdio.h>
#include <string.h>

int main ()
{
    char arr[] = "admin@urtaome.com";
    char* ret = NULL;

    ret = strtok(arr, "@.");
    printf("%s\n", ret);

    ret = strtok(arr, "@.");
    printf("%s\n", ret);

    ret = strtok(arr, "@.");
    printf("%s\n", ret);
    return 0;
}
```
但是上述代码存在冗余，可以改成这样：
```
#include <stdio.h>
#include <string.h>

int main ()
{
    char arr[] = "admin@urtaome.com";
    char* ret = NULL;

    for(ret = strtok(arr, "@."); ret != NULL; ret = strtok(NULL, "@."))
    {
        printf("%s\n", ret);
    }
    return 0;
}
```

## 1.5 错误信息报告
### 1.5.1 strerror
```
char * strerror ( int errnum );
```
使用示例：
```
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
    printf("%s\n", strerror(0));
    printf("%s\n", strerror(1));
    printf("%s\n", strerror(2));
    printf("%s\n", strerror(3));
    printf("%s\n", strerror(4));
    printf("%s\n", strerror(5));
    return 0;
}

输出值为：
No error
Operation not permitted
No such file or directory
No such process
Interrupted function call
Input/output error
```

## 1.6 内存操作函数
### 1.6.1 memcpy
```
void * memcpy ( void * destination, const void * source, size_t num );
```
1. 函数```memcpy```从```source```的位置开始向后复制```num```个字节的数据到```destination```的内存位置。
2. 这个函数在遇到```'\0'``` 的时候并不会停下来。
3. 如果```source```和```destination```有任何的重叠，复制的结果都是未定义的。

使用案例：
```
int main()
{
    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int arr2[10] = { 0 };

    memcpy(arr2, arr1, 20);
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr2[i]);//1 2 3 4 5
    }
    return 0;
}
```
### 1.6.2 memmove
```
void * memmove ( void * destination, const void * source, size_t num );
```

1. 和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
2. 如果源空间和目标空间出现重叠，就得使用memmove函数处理。

使用案例：
```
int main()
{
    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
    memmove(arr1 + 2, arr1, 20);
    return 0;
}
```
上述代码经过调试可发现，可以处理内存重叠的情况
![memmovedebug.png](https://s2.loli.net/2022/02/09/CPJ8uViWyBGFlOS.png)

### 1.6.3 memset
```
void *memset( void *dest, int c, size_t count );
```
使用案例：
```
int main()
{
    int arr[10] = { 0 };
    memset(arr, 1, 20);//将前20个字节全部设置成1
    return 0;
}
```
通过调试发现，memset实现了将前20个字节设置成了1.
![memsetdebug.png](https://s2.loli.net/2022/02/09/lGq9PJgTiuM4KZ8.png)

### 1.6.4 memcmp
```
int memcmp ( const void * ptr1, const void * ptr2, size_t num );
```
**比较从ptr1和ptr2指针开始的num个字节**
返回值如下：
```
Return Value            Relationship of First count Bytes of buf1 and buf2 
< 0                             buf1 less than buf2 
= 0                             buf1 identical to buf2 
> 0                             buf1 greater than buf2 
```

使用案例：
```
int main()
{
    float arr1[] = {1.0, 2.0, 3.0, 4.0};
    float arr2[] = {1.0, 3.0};
    int ret = memcmp(arr1, arr2, 4);
    printf("%d\n", ret);
    return 0;
}
```

# 2. 库函数模拟实现
## 2.1 模拟实现strlen
```
#include<stdio.h>
#include<assert.h>

int my_strlen(const char *str)
{
    assert(str != NULL);
    int count = 0;
    while (*str != '\0')
    {
        //如果指针指向的字符不是\0，每循环一次就自增
        count++;
        str++;
    }
    //当跳出循环时，返回值
    return count;
}

int main()
{
    char arr[] = "abc";
    int len = my_strlen(arr);
    printf("%d\n", len);
    return 0;
}
```
## 2.2 模拟实现strcpy
```
void my_strcpy(char* dest, char* src)
{
    while (*src != '\0')//不能被拷贝\0
    {
        *dest = *src;
        dest++;
        src++;
        //*dest++ = *src++;
    }
    *dest = *src;//拷贝\0
}

int main()
{
    char arr1[20] = "xxxxxxxxxxx";
    char arr2[] = "hello";
    my_strcpy(arr1, arr2);
    printf("%s\n", arr1);
    return 0;
}
```
可将函数优化为：
```
void my_strcpy(char* dest, char* src)
{
    while (*dest++ = *src++)
    {
       ;
    }
}
```
## 2.3 模拟实现strcat
```
#include<stdio.h>
#include<assert.h>

char* my_strcat(char* dest, const char* src)
{
    char* ret = dest;
    assert(dest && src);
    //1. 找到目标字符串中的\0
    while(*dest != '\0')
    {
        dest++;
    }

    //2. 原数据追加过去， 包含\0
    while (*dest++ = *src++)
    {
        ;
    }
    return ret;
}

int main()
{
    char arr1[20] = "hello ";
    char arr2[] = "world";
    printf("%s\n", my_strcat(arr1, arr2));
    return 0;
}
```
## 2.4 模拟实现strstr
```
#include<stdio.h>
#include<assert.h>

char* my_strstr(const char* str1, const char* str2)
{
    assert(str1 && str2);
    const char* s1 = str1;
    const char* s2 = str2;
    const char *cp = str1;

    if (*str2 == '\0')
    {
        //NULL与\0不一样
        return (char*)str1;
    }

    while (*cp != '\0')
    {
        //当匹配失败时，回退到开始匹配的起始地址
        s1 = cp;
        s2 = str2;
        
        //若s1和s2都不为\0，且为相同字符时，开始查找
        //防止字符同为\0
        while(*s1 && *s2 && (*s1 == *s2))
        {
            //每循环一次就自增
            s1++;
            s2++;
        }

        if (*s2 == '\0')
        {
            return (char*)cp;
            //若查找s2的字符为\0，则返回相同字符的起始地址
        }
        //如果匹配不成功，回退地址自增并再次开始循环匹配
        cp++;
    }
    return NULL;
    //若找不到，返回空指针
}

int main ()
{
    char arr1[] = "abcdefabcdef";
    char arr2[] = "bcd";
    char* ret = my_strstr(arr1, arr2);
    if (ret == NULL)
    {
        printf("没找到\n");
    }
    else
    {
        printf("找到了：%s\n", ret);
    }
    return 0;
}
```
## 2.5 模拟实现strcmp
```
#include<stdio.h>
#include<assert.h>

int my_strcmp(const char* s1, const char* s2)
{
    assert(s1 && s2);
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
        {
            //若相等，返回0
            return 0;
        }
        s1++;
        s2++;
    }

    //比较ACSII码值，返回一个大于0或者小于0的数字
    return *s1 - *s2;
}

int main()
{
    char* p= "abcdef";
    char* q = "abbb";
    int ret = my_strcmp(p, q);
    if (ret > 0)
    {
        printf("p > q\n");
    }
    else if (ret < 0)
    {
        printf("p < q\n");
    }
    else
    {
        printf("p == q\n");
    }
    return 0;
}
```
## 2.6 模拟实现memcpy
```
void* my_memcpy(void* dest, const void* src, unsigned int num)
{
    void* ret = dest;
    assert(dest && src);
    while (num--)
    {
        *(char*)dest = *(char*)src;
        dest = (char*)dest + 1;
        src = (char*)src + 1;
    }
    return dest;
}

int main()
{
    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int arr2[10] = { 0 };

    my_memcpy(arr2, arr1, 20);
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr2[i]);//1 2 3 4 5
    }
    return 0;
}
```
## 2.7 模拟实现memmove
```
void* my_memmove(void* dest, const void* src, unsigned int num)
{
    void* ret = dest;
    assert(dest && src);
    if (dest < src)
    {
        //从前向后拷贝
        while (num--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src = (char*)src + 1;
        }
    }
    else
    {
        //从后向前拷贝
        while (num--)
        {
            *((char*)dest + num) = *((char*)src + num);
        }
    }
    return ret;
}

int main()
{
    int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
    my_memmove(arr1 + 2, arr1, 20);

    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}
```