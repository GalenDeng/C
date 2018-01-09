#include <stdio.h>
#include <string.h>

int main()
{
	int k,i,j;
	char a[2000];
	while(gets(a) != '\0')
	{
		j = strlen(a);
		for(i=0,j=j-1;i<=j;i++,j--)
		{
		if(a[i] != a[j]) break;
		}
		if(i<j) 
		{
			printf("不是回文\n");
		}
		else printf("是回文\n");

	}


	return 0;
}