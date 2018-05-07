#include<stdio.h>
#include<stdlib.h>

typedef struct STACK
{
	int date;
	struct STACK *next;
}SNode,*LinkStack;

LinkStack InitStack(LinkStack top);
void Push(LinkStack top,int date);
void Pop(LinkStack top);
int StackEmpty(LinkStack top);
void PrinStack(LinkStack top); 
int main()
{
	LinkStack top;
	top=InitStack(top);
		printf("ÇëÊäÈëÑ¡Ôñ£º\n");
		int  n;

		while(scanf("%d",  &n),n!=-1)
		{
			
			Push(top,n);
		}
		while(!StackEmpty(top))
		{
			Pop(top);
			printf(" ");
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
int StackEmpty(LinkStack top)
{
	if(top->next) return 0;
	else return 1; 
}
void Pop(LinkStack top)
{
	if(!StackEmpty) return;
	LinkStack p=top->next;
	printf("%d", p->date);
	top->next=p->next;
	free(p);
}
void Push(LinkStack top, int date)
{
		LinkStack p;
		p=(LinkStack)malloc(sizeof(SNode));
		if(!p) exit(0);
		p->date=date;
		p->next=top->next;
		top->next=p;		
}
LinkStack InitStack(LinkStack top)
{
	top=(LinkStack)malloc(sizeof(SNode));
	if(!top) exit(0);
	top->next=NULL;
	return top;
}




