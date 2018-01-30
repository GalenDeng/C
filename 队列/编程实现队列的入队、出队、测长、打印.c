/* 编程实现队列的入队、出队、测长、打印 */
#include <stdio.h>
#include <malloc.h>

// 单链表节点的结构体
typedef struct node
{
	int data;
	struct node *next;
}Node;

// 队列的结构体
typedef struct queue
{
	Node *first;
	Node *rear;
}Queue;

// 创建空队列
Queue *QueueCreate()
{
	Queue *q = (Queue *)malloc(sizeof(Queue));	// 给队列申请一个动态内存空间(堆内存)
	q->first = NULL;
	q->rear  = NULL;
	return q;
}

// 入队
Queue *QueueInsert(Queue *q,int num)
{
	Node *NewNode = (Node *)malloc(sizeof(Node));
	NewNode->data = num;
	NewNode->next = NULL;	// 新建节点

	// 新建节点放在原队尾后
	if (q->rear == NULL)	{	// 在空队列中插入新节点(入队)
		q->first = NewNode;
		q->rear  = NewNode;
	} else {
		q->rear->next = NewNode;
		q->rear = NewNode;
	}
	return q;
}

// 出队
Queue *QueueDelete(Queue *q)
{
	Node *p = q->first;
	if (p == NULL) {
		printf("该队列是空队列,不能进行出队操作\n");
	} else {
		printf("%d出队\n",p->data);
		q->first = q->first->next;
		if (q->first == NULL) {
			q->rear = NULL;			// 当删除后队列为空时,对rear(后面的节点)置空
		}
		free(p);	// 释放出队节点的动态内存空间
	}
	return q;
}

// 测出队列的长度
int QueueLength(Queue *q) 
{
	Node *p=q->first;
	int len = 0;
	if (p != NULL) {
		len = 1;
	}

	while (p != q->rear) {	// 遍历队列
		p = p->next;
		len++;
	}
	return len;
}

// 打印出队列
void QueuePrint(Queue *q)
{
	Node *p = q->first;
	if (p == NULL) {
		printf(" Empty Queue!\n");
		return;
	} 
	printf("data: \n");
	while (p != q->rear) {		// 遍历
		printf("%d\t", p->data);	// 打印节点数据
		p = p->next;
	}
	printf("%d\t", p->data);		// 打印队尾节点数据
	printf("\n");
}

int main()
{
	int num,len,i,num2;
	Queue *q = QueueCreate();	// 创建空队列
	printf("入队\n");
	printf("请输入4个入队数字: ");
	for (i = 0;i<4;i++) {
		scanf ("%d",&num);
		q = QueueInsert(q,num);	// num入队	
	}
	len = QueueLength(q);	 	// 队列长度
	printf("队列的长度为: %d\n", len );
	QueuePrint(q);

	printf("出队\n");
	printf("请输入出队数量: ");
	scanf ("%d",&num2);
	for (i = 0; i < num2 ;i++) {
		q = QueueDelete(q);			
	}

	len = QueueLength(q);	 	// 队列长度
	printf("队列的长度为: %d\n", len );
	QueuePrint(q);

	return 0;
}

/*
 * VC6.0调试结果
入队
请输入4个入队数字: 5 6 7 8
队列的长度为: 4
data:
5       6       7       8
出队
请输入出队数量: 2
5出队
6出队
队列的长度为: 2
data:
7       8
Press any key to continue
*/