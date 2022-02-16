---
title: 'C语言 - 文件操作'
date: 2022-02-12 13:24:33
tags: [C]
published: true
hideInList: false
feature: /post-images/c-file.png
isTop: false
---
# 1. 什么是文件
磁盘上的文件是文件。
但是在程序设计中，一般谈到的文件有两种：程序文件、数据文件

## 1.1 程序文件
包括源程序文件（后缀为```.c```）,目标文件（windows环境后缀为```.obj```）,可执行程序（windows环境后缀为```.exe```）。

## 1.2 数据文件
文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件。

## 1.3 为什么使用文件
在前面学习结构体时，写了通讯录的程序，当通讯录运行起来的时候，可以给通讯录中增加、删除数据，此时数据是存放在内存中的，当程序退出的时候，通讯录中的数据自然就不存在了，等下次运行通讯录程序的时候，数据又得重新录入。
既然是通讯录就应该把信息记录下来，只有我们自己选择删除数据的时候，数据才会不复存在。这就涉及到了数据持久化的问题，我们一般使数据持久化的方法有，把数据存放在磁盘文件、存放到数据库等方式。
而使用文件我们可以将数据直接存放在电脑的硬盘中，做到了数据的持久化。

# 2. 文件名
一个文件要有一个唯一的文件标识，以便用户识别和引用。
文件名包含3部分：文件路径+文件名主干+文件后缀
例如： ```c:\code\test.txt```
为了方便起见，文件标识常被称为**文件名**。

# 3. 文本文件和二进制文件
根据数据的组织形式，数据文件被称为**文本文件**或者**二进制文件**。
数据在内存中以二进制的形式存储，如果不加转换的输出到外存，就是**二进制文件**。

如果要求在外存上以```ASCII```码的形式存储，则需要在存储前转换。以```ASCII```字符的形式存储的文件就是**文本文件**。
一个数据在内存中是怎么存储的呢？
字符一律以```ASCII```形式存储，数值型数据既可以用```ASCII```形式存储，也可以使用二进制形式存储。
如有整数```10000```，如果以```ASCII```码的形式输出到磁盘，则磁盘中占用```5```个字节（每个字符一个字节），而二进制形式输出，则在磁盘上只占```4```个字节（VS2013测试）。

测试代码：
```
#include <stdio.h>

int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//写文件
	fwrite(&a, sizeof(int), 1, pf);//二进制的形式写到文件中

	//关文件
	fclose(pf);
	pf = NULL;
	return 0;
}
```

# 4. 文件缓冲区

ANSIC 标准采用**缓冲文件系统**处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序中每一个正在使用的文件开辟一块**文件缓冲区**。从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上。如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），然后再从缓冲区逐个地将数据送到程序数据区（程序变量等）。缓冲区的大小根据C编译系统决定的。

# 5. 文件的打开和关闭
## 5.1 文件指针
缓冲文件系统中，关键的概念是```文件类型指针```，简称```文件指针```。
每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等）。这些信息是保存在一个结构体变量中的。该结构体类型是由系统声明的，取名```FILE```。

例如,VS2008编译环境提供的```stdio.h```头文件中有以下的文件类型申明：
```
struct _iobuf
{
	char *_ptr;
	int _cnt;
	char *_base;
	int _flag;
	int _file;
	int _charbuf;
	int _bufsiz;
	char *_tmpfname;
};
typedef struct _iobuf FILE;
```
不同的C编译器的FILE类型包含的内容不完全相同，但是大同小异。
每当打开一个文件的时候，系统会根据文件的情况自动创建一个```FILE```结构的变量，并填充其中的信息，使用者不必关心细节。
一般都是通过一个```FILE```的指针来维护这个```FILE```结构的变量，这样使用起来更加方便。

下面我们可以创建一个```FILE*```的指针变量:
```
FILE* pf;//文件指针变量
```
定义```pf```是一个指向```FILE```类型数据的指针变量。可以使```pf```指向某个文件的文件信息区（是一个结构体变量）。通过该文件信息区中的信息就能够访问该文件。也就是说，**通过文件指针变量能够找到与它关联的文件。**

## 5.2 文件的打开和关闭
文件在读写之前应该先**打开文件**，在使用结束之后应该**关闭文件**。
在编写程序的时候，在打开文件的同时，都会返回一个```FILE*```的指针变量指向该文件，也相当于建立了指针和文件的关系。
ANSIC 规定使用```fopen```函数来打开文件，```fclose```来关闭文件。
```
FILE * fopen ( const char * filename, const char * mode );
int fclose ( FILE * stream );
```
打开方式如下：

| 文件的使用方式 | 含义 | 如果指定文件不存在 |
| :------------| :--- | :--- |
| r（只读） | 为了输入数据，打开一个已经存在的文本文件 | 出错 |
| w（只写） | 为了输出数据，打开一个文本文件 | 建立一个新的文件 |
| a（追加） | 向文本文件尾添加数据 | 出错 |
| rb（只读） | 为了输入数据，打开一个二进制文件 | 出错 |
| wb（只写） | 为了输出数据，打开一个二进制文件 | 建立一个新的文件 |
| ab（追加） | 向一个二进制文件尾添加数据 | 出错 |
| r+（读写） | 为了读和写，打开一个文本文件 | 出错 |
| w+（读写） | 为了读和写，建议一个新的文件 | 建立一个新的文件 |
| a+（读写） | 打开一个文件，在文件尾进行读写 | 建立一个新的文件 |
| rb+（读写） | 为了读和写打开一个二进制文件 | 出错 |
| wb+（读写） | 为了读和写，新建一个新的二进制文件 | 建立一个新的文件 |
| ab+（读写） | 打开一个二进制文件，在文件尾进行读和写 | 建立一个新的文件 |

有如下代码：
```
int main()
{
	FILE* pf = fopen("test.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	
	//关文件
	fclose(pf);
	pf = NULL;
	return 0;
}
```

# 6. 文件的顺序读写

| 功能           | 函数名  | 适用于     |
| -------------- | ------- | ---------- |
| 字符输入函数   | fgetc   | 所有输入流 |
| 字符输出函数   | fputc   | 所有输出流 |
| 文本行输入函数 | fgets   | 所有输入流 |
| 文本行输出函数 | fputs   | 所有输出流 |
| 格式化输入函数 | fscanf  | 所有输入流 |
| 格式化输出函数 | fprintf | 所有输出流 |
| 二进制输入     | fread   | 文件       |
| 二进制输出     | fwrite  | 文件       |

有如下代码：
## 6.1 fgetc & fputc
```
int main()
{
	FILE* pf = fopen("test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	
	//写文件
	//fputc('b', pf);
	//fputc('i', pf);
	//fputc('t', pf);

	//读文件
	int ret = fgetc(pf);
	printf("%c", ret);
	
	//关闭文件
	fclose(pf);
	pf == NULL;
	return 0;
}
```

## 6.2 fputs & fgets
```
//fputs
int main()
{
	FILE* pf = fopen("test.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	fputs("abcdef\n", pf);
	fputs("qwertyuiop\n", pf);
	
	fclose(pf);
	pf == NULL;
	return 0;
}

//fgets
int main()
{
	char arr[10] = "xxxxxxxx";
	FILE* pf = fopen("test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	fgets(arr, 4, pf);
	printf("%s\n", arr);
	fgets(arr, 4, pf);
	printf("%s\n", arr);

	fclose(pf);
	pf = NULL;

	return 0;
}
```

## 6.3 fprintf & fscanf
```
//fprintf
struct S
{
	char arr[10];
	int num;
	float sc;
};

int main()
{
	struct S s = { "abcdef", 10, 5.5f };

	//对格式化的数据进行写文件
	FILE* pf = fopen("test.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//写文件
	fprintf(pf, "%s %d %f", s.arr, s.num, s.sc);

	//关闭文件
	fclose(pf);
	pf = NULL;

	return 0;
}

//fscanf
struct S
{
	char arr[10];
	int num;
	float sc;
};

int main()
{
	struct S s = { 0 };

	FILE* pf = fopen("test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//读文件
	fscanf(pf, "%s %d %f", &(s.arr), &(s.num), &(s.sc));

	//打印
	printf("%s %d %f", s.arr, s.num, s.sc);

	//关闭文件
	fclose(pf);
	pf = NULL;

	return 0;
}
```
## 6.4 fread & fwrite
```
//fwrite
struct S
{
	char arr[10];
	int num;
	float sc;
};

int main()
{
	struct S s = { "abcdef", 10, 5.5 };

	FILE* pf = fopen("test.dat", "w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//写文件
	fwrite(&s, sizeof(struct S), 1, pf);

	//关闭文件
	fclose(pf);
	pf = NULL;

	return 0;
}

//fread
struct S
{
	char arr[10];
	int num;
	float sc;
};

int main()
{
	struct S s = { 0 };

	FILE* pf = fopen("test.dat", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	//读文件
	fread(&s, sizeof(struct S), 1, pf);

	//打印
	printf("%s %d %f", s.arr, s.num, s.sc);

	//关闭文件
	fclose(pf);
	pf = NULL;

	return 0;
}
```

## 6.5 对比一组函数
```
scanf/fscanf/sscanf
scanf - 针对标准输入（键盘）的格式化的输入语句 - stdin
fscanf - 针对所有输入流的格式化的输入语句 - stdin/文件
sscanf - 从一个字符串中读取一个格式化的数据

printf/fprintf/sprintf
printf - 针对标准输出的格式化的输出语句 - stdout
fprintf - 针对所有输出流的格式化的输出语句 - stdout/文件
sprintf - 把一个格式化的数据，转换成字符串
```

对于```sscanf```和```sprintf```，有如下代码：
```
//sprintf
struct S
{
	char arr[10];
	int age;
	float f;
};

int main()
{
	struct S s = { "hello", 20, 5.5f };
	char buf[100] = { 0 };
	sprintf(buf, "%s %d %f", s.arr, s.age, s.f);
	printf("%s\n", buf);
	return 0;
}

//sscanf
struct S
{
	char arr[10];
	int age;
	float f;
};

int main()
{
	struct S s = { "hello", 20, 5.5f };
	struct S tmp = { 0 };

	char buf[100] = { 0 };
	sprintf(buf, "%s %d %f", s.arr, s.age, s.f);
	printf("%s\n", buf);

	//从buf字符串中还原出一个结构体
	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.age), &(tmp.f));
	printf("%s %d %f", tmp.arr, tmp.age, tmp.f);
	return 0;
}
```

# 7. 文件的随机读写
## 7.1 fseek
根据文件指针的位置和偏移量来定位文件指针。
```
int fseek ( FILE * stream, long int offset, int origin );

long int offset有三种选项，分别是：
SEEK_CUR - Current position of file pointer - 当前指针指向的位置
SEEK_END - End of file - 文件的末尾
SEEK_SET - Beginning of file - 文件的开头
```

使用案例：
```
/* fseek example */
#include <stdio.h>

int main()
{
	FILE* pf = fopen("test.txt", "r");//abcdef
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//读取文件
	int ch = fgetc(pf);
	printf("%c\n", ch);//a
	fseek(pf, 2, SEEK_CUR);//向后偏移两个字节
	ch = fgetc(pf);
	printf("%c\n", ch);//d
	ch = fgetc(pf);
	printf("%c\n", ch);//e
	
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}
```

## 7.2 ftell
返回文件指针相对于起始位置的偏移量
```
long int ftell ( FILE * stream );
```

使用案例：
```
/* ftell example : getting size of a file */
#include <stdio.h>

int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//读取文件
	int ch = fgetc(pf);
	printf("%c\n", ch);//a

	//调整文件指针
	fseek(pf, -2, SEEK_END);

	ch = fgetc(pf);
	printf("%c\n", ch);//e
	ch = fgetc(pf);
	printf("%c\n", ch);//f

	//查看偏移量
	int ret = ftell(pf);
	printf("%d\n", ret);//6

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}
```

## 7.3 rewind
让文件指针的位置回到文件的起始位置
```
void rewind ( FILE * stream );
```
使用案例：
```
/* rewind example */
#include <stdio.h>

int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//读取文件
	int ch = fgetc(pf);
	printf("%c\n", ch);//a

	//调整文件指针
	fseek(pf, -2, SEEK_END);
	ch = fgetc(pf);
	printf("%c\n", ch);//e
	ch = fgetc(pf);
	printf("%c\n", ch);//f

	//查看偏移量
	int ret = ftell(pf);
	printf("%d\n", ret);//6

	//让文件指针回到起始位置
	rewind(pf);
	ch = fgetc(pf);
	printf("%c\n", ch);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}
```

# 9. 文件结束判定
牢记：在文件读取过程中，不能用```feof```函数的返回值直接用来判断文件的是否结束。
而是**应用于当文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束。**
1. 文本文件读取是否结束，判断返回值是否为```EOF （fgetc）```，或者```NULL（fgets）```
例如：
```fgetc```判断是否为```EOF```.
```fgets```判断返回值是否为```NULL```.
2. 二进制文件的读取结束判断，判断返回值是否小于实际要读的个数。
例如：
```fread```判断返回值是否小于实际要读的个数。

正确的使用：
```
//把test.txt文件拷贝一份，生成test2.txt文件
int main()
{
	FILE* pfread = fopen("test.txt", "r");
	if (pfread == NULL)
	{
		return 1;
	}

	FILE* pfwrite = fopen("test2.txt", "w");
	if (pfwrite == NULL)
	{
		fclose(pfread);
		pfread = NULL;
		return 1;
	}//文件打开成功

	//读写文件
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF)
	{
		//写文件
		fputc(ch, pfwrite);
	}
	
	//结束结果判定
	if (feof(pfread))
	{
		printf("遇到文件结束表示，文件正常结束\n");
	}
	else if (feof(pfread))
	{
		printf("文件读取失败结束\n");
	}
	
	//关闭文件
	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;
	return 0;
}
```