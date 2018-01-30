/* 编程实现栈的入栈/出栈 */

#include <stdio.h>
#include <malloc.h>


/* 节点的结构体 */
typedef struct node 
{
	int data;
	struct node *next;
}Node;

/* 栈的结构体 */
typedef struct stack
{
	Node *top;		// 栈顶
	Node *zhandi;	// 栈底
}Stack;

// 建立一个空栈 (堆内存)
Stack *StackCreate()
{
	Stack *s = (Stack *)malloc(sizeof(Stack));	
	s->top = NULL;
	s->zhandi = NULL;
	return s;
}

// 入栈
Stack *StackInsert(Stack *s,int num)
{
	/* 新建一个节点 */
	Node *NewNode = (Node *)malloc(sizeof(Node));
	NewNode->data = num;
	NewNode->next = NULL;

	if (NULL == s->zhandi) {		// 空栈
		s->zhandi = NewNode;	// 只有一个元素入栈
		s->top = NewNode;
	} else {
		s->top->next = NewNode;
		s->top = NewNode;
	}
	return s;
}

// 出栈
Stack *StackDelete(Stack *s)
{
	Node *p=s->zhandi;
	if (NULL == s->zhandi) {
		printf("栈已经为空,不能进行出栈操作\n");
		return s;
	} else {
		if (s->top == s->zhandi) {
			s->top = NULL;
			s->zhandi = NULL;
			free(p);	// 释放堆内存空间
		} else {
			while (p->next != s->top) {
				p = p->next;
			}
			s->top = p;
			s->top->next = NULL;
			p = p->next;
			free(p);			// 释放
		}
	}
	return s;
}

// 栈的打印
void StackPrint(Stack *s)
{
	Node *p = s->zhandi;	// 中间变量
	if (NULL == p) {
		printf("栈为空\n");
		return;
	}
	printf("栈的情况: \n");
	while (p != s->top) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("%d\t", p->data);
	printf("\n");
}


int main()
{
	int num,i=0,val,num2;
	Stack *s = StackCreate();	// 创建空栈
	printf("请输入入栈的元素数量:  ");
	scanf("%d",&num);
	printf("请输入创建%d个栈的元素数据: \n",num);
	for (i=0; i<num;i++) {
		scanf("%d",&val);
		s= StackInsert(s,val);	
	}
	StackPrint(s);		// 打印建立的栈

	printf("请输入出栈的元素数量:  ");
	scanf("%d",&num2);
	for (i=0; i<num2;i++) {
		s = StackDelete(s);	
	}
	StackPrint(s);		// 打印建立的栈
	return 0;
}

/*
 * VC6.0调试结果:
请输入入栈的元素数量:  4
请输入创建4个栈的元素数据:
12 45 67 89
栈的情况:
12      45      67      89
请输入出栈的元素数量:  1
栈的情况:
12      45      67
Press any key to continue

*/