#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
		//getchar从键盘获取标准字符，为int类型
		//读取正确时返回ACSII值
		//若错误返回EOF
		//EOF-end of file文件结束标志
		putchar(ch);
		//输出一个字符
	printf("%c\n", ch);
	return 0;
}