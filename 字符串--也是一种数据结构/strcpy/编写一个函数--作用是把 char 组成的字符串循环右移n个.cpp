// 编写一个函数--作用是把 char 组成的字符串循环右移n个.
// 比如原来是 "abcdefghi",如果 n = 2, 移位后应该是 "hiabcdefgh"
#include <iostream>
#include <string.h>
#define MAX_LEN  20
void LoopMove(char *pStr, int steps)
{
	int n = strlen(pStr) - steps;			
	char tmp[MAX_LEN] ;	// 中间变量
	memcpy(tmp,pStr + n, steps);
	memcpy(pStr + steps,pStr,n);
	memcpy(pStr,tmp,steps);
}

int main(void)
{
	char s[10] = "abcdefghi";
	printf("循环右移之前的字符串\n");
	printf("%s\n",s);
	LoopMove(s,2);
	printf("循环右移之后的字符串\n");
	printf("%s\n",s);
	return 0;
}

/* 
 * VC6.0调试结果:
循环右移之前的字符串
abcdefghi
循环右移之后的字符串
hiabcdefg
Press any key to continue
*/