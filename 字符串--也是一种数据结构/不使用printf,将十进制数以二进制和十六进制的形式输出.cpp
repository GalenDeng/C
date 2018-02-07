// 不使用printf,将十进制数以二进制和十六进制的形式输出
// 核心思想: 位运算 --- 移位运算思想
#include <stdio.h>
#include <stdlib.h>
// 十进制转二进制输出 --- 核心思想 : long == 32位二进制数 => 遍历 => 移位取数存储 => 返回buffer堆地址
char *Get2String(long number)
{
	int i = 0;
	char *buffer;	// 缓冲区 --- 没指定字符指针的指向位置
	char *temp;		// 中间变量

	// 申请动态内存 --- 堆内存 => 堆区
	buffer = (char *)malloc(sizeof(char) * 33);	// number是long(长整型)型 => 32位二进制数 => 需要加一位空字符位('\0')
	temp = buffer;
	for ( i = 0; i < 32; i++)
	{
		temp[i] = (number  &  ( 1 << (31 - i))) >> (31 - i);	// 从高位到低位,选择相应的位数据,然后把取到的该位数据放到最低位的位置
		temp[i] = (temp[i] == 0 )? '0' : '1';	// 数字变字符串
	}

	buffer[32] = '\0';		// 空字符/结束符 --- 字符串的终止

	return buffer;			// 返回堆内存的地址
}

// 十进制转二进制输出 --- 核心思想: 理解4位二进制数组成一个16进制数 负数的转换(类型) [源码取反] + 1 = 补码
char *Get16string(int number)
{
	int i = 0;
	char *buffer;
	char *temp;

	buffer = (char *)malloc(sizeof(char) * 11);	// 申请11个字节动态内存空间

	buffer[0] = '0';
	buffer[1] = 'x';		// 表示十六进制的 0x

	buffer[10] = '\0';		// 结束符

	temp   = buffer + 2;		// temp为中间变量
	for ( i = 0; i < 8; ++i)	// 4位二进制数位组成一个十六进制数 32/4 = 8	(8个16进制数)
	{
		// 4位组成一个16进制数, 每次把需要取出的十六进制数放在高 31-28位, 
		//然后右移放到最低位 3-0位,以便取出
		temp[i] = (char)(number << 4 * i  >> 28);	// 记得强制转换为char型
		temp[i] = temp[i] >=0 ? temp[i] : temp[i] + 16;	
/*
 * 	temp[i] + 16 的理解:
因为long型是有符号的数,最高位为1表示符号,当我们左移4位后得到 1110 ... ... ,
	这个时候编译器会认为这个数是负数,
		当我们进行右移的时候,编译器默认补进来的位值都为1, 因为编译器认为该数为负数,要保证高位为1 => 持续进1
			得到 ... ... 1111 1110
				因为char型也是有符号位的,所以它也认为该数为负数
					1111 1110 是计算机存储的位 => 计算机以补码形式存储 => 变为源码才能知道真实值
						(源码取反) + 1 = 补码  => ~源码 = 1111 1101 => 源码 = 1000 0010(符号位不变)
							源码 = -2
								原值 0000 1110 = E =>  -2 + 16 = E
									所以要进行 temp[i] + 16 (temp[i]为负数的时候) 
*/
		temp[i] = temp[i] > 10 ? temp[i] -10 + 'A'/* 65 */ : temp[i] + '0'/* 48 */;
	}
	return buffer;		// 返回堆内存地址
}

int main(void)
{
	char *get2string;
	char *get16string;
	int number = 12345;

	get2string  = Get2String(number);
	get16string = Get16string(number);
	
	printf("%d 的二进制数为: %s\n", number,get2string);
	printf("%d 的十六进制数为: %s\n", number,get16string);
	return 0;
}

/*
 * VC6.0调试结果:
12345 的二进制数为: 00000000000000000011000000111001
12345 的十六进制数为: 0x00003039
Press any key to continue
*/