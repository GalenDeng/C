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

## `类型强制转换与运算符的优先级`
```
#include <stdio.h>
int main()
{
	unsigned char a = 0xA5;
	unsigned char b = ~a>>4+1;  // 参考该文件的运算符的优先级的记忆口诀(在链接中)
	printf("b=%d\n",b);         // b = 250
	return 0;
}
```
## `单目/双目/三目运算符的定义`
```
* 单目运算符是指运算所需变量为一个的运算符，又叫一元运算符，其中有逻辑非运算符:!、按位取反运算符:~、自增自减运算符:++， --等
* 运算所需变量为两个的运算符叫做双目运算符，例如+，-，*，/，%，<，>，>=，<=，==，!=，<<，>>，&，^，|，&&，||，=
* 运算所需变量为三个的运算符叫做三目运算符，只有条件表达式【?:】
```
## `有2个数据，写一个交换数据的宏`
```
#include <stdio.h>
#include <string.h>

#define swap(a,b) \
{ char tempBuf[10]; memcpy(tempBuf,&a,sizeof(a)); \
memcpy(&a,&b,sizeof(b)); memcpy(&b,tempBuf,sizeof(a));}

int main()
{
	double a=2,b=3;

	swap(a,b);

	printf("%1f,%1f\n",a,b);
	return 0;
}
```
```
* 得出结果
3.000000,2.000000
Press any key to continue
```
## `宏定义`
```
#include <stdio.h>
#define SUB(x,y) ((x)-(y))
#define ACCESS_BEFORE(element,offset,value) *SUB(&element,offset) =value

int main()
{
	int i; int array[10] = {1,2,3,4,5,6,7,8,9,10};
	ACCESS_BEFORE(array[5],4,6);
	for( i=0; i<10; ++i)
	{
		printf("%d",array[i]);
	}
	return (0);
}
```
```
VC6.0的结果:
16345678910Press any key to continue
```
## 解读复杂指针声明的方法
* 使用右左法则：首先从最里面的圆括号看起，然后往右看，再往左看，每当遇到圆括号时,应该掉转阅读方向。
* 一旦解析完圆括号里面的所有的东西，就跳出圆括号，重复这个过程，直到整个声明解析完毕。
* 应该是从未定义的标识符开始阅读，而不是从括号读起
* 具体分析见 《C和C++程序员面试秘笈》 P58

## `指针赋值`
```
#include <stdio.h>

int main(void)
{
	char a[]= "hello,world";
	char *ptr = a;

	printf("%c\n", *(ptr+4));
	printf("%c\n", ptr[4]);
	printf("%c\n", a[4]);
	printf("%c\n", *(a+4));

	*(ptr+4)+=1;
	printf("%s\n",a);

	return 0;
}
```
```
程序的效果：
o
o
o
o
hellp,world
Press any key to continue
```
## `数据对齐 -- sizeof`
* 程序员面试宝典 P52
* char : 1字节; short : 2字节; int ；4字节; float : 4字节; long : 4字节;  double : 8字节

## `sizeof 和 strlen`
* strlen()的参数只能是 char* , 且必须是以“\0”结尾的
* char* ss="1234"; // strlen(ss) = 4
* int ss[4] ;	   // strlen(ss) 错误
* 详细介绍 : 程序员面试宝典 P57
* 数组作为参数传给函数时传递的是指针而不是数组,传递的是数组的首地址,
* 如 fun(char [8])、 fun(char [])都等价于fun(char *)。在C++ 里传
* 递数组永远都是传递指向数组首元素的指针,编译器不知道数组的大小

## `sizeof的意义`
```
#include <stdio.h>
int main(void)
{
	int a =8;
	printf("%d\n",a);
	printf("%d\n",sizeof(a));
	printf("%d\n",sizeof(a = 6));		// sizeof的括号内的内容在编译过程中是不被编译的,而是被替代类型
										// 在编译过程中,不管a的值是什么，只是被替换成类型sizeof(int),
										// 而 a= 6 是不被编译的,所以 a 还是等于 8 , 是不变的。
	sizeof(a =6);
	printf("%d\n",a);
}
```
```
* VC6.0的执行结果:
8
4
4
8
Press any key to continue
```
## `数组作为参数传给函数时传递的是指针而不是数组,传递的是数组的首地址`
* fun(char a[8]) , fun(char a[]) 都等价于 fun(char *)
```
#include <stdio.h>

int test(char var[])
{
	return sizeof(var);
}
int main(void)
{
	char var[10];
	int a;
	a = test(var);
	printf("%d\n",a);
}
```
```
* VC6.0的执行结果:
4
Press any key to continue
```
## `空类占内存空间为 1 ;单一继承和多重继承的空类占内存空间为 1 ; 虚继承的空类占内存空间为 4(涉及虚指针)`
## `传递动态内存 --- 函数参数传递、值传递、指针传递(地址传递)、引用传递` 
* 程序员面试宝典 P67

## `动态内存`
```
#include <iostream.h>
#include <stdio.h>
void GetMemory(char *p,int num)				// 这里的 p 为str的一个副本, 指向 NULL(即不指向任何位置的内存)
{
	p = (char *)malloc(sizeof(char)*num);	// 申请新的内存,即这里改变副本p的指向位置，这里p的指向从NULL指向申请的新											// 的内存位置,即现在str和p的指向不一样了,这里申请的内存没有进行释放,
											// 会一直占用内存空间, 造成内存的泄漏
}

int main()
{
	char *str = NULL;

	GetMemory(str,100);
	strcpy(str,"hello");					// 因为str没有指向任何的内存空间,这里执行字符串的赋值会导致程序崩溃
	return 0;
}
```
* 如果一定要用指针参数取申请内存,那么应该采用指向指针的指针(char **p),传str的地址给函数GetMemory
```
#include <iostream>
using namespace std;
void GetMemory(char **p,int num)
{
	*p = (char *)malloc(sizeof(char)*num);
}

int main()
{
	char *str = NULL;

	GetMemory(&str,100);
	strcpy(str,"hello");
	cout << *str << endl;		// 字符串的某一字符的值
	cout << str  << endl;		// 字符串的值
	cout << &str << endl;		// 字符串的地址
	return 0;
}
```
```
* VC6.0调试结果：
h
hello
0019FF3C
Press any key to continue
```
## 函数返回值来传递动态内存
```
#include <iostream>
using namespace std;
char *GetMemory(char *p,int num)			// 函数返回值传递动态内存
{
	p = (char *)malloc(sizeof(char)*num);
	return p;
}

int main()
{
	char *str = NULL;

	str= GetMemory(str,100);
	strcpy(str,"hello");
	cout << *str << endl;
	cout << str  << endl;
	cout << &str << endl;
	return 0;
}
```
```
* VC6.0调试结果：
h
hello
0019FF3C
Press any key to continue
```
##  整型变量传值
```
#include <iostream>
using namespace std;

void Getmemory(int *z)
{
	*z = 5;
}

int main()
{
	int v;
	Getmemory(&v);
	cout << v << endl;
	return 0;
}
```
```
* VC6.0调试结果：
5
Press any key to continue
```
## `局部数组:内存中的栈;指针变量是全局变量:内存中的全局区域(静态存储区);字符串常量:只读数据段`
* 1. `字符串常量`
```
char *c = "hello world ";	// &c ：保存在静态存储区  "hello world":保存在只读数据段中(不允许修改)
*c = 't';	// 因为指针c直接指向只读数据段中的"hello world"的地址,尝试修改首地址的值为't',当然会失败(编译器报错)
```
* 2. `局部变量` 
```
char c[] = "hello world";	// char c[] : 字符数组，属于局部数组,保存在内存中的栈中,
							// 这里就是从只读数据段中copy一份"hello world"保存在局部数组相对应的栈地址中
c[0] = 't';					// 改变栈中的局部数组第一个元素的值为't'
```
3. `static`
* 不加 static的时候,函数strA在调用完毕之后,str这个局部变量就释放了,栈的临时空间被重置,所以返回的结果是不确定的
* 且不安全的,随时都有被收回的可能，添加static关键字后,改变了str的存储方式,在函数调用完毕之后,值不变
```
const char* strA()			// 添加 const , 定义函数的返回值不能修改
{
	static char str[] = "hello world";	// 添加 static关键字,将局部数组变为静态局部数组,存储方式从 栈 => 静态存储区
	return str;
}
```
4. `代码实验`
* 代码
```
#include <iostream>
using namespace std;

int main()
{
	char *c = "hello world";
	*c = 't';					// 不能尝试去改变字符串常量(只读数据段)
	cout << c << endl;
	return 0;
}
```
* 实现结果 : 程序崩溃
5. `数组指针`
```
#include <iostream>
using namespace std;
int main()
{
	static int a[2] = {1,2};

	int *ptr[5];

	int p=5,p2=6,*page,*page2;

	int Test[2][3] = { {1,2,3},{4,5,6}};
	int Test2[3] = { 1,2,3};

	page =&p;
	page2 = &p2;

	ptr[0] = &p;
	ptr[1] = page2;

	int (*A)[3],(*B)[3];

	A = &Test[1];		// 二维数组 这里的Test[1] = Test[1][0]
	B = &Test2;

	cout << *page<<endl;
	cout << (*A)[0] << (*A)[1] << (*A)[2] << endl;
	cout << (*B)[2] << endl;
	return 0;
}
```
```
* VC6.0测试结果
5
456
3
Press any key to continue
```
*  (*B)[3] = 1 (*B)[4] = 2 (*B)[5] = 3 (*B)[6] = 4 ... 逐渐递增

## `数组名的识别记忆方法 --- 通过 一级指针还是二级指针判断`
* 如下所示, a 表示为数组名(而数组名本身就是指针),再加个&,就变成双级指针(有时可以看作为二维数组)
```
* int a[2]={1,2};
``` 
```
#include <iostream>
using namespace std;
int main()
{
	int a[] = {1,2,3,4,5};
	int *ptr = (int *)(&a + 1);			// 表示 a[6]
	printf("%d,%d\n",*(a+1),*(ptr-1));
	return 0;
}

* VC6.0的测试结果:
2,5
Press any key to continue
```

```
int v[2][10];
int (*a)[10] = v;	// 数组指针	, v 为 数组名(即指针), 所以这里的 a 可以理解为二级指针
所以:
cout << **(a + 1) << endl;  // a + 1 表示 v[1][0]的地址 *(a+1)= v[1][0] 
cout << *(a[1])   << endl; 	// 结果同上
```
## `迷途指针(悬浮指针)(失控指针)`
1. 定义
```
* 当对一个指针进行delete操作后 ---这样会释放它所指向的内存---并没有把它设置为空指针而产生的
* 如果上述的情况没有赋值就试图再次使用该指针，引起的结果是不可预料的。
```
* 当delete一个指针的时候,实际上只是让编译器释放内存,但指针本身依然存在,此时为迷途指针

## `this指针`
1. 理解
```
* 关于this指针,有这么一段描述：当你进入到一个房子后,你可以看到桌子、椅子、地板等,
  但你看不到房子的全貌
* 对于一个类的实例来说,你可以看到它的成员函数、成员变量,但是实例本身看不到,this指针
  就是这样的一个指针,它时时刻刻指向这个实例本身
```
2. 成员函数默认的第一个参数为 T* const this
```
class A
{
	public:
	int func(int p) { } 
};

func的原型在编译器看来应该是:
int func( A* const this, int p);
* 当调用一个类的成员函数时,编译器将类的指针作为函数的this参数传递进去
  A a;
  a.func(10);
  编译器将会编译成:
  A::func(&a,10);
```
* this是个指向对象的"常指针"
## `float、double、int的存储方式`
```
#include <iostream>
using namespace std;
int main()
{

	double a=12.3;
	a=(int)a;
	printf("%f\n",5);			// 输出 0.000000  在printf中float会自动转换为double,因此从stack中读8个字节
	printf("%d\n",5.01);		// 输出一个很大的数
	cout << a << endl;			// 12
	return 0;
}

答：a是double型，值为12
double a = 12.3; 说明a为double型
a = (int)a; 先把a显式强制转换成int，再隐式转换成double，中间有精度丢失

* VC6.0的结果是:
0.000000
1889785610
12
Press any key to continue
```
## `十进制小数转换二进制的问题`
[转帖：float型和double型数据的存储方式](https://www.cnblogs.com/fly-height/articles/2340396.html)
[C中double到int的转换、四舍五入](http://blog.csdn.net/lin200753/article/details/27952897)
```
无论是单精度还是双精度在存储中都分为三个部分：

符号位(Sign) : 0代表正，1代表为负
指数位（Exponent）:用于存储科学计数法中的指数数据，并且采用移位存储
尾数部分（Mantissa）：尾数部分

120.5用二进制表示为：1110110.1用二进制的科学计数法表示1000.01可以表示为1.00001*clip_image002[2],1110110.1可以表示为1.1101101*clip_image002[3],任何一个数都的科学计数法表示都为1.xxx*clip_image002[1],尾数部分就可以表示为xxxx,第一位都是1嘛，干嘛还要表示呀？可以将小数点前面的1省略，所以23bit的尾数部分，可以表示的精度却变成了24bit，道理就是在这里，那24bit能精确到小数点后几位呢，我们知道9的二进制表示为1001，所以4bit能精确十进制中的1位小数点，24bit就能使float能精确到小数点后6位，而对于指数部分，因为指数可正可负，8位的指数位能表示的指数范围就应该为:-127-128了，所以指数部分的存储采用移位存储，存储的数据为元数据 127，下面就看看8.25和120.5在内存中真正的存储方式
```
```
整数和小数分别转换。
整数除以2，商继续除以2，得到0为止，将余数逆序排列。
22 / 2  11 余0
11/2     5  余 1
5 /2      2  余 1
2 /2      1  余 0
1 /2      0  余 1
所以22的二进制是10110
小数乘以2，取整，小数部分继续乘以2，取整，得到小数部分0为止，将整数顺序排列。
0.8125x2=1.625 取整1,小数部分是0.625
0.625x2=1.25 取整1,小数部分是0.25
0.25x2=0.5 取整0,小数部分是0.5
0.5x2=1.0 取整1,小数部分是0，结束
所以0.8125的二进制是0.1101
十进制22.8125等于二进制10110.1101
```
## `(int)"a"`
```
int i = (int)"a";		// 此处的意思是把把这个字符串首字母在常量区的内存地址转化为int类型, 再赋值给i
cout << i << endl;		// 得出 4648988这个int内存地址

char *p = "a";
int i = (int)p;			// 把p的值(即“a”的常量区内存地址)转化为int型再赋值给i
cout << i << endl;		// 得出 4648988这个int内存地址
```
## `C++类型转换`
* 转换符: static_cast const_cast dynamic_cast reinterpret_cast
* static的限制: 不能把struct转换为int、不能把double转换为指针类型、不能去除const属性
* reinterpret: 通常为操作数的位模式提供底层的重新解释
```
int firstNumber,secondNumber;
double result = static_cast(double)(firstNumber)/secondNumber;
```
## `unsigned short int`
* 在 unsigned short int 中无符号的 -1的结果就是 65535
```
#include <iostream>
using namespace std;
int main()
{
	unsigned short int i=0;
	int j=8,p;
	p = j << 1;
	i = i -1;
	cout << p << endl;
	cout << i << endl;			// 2^16-1
	return 0;
}
* VC6.0的结果:
16
65535
```
## `联合体内的成员共享内存空间 --- 内存中的数据排列问题`
```
#include <iostream>
using namespace std;

union {
	unsigned char a;
	unsigned int i;
}u;

int main()
{

	u.i=0xf0f1f2f3;
	cout << hex << u.i << endl;			// 16进制显示
	cout << hex << int(u.a)  << endl;	// u.a取低字节的一个字节
	return 0;
}

* VC6.0的结果:
f0f1f2f3
f3
Press any key to continue
```
## `在某工程中,要求设置一绝对地址为0x67a9的整型变量的值为0xaa66`
```
* 法一: 面试时推荐这种写法
int *ptr;
ptr = (int *)0x67a9;	// 0x67a9就是一个地址
*ptr = 0xaa66;

* 法二:
*((int * const)0x67a9) = 0xaa66;
```
## `(char *)malloc(0) 的理解`
```
ptr = (char *)malloc(0)		
// malloc(0)是指分配内存大小为零(但是因为内存大小为0,所以不能进行写操作,
//因为内存给它存放),但是在堆中准备好了相应的内存地址
char   *ptr;
if ((ptr   =   (char   *)malloc(0))   ==   NULL)   
puts( "Got   a   null   pointer "); 
else 
puts( "Got   a   valid   pointer "); 
上面程序在VC6.0下输出结果是：Got   a   valid   pointer 

当使用malloc后，只有在没有足够内存的情况下会返回NULL，或是出现异常报告。 

malloc(0)，系统就已经帮你准备好了堆中的使用起始地址（不会为NULL)。但是你不能对该地址进行写操作（不是不允许），如果写了话，当调用free(ptr)就会产生异常报告（地址受损）。

NULL一般预定义为   (void   *)0,指向0地址。malloc是在程序堆栈上分配空间，不会是0地址 

NULL是不指向任何实体 
malloc(0)也是一种存在不是NULL
```
## `ASCII码`
```
* a - z : 97 - 122
* A - Z : 65 - 90
```
```
#include <iostream>
using namespace std;

typedef struct bitstruct {
	int b1:5;
	int :2;			// 中间 2位
	int b2:2;
}bitstruct;			// 该结构体共9位

int main()
{

	bitstruct b;
	memcpy(&b,"EMC EXAMINATION",sizeof(b));	// sizeof(b) = 4  , 因为结构体b的成员变量是int型，且只有9位，未填充完一											// 个int(4字节),未填充的位补0
	printf("%d,%d\n",b.b1,b.b2);
	return 0;
}

* b2(10)的最高位为1,表示为负数,其原码要进行取反加1才能得到,这里为 -2

* VC6.0调试结果:
5,-2
Press any key to continue
```
## `原码, 反码, 补码的基础概念和计算方法`
[原码, 反码, 补码的基础概念](http://www.cnblogs.com/zhangziqiu/archive/2011/03/30/ComputerCode.html)
```
原码就是符号位加上真值的绝对值, 即用第一位表示符号, 其余位表示值. 比如如果是8位二进制:
[+1]原 = 0000 0001
[-1]原 = 1000 0001

反码的表示方法是:
正数的反码是其本身
负数的反码是在其原码的基础上, 符号位不变，其余各个位取反.
[+1] = [00000001]原 = [00000001]反
[-1] = [10000001]原 = [11111110]反
可见如果一个反码表示的是负数, 人脑无法直观的看出来它的数值. 通常要将其转换成原码再计算

补码的表示方法是:
正数的补码就是其本身
负数的补码是在其原码的基础上, 符号位不变, 其余各位取反, 最后+1. (即在反码的基础上+1)
[+1] = [00000001]原 = [00000001]反 = [00000001]补
[-1] = [10000001]原 = [11111110]反 = [11111111]补
对于负数, 补码表示方式也是人脑无法直观看出其数值的. 通常也需要转换成原码在计算其数值
```
* 十进制数 -10 的三进制4位数补码形式 : -(3^4 - |-10|) = 71 = 2212 => 2122
## `scanf`
* 使用scanf不要加\n,即不要使用 scanf("%d\n",&val)的形式,应写为 scanf("%d",&val)
## `空链表`
```
List list = new ArrayList();
此时的list就是一个空链表，此时它里面什么都没有，但是已经开辟了一块空间
“为什么还有构造空链表”
这就是要为了以后向里面放元素放的准备，
打个比方，你想要存放东西，那么首先你得有仓库吧，而你自己没有，你就得先申请一个空的仓库
已备你以后向里放你想放的东西～～
```
## `-i--`
* -i--就是先进行i--运算，然后再取其负值
* --与负号处于同一优先级，而结合方向是从右到左，所以是先进行i--运算，再取负号。
* i--就是把i自减1，但是它的返回值却是i，这就是i--与--i的区别，--i的返回值就是i-1了
```
#include <stdio.h>

int main(void)
{
	int i=8;

	printf("%d\n",++i);
	printf("%d\n",--i);
	printf("%d\n",i++);
	printf("%d\n",i--);
	printf("%d\n",-i++);
	printf("%d\n",-i--);
	printf("%d\n",-(++i));
	printf("%d\n",-(--i));
	printf("------\n");

}

* VC6.0调试结果:
9
8
8
9
-8
-9
-9
-8
------
Press any key to continue
```
## `int与uint类型之间转换过程中值的变化`
* [int与uint类型之间转换过程中值的变化](http://blog.csdn.net/xiaokui_wingfly/article/details/8528442)
* 计算机中存储数据都是用补码来存储
```
int类型的数据转化为uint类型：
因为int是带符号的类型，当int是正数时，int类型数据转化为uint时不发生改变。
当int是负数时，int类型数据转化为uint类型时，值就要发生变化。
但转化的过程并不是去掉前面的负号，例如

int a=-1;  
uint b=(uint)a;  

这时b的结果并不是1；而是4294967295；
我们知道在计算机中存储数据都是用补码来存储的，int的大小是4个字节，也就是32位，并且第一位是符号位；
而uint的大小同样是4个字节，32位，但没有符号位。
所当int a=-1;在计算机中存储的是补码：1111 1111 1111 1111;第一位是符号位。
执行uint b=(uint)a;转化为uint类型时，存储的依然是补码：1111 1111 1111 1111;没有符号位。
这时值就变成了4294967295
```
```
#include <stdio.h>

char getChar(int x,int y)
{
	char c;
	unsigned int a =x;
	(a+y > 10)?(c=1):(c=2);
	return c;
}

int main(void)
{
	char c1 = getChar(7,4);
	char c2 = getChar(7,3);
	char c3 = getChar(7,-7);	// -7 => 二进制 => 补码(源码[符号位不变]取反加1) => +7(变为二进制) => 刚好溢出 => 0 
	char c4 = getChar(7,-8);

	printf("c1 = %d\n",c1);
	printf("c2 = %d\n",c2);
	printf("c3 = %d\n",c3);
	printf("c4 = %d\n",c4);
}

* VC6.0调试结果:
c1 = 1
c2 = 2
c3 = 2
c4 = 1
Press any key to continue
```
## `宏定义`
* 宏定义的执行是在编译之前的,即预处理的阶段[重点]
* 宏定义的参数记得用()括起来
* #define STR(s) #s		// # : 把宏参数变为一个字符串
* #define CONS(a,b) (int)(a##e##b)	// ## ：把参数a,b贴合在一起 
* CONS(2,3)		// 2 * 10^3 = 2000
```
#include <stdio.h> //  <> : 该文件是一个工程或标准头文件，查找的时候先查找预定义目录

#define SQR(x) (x*x) 	// 这里的 x*x = b+2*b+2=b+2b+2=3b+2 => 突显宏参数一定要加()的重要性

int main(void)
{
	int a,b=3;
	// 因为 SQR是一个宏,作用为字符替换,宏处理在编译前,所以宏中的x = b +2 ,但b没有值,编译后才会出现 b =3
	a = SQR(b+2);		
	printf("%d\n",a);
	return 0;
}

* VC6.0调试结果:
11
Press any key to continue
```
## `宏定义得到字的高位和低位字节`
* 字 ： 两个字节 === unsigned short
```
//#include <stdio.h> //  <> : 该文件是一个工程或标准头文件，查找的时候先查找预定义目录
#include <iostream>
#define WORD_LO(xxx) ((unsigned char) ((unsigned short)(xxx) & 0xff))
#define WORD_HI(xxx) ((unsigned char) ((unsigned short)(xxx) >> 8))
int main(void)
{
	printf("该字的高字节为: \n");
	printf("%c\n",WORD_HI(16706));	// 16706 === 0x4142 === AB
	printf("该字的低字节为: \n");
	printf("%c\n",WORD_LO(16706));

	return 0;
}

* VC6.0的调试结果:

该字的高字节为:
A
该字的低字节为:
B
Press any key to continue
```
## `虚函数占用内存空间`
```
普通函数不占用内存,只要有虚函数,就会占用一个指针大小的内存,原因是系统多用了一个指针
来维护这个类的虚函数表,并且注意这个虚函数无论含有多少项(类中含有多少个虚函数),都不会
再影响类的大小
```
## `#pragma pack`
* #pragma pack(1) 	// 对齐方式 : 1字节 

## `交换两个字符串`
```
//法一:
#include <iostream> //  <> : 该文件是一个工程或标准头文件，查找的时候先查找预定义目录
void swap(char* &p1, char* &p2)	//这里是指针引用,所以传入函数的是实参
{	
// 若改为swap(char* p1, char* p2) 则指针的交换只在swap函数体内有效,对实际的(主函数的)p1,p2没影响						// 实际上的 p1 p2所指向的字符串是放在常量区,这里的函数参数 char *p1,char *p2只是一个临时分配的,不是实参
// 因为他们的地址不是主函数中两指针本身的地址,是新开辟的
// 总结: 要确保传递的参数是实参	
	char *temp;
	temp=p1;
	p1=p2;
	p2=p1;
}

int main(void)
{
	char *p1="abc";
	char *p2="ABC";
	printf("%s\n",p1);
	printf("%s\n",p2);
	swap(p1,p2);
	printf("%s\n",p1);
	printf("%s\n",p2);
	return 0;
}

//法二:
#include <iostream> //  <> : 该文件是一个工程或标准头文件，查找的时候先查找预定义目录

void swap(char **p1,char **p2)	// 传入的是主函数的两指针的实际内存地址,为实参
{
	char *temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main(void)
{
	char *p1="abc";
	char *p2="ABC";
	printf("%s\n",p1);
	printf("%s\n",p2);
	swap(&p1,&p2);		// 传入函数参数的是p1、p2本身的内存地址
	printf("%s\n",p1);
	printf("%s\n",p2);
	return 0;
}
```
## `创建单链表`
* [创建单链表code](https://github.com/GalenDeng/C/blob/master/%E9%93%BE%E8%A1%A8/%E5%88%9B%E5%BB%BA%E5%8D%95%E9%93%BE%E8%A1%A8/create_list.cpp)
* [调试结果](https://github.com/GalenDeng/C/blob/master/%E9%93%BE%E8%A1%A8/%E5%88%9B%E5%BB%BA%E5%8D%95%E9%93%BE%E8%A1%A8/create_list%E8%B0%83%E8%AF%95%E7%BB%93%E6%9E%9C)