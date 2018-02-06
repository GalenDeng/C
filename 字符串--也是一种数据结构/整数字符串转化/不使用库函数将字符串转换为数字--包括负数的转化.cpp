// 不使用库函数将字符串转换为数字--包括负数的转化
#include <stdio.h>
#include <stdlib.h>

int str2int(const char *str)
{
	int temp=0,i=0;			// temp 为 number 的绝对值
	if (str == NULL) {		// 确保str的有效性
		return NULL;
	}

	const char *ptr = str;	// 保存str的首地址

	if (*str == '-' || *str == '+') {
		str++;				// 判断如果是负数或者整数有显示正号的话,我们忽略它,并移向下一个字符
	}

	while(str) {
		if (*str < '0' || *str > '9') {		// 如果当前不是数字的话,退出循环
			break;
		}

		temp = temp*10 + (*str++ - '0') ;	// 获取字符串转化后的整数
	}

	if (*ptr == '-') {
		temp = -temp;		// 为负数的时候要取反得到转化后的整数
	}

	return temp;
}

int main(void)
{
	int number =0;
	char str[30] = "-12345";
	printf("原字符串为: %s\n", str);
	number = str2int(str);
	printf("字符串转化为数字为: %d\n", number);
	return 0;
}

/*
 * VC6.0调试结果:
原字符串为: -12345
字符串转化为数字为: -12345
Press any key to continue
*/
			