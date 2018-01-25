#include <iostream>
using namespace std;

// list的结构体
 typedef struct node
{
	int data;		// 数据域
    struct node *next;		// 指针
}Node;

// 创建单链表
node *list_create(void)
{
	Node *head,*current,*pre;
    int n,val;
	head = NULL;	// 初始化指针

	printf("输入该链表的节点数: \n");
	scanf("%d",&n);
	printf("输入该链表的数据: \n");		

	if (n > 0) {								// 不为空链表的时候
		for(int i =0;i<n;i++) {					
		scanf("%d",&val);
		current = (Node *)malloc(sizeof(Node));
		current->data = val;
		if ( head == NULL)
			head = pre = current;
		else 
			pre->next = current;
		pre = current;
		}
		pre->next = NULL;	
	} 
	return head;
}

// 单链表测长(通过Node的非空指针数量或数据的数量来计数)
int length(Node *head)
{
	Node *p;
	p = head;
    int i =0;		// 存在内存的栈中
	while(p)
	{
		i++;
		p=p->next;
	}
	return i;
}

// 找到第一个相同的节点并删掉它 分[头节点和中间节点]
Node *ListDedelete(Node *head,int num)
{
	Node *p =head;
	Node *cur;

	while(num != p->data && p->next != NULL){	// 遍历链表,看是否存在相等的数据值
		cur = p ;		// 作用 : cur->next = p->next; 跳转相同值的节点
		p = p->next;	
	}
	
	if (num == p->data) {
		if (p == head) {
			head = p->next;
			free(p);	// 释放头节点
		} else {
			cur->next = p->next;
			free(p);	// 释放废弃的节点内存空间
		}
	}
	else
		printf("\n%d could not been found",num);
	return head;

}

// 单链表插入,插入到原链表第一个数比它大的前面
Node *list_insert(Node *head,int num)
{
	Node *p,*p1,*NewNode;
	p = head;
	NewNode = (Node *)malloc(sizeof(Node));	// 申请一个新的内存
	NewNode->data = num;	// 数据域

	while(NewNode->data > p->data && p->next != NULL){
		p1 = p; p = p->next;
	}

	if (NewNode->data <= p->data){
		if (p == head) {
			NewNode->next = p;
			head = NewNode;
		} else {
			p1->next = NewNode;
			NewNode->next = p;
		}
	} else {
		p->next = NewNode;
		NewNode->next = NULL;
	}
	return head;
}

// 单链表从小到大排序: 冒泡排序
Node *ListSort(Node *head,int n)
{
	Node *p;
	int temp;	// 中间媒介
//	printf("该链表的长度为: %d\n",n);
	if (head == NULL || head->next == NULL)	{	// 空链表或者为NULL
		return head;
	} 
	for (int i=1;i <=n-1; i++) {
		p=head;					// 关键 每次遍历都要重新初始化
		// 交换节点数据的方式
		for (int j=0; j<n-i; j++) {	// i至少为1 ，即第一次循环开始的值应该是1
			if (p->data > p->next->data) {	// 单次交换
				// 这里只是交换了数据域中的值,指针域的指向不变
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;		
			}
				p = p->next;
		}
	}
	return head;	// 所以这里直接返回头节点就可以了
}

// 打印链表
void list_printf(Node *head)
{
	Node *p;
	p = head;
	printf("该链表为:\n");
	while(p != NULL) {
		printf("%d\t",p->data);
		p = p->next;
	}

	printf("\n");
}

int main()
{
	int num,num2;
	Node *list1;
	list1 = list_create();
	list_printf(list1);

	printf("该链表的长度为: %d\n",length(list1));			// 测长

	printf("请输入要删除的节点值: \n");		// 删除某节点 
	scanf("%d",&num);
	list1 = ListDedelete(list1,num);
	list_printf(list1);

	printf("请输入要插入的节点值: \n");		// 插入某节点
	scanf("%d",&num2);
	list1 = list_insert(list1, num2);
	list_printf(list1);

	list1=ListSort(list1,length(list1));	// 冒泡排序单链表
	printf("冒泡排序后: \n");
	list_printf(list1);
	return 0;
}

/* 
 * VC6.0的调试结果:

输入该链表的节点数:
4
输入该链表的数据:
11 33 21 22
该链表为:
11      33      21      22
该链表的长度为: 4
请输入要删除的节点值:
11
该链表为:
33      21      22
请输入要插入的节点值:
20
该链表为:
20      33      21      22
冒泡排序后:
该链表为:
20      21      22      33
Press any key to continue

*
*/