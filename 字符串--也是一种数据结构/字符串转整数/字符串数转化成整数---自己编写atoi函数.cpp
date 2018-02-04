// 字符串数转化成整数
// 思想: 字符串 - '0' 再累加 
#include <iostream>

void Atoi(char *str,int &number)			// number 为 主函数中 number的引用,即 主函数的number的别名 --- 实参
{
	int sum = 0;
	while(*str) {							// 判*str是否为空
		sum = sum * 10 + ((*str++) - '0');	// 字符减'0'再累加得结果
	}

	number = sum;
}

int main(void)
{
	int number;
	char str[7] = { '1','2','3','4','5','6','\0'};
	printf("字符串为: %s\n",str);
	Atoi(str,number);
	printf("字符串转化的数字为: %d\n",number);
	return 0;
}

/*
 * VC6.0调试结果:
字符串为: 123456
字符串转化的数字为: 123456
Press any key to continue
*/