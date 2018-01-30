
/* 用两个栈实现一个队列的功能---c++实现 */
#include <iostream>
#include <stack>
using namespace std;
template <class T>

 struct queue			// 这里不能添加 typedef设置别称
 {
 	stack<T>  s1;	// 栈s1用来实现入队的操作
 	stack<T>  s2;	// 栈s2用来实现出队的操作
 	/* 入栈s1 --- 入队 */
 	void push (T &t) 
 	{
 		s1.push(t);
 	}

 	/* 显示 --- 入栈s2 */
 	T front()
 	{
 		if (s2.empty()) {	// 栈s2为空
 			if (s1.size() == 0) throw;	// s1没分配内存
 			while (!s1.empty()) {
 				s2.push(s1.top());		// 入栈s2
 				s1.pop();
 			}
 		}
 		return s2.top();
 	}

 	/* 出队 */
 	void pop()
 	{
 		// 情况一: 栈s2为空时,先在栈s1的栈顶取一个值放在栈s2中
 		if (s2.empty()) {
 			while (!s1.empty()) {
 				s2.push(s1.top());
 				s1.pop();	
 			}
 		}

 		// 情况二: 栈s2不为空
 		if (!s2.empty()) {
 				s2.pop();	// 出队操作
 		}
 	}

 }; 					// 不能加上真正的变量名

 int main()
 {
 	queue<int> mq;
 	int i;

 	for(i=0;i<10 ; i++) {
 		mq.push(i);	// 栈s1入栈 --- 入队
 	} 

 	for(i=0;i<10;i++) {
 		cout << mq.front() << endl;	// 栈s2入栈
 		mq.pop();					// 栈s2出栈 --- 出队
 	}

 	return 0;
 }

/*
 * VC 6.0 调试结果:
0
1
2
3
4
5
6
7
8
9
Press any key to continue

*/