#include<stdio.h>
#include<stdlib.h>

typedef struct STACK
{
	int date;
	struct STACK *next;
}SNode,*LinkStack;

LinkStack InitStack(LinkStack top);
void Push(LinkStack top);
void Pop(LinkStack top);
void PrinStack(LinkStack top);
int main()
{
	LinkStack top;
	top=InitStack(top);
	while(1)
	{
		printf("ÇëÊäÈëÑ¡Ôñ£º\n");
		int choice;
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:Push(top);break;
			case 2:Pop(top);break;
			case 3:PrinStack(top);break;
			
		}
	}
	
	
	return 0;
}
void PrinStack(LinkStack top)
{
	LinkStack p=top->next;
	while(p)
	{
		printf("%d,", p->date);
		p=p->next;
	} 
}
void Pop(LinkStack top)
{
	
	LinkStack p=top->next;
	if(!p) {
		printf("Õ»Îª¿Õ£¡\n");
		return ;
	}
	printf("%d\n", p->date);
	top->next=p->next;
	free(p);
}
void Push(LinkStack top)
{
	int date;
	while(scanf("%d", &date),date!=-1)
	{
		LinkStack p;
		p=(LinkStack)malloc(sizeof(SNode));
		if(!p) exit(0);
		p->date=date;
		p->next=top->next;
		top->next=p;
	}			
}
LinkStack InitStack(LinkStack top)
{
	top=(LinkStack)malloc(sizeof(SNode));
	if(!top) exit(0);
	top->next=NULL;
	return top;
}




