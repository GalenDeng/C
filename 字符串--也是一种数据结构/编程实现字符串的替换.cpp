// 编程实现字符串的替换
// 先请用户输入3个字符串，然后把在第一个字符串中出现的所有第二个字符串替换成
// 第三个字符串，最后输出新的字符串
/*
 * example:
   str； abcdefcdg
   sub1: cd
   sub2: 123
output: ab123ef123g
*/

#include <stdio.h>
#include <string.h>
char *Replace(const char *str, const char *sub1,const char *sub2,char *output)
{
	char *pOutput = NULL;
    const char *ptr = NULL;

	// 检验 传入参数的有效性
	if ( NULL == str || NULL == sub1 || NULL == sub2 || NULL == output ) {
		return NULL;			
	}

	pOutput = output;	// pOutput用作打印
	ptr = str;			// ptr用作遍历str

	while (*ptr != '\0') {		// 遍历主字符串
		ptr = strstr(ptr,sub1);	// 在ptr字符串中查找是否有子串 sub1的存在,有的话即返回sub1的首地址,否则返回NULL

		if ( NULL != ptr) {	    // 找到子串
			memcpy(pOutput,str,ptr-str);	// 复制找到的sub1的地址位置之前的str字符到输出中
			pOutput += (ptr-str);		// 输出打印指针跳到尾部,准备复制sub2的字符串
			memcpy (pOutput,sub2,strlen(sub2));		// 复制sub2到输出中 -- 实现 sub1到sub2的替换
			pOutput += strlen(sub2);		// 输出打印指针跳到尾部,准备复制其他内容
			ptr += strlen(sub1);			// 遍历跳过找到的子串,指向之后的其他位置,再继续遍历
			str = ptr;						// 调整str的指向,以便进行 ptr - str 进行非sub1子串的复制
		} else {
			break;							// 退出while循环
		}
	}
	*pOutput = '\0';	// 使到pOutput成为一个字符串

	if ( '\0' != *str) {
		strcpy(pOutput,str);
	}

	return output;		// 返回替换后的字符串
}

int main(void)
{
	char str[50] = "";
	char sub1[10] = "";
	char sub2[10] = "";	
	char output[100] = "";


	printf("str = ");
	scanf("%s",str);
	printf("sub1 = ");
	scanf("%s",sub1);
	printf("sub2 = ");
	scanf("%s",sub2);
	Replace(str,sub1,sub2,output);
	printf("替换后的值为: %s\n", output);
	return 0;
}

/*
 * VC6.0调试结果:
str = abcdefcdg
sub1 = cd
sub2 = 123
替换后的值为: ab123ef123g
Press any key to continue
*/