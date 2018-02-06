// 整数转字符串(负数也能实现)
#include <stdio.h>
#include <stdlib.h>

void int2str(int number, char *str)
{
	int temp,i=0,j=0,len;	// 中间变量 --- 为 number的绝对值
	char buf[30];	// 中间变量
	if (str == NULL) {			// 检验 str的是否已经成功初始化
		return;				
	}

	temp = number < 0 ? -number : number;

	// 遍历取出基数值
	do  {
		buf[i++] = temp % 10 + '0';	// 取基数 => + '0' => 变字符
		temp = temp / 10;
	} while(temp);

	len = i;					// 得到遍历后的字符串长度(包括'\0')
	i = number < 0 ? ++i : i;	// 得到字符串的长度(包括 '\0')

	str[i] = '\0';				// 添加结束符
	i--;						// 准备逆序的下标位置
	// 逆序
	while( j < len ) {
		str[i--] = buf[j++];
	}

	if (i == 0) {			// 如果number = 正整数, 此时的 i = -1 ; number = 负整数, 此时的 i = 0 
		str[i] = '-';		// 添加负号 
	}
}

int main()
{
	int number1 = 12345;
	int number2 = -12345;
	char str1[30];
	char str2[30];
	printf("原数字 = %d\n", number1);
	int2str(number1,str1);
	printf("整数转字符串 = %s\n", str1);

	printf("原数字 = %d\n", number2);
	int2str(number2,str2);
	printf("整数转字符串 = %s\n", str2);
	return 0;
}			

/*
 * VC6.0调试结果:
原数字 = 12345
整数转字符串 = 12345
原数字 = -12345
整数转字符串 = -12345
Press any key to continue
*/