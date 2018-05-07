#include<stdio.h>
#include<stdlib.h>
typedef struct stu
{
	int date;
	struct stu *next;
}LNode,*LinkList;
LinkList IntList(LinkList head);
void ListInsert(LinkList head);
void ListDelete(LinkList head);
void LocateElem(LinkList head);
void UpdateElem(LinkList head);
void PrintLink(LinkList head);
void LinkRev(LinkList head);
int main()
{
	LinkList head;
	head=IntList(head);
	while(1){
	printf("������ѡ��\n");
	int choice;
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:ListInsert(head);break;
		case 2:ListDelete(head);break;
		case 3:LocateElem(head);break;
		case 4:UpdateElem(head);break;
		case 5:PrintLink(head);break;
		case 6:LinkRev(head);break;
	}
			
	}
	
	
	return 0;
}
void LinkRev(LinkList head)
{
	LinkList p,q;
	p=head->next;
	head->next=NULL;
	while(p){
		q=p;
		p=p->next;
		q->next=head->next;
		head->next=q;
	}
}
void PrintLink(LinkList head)
{
	LinkList p=head->next;
	while(p){

	printf("%d,",p->date);p=p->next;	}
}
void UpdateElem(LinkList head)
{
	printf("��������Ҫ�޸ĵ�Ԫ�أ�\n");
	int elem;
	scanf("%d", &elem);
	LinkList p=head->next;
	while(p)
	{
		if(p->date==elem){
			printf("��������º����\n");
			scanf("%d", &p->date); 
			break;
		} 
		p=p->next;
	}
	if(!p) printf("�����д�����\n");
}
void LocateElem(LinkList head)
{
	LinkList p=head->next;
	int n;
	printf("������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d", &n);
	while(p)
	{
		if(p->date==n) {
			printf("���ҵ�������\n");
			break;
		}
		p=p->next;
	}
	if(!p) printf("�����д�����\n");
}
void ListDelete(LinkList head)
{
	printf("��������Ҫɾ����������\n");
	int n,count=0;
	scanf("%d", &n);
	LinkList p=head,ptr=p->next;
	while(p->next)
	{
		if(ptr->date==n)
		{
			count=1;
			break;
		}
		p=p->next;
		ptr=p->next;
	}
	p->next=ptr->next;
	free(ptr);
}
void ListInsert(LinkList head)
{
	LinkList p,rear=head;
	int a;
	printf("��������������������-1ʱ������\n");
	
	while(scanf("%d", &a),a!=-1)
	{
		p=(LinkList)malloc(sizeof(LNode));
		if(!p) exit(0);		
		p->date=a;		
		rear->next=p;
		rear=p;
		
	}
	rear->next=NULL;
}
LinkList IntList(LinkList head)
{
	head=(LinkList)malloc(sizeof(LNode));
	if(!head) exit(0);
	head->next=NULL;
	return head;
}
