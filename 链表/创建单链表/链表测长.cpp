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