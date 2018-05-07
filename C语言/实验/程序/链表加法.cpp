#include<stdio.h> 
#include<stdlib.h>
struct ListNode{
		int val;
		struct ListNode *next;
};
	
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void input(struct ListNode * head);
void output(struct ListNode* head);

int main()
{
	struct ListNode *l1 = new struct ListNode, *l2 = new struct ListNode;
	input(l1);
	input(l2);
	struct ListNode* s1;
	
	s1 = addTwoNumbers(l1->next,l2->next);
	output(s1);
	return 0;
}
void output(struct ListNode* head)
{
	struct ListNode *p = head->next;
	while(p)
	{
		printf("%d,", p->val);
		p = p->next;
	}
}
void input(struct ListNode * head)
{
	struct ListNode *rear = head, *p;
	int a = 0;	
	while(scanf("%d", &a), a!=-1)
	{
		p = new (struct ListNode);
		p->val = a;
		rear->next = p;
		rear = p;
	}
	rear -> next = NULL;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	static struct ListNode * l3 = (struct ListNode*) malloc(sizeof(ListNode));
	l3->next = NULL;
	struct ListNode *head = l3;
	int s = 0;
	int sum = 0;
    while(l1||l2||s)
    {
		if(l1) s += l1->val, l1 = l1->next;
		if(l2) s += l2->val, l2 = l2->next;
		l3->next = (struct ListNode*) malloc(sizeof(struct ListNode));
		l3->next->val = s % 10;
		s /= 10;
		l3 = l3->next; 
    }
    l3->next = NULL;

    return head;
    
}
