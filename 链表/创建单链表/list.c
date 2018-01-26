#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

// ������Ĵ���
Node *ListCreate()
{
	Node *head,*pre,*cur;
	int n,val,i;
	head = NULL;

	printf("�����뽨��������ڵ�����Ϊ: \n");
	scanf("%d",&n);
	printf("������ڵ������\n");
	if (n > 0) {
		for (i=0;i<n;i++) {
			scanf("%d",&val);
			cur = (Node *)malloc(sizeof(Node));
			cur->data = val;

			if (head == NULL) {
				head = pre = cur;
			} else {
				pre->next = cur;
			}

			pre = cur;
		}	
		pre->next = NULL;
	}
	return head;
}

// ��ӡ
void ListPrint(Node *head) 
{
	Node *p = head;
	printf("������Ϊ: \n");
	while(p) {
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

// ������Ĳ���
Node *ListInsert(Node *head,int num)
{
	Node *NewNode,*p1,*p2;
	NewNode = (Node *)malloc(sizeof(Node));
	NewNode->data = num;
	NewNode->next = NULL;
	p1 = head;

	if (head == NULL) {
		head = NewNode;
		return head;
	}

	while(NewNode->data > p1->data && p1->next != NULL) {
		p2 =p1; p1 = p1 ->next;
	}

	if (NewNode->data <= p1->data) {
		if (p1 == head) {
			NewNode->next = p1;
			head = NewNode;
		} else {
			p2->next =NewNode;
			NewNode->next = p1;
		}
	} else {
		p1->next = NewNode;
		NewNode->next = NULL;
	}
	return head;
}

// ɾ��һ���ڵ�
Node *ListDelete(Node *head,int num) 
{
	Node *p1,*p2;
	if (head == NULL) {
		printf("%d can not to be found\n", num);
		return head;
	}

	p1 = head;

	while (num != p1->data && p1->next != NULL) {
		p2 =p1; p1 = p1->next;
	}

	if (num == p1->data) {
		if (p1 == head) {
			head = head->next;
			free(p1);
		} else {
			p2->next = p1->next;
			free(p1);
		}
	} else {
		printf("%d can not to be found\n", num);
	}

	return head;
}

// �������ĳ���
int length(Node *head)
{
	Node *p=head;
	int i = 0;
	while(p) {
		i++;
		p = p->next;
	}
	return i;
}

// ��С����ð������
Node *ListSort(Node *head)
{
	Node *p =head;
	int n ,temp,i,j;
	n = length(head);
	if (p == NULL || p->next == NULL) {
		return head;
	}

	for( i= 1;i<=n-1;i++) {
		p = head;
		for (j = 0; j <n-i; j++)
		{
			if(p->data > p->next->data) {
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			} 
			p = p->next;
		}
	}
	return head;
}

// �����������
Node *ListReverse(Node *head)
{
	Node *p0,*p1,*p2;
	p0 =head;
	if (p0 == NULL || p0->next == NULL) {
		return head;
	}
	p1 = p0->next;
	while(p1) {
		p2 = p1->next;
		p1->next = p0;
		p0 = p1;
		p1 = p2;
	}
	head->next = NULL;
	head = p0;
	return head;
}

// ֻ����һ�β��ҵ�������м�ڵ�
Node *ListSearch(Node *head,Node *mid) 
{
	Node *p=head;
	if (head == NULL ) {
		mid = head;
		return mid;
	}
	while(head->next != NULL && head->next->next != NULL) {
		head = head->next->next;
		p = p->next;
	}
	mid = p;
	return mid;
} 

// ɾ��������Ԫ��
Node *ListRemoveHead(Node *head)
{
	Node *p= head;
	if (head == NULL) {
		return head;
	}
	head = head->next;
	free(p);
	return head;
}

int main(void)
{
	Node *list1,*mid,*list2;
	int num,num2;
	list1 = ListCreate();
	ListPrint(list1);
	printf("����ĳ���Ϊ: %d\n",length(list1));
	
	printf("����һ���ڵ�: \n");
	scanf("%d",&num);
	list1 = ListInsert(list1, num);
	ListPrint(list1);

	printf("ɾ��һ���ڵ�: \n");
	scanf("%d",&num2);
	list1 = ListDelete(list1, num2);
	ListPrint(list1);

	list1 = ListSort(list1);
	printf("��С����ð������������Ϊ: \n");
	ListPrint(list1);

	printf("���õ�����: \n");
	list1 = ListReverse(list1);
	ListPrint(list1);

	printf("ɾ�����������Ԫ��: \n");
	list1 = ListRemoveHead(list1);
	ListPrint(list1);

	printf("ֻ����һ�β��ҵ�������м�ڵ�Ϊ: \n");
	list2 = ListSearch(list1,mid);
	if (list2 != NULL) {
		printf("��������м�ڵ�Ϊ: %d\n",list2->data);
	} else {
		printf("\n");
	}
	return 0;
}