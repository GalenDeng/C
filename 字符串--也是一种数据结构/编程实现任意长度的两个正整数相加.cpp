// 编程实现任意长度的两个正整数相加
// c/c++中通常用 int/float/double来表示数字 => 缺点: 都是有长度限制
// 尝试用字符串替代int等数据类型来表示数字 => 实现任意长度的两个正整数的相加 => 结果用字符串表示 => 要考虑进位
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *AddBigInt(char *num1,char *num2)
{
	int i,j,k,maxlength;
	int c = 0 ; 	// 设置初始进位值为0
	if (NULL == num1 || NULL == num2) {
		return NULL;
	}

	i = strlen(num1) - 1; 	// 指向数字的最低位 -- 下标式
	j = strlen(num2) - 1; 	// 指向数字的最低位 -- 下标式	

	maxlength =  ( strlen(num1) > strlen(num2) ) ? strlen(num1) + 1 : strlen(num2) + 1 ; // 加1是因为考虑进位

	// 申请动态内存 --- 堆内存 保存加法后得到的值
	char *rst /*result*/ = (char *)malloc(sizeof(char) * (maxlength + 1)); 	// +1 是因为考虑进位
	rst[maxlength] 	= '\0';	// 结果字符串结束标志 -- 添加结束符 '\0'
	// 设置指向
	k = strlen(rst) - 1;	// 从最低位开始

	while( (i >= 0) && (j >= 0)) {
		rst[k] = ( (num1[i] - '0') + (num2[j] - '0') + c) % 10 + '0';	// 计算本位的值; c为进位,若有值进来则加
		c =  ( (num1[i] - '0') + (num2[j] - '0') + c) / 10 ;			// 进位值

		--i;
		--j;
		--k;
	}

	// 若相加之后 num1 和 num2还有字符剩下来的,补充进相加字符串的相应位中
	while ( i>=0) {
		rst[k] = ( (num1[i] - '0') + c) % 10 + '0';	// 计算本位的值; c为进位,若有值进来则加
		c =  ( (num1[i] - '0') + c) / 10 ;			// 进位值
		--i;
		--k;
	}

	while ( j>=0) {
		rst[k] = ( (num2[j] - '0') + c) % 10 + '0';	// 计算本位的值; c为进位,若有值进来则加
		c =  ( (num2[i] - '0') + c) / 10 ;			// 进位值
		--j;
		--k;
	}	

	// 填充进位值
	rst[0] = c + '0' ;

	// 返回结果字符串
	if (rst[0] != '0') {	// 有进位
		return rst;
	} else {				// 无进位
		return rst + 1;
	}
}

int main(void)
{
	char *num1 = "12345678901234567890";
	char *num2 = "23456789012345678901";
	char *result = AddBigInt(num1,num2);
	printf("%s 和 %s 相加得到: \n%s\n", num1,num2,result);
	return 0;
}			

/*
 * VC6.0调试结果:
12345678901234567890 和 23456789012345678901 相加得到:
35802467913580246791
Press any key to continue
*/