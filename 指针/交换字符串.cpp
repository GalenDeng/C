/* 交换字符串 */

//法一 : 指针引用传实参
/*
#include <iostream> //  <> : 该文件是一个工程或标准头文件，查找的时候先查找预定义目录
void swap(char* &p1, char* &p2) //这里是指针引用,所以传入函数的是实参
{
// 若改为swap(char* p1, char* p2) 则指针的交换只在swap函数体内有效,对实际的(主函数的)p1,p2没影响						// 实际上的 p1 p2所指向的字符串是放在常量区,这里的函数参数 char *p1,char *p2只是一个临时分配的,不是实参
// 因为他们的地址不是主函数中两指针本身的地址,是新开辟的
// 总结: 要确保传递的参数是实参	
	char *temp;
	temp=p1;
	p1=p2;
	p2=temp;
}

int main(void)
{
	char *p1="abc";
	char *p2="ABC";
	printf("%s\n",p1);
	printf("%s\n",p2);
	swap(p1,p2);
	printf("%s\n",p1);
	printf("%s\n",p2);
	return 0;
}
*/
//法二:
#include <iostream> //  <> : 该文件是一个工程或标准头文件，查找的时候先查找预定义目录

void swap(char **p1,char **p2) // 传入的是主函数的两指针的实际内存地址,为实参
{
	char *temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main(void)
{
	char *p1="abc";
	char *p2="ABC";
	printf("%s\n",p1);
	printf("%s\n",p2);
	swap(&p1,&p2);		// 传入函数参数的是p1、p2本身的内存地址
	printf("%s\n",p1);
	printf("%s\n",p2);
	return 0;
}
