// 编程实现strcmp库函数
// 对于两个字符串str1和str2,若 str1 == str2,则 return 0; 若str1 > str2,则 return 1; 若str1 < str2,则 return -1;
#include <stdio.h>

int StrCmp(const char *str1,const char *str2)
{
	const char *ptr1 = str1;
	const char *ptr2 = str2;
	int ret = 0;				// 用来存 str1 str2对比的比较值
	if (str1 == NULL || str2 == NULL) {
		return -2;						// 检测 str1 str2的有效性
	}
	// compare str1,str2
	while(!(ret = *(unsigned char *)ptr1 - *(unsigned char *)ptr2) && *ptr1 && *ptr2) {	// 记得强制转换
		ptr1++;
		ptr2++;
	}
	if (ret < 0) {				// str1 < str2  => -1
		return -1;
	} else if (ret > 0){		// str1 > str2  => 1
		return 1;
	} else {					// str1 == str2 => 0
		return 0;
	}
}

int main(void)
{
	char str1[10] = "1234";
	char str2[10] = "123";
	char str3[10] = "12345";

	printf("%s 比 %s is %d\n", str1,str2,StrCmp(str1,str2));
	printf("%s 比 %s is %d\n", str1,str3,StrCmp(str1,str3));
	return 0;
}		

/*
 * VC6.0调试结果:
1234 比 123 is 1
1234 比 12345 is -1
Press any key to continue
*/