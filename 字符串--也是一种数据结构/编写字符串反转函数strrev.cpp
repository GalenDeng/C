// 编写字符串反转函数strrev
// input : abcd ; output : dcba
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 法1 : 遍历字符串,首尾字符交换 ==> 下标法
char *reverse1(char *str)				// const不改变传入参数的值 --- 常量
{
	int len = strlen(str);	// 字符串的长度
	int i = 0;
	char *tmp = (char *)malloc(sizeof(char) * (len + 1));	// 申请动态内存 --- 堆内存用来存放str的字符串
	char t = 0;	

	strcpy(tmp,str);		// 复制str 到 tmp

	for (i = 0; i < len / 2; ++i)	// i < len / 2 交换字符次数控制
	{
		// 首尾字符交换 --- 下标法
		t = tmp[i];
		tmp[i] = tmp[len-1-i];	
		tmp[len-1-i] = t;
	}
	return tmp; 
}

// 法2 : 遍历字符串,首尾字符交换 ==> 指针法
char *reverse2(char *str)
{
 	char *tmp,*ptr,*ret;
 	char t; 
 	int len = strlen(str);
 	if (NULL == str) {
 		return NULL;
 	}

 	tmp= (char *)malloc(sizeof(char) * (len + 1));	// 申请堆内存,存放str字符串的值
 	strcpy(tmp,str);

 	ptr = tmp + len - 1;	// 尾字符地址
	ret = tmp;				// 保存tmp的起始地址,用来返回的
 	// 交换字符串
 	while (tmp < ptr) {
 		t = *tmp;
 		*tmp = *ptr;
 		*ptr = t;

		--ptr;
		++tmp;
 	}
 	return ret;		// 返回的是tmp申请的连续的堆内存的起始地址
}

// 法3 : 遍历字符串,首尾字符交换 ==> 指针法 [异或运算实现字符交换]
char *reverse3(char *str)
{
 	char *tmp,*ptr,*ret;
 	int len = strlen(str);
 	if (NULL == str) {
 		return NULL;
 	}

 	tmp= (char *)malloc(sizeof(char) * (len + 1));	// 申请堆内存,存放str字符串的值
 	strcpy(tmp,str);

 	ptr = tmp + len - 1;	// 尾字符地址
	ret = tmp;				// 保存tmp的起始地址,用来返回的
 	// 交换字符串
 	while (tmp < ptr) {
 		*tmp ^= *ptr;		// 异或运算实现交换字符
 		*ptr ^= *tmp;
 		*tmp ^= *ptr;

		--ptr;
		++tmp;
 	}
 	return ret;		// 返回的是tmp申请的连续的堆内存的起始地址
}

// 法4 : 遍历字符串,首尾字符交换 ==> 指针法 [加减运算实现字符交换]
char *reverse4(char *str)
{
 	char *tmp,*ptr,*ret;
 	int len = strlen(str);
 	if (NULL == str) {
 		return NULL;
 	}

 	tmp= (char *)malloc(sizeof(char) * (len + 1));	// 申请堆内存,存放str字符串的值
 	strcpy(tmp,str);

 	ptr = tmp + len - 1;	// 尾字符地址
	ret = tmp;				// 保存tmp的起始地址,用来返回的
 	// 交换字符串
 	while (tmp < ptr) {
 		*tmp += *ptr;		// 加减法运算实现交换字符
 		*ptr = *tmp - *ptr;
 		*tmp = *tmp - *ptr;

		--ptr;
		++tmp;
 	}
 	return ret;		// 返回的是tmp申请的连续的堆内存的起始地址
}

// 法5 : 递归 : 直接修改实参中的元素数值
char *reverse5(char *str,int len)
{
	char  tmp;			// 中间变量
	if (len <= 1) {		// 递归终止条件
		return str;
	}

	// 首尾字符交换
	tmp  = *str;
	*str = *(str + len - 1);	
	*(str + len - 1) = tmp ;

	// 递归 --- 处理第二对首尾字符,将其交换
	return (reverse5(str + 1, len - 2) - 1);
/*
 * 理解这里为啥 - 1
 * 递归函数前的按被调函数的顺序依次执行,递归函数后的按被调函数的反顺序执行
 * 递归理解: 有递有归，这里的 return (reverse5(str + 1, len - 2) - 1); 就是取归来之值

 * str+1    === dcba len = 4    ===> 这个就是归来之值
 * str+1	=== cba  len = 2
 * str		=== ba   len = 0

  若 return (reverse5(str + 1, len - 2)); ===> 归来值的str是指向 b, printf(str) = ba
*/
}

int main(void)
{
	char str1[] = "abcd";
	char str2[] = "abcdefg";
	char *getstring1;char *getstring2;
	char *getstring3;char *getstring4;
	char *getstring5;char *getstring6;
	char *getstring7;char *getstring8;
	char *getstring9;char *getstring10;
	printf("str1字符串是: %s\n", str1);
	printf("str2字符串是: %s\n", str2);

	getstring1 = reverse5(str1,strlen(str1));
	getstring2 = reverse5(str2,strlen(str2));


	getstring3 = reverse1(getstring1);
	getstring4 = reverse1(getstring2);

	getstring5 = reverse2(getstring3);
	getstring6 = reverse2(getstring4);

	getstring7 = reverse3(getstring5);
	getstring8 = reverse3(getstring6);

	getstring9 = reverse4(getstring7);
	getstring10 = reverse4(getstring8);

	printf("str1 字符串反转的结果getstring1是(递归法): %s\n", getstring1);	
	printf("getstring1 字符串反转的结果是(下标法): %s\n", getstring3);
	printf("getstring3 字符串反转的结果是(指针法): %s\n", getstring5);
	printf("getstring5 字符串反转的结果是(指针法 [异或运算实现字符交换]): %s\n", getstring7);
	printf("getstring7 字符串反转的结果是(指针法 [加减运算实现字符交换]): %s\n", getstring9);
	printf("\n");
	printf("str2 字符串反转的结果getstring2是(递归法): %s\n", getstring2);
	printf("getstring2 字符串反转的结果是(下标法): %s\n", getstring4);
	printf("getstring4 字符串反转的结果是(指针法): %s\n", getstring6);
	printf("getstring6 字符串反转的结果是(指针法 [异或运算实现字符交换]): %s\n", getstring8);
	printf("getstring8 字符串反转的结果是(指针法 [加减运算实现字符交换]): %s\n", getstring10);

	return 0;
}

/*
 * VC6.0调试结果:
str1字符串是: abcd
str2字符串是: abcdefg
str1 字符串反转的结果getstring1是(递归法): dcba
getstring1 字符串反转的结果是(下标法): abcd
getstring3 字符串反转的结果是(指针法): dcba
getstring5 字符串反转的结果是(指针法 [异或运算实现字符交换]): abcd
getstring7 字符串反转的结果是(指针法 [加减运算实现字符交换]): dcba

str2 字符串反转的结果getstring2是(递归法): gfedcba
getstring2 字符串反转的结果是(下标法): abcdefg
getstring4 字符串反转的结果是(指针法): gfedcba
getstring6 字符串反转的结果是(指针法 [异或运算实现字符交换]): abcdefg
getstring8 字符串反转的结果是(指针法 [加减运算实现字符交换]): gfedcba
Press any key to continue
*/