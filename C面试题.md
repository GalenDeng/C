## C面试题 (2018.1.14)
1. [面试题1](http://blog.csdn.net/lincoln_2012/article/details/49179503)
2. [面试题2](http://blog.csdn.net/liucong2004/article/details/4210651)
3. [面试题3](http://blog.csdn.net/lostinai/article/details/8729123)
4. [面试题4](http://blog.csdn.net/xww810319/article/details/17785291)
5. [面试题5](http://blog.csdn.net/hkh5730/article/details/14674183)
6. [面试题6](http://blog.csdn.net/hnust_xiehonghao/article/details/17638297)
7. [面试题7](http://blog.csdn.net/qq_30925271/article/details/49312723)
8. [面试题8](http://blog.csdn.net/yishengzhiai005/article/details/50733242)
9. [面试题9](http://blog.csdn.net/myblog_dwh/article/details/26601093)
10. [面试题10](http://blog.csdn.net/jxnu_xiaobing/article/details/12561141)
11. [linux驱动面试题整理](http://blog.csdn.net/lhhero701/article/details/51171948)
12. [常见linux驱动面试题](http://blog.csdn.net/qq_31505483/article/details/75012661)
13. [嵌入式软件工程师面试题](http://blog.csdn.net/u012478275/article/details/51546465)
14. [Linux设备树语法详解](http://www.cnblogs.com/xiaojiang1025/p/6131381.html)
15. [Linux驱动开发](http://www.cnblogs.com/xiaojiang1025/category/918665.html)
16. [从零开始写设备树DTS](http://blog.csdn.net/woshidahuaidan2011/article/details/52948732)
17. [C 语言运算符优先级（记忆口诀）](http://blog.csdn.net/u013630349/article/details/47444939)
18. [C语言运算符优先级和口诀](http://www.cnblogs.com/zhanglong0426/archive/2010/10/06/1844700.html)
 
```
笔试的时候大多是基础为主,如果说要找重点的话
1.<C/C++高质量编程>最后的那张卷子
2.<The C programming language>里的课后题和例程.
3.struct的大小(注意编译器,操作系统,硬件体系,最好自己实验出结果).
4.冒泡排序,快速排序,shell排序,折半查找,约瑟夫环,链表的操作.
5.google搜<C语言面试题>(要知道,一般的面试题也是这样出来的,呵呵)
```

## `Sizeof与Strlen的区别与联系`
[Sizeof与Strlen的区别与联系](http://www.cnblogs.com/carekee/articles/1630789.html)
```
一、sizeof
    sizeof(...)是运算符，在头文件中typedef为unsigned int，其值在编译时即计算好了，参数可以是数组、指针、类型、对象、函数等。
    它的功能是：获得保证能容纳实现所建立的最大对象的字节大小。
    由于在编译时计算，因此sizeof不能用来返回动态分配的内存空间的大小。实际上，用sizeof来返回类型以及静态分配的对象、结构或数组所占的空间，返回值跟对象、结构、数组所存储的内容没有关系。
    具体而言，当参数分别如下时，sizeof返回的值表示的含义如下：
    数组——编译时分配的数组空间大小；
    指针——存储该指针所用的空间大小（存储该指针的地址的长度，是长整型，应该为4）；
    类型——该类型所占的空间大小；
    对象——对象的实际占用空间大小；
    函数——函数的返回类型所占的空间大小。函数的返回类型不能是void。

二、strlen
    strlen(...)是函数，要在运行时才能计算。参数必须是字符型指针（char*）。当数组名作为参数传入时，实际上数组就退化成指针了。
    它的功能是：返回字符串的长度。该字符串可能是自己定义的，也可能是内存中随机的，该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符NULL。返回的长度大小不包括NULL。
    eg1、char arr[10] = "What?";
              int len_one = strlen(arr);
              int len_two = sizeof(arr); 
              cout << len_one << " and " << len_two << endl; 
    输出结果为：5 and 10
    点评：sizeof返回定义arr数组时，编译器为其分配的数组空间大小，不关心里面存了多少数据。strlen只关心存储的数据内容，不关心空间的大小和类型
```
## 指针
```
#include <stdio.h>

void main()
{
	int b=3;

	int arr[]={6,7,8,9,10};

	int *ptr = arr;

	*(ptr++) += 123;

	printf("%d,%d,%d\n",*(ptr-1),*ptr,*(++ptr));
}
```
```
打印结果:
7,8,8
Press any key to continue
```
## `*(ptr++) 和 *ptr++ 是一样的` --- `都是最后才得到 ptr = ptr + 1`
```
#include <stdio.h>
void main() 
{ 
char *ptr = "csdn";  
printf("%c\n",*ptr++);
}
```
```
#include <stdio.h>
void main() 
{ 
char *ptr = "csdn"; 
printf("%c\n",*(ptr++)); 
}
```
```
打印结果:
c
Press any key to continue
```
## C中的printf计算参数是从右到左压栈的
* 例子：见程序员面试宝典的 5.2.2 P34