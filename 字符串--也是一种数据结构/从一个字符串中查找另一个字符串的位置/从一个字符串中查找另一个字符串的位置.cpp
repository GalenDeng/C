// 从一个字符串中查找另一个字符串的位置 --- strstr("12345","34")返回2,在2号位置找到字符串34
#include <stdio.h>

const char *StrStr(const char *src,const char *sub)
{
	const char *bp,*sp;						// *src *sub为常量 => *bp *sp也必为常量 ===  之前为常量 => 之后也必为常量才行 => const
	if (src == NULL || sub == NULL) {		// 检查src和sub是否正确初始化 --- 检验有效性
		return NULL;
	}

	while (*src) {							// 遍历原字符串
		bp = src;
		sp = sub;							// 子字符串
		do
		{
			if (!*sp) {						// 若 *sp = '\0' , 出口
				return src;					// 返回从sub字符串开头的指针位置
			}
		} while (*bp++ == *sp++);			// 若 *bp === *sp 就进入do{} => 入口
		src += 1;							// 遍历计数移位		
	}

	return NULL;							// 遍历了整个字符串src都找不到字符串sub,报错	
}

int main(void) 
{
	char src[]  = "12345";
	char sub1[] = "32";							
	char sub2[] = "34";							
	const char *ptr1 = StrStr(src,sub1);		// StrStr函数的返回值是常量,所以 *ptr也要定义为常量 const char *ptr
	const char *ptr2 = StrStr(src,sub2);		// StrStr函数的返回值是常量,所以 *ptr也要定义为常量 const char *ptr
	printf("ptr1: %s\n", ptr1);					// 返回空
	printf("ptr2: %s\n", ptr2);					// 返回345
	return 0;
}	

/*
 * 
ptr1: (null)
ptr2: 345
Press any key to continue
*/