// 冒泡排序
#include <stdio.h>
int array[101];

// 交换数据
void swap(int x , int y)
{
	int temp;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

int main()
{
	int num,val,i,j,temp;

	printf("请输入要建立的数组元素的个数: \n");
	scanf("%d",&num);
	printf("请输入数组的元素数据: \n");

	// 数据存放在数组array中
	for ( i = 1; i <= num; ++i)
	{
		scanf("%d",&val);
		array[i] = val;
	}

	for ( i = 1; i <=num-1; i++)
	{
		for (j = 1;j<=num-i; j++)
		{
			if (array[j] > array[j+1]) {
				swap(j,j+1);
			}
		}
	}

	printf("冒泡排序的数组: \n");
	for ( i = 1; i <= num; ++i)
	{
		printf("%d\t", array[i]);
	}	
	return 0;
}