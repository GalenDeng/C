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
				cur->pre = pre;
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
/*	printf("\n");	
	printf("反序显示(head->pre): \n");	
	while(p2) {
		printf("%d\t", p2->data);
		p2 = p2->pre;		
	}
	printf("\n");*/
}

//双链表的删除
Node *ListDelete(Node *head,int num)
{
	Node *p1,*p2;
	if (head == NULL) {
		printf ("双链表为空,不能进行删除操作\n");
		return head;
	}

	p1=head;
	while(num != p1->data && p1->next != NULL) {
		p2 = p1; p1 = p1->next;
	}

	if (num == p1->data) {
		if(p1 == head) {
			head =head->next;
			head->pre = NULL;		// 保证释放内存后不会出现野指针
			free(p1);	// 释放内存
		} else if (p1->next == NULL) {
			p2->next = NULL;
			free(p1);
		} else {				
			p2->next = p1->next;
			p1->next->pre = p2;
			free(p1);
		}
	} else {
		printf("%d could not to be found\n",num);
	}
	return head;
}

int main()
{
	Node *list1;
	int num;
	list1 = ListCreate();
	ListPrint(list1);
	
	printf("删除第一个相同的节点值: \n");
	printf("请输入要删除的节点值:\n");
	scanf("%d",&num);
	list1 = ListDelete(list1,num);
	ListPrint(list1);
	
	return 0;
}

/*
 * VC6.0的调试结果:
请输入要建立双链表的节点数目:
4
请输入双链表的数据:
12 23 45 67
正序显示(head->next):
12      23      45      67      删除第一个相同的节点值:
请输入要删除的节点值:
12
正序显示(head->next):
23      45      67      Press any key to continue
*/