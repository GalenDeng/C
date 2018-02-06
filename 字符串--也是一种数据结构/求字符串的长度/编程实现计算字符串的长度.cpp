// 编程实现计算字符串的长度
#include <stdio.h>

// 字符串较长时,效率较低
int StrLen1(const char *str)
{
	int len = 0;

	if (str == NULL) {		// 检验str的有效性
		return NULL;
	}

	while (*str++ != '\0') {	// 循环一次,二次自增
		len++;
	}

	return len;
}

// 字符串较长时,效率较高
int StrLen2(const char *str)
{
	if (str == NULL) {
		return NULL;
	}

	const char *temp = str;		// 局部指针变量ptr , 指向 str
	while (*str++ != '\0');	
	return (str-temp-1);		// str - 1 - temp : 字符串长度	
}

int main()
{
	char str[] = "1234567";
    printf("StrLen1 len: %d\n", StrLen1(str));
	printf("StrLen2 len: %d\n", StrLen2(str));
	return 0;
}

/*
 * VC6.0调试结果:
StrLen1 len: 7
StrLen2 len: 7
Press any key to continue
*/