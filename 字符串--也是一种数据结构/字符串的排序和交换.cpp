// 字符串的排序和交换
// 编写一个函数将一条字符串分成两部分，将前半部分按ASCII码升序排序，
// 后半部分不变，(如果字符串是奇数,则中间的字符不变)，再将前后两部分交换，
// 最后将该字符串输出
// 原 : "cacde"  =>  后 ："decac" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 冒泡排序法
void SortStr(char *str,int len)
{
	int i = 0,j = 0;
	if (NULL == str) {		// 检验str的有效性
		return;
	}

	for ( i = 0; i < len - 1 ; ++i)
	{
		for ( j = 0; j < len - i ; ++j)
		{
			if (str[j] > str[j + 1]) {	// 升序排序 ( 0 1 2 3 4 5)
				str[j] ^= str[j + 1];
				str[j + 1] ^= str[j];
				str[j] ^= str[j + 1];	// 如果大小次序不对，则使用异或运算进行排序   
			}
		}
	}
}

// 该字符串的前后部分进行字符交换 --- 使用中间变量(申请堆内存临时保存后半部分的数据)
char *Swap(char* str,int len)
{
	char *tmp;
	int i = 0;
	int num = len % 2 == 0 ? 0 : 1;		// 判断中间分段节点是奇数还是偶数
	if (NULL == str) {					// 检验str的有效性
		return NULL;
	}

	tmp = (char *)malloc(sizeof(char) * len);	// 申请堆内存临时保存后半部分的数据

	for ( i = 0 ; i < len ; ++i)
	{
		tmp[i] = str[len + i];				// 堆内存临时保存后半部分的数据
		str[len + i] = str[i];				// 将前半部分的数据放到后半部分
		str[i] = tmp[i];					// 把堆内存保存的数据复制到原字符串的前半部分
	}	
	free(tmp);								// 释放堆内存

}

char *transstr(char *str)
{
	int len,n;
	if (NULL == str) {		// 检验str的有效性
		return NULL;
	}

	len = strlen(str);
	n 	= len / 2;			// 前后半部分的划分点

	SortStr(str, n);	// 冒泡升序排序
	// 交换前后部分的字符
	Swap(str,n);
	return str;
}

int main(void)
{
	char str1[] = "cacde";
	char str2[] = "cacd";
	char *str3,*str4;
	printf("str1 = %s\nstr2 = %s\n", str1,str2);
	str3 = transstr(str1);
	str4 = transstr(str2);
	printf("str1排序交换后为 : %s\nstr2排序交换后为 : %s\n", str3,str4);
	return 0;
}

/*
 * VC6.0调试结果:
str1 = cacde
str2 = cacd
str1排序交换后为 : cdace
str2排序交换后为 : cdac
Press any key to continue
*/