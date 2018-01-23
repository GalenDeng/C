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
	Node *list1;
	list1 = list_create();
	list_printf(list1);
	return 0;
}