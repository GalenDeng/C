// 整数 => 字符串转化
// 思想: 整数基数 + '0' => 变字符串和整数的数字相同的值
#include <iostream>

void Itoa(int number,char *str)
{
	int i = 0,j = 0;
	char  temp[7];
	while (number) {
		temp[i++] = number % 10 + '0';	// 取个位上的数字,通过加'0'隐性转为为char类型
		number = number / 10;
	}

	temp[i] = '\0';	// 空字符
	i = i - 1 ;

	// 逆序
	while ( i >= 0) {
		str[j++] = temp[i--];
	}

		str[j] = '\0';		// 空字符
}

int main()
{
	char str[7];		// 字符数组
	int number = 12345;
	printf("数字为: %d\n",number);
	Itoa(number,str);
	printf("数字转化为字符串的值为: %s\n", str);
	return 0;
}

/*
 * VC6.0的调试结果:
数字为: 12345
数字转化为字符串的值为: 12345
Press any key to continue
*/
