/* 对一组数通过最大堆进行从小到大排序  --- 堆排序 */
#include <stdio.h>
int n;	// 用来存储堆中元素的个数,即堆的大小
int array[101];	// 用来存放堆的数组

// 交换数据
void swap(int x , int y)
{
	int temp;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
	return;
}

// 确定这组数的元素个数,把这些元素依次存入array数组中
void ArrayCreate(int num) 
{
	int i = 1;
	int val;
	for (i = 1; i <= num; ++i)
	{
		scanf("%d",&val);
		array[i] = val;
	}
}

// (最大堆)向下调整函数
void shiftdown (int i)
{
	int temp;
	int flag = 0;	// 用来标记是否需要继续向下调整
	// array[i](父节点) 与 array[2i](子节点)
	// 存在左儿子的时候,它和左儿子比较
	while(i*2 <= n && flag == 0) {
		if (array[i] < array[i*2]) {
			temp = i * 2;					// 交换数值
		} else {
			temp = i;
		}

		// 存在左儿子的时候,和右儿子对比
		if (i*2+1 <= n ) {
			if (array[temp] < array[i*2+1]) {
				temp = i * 2 + 1;
			}			
		}

		// 如果发现最大的节点编号不是自己,要进行交换处理
		if (temp != i) {
			swap(i,temp);	// 交换数据
			i = temp;			// 更新i的为刚才与它交换的儿子的编号,实现向下调整处理 --- 关键
		} else {
			flag = 1;		// 当前的父结点已经比两个子结点大了,所以不需要再进行向下调整处理了 
		}
	}
	return;
}

// 建立最大堆
void HeapCreate()
{
	int i = 0;
	for (i = n / 2 ; i >=1 ; i--) {
		shiftdown(i);	// 向下调整函数
	}
	return;
}

// 从小到大排序
void HeapSort()
{
	// 实现数组array[1] => array[n] 从小到大排序
	while (n > 1) {
		swap(1,n);
		n--;
		shiftdown(1);		
	}
	return;
}

// 数组输出
void ArrayPrint(int num)
{
	int i = 1;
	for ( i = 1; i <= num; i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
}

int main()
{
	int num;			// 读入多少个数字

	printf("输入多少个元素: \n");
	scanf("%d",&num);
	n = num;
	printf("请输入元素的数据: \n");
	ArrayCreate(num);		// 元素依次存入array数组中
	HeapCreate();	// 建立最大堆
	printf("最大堆的元素分布为: \n");
	ArrayPrint(num);	// 数组输出

	printf("堆排序 -- 从小到大排序后: \n");
	HeapSort();			// 从小到大排序
	ArrayPrint(num);	// 数组输出
	return 0;

}

/*
 * VC6.0调试结果:
输入多少个元素:
7
请输入元素的数据:
11 12 13 14 15 16 17
最大堆的元素分布为:
17      15      16      14      12      11      13
堆排序 -- 从小到大排序后:
11      12      13      14      15      16      17
Press any key to continue
*/