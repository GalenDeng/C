// 编程查找两个字符串的最大公共子串
/*
 核心思想 : 
 * 利用库函数 strstr(longstr,shortstr)实现在一个字符串中查找子串
 * 判 str1 str2 的 长度 , 调整好 longstr 和 shortstr的指向,方便使用 strstr()函数
 * 双层嵌套
 	for (i = strlen(shortstr) - 1; i > 0 ; i--)			// strlen(shortstr) - 1 :  缩短字符串大小 长度必大于0
	{
		for ( j = 0; j <= strlen(shortstr)-(unsigned int)i; j++)	// strlen()得出的数字是 uint,所以i => unsigned int i
		{
			memcpy(substr,&shortstr[j],i);	// 复制(原最短字符串长度 - 1)个字符给堆内存substr 
			substr[i] = '\0';				// 添加字符串结束符

			if (strstr(longstr,substr) != NULL) {		// 找到最大公共子串,返回
				return substr;
			}
		}
	}
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *CommonString(char *str1,char *str2)
{
    char *longstr  = str1;
    char *shortstr = str2;
    char *substr;
    int i = 0 , j = 0 ;
	if (str1 == NULL || str2 == NULL) {
		return NULL;					// 检验有效性
	}

	// 使用strlen()调整 longstr和shortstr的指向,以便strstr(longstr,shortstr)进行在字符串中查找子串的功能
	if (strlen(str1) < strlen(str2)) {
		longstr = str2;
		shortstr= str1;
	} else {
		longstr = str1;
		shortstr= str2;		
	}

	// 使用strstr函数进行一个字符串中查找子串
	if (strstr(longstr,shortstr) != NULL) {
		return shortstr;						// 短的字符串整体就是两个字符串的公共子串
	}

	// 申请堆内存,用来保存最大公共子串来返回
/*
	shortstr = 12345
	substr 取4个字符 1234 2345		=> 2种形式的字符串 for ( j = 0; j <= strlen(shortstr) - i; j++) => (j = 0 ; j <= 5 - 4 = 1 ; j++)
	substr 取3个字符 123 234 345 	=> 3种形式的字符串 for ( j = 0; j <= strlen(shortstr) - i; j++) => (j = 0 ; j <= 5 - 3 = 2 ; j++)
*/
	substr = (char *)malloc(sizeof(char) * (strlen(shortstr) + 1));	// strlen 不包括'\0',所以要加1;

	for (i = strlen(shortstr) - 1; i > 0 ; i--)			// strlen(shortstr) - 1 :  缩短字符串大小 长度必大于0
	{
		for ( j = 0; j <= strlen(shortstr)-(unsigned int)i; j++)	// strlen()得出的数字是 uint,所以i => unsigned int i
		{
			memcpy(substr,&shortstr[j],i);	// 复制(原最短字符串长度 - 1)个字符给堆内存substr 
			substr[i] = '\0';				// 添加字符串结束符

			if (strstr(longstr,substr) != NULL) {		// 找到最大公共子串,返回
				return substr;
			}
		}
	}

	return NULL;	// 找不到公共子串即返回NULL
}

int main(void)
{
	char *str1 = (char *)malloc(256);
	char *str2 = (char *)malloc(256);
	char *common = NULL;

	gets(str1);		// 从终端输入 str1 str2
	gets(str2);

	common = CommonString(str1,str2);	// 取最大的相同子串

	printf("%s和%s的最大公共子串为: %s\n",str1,str2,common);

	return 0;
}	

/*
 * VC6.0调试结果:
123456789
21456987
123456789和21456987的最大公共子串为: 456
Press any key to continue

123456789
1234
123456789和1234的最大公共子串为: 1234
Press any key to continue
*/