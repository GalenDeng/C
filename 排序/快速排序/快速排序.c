// 快速排序 --- 啊哈!算法 P12 - P20

#include <stdio.h>
int array[101];

void swap (int x ,int y) 
{
	int temp;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

// 从小到大排序
void QuickSort(int left, int right)
{
	int temp,i,j;

	if (left > right) {
		return ;
	}

	temp = array[left];	// 暂时存储这个值,作为基准值
	i = left;
	j = right;

	while (i != j) {
		while ( array[j] >= temp && i < j) {
			j--;
		}			// 哨兵j先走,走到第一个比基准值小的位置,然后停下

		while (array[i] <= temp && i < j) {
			i++;
		}			// 哨兵i后走,走到第一个比基准值大的位置,然后停下
		if (i < j) {		// 两哨兵没有相遇的时候
			swap (i,j) ;	// 交换哨兵 i,j 所在位置的值	
		}
	}
	array[left] = array[i];	// 基准位置的值和此时哨兵i位置(也是哨兵j的位置,因为两者相遇)的值交换
	array[i] = temp;

	QuickSort(left, i-1);
	QuickSort(i+1,right);
	return;
}

int main()
{
	int num,val,i,j;

	printf("请输入要建立的数组元素的个数: \n");
	scanf("%d",&num);
	printf("请输入数组的元素数据: \n");

	// 数据存放在数组array中
	for ( i = 1; i <= num; ++i)
	{
		scanf("%d",&val);
		array[i] = val;
	}

	QuickSort(1,num);		// 快速排序

	// 打印快速排序后的数组
	printf("快速排序后的数组: \n");
	for ( i = 1; i <= num; ++i)
	{
		printf("%d\t", array[i]);
	}

	return 0;
}

/*
 * VC6.0调试结果:
请输入要建立的数组元素的个数:
5
请输入数组的元素数据:
87 65 544 33 22
快速排序后的数组:
22      33      65      87      544     Press any key to continue

*/