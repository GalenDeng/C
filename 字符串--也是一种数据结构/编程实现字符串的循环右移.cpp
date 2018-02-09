// 编程实现字符串的循环右移
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void LoopMove(char *str,int len)
{
	int num = strlen(str);
	char *tmp = (char *)malloc(sizeof(char) * num );		// 申请动态内存,保证可以全存下str的字符串(除'\0')
	int n  =  len % num ;									// 计算字符串尾部移到头部的字符个数
	printf("n = %d\n",n);
	int m  =  num - n;	
	printf("m = %d\n",m);
	memcpy(tmp,str + m , n );	// 保存尾部要移动的字符串 -- n 位
	memcpy(str + n,str, m);
	memcpy(str,tmp,n);
	free(tmp);					// 释放堆内存空间
}

// 法二 : 自写函数实现循环右移
void LoopMove2(char *str,int len)
{
	int i = 0;
	int num = strlen(str);		// 传入字符串长度
	int n = len % num;			// 从尾部移到头部的字符个数
	char *tmp;
	if (NULL == str) {
		return;
	}


	tmp = (char *)malloc(sizeof(char) * n );	// 申请动态内存,存放从尾部移到头部的字符

	for ( i = 0; i < n; i++)					// 把从尾部移到头部的字符临时存进字符数组中
	{
		tmp[i] = str[ num - n + i];
	}

	for ( i = num - n -1 ; i >= 0; i--)				// 把从头部的字符移到尾部 --- > 注意要从右向左移动，不然会发烧覆盖字符的情况
	{												// i = num - n -1 => 下标是长度的 - 1
		str[i + n] = str[i];						// 下标法
		printf("%c\n",str[i+n]);
	}

	for ( i= 0; i < n; ++i)
	{
		str[i] = tmp[i];						// 从堆内存中复制尾部字符到头部
	}
	free(tmp);
}

int main(void)
{
	char str1[] = "12345";
	char str2[] = "12345";
	printf("循环前的字符串为: %s\n", str1);
	printf("循环前的字符串为: %s\n", str2);
	LoopMove(str1,7);
	LoopMove2(str2,7);
	printf("循环右移 7 位后的字符串为: %s\n", str1);
	printf("循环右移 7 位后的字符串为: %s\n", str2);
	return 0;
}

/*
 * VC6.0的调试结果:
循环前的字符串为: 12345
循环前的字符串为: 12345
n = 2
m = 3
3
2
1
循环右移 7 位后的字符串为: 45123
循环右移 7 位后的字符串为: 45123
Press any key to continue
*/