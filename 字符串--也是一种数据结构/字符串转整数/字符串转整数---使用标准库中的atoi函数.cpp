// 字符串转整数---使用标准库中的atoi函数
#include <iostream>
#include <stdlib.h>
int main(void)
{
	int number;
	char str[7] = { '1','2','3','4','5','6','\0'};
	printf("字符串为: %s\n",str);
	number = atoi(str);				// 标准库中的 atoi函数
	printf("字符串转化的数字为: %d\n",number);
	return 0;
}

/*
 *
字符串为: 123456
字符串转化的数字为: 123456
Press any key to continue
*/