// 编程实现strcpy函数的功能--完整
#include <stdio.h>
#include <stdlib.h>

char *StrCpy(char *strDest,const char *strSrc)	// 传入的参数不会被函数修改的,应该加上关键字 const
{// 返回值类型 char * => 为了实现链式表达式,通过这种链式表达式来同时做两个操作 => 调用方便,程序结构简洁

	char *strDestCpy = strDest;
	if (strDest == NULL || strSrc == NULL) {
		return NULL;						// 判断strDest,strSrc的有效性(初始化成功了吗?会是野指针)
	}
	while((*strDest++ = *strSrc++)!= 0);			// strSrc的字符串复制到strDest里
	return strDestCpy;
}

int GetStrLen(const char *strSrc)
{
	int len=0;			// 记得初始化
	while(*strSrc++ != '\0') {
		len++;
	}
	return len;			// 字符串的长度
}

int main(void)
{
	int len = 0;
	char str1[30] = "123456";
	char str2[30];
	printf("str1的值为: %s\n", str1);
    len = GetStrLen(StrCpy(str2,str1));			// 体现 StrCpy的返回值类型 char * 的好处
									// 链式表达式 => 同时进行两个操作 => 调用方便,程序结构简洁
	printf("str2的值为: %s\n", str2);
	printf("str2的长度为:%d\n", len);
	return 0;
}	

/*
 * VC6.0调试结果:
str1的值为: 123456
str2的值为: 123456
str2的长度为:6
Press any key to continue
*/	