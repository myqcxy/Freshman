#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue *Q);
void EnQueue(SqQueue *Q);
void DeQueue(SqQueue *Q);
int main()
{
	SqQueue Q;
	InitQueue(&Q);
	while(1)
	{
		printf("ÇëÊäÈëÑ¡Ôñ£º\n");
		int choice;
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:EnQueue(&Q);break;
			case 2:DeQueue(&Q);break;
		}
	}
	
	
	
	return 0;
}
void DeQueue(SqQueue *Q)
{
	if(Q->rear==Q->front) exit(0);
	printf("%d",Q->base[Q->front]);
	Q->front=(Q->front+1)%100;
}
void EnQueue(SqQueue *Q)
{
	int e;
	while(scanf("%d", &e),e!=-1)
	{
		if((Q->rear+1)%100==Q->front) exit(0);
		Q->base[Q->rear]=e;	
		Q->rear=(Q->rear+1)%100;
	}
	
}
void InitQueue(SqQueue *Q)
{
	Q->base=(int *)malloc(100*sizeof(int));
	Q->front=Q->rear=0;
} 
