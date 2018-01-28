#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int data;
	struct node *next;
	struct node *pre;
}Node;

// 双链表的建立
Node *ListCreate()
{
	Node *head=NULL,*pre,*cur;
	int i,n,val;
	printf("请输入要建立双链表的节点数目: \n");
	scanf("%d",&n);
	printf("请输入双链表的数据: \n");
	if(n>0) {
		for (i=0;i<n;i++) {
			scanf("%d",&val);
			cur = (Node *)malloc(sizeof(Node));
			cur->data = val;

			if (head == NULL) {
				head = pre = cur;
			} else {
				pre->next = cur;
				cur->pre = pre;		// 前置链
				pre = cur;
			}
		}
		pre->next = NULL;
		head->pre = NULL;
	}
	return head;
}

// 测出双链表的长度
int ListLength(Node *head) 
{
	int i=0;
	Node *p = head;
	while(p) {
		i++;
		p = p->next;
	}
	return i;
}

// 双链表的打印
void ListPrint(Node *head)
{
	Node *p=head,*p2=head;
	printf("正序显示(head->next): \n");
	while(p){
		printf("%d\t", p->data);
		if (p->next == NULL) {
			p2 = p;
		}
		p = p->next;
	}
	printf("\n");	
	printf("反序显示(head->pre): \n");	
	while(p2) {
		printf("%d\t", p2->data);
		p2 = p2->pre;		
	}
	printf("\n");
}

int main()
{
	Node *list1;
	list1 = ListCreate();
	ListPrint(list1);
	return 0;
}

/*
 * VC6.0的调试结果:
 请输入要建立双链表的节点数目:
4
请输入双链表的数据:
12 23 43 56
正序显示(head->next):
12      23      43      56
反序显示(head->pre):
56      43      23      12
Press any key to continue
*/