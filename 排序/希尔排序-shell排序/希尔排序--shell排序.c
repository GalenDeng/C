// 希尔排序 --- shell排序

#include <stdio.h>

void InsertSort(int array[],int num)
{
	int h,i,j,temp;

	for ( h = num / 2; h > 0; h = h / 2)	// h 为步长,也是分组的份数
	{
		for (i = h; i < num; i++)			// 直接插入排序
		{
			temp = array[i];
			for (j = i-h; j >= 0 && temp < array[j]; j-=h)
			{
				array[j+h] = array[j];
			}
			array[j+h] = temp;
		}
	}
}

// 打印数组
void ArrayPrint(int array[], int num)
{
	int i = 0;
	for ( i = 0; i < num; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[10] = { 11,31,34,56,43,21,11,54,44,65 } ;
	printf("原序列为: \n");
	ArrayPrint(array,10);

	printf("希尔排序后的序列为: \n");
	InsertSort(array,10);
	ArrayPrint(array,10);
	return 0;
}

/*
 * VC6.0调试结果:
原序列为:
11      31      34      56      43      21      11      54      44      65
希尔排序后的序列为:
11      11      21      31      34      43      44      54      56      65
Press any key to continue
*/