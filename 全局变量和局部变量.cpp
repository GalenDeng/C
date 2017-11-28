## 全局变量和局部变量的区别

1.全局变量和局部变量的作用范围
#include <iostream>
using namespace std;

// 全局变量声明
int g = 99;

// 函数声明
int func();

int main()
{
	// 局部变量声明
	int g = 10;
	cout << g;          //输出 ： 10
	int kk = func();    //输出 ： 99
	cout << kk;
	return 0;
}

// 函数定义
int func()
{
	return g;
}

2.在一个函数体内可以存在重名的变量，前提是它们的作用域不同
#include <iostream>
using namespace std;

int main()
{
    int b = 2;

   {

        int b = 1;
        cout << "b = " << b << endl;      //输出 ： 1

    }

    cout << "b = " << b << endl;          //输出 ： 2
}

/* 
当变量间出现重名的情况下，作用域小的屏蔽作用域大的，
所以上面第一个 cout 输出 b 的值为 1，但由于在块里
面申请的变量作用域只限于当前块，所以离开这个块后变
量会自动释放，所以第二个 cout 输出 b 的值为 2。
*/

3.全局变量的值能被局部所改变
#include <iostream>
using namespace std;
// 全局变量声明
int g = 20;
int fun1(int a,int b){
    g=a+b;
    cout<<"被改变的全局变量为："<<g<<endl;
    return 0;
}

int fun2(){
    cout<<"此时的全局变量为："<<g<<endl;
    return 0;
}

int main(){
    fun2();
    fun1(10,20);
    fun2();
    return 0;
}