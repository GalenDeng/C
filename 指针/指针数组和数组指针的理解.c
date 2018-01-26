
// 指针数组和数组指针的理解
#include <stdio.h>

int main()
{
	char *str[] = {"Welcome","to","Fortemedia","Nanjing"};
	char **p = str + 1;			// str + 1 二维数组 + 1 == str[1]
	str[0] = (*p++) +2;
	str[1] = *(p+1);
	str[2] = p[1] + 3;
	str[3] = p[0] + (str[2]-str[1]);

	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);

	return 0;
}

// 图解见:
/*
* VC6.0调试结果:

Nanjing
jing
g
Press any key to continue
*/