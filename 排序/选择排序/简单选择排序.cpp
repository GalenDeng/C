// 简单选择排序
#include <iostream>
using namespace std;
void SelectSort(int array[],int len)
{
	int tmp;	// 暂存最小值
	int t;		// 记录每一趟的最小数的下标值
	for (int i = 0; i < len - 1; ++i)	// 遍历 n -1 趟(结合选择排序的算法实现图解可知)
	{
		tmp = array[i];
		t = i;

		for (int j = i; j < len; ++j)	// 每一趟都选取出待排序序列中的最小值
		{
			if ( array[j] < tmp ) {
				 tmp = array[j];
				 t = j;
			}
		}

		// 把最小元素和每一趟待排序的首元素交换(如果最小值不是待排序序列的首元素的时候)
		array[t] = array[i];
		array[i] = tmp;

	}
}

int main(void)
{
	int array[10] = { 11,21,67,98,43,66,44,99,38,80};
	cout << "原序列为:  \n";
	for (int i = 0; i < 10; ++i)
	{
		cout << array[i] << "  ";	
	}
	cout << endl;
	SelectSort(array, 10);
	cout << "选择排序后的序列为: " << endl ;
	for (int j = 0; j < 10; ++j)
	{
		cout << array[j] << "  ";	
	}	
	cout << endl;
	return 0;
}

/*
 * VC6.0调试结果:
原序列为:
11  21  67  98  43  66  44  99  38  80
选择排序后的序列为:
11  21  38  43  44  66  67  80  98  99
Press any key to continue

*/