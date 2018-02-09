// new申请的堆内存刚开始没被初始化-内存块中的值是随机数-需要手动进行初始化-使用 strcat连接字符串 --- 错误与正确分析 
#include <iostream>
using namespace std;

int main()
{
	char *str1 = "hello";
	char *str2 = " china";
	char *str3 = NULL;
	// 申请动态内存 --- 堆内存
	str3 = new char[strlen(str1) + strlen(str2) + 1];	// new申请的堆内存是没有被初始化的,内存中的值都是随机数
	str3[0] = '\n';      
	strcat(str3,str1);	// 不能把 st1r1的内容复制到堆内存块中，并且会导致数组越界
	strcat(str3,str2);	// 不能把 st1r1的内容复制到堆内存块中，并且会导致数组越界
	
	cout << str3 << endl;	// 乱码 + 数组越界
	return 0;
}

/*
 * VC6.0调试结果:

屯屯屯屯屯妄齢ello china
Press any key to continue
*/

// 修改方法:
// str[0] = '\0';	=> 方便strcat函数的正常调用

/*
 * 修改后的代码在VC6.0的调试结果:
 hello china
Press any key to continue
*/
