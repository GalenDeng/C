// 基数排序  Radix Sort
#include <iostream.h>
#include <math.h>

// 查找最大的元素
int FindMax(int a[], int len )
{
	int max = a[0];
	for ( i = 1; i < len; i++)
	{
		if ( max < a[i] ) {
			max = a[i];
		}
	}
	return max;
}

// 确定最大元素的最高位
int DigitNumber(int number)
{
	int digit = 0;
	do
	{
		number /= 10;
		digit++;
	} while (number != 0);
	return digit;
}


// 得到各值各个位的基数Radix
int KthDigit(int number,int kth)
{
	number /= pow(10,kth);			// c = pow(a,b) => a的b次方 = c
	return number % 10;
}

// 对长度为len的数组进行基数排序
void RadixSORT(int array[],int len)
{

	int *temp[10];		// 定义10个指针数组,分别对应 0-9个桶
	int count[10] = { 0,0,0,0,0,0,0,0,0,0};	// 用于存储每个( 0 - 9 )桶子装有多少元素 (记录元素个数)

	int max = FindMax(array, len );		// 找到最大元素值
	int maxdigit = DigitNumber(max);		// 确定这个最大元素值的最高位的位数,即外循环 digit次

	int i,j,k;
	for (i = 0; i < 10; ++i)
	{
		temp[i] = new int[len];			// 使到每一个箱子都能装下len个int元素
		memset(temp[i],0,sizeof(int)*len);
	}

	for ( i = 0; i < maxdigit; ++i)		// 外循环 digit次
	{
		memset(count,0,sizeof(int) * 10);	// 每次装桶前把count清空 (清除元素个数记录)
		for ( j = 0; j < len ; ++j)
		{
			int t = KthDigit(array[j],i);	// 取得该元素该位的数值
			temp[t][count[t]] = array[j];	// 暂存该元素在temp[t]这个桶中,且在这个桶中排在count[t]的位置
			count[t]++;						// 此桶的计数递增
		}

		int index = 0;		// 用作一次基数排序结束后,序列从桶中取出的索引
		for (j = 0; i < l0; ++j)			// 0-9数字 --- 10个桶
		{
			for ( k = 0; k < count[k]; ++k)	// 每个桶有多少个元素
			{
				a[index++] = temp[j][k];// index++ : 先把返回值index = t 给a[t],然后再 index = index +1
			}
		}
	}

	for (i = 0; i < 10; ++i)
	{
		delete[] temp[i];				// 释放堆内存空间
	}

}


int int main(void)
{
	int array[] = { 22,32,19,53,47,29};
	RadixSORT(array,6);
	return 0;
}

/*
 * VC6.0调试结果:
原序列为:
22      32      19      53      47      29
基数排序后的序列为:
19      22      29      32      47      53
Press any key to continue
*/