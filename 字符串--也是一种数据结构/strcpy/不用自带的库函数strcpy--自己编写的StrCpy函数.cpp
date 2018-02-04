// 不用自带的库函数strcpy--自己编写的StrCpy函数
#include <iostream>
#include <assert.h>
char *StrCpy(char *strDest,char *strSrc)
{
	assert((strDest != NULL) && ( strSrc != NULL));	// 假的时候,在stderr终端打印一条错误的信息，并调用abort终止程序
// address + 返回值类型 char * 的组合为了实现链接表达式,返回具体值 int length = strlen(strcpy(strDest,"hello,world"));
	char *adderss = strDest;
	while (*strDest++ = *strSrc++);
	return adderss;	
}

int main(void)
{
	char *s = (char *)malloc(10);
	char *d = (char *)malloc(10);
	s = "12456";
//	StrCpy(s,"hello,world");
	StrCpy(d,s);
	printf("%s\n%s\n", d,s);
	return 0;
}

/*
 * VC6.0调试结果:
12456
12456
Press any key to continue
*/