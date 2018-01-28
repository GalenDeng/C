/*
 *
已知n个人(以编号1,2,3, ... , n 分别表示)围坐在一张圆桌周围。从编号
为k的人开始报数,数到m的那个人出列;他的下一个人又从K开始报数,数到m的
那个人又出列;依此规律重复下去,直到圆桌周围的人全部出列。试用c++编程
实现。--- 约瑟夫环问题的实际场景
*/

/*
 * 解决问题核心步骤:
 1. 建立一个具有n个链节点、无头节点的循环链表
 2. 确定第一个报数人的位置
 3. 不断地从链表中删除链节点,直到链表为空
*/

#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

// 循环单链表的建立: 约瑟夫问题的实际场景  => 输出处理后的列的序列
void ListCreate_second(int n,int k ,int m)		// n : 总人数 k : 编号为k开始 m : 从编号k数来m位
{
	/* 建立一个具有n个链节点、无头节点的循环链表 */
	int i,j;
	Node *head=NULL,*pre,*cur;
	if(n > 0) {
		for (i = 1 ; i <= n;i++) {
			cur = (Node *)malloc(sizeof(Node));
			cur->data = i;
			if(head == NULL) {
				head = pre = cur;
			} else if (i == n) {
				pre->next = cur;
				cur->next = head;		// 组成循环单链表
			} else {
				pre->next = cur;	
				pre = cur;
			}
		}
	}
	/* 确定第一个报数人的位置 */
	pre = head;
	while(--k) {		// 编号为k
		cur = pre;	// 把 数据域 data = 1的节点看作头部
		pre = pre->next;
	} // 这里得到的是k前一个人的位置,因为下面用到 cur=pre,而这里是 pre = pre->next;
	/* 打印出删除(即出列的先后顺序)的序列 */
	while(n) {
		for(j = 1;j<m;j++) { // 每次点m人
			cur = pre;
			pre = pre->next;
		}
		cur->next = pre->next;	// 跳过要出列的节点pre	
		printf("%d\t", pre->data);
		free(pre);	// 释放删除的节点pre的内存空间
		if(n >1) {
			pre = cur->next;	// 指向cur的下一节点,用来循环倒数			
		} else {
			pre = NULL;
		}
		n--;
	}
	printf("\n");

}


int main()
{
	ListCreate_second(7,4,3);
	return 0;
}

/*
 * VC6.0调试结果:
6       2       5       3       1       4       7
Press any key to continue
*/