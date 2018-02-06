// 编写实现memcpy函数--内存复制
#include <stdio.h>
//#include <assert.h>
void *memcpy2(void *memTo,const void *memForm,size_t size)
{
	if (memTo == NULL || memForm == NULL) {		// 检验有效性(是否正常初始化)
		return NULL;
	}

//	assert((memTo != NULL)&&(memForm != NULL));
	char *tempForm = (char *)memForm;
	char *tempTo   = (char *)memTo;		// 保存首地址

	while (size-- > 0) {
		*tempTo++ = *tempForm++;		// 复制
	}

	return memTo;						// 返回地址 
										// 为了实现链式表达式 => 调用方便,程序结构简洁
}

int main(void)
{
	char strSrc[] = "hello world!";
	char strDest[30];

	memcpy2(strDest,strSrc,4);	// 复制四个字符
	strDest[4] = '\0';			// 添加结束符
	printf("strDest: %s\n", strDest);
	return 0;
}			

/*
 * VC6.0调试结果:
strDest: hell
Press any key to continue
*/