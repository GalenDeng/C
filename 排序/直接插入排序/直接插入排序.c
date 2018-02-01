// 直接插入排序

#include <stdio.h>


// 直接插入排序算法核心代码
void  InsertSort(int array[],int num)
{
	int i,j,temp;
	// 从小到大排序
	for (i = 1; i < num; i++)	// 外部循环
	{
		temp = array[i];		// 要插入到前面有序序列的数值
		for ( j = i - 1/*从右向左比较数值大小 */; j>=0,temp < array[j]; j--)		// 插入的数小于前面的序列的时候,有序序列向后移动
		{
			array[j+1] = array[j]; 	// 有序序列的数向后移
		}
	array[j + 1] = temp;
	}
}

// 打印序列
void ArrayPrint(int array[],int num)
{
	int i;
	for ( i = 0; i< num; i++) {
		printf("%d\t", array[i] );
	}
	printf("\n");
}

int main()
{
	int array[10] = {11,21,32,10,9,32,22,76,81,94};
	printf("原序列为: \n");
	ArrayPrint(array,10);

	InsertSort(array,10);
	printf("直接插入排序后的有序序列为: \n");
	ArrayPrint(array,10);
	return 0;
}

/*
 * VC6.0的调试结果:
原序列为:
11      21      32      10      9       32      22      76      81      94
直接插入排序后的有序序列为:
9       10      11      21      22      32      32      76      81      94
Press any key to continue
*/