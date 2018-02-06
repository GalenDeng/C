// itoa函数的使用 --- itoa(int,string,进制)
// gcvt函数的使用 --- gcvt(double, 1 /*有效位为1位,其他四舍五入*/ , string)
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num_int = 435;
	double num_double = 435.10f;
	char str_int[30];
	char str_double[30];

	itoa(num_int,str_int,10);								// 435  10 : 十进制
	gcvt(num_double,1,str_double);							// 4e+002	1 : 表示只显示一位有效位,其他四舍五入
// 	num_double = 465.10f; gcvt(num_double,1,str_double);	// 5e+002
//  gcvt(num_double,8,str_double);							// 435.10001 => 有效位 4 3 5 1 0 0 0 1
	printf("str_int: %s\n", str_int);			
	printf("str_double: %s\n", str_double);			

	return 0;
}
