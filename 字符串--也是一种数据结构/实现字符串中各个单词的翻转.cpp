// 实现字符串中各个单词的翻转
// 将 "I am from Shanghai" 倒置为 "Shanghai from am I" => 句子中的单词位置倒置,而不改变单词内部的结构
// 核心思想:  全局翻转(整段字符串) + 局部翻转(单个单词)  OR  局部翻转(单个单词) + 全局翻转(整段字符串)
//#include <stdio.h>
#include <iostream>
using namespace std;
// 交换字符
void swap (char *start,char *end)
{
	char temp;
	temp 	= *start;
	*start 	= *end;
	*end 	= temp;

}

// 倒置操作
void RevStr(char *src)
{
	// 需要3个指针
	char *start = src;
	char *end	= src;
	char *ptr 	= src;

	if (NULL == src) {		// 有效性检测
		return;
	}

	while(*ptr++ != '\0');			// 遍历一次,以便取得字符串尾部的位置
	end	= ptr - 2;			// 除去指针多走的一步和'\0'的位置
	// 全局翻转 --- 整个字符串翻转
	// 这里的条件 start < end --- 联想一下快速排序的哨兵i,j，只不过这里我们把哨兵的行走顺序改为: 一起同时走
	while (start < end) {
		swap(start++,end--);	// 交换字符 参数传的是---src的指向的地址---即主函数中src的真实地址---传实参
	}

	// 局部翻转 --- 单个单词的翻转
	start = src;
	end   = ptr - 2 ;
	ptr   = start;			// 为了再一次的遍历

	while (*ptr++ != '\0') {	// 再次遍历字符串
		if (*ptr == ' ' || *ptr == '\0' ) {	// 找到单词的结尾
			end = ptr - 1; 		// 单词的非'\0'尾字符位置
			while (start < end) {			// 单词逆置 
				swap(start++,end--);	
			}
			start = ptr + 1;			// 下一个单词
		}	
	}
}

int main(void)
{
	char src[] = "I am from Shanghai";
	printf("old src: %s\n", src);
	RevStr(src);
	printf("new src: %s\n", src);
	return 0;
}	

/*
 * VC6.0调试结果:
old src: I am from Shanghai
new src: Shanghai from am I
Press any key to continue
*/		