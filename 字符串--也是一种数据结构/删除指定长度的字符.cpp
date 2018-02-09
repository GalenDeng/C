// 删除指定长度的字符
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *DeleteChar(char *str,int pos,int len)
{
	char *tmp;
	int num;

	if (NULL == str) {	// 检验str的有效性
		return NULL;
	}

	tmp =  str + pos - 1; 		// 下标式显示 --- 需要减 - 1(空字符)
	num =  strlen(str);			//  str的字符串长度

	// 检验 pos的合法性
	if ( pos < 1 ||  tmp - str  > num) {		// tmp - str === 一个数值
		return str;				//  pos的位置不合格,直接返回原字符串
	}

	// 检验 len的合法性
	if ( tmp - str + len > num ) {			// tmp - str 若 str = "12345",
											// 而 tmp = "2345",pos = 1,  
											// 则 len最大为 4  => 1 + 4 = strlen(str) 
											// => len不合法的时候为: tmp -str + len > strlen(str)
		*tmp = '\0';			// len的长度超过了
		return str;				
	}

	// 进行删除操作
	while (*tmp && *(tmp + len)) {
		*tmp = *(tmp + len);
		tmp++;					// 即 "12345" => delete "23" => 剩下 "145"
	}
	*tmp = '\0';

	return str;
}

int main(void)
{
	char str[] = "12345";
	printf("原字符串为: \n%s\n", str);

	char *transstr = DeleteChar(str,1,2);
	printf("进行删除操作后的字符串为: \n%s\n", transstr);
	return 0;
}

/*
 * VC6.0调试结果:
原字符串为:
12345
进行删除操作后的字符串为:
345
Press any key to continue
*/