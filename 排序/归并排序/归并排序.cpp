// 归并排序 --- 用到递归算法思想
#include <iostream>
using namespace std;

// 合并
void merge(int array[],int tmp[],int left,int mid,int right)
{
	int  low = left, high = mid + 1;
	int tmpPos = left;
	int array_len = right - left + 1;	// 数组长度

	// 两序列对比,从第二个序列中依次拿元素a[j]和序列一的元素(先从左首元素开始)a[i]对比,小于等于就把a[j]放在tmp这个数组桶中
	// 大于就把a[i]放在tmp这个数组桶中
	while (low <= mid && high <= right) {
		if (array[high] <= array[low]) {
			tmp[tmpPos++] = array[high++];
		} else {
			tmp[tmpPos++] = array[low++];
		}
	}

	// 如果对比完,序列一还有元素剩下，则把这些元素依次放到tmp这个数组桶中
	while (low <= mid) {
		tmp[tmpPos++] = array[low++];
	}

	// 如果对比完,序列二还有元素剩下，则把这些元素依次放到tmp这个数组桶中
	while (high <= right) {
		tmp[tmpPos++] = array[high++];
	}

	// 从临时数组桶中取出数据放在原序列的数组中
	for (int k = 0; k < array_len; k++,right--)		// 注意这里是从right开始取出
	{
		array[right] = tmp[right];
	}


}


// 分解
// int a[]  	:原序列数组
// int tmp[] 	: 该数组的作用是临时存储序列的元素,进行插入排序 
// low : 序列首元素 high : 序列尾元素(array.length - 1)
void msort(int array[],int tmp[],int low,int high) {
	if (low >= high) {		// 递归结束条件
		return;
	}
// 按被调函数的顺序执行(递归调用语句前) => 递归调用函数 => 按被调函数的相反顺序执行(递归调用语句后)
// int middle=(low + high)/2; 这段代码相当于在这代码外加了一层for循环,但是这段代码按被调函数的顺序执行
	int middle = (low + high) / 2 ;		

	msort(array,tmp,low,middle);		// 递归分解左序列(归并左序列)
	msort(array,tmp,middle+1,high);		// 递归分解右序列(归并右序列)
//  merge(array,tmp,low,middle+1,high); 这段代码相当于在这代码外加了一层for循环,但是这段代码按被调函数的相反顺序执行
	merge(array,tmp,low,middle,high);	// 组合,把两个有序序列合并成一个有序序列
}

void merge_sort(int array[],int len)
{
	int *tmp= NULL;	
	tmp = new int[len];		// 申请足够的临时内存来存取序列的元素
	if (tmp != NULL) {		// 检验是否成功申请堆内存(动态内存)
		msort(array,tmp,0,len-1);	// 调用msort进行归并排序
		delete[] tmp;				// 归并排序结束后记得释放内存空间
	}

}

void ArrayPrint(int array[],int len)
{
	int i =0;
	for (i =0; i< len; i++) {
		printf("%d\t",array[i]);
	}
	printf("\n");
}

int main()
{
	int array[8] = { 8,6,1,3,5,2,7,4};
	printf("原序列为: \n");
	ArrayPrint(array,8);

	merge_sort(array,8);
	printf("归并排序后的序列为: \n");
	ArrayPrint(array,8);
	return 0;
}

/*
 * VC6.0调试结果:
原序列为:
8       6       1       3       5       2       7       4
归并排序后的序列为:
1       2       3       4       5       6       7       8
Press any key to continue
*/