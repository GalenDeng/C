// 整数字符串转化--直接调用 itoa函数 : itoa(number,string,进制)
#include <iostream>
#include <stdlib.h>

int main()
{
	char str[7];		// 字符数组
	int number = 12345;
	printf("数字为: %d\n",number);
	itoa(number,str,10);
	printf("数字转化为字符串的值为: %s\n", str);
	return 0;
}

/*
 * VC6.0的调试结果:
数字为: 12345
数字转化为字符串的值为: 12345
Press any key to continue
*/