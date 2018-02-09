// 编程实现转换字符串、插入字符的个数
// 例如字符串 aaab => 插入字符个数 => aaa3b1
// 核心思想: 计数器/两指针 : count = 1; p = str q = p + 1 => 两两比较 => *p=*q => p++ q++ count++
//           使用 strcat (string catenate -- 字符连接)  strcat(str,buf) 
/*
 * VC6.0调试结果:
原字符串是:
aaabccddeabcefffbb
原字符串的字符个数统计后的字符串是:
aaa3b1cc2dd2e1a1b1c1e1fff3bb2
Press any key to continue
*/ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *TransFormation(char *str)
{
	// 两指针
	char *p;
	char *q;
    int len = strlen(str);
	int count = 0;	// 计数器
	int bits = 0;	// 计算buffer的长度
	// 在栈上给足内存空间,保证str可以保存进buffer上  
	// + 1是为了实现存放 '\0' => 字符数组的最后元素为'\0'才可以表示为字符串
//	char buffer[len+1];	error => 因为这里的len是变量，不是常量
	char *buffer = (char *)malloc(sizeof(char) * (len+1));	// 分配动态内存

	if (NULL == str) {
		return NULL;
	}

	// 初始化
	p = str;
	q = p + 1;	// 两指针用作两两比较
	count = 1;	// 计数器

	while (*q) {	// 遍历字符串str
		if ( *p == *q) {
			p++;
			q++;
			count++;					// 递增
		} else {
			itoa(count,buffer,10);		// count 由 int 转为 char型的buf ; 10 : 10进制 => printf(buf)= "3"(以例子为例)
			bits = strlen(buffer);		// 计算buffer的长度
			strcat(buffer,q);				// buf = "3" q = "b" => strcat(buf,q) = "3b"
			*q = '\0';					// 把q指向的地址的值设为'\0' => 使到 str变为 aaa字符串(以例子为例)
			strcat(str,buffer);			// "aaa" + "3b" = "aaa3b"

			// 重新复位两两比较的指针的位置 + 复位计数器 = 1
			q += bits;					// 添加的统计字符个数的值的字符串的长度
			p = q;
			q = p + 1;
			count = 1;
		}	
	}
	// 添加字符串str的最后字符的字符统计个数
	itoa(count,buffer,10);
	strcat(str,buffer);					// 转换字符串、插入字符的个数的最终结果
	free(buffer);						// 释放内存两部曲
	buffer = NULL;
	return str;
}

int main(void) 
{
	char str[250] = "aaabccddeabcefffbb";		// 记得具体设置str分配的内存大小
	printf("原字符串是: \n%s\n",str);
	char *transstr = TransFormation(str);

	printf("原字符串的字符个数统计后的字符串是: \n%s\n",transstr);
	return 0;
}
			