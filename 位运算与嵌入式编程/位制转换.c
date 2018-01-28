/* 位制转换  */
#include <stdio.h>
int main(int argc,char* argv[])
{
	int i =5.01;
	float f = 5;

	printf("%f\n", 5);		// 0.000000
	printf("%lf\n",5.01);	// 5.010000
	printf("%f\n", f);		// 5.000000

	printf("%d\n", 5.01);	// 一个很大的整型数 1889785610
	printf("%d\n", i);		// 5
	return 0;

}

