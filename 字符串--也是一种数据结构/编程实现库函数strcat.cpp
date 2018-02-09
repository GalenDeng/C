// 编程实现库函数 strcat
// 核心思想 : 遍历找到原dest字符串的'\0'的位置,然后在'\0'的位置后连接另一个src字符串的内容

#include <stdio.h>

// 自己构造strcat连接字符串
char *StrCat(char *dest, const char *src)
{
	char *ret;	

	if ( NULL == dest || NULL == src) {
		return NULL;					// 检测传入字符指针的有效性
	}

	ret = dest;	// 用来返回,实现链式表达式

	// 遍历dest
	while(*dest++);
	dest--;		// 找到原dest的'\0'的位置

	while(*dest++ = *src++);	// 复制src的内容到dest

	return ret;
}

int main(void)
{
	char str1[] = "abcd";
	char str2[] = "efgh";
	printf("str1 = %s\nstr2 = %s\n", str1,str2 );
	StrCat(str1,str2);
	printf("str1和str2连接后的字符串为: %s\n", str1);
	return 0;
}

/*
 * VC6.0调试结果:
str1 = abcd
str2 = efgh
str1和str2连接后的字符串为: abcdefgh
Press any key to continue
*/