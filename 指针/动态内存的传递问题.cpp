/* 动态内存传递问题 */
/*
 * 程序崩溃
#include <iostream>
using namespace std;
void GetMemory(char *p,int num)
{
	p = (char *)malloc(sizeof(char)*num);	// 申请的动态内存
	// 不能从GetMomory函数返回时获得申请的堆内存的地址 => 即申请的堆内存不能继续被引用
	// => 即不能释放 => 调用一次产生num字节的内存泄漏
};

int main()
{
	char *str = NULL;
	GetMemory(str,10);
	strcpy(str,"hello");
// str = NULL 因为strcpy的时候,str没有初始化指向特定的内存地址,所以导致程序崩溃
	return 0;
}
*/
/* 
 * 解决动态内存的传递问题的三种方式:
 1. 指向指针的指针 char **p => 传入函数实参(指针str本身的地址 &str) ; GetMemory1(&str,10) ; *p = (char *)malloc(sizeof(char)*num);
 2. c++中的指针引用 char* &p ; GetMemory2(str,10);
 3. 使用函数返回值来传递动态内存 char *GetMomory(int mum) ; str = GetMemory3(10)
*/
#include <iostream>
using namespace std;
// 指向指针的指针方式
void GetMemory1(char **p,int num)
{
	*p = (char *)malloc(sizeof(char)*num);
}

// 指针引用方式
void GetMemory2(char* &p,int num)
{
	p = (char *)malloc(sizeof(char)*num);
}

// 函数返回值方式
char *GetMemory3(int num)
{
	char *p = (char *)malloc(sizeof(char)*num);
	return p;
}

int main()
{
	char *str1 = NULL;
	char *str2 = NULL;
	char *str3 = NULL;

	GetMemory1(&str1,10);
	GetMemory2(str2,10);
	str3 = GetMemory3(10);

	strcpy(str1,"hello");
	strcpy(str2,"hello");
	strcpy(str3,"hello");

	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	free(str1);
	free(str2);
	free(str3);
	str1 = NULL;
	str2 = NULL;
	str3 = NULL;	
	return 0;
}

/*
 * VC6.0调试结果:
str1 = hello
str2 = hello
str3 = hello
Press any key to continue

*/