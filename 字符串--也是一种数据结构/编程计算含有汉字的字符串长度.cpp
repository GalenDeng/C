// 编程计算含有汉字的字符串长度
// 编写gbk_strlen函数,计算含有汉字的字符串的长度，汉字作为一个字符处理；
// 已知: 汉字编码为双字节，其中首字节 < 0, 尾字节在 0 ~ 63 以外 ( 如果
// 一个字节是 -128 ~ 127)
/*
 * 实例:
 12345中国6787加油 的字符串长度为:
 13
*/
#include <stdio.h>

int gbk_strlen(const char *str)
{
	const char *p;	// 用来作遍历之用
	if ( NULL == str) {
		return -1;		// 检测字符指针的有效性
	}

	p = str;

	// 遍历
	while (*p) {
		if ( (*p) < 0 && ( *(p+1) < 0) || *(p+1) > 63) {		// 汉字编码的字符数值情况
			str++;
			p += 2;												// p - str 来达到一个汉字当作一个字符来处理
		} else {
			p++;
		}
	}

	return (p-str);
}

int main(void)
{
	char str[] = "12345中国6787加油";
	int len = gbk_strlen(str);
	printf("%s 的字符串长度为: \n%d\n", str,len);
	return 0;
}

/*
 * VC6.0调试结果:
12345中国6787加油 的字符串长度为:
13
Press any key to continue
*/