// 编程实现删除字符串中的所有指定的字符
// 假设字符串为 "cabcdefcgchci",把该字符串中所有的字符 'c'删除后,
// 结果应为 "abdefghi"
// 核心思想: 传入字符指针的有效性检测  + 两指针 head(用作遍历,实现链式表达式) + ptr(结合str作记录非ch的字符)

#include <stdio.h>

char *DeleteChar(char *str,char ch)
{
	char *head = NULL;		// 该指针用来作遍历用 --- 实现链式表达式
	char *ptr  = NULL;		// 该指针用来进行非 ch 记录的

	if ( NULL == str ) {
		return NULL;		// 检验 str的有效性
	}

	ptr = head = str;		// 初始化指针

	while (*ptr++) {
		if (*ptr != ch) {
			*str++ = *p;	// str 记录非 ch 的字符
		}
	}

	*ptr = '\0';			// 空字符 --- 字符串结束的标志

	return head;
}

int main(void)
{
	char str[] = "cabcdefcgchci";
	printf("原 str = %s\n", str );	
	DeleteChar(str,'c');	// 实现链式表达式 => 一个链式表达式可以同时进行两个操作 int num = strlen(DeleteChar(str,'c')); => 操作方便,程序简洁明了
	printf("删除所有的'c'后的 str = %s\n", str );
	return 0;

}

/*
 * VC6.0调试结果:
原 str = cabcdefcgchci
删除所有的'c'后的 str = abdefghi
Press any key to continue
*/