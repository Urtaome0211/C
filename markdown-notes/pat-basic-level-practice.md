---
title: 'PAT (Basic Level) Practice'
date: 2021-12-15 18:02:33
tags: [C]
published: true
hideInList: false
feature: /post-images/pat-basic-level-practice.jpeg
isTop: false
---
# 1001 害死人不偿命的(3n+1)猜想
[题目来源](https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528)
实现代码如下：
```
#include<stdio.h>
int main()
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    while(n > 1)
    {
        if(n%2 == 0)
        {
            n = n/2;
        }
        else
        {
            n=(3*n+1)/2;
        }
        i++;
    }
    printf("%d\n", i);
    return 0;
}
```