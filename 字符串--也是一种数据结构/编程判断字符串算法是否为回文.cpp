// 编程判断字符串算法是否为回文
// 核心思想 : 从一个字符串的两端进行遍历比较 + 确定比较次数 (len = strlen(str); i < len / 2)
#include <stdio.h>
#include <string.h>
int IsRevStr(const char *str)
{
	int i=0,len=0;
	int found = 1;		// found = 1:回文 ; found = 0:不是回文
	if (NULL == str) {	// 检验str的有效性---是否正常初始化
		return -1;
	}

	len = strlen(str);	// 取得字符串str的长度
	for ( i = 0; i < len / 2; i++)	// i < len / 2 => 确认比较次数
	{
		if (str[i] != str[len-i-1])  { // len - 1 为字符串除'\0'的最后字符的下标值
			found = 0;
			break;		// 退出for循环,执行主函数的下一指令
		}
	}
	return found;
}

int main(void)
{
	char str1[] = "level";
	char str2[] = "levell";

	char  *IsStr1 = IsRevStr(str1) == 1 ? "YES" : "NO";
	char  *IsStr2 = IsRevStr(str2) == 1 ? "YES" : "NO";

	printf("%s is 回文? %s\n", str1,IsStr1 );
	printf("%s is 回文? %s\n", str2,IsStr2 );

	return 0;
}	

/*
 * VC6.0调试结果:
level is 回文? YES
levell is 回文? NO
Press any key to continue
*/		