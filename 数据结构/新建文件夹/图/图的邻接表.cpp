#include<stdio.h>
#include<stdlib.h>
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextrac;
} ArcNode;
typedef struct VNode
{
	int date;
	ArcNode *firstarc;
}VNode, AdjList[20];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
	int kind;
}ALGraph;
int main()
{
	int i,j;
	ALGraph G;
	scanf("%d", &G.vexnum);
	for(i=0;i<G.vexnum;i++) 
	{ 
		G.vertices[i].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
		G.vertices[i].firstarc->nextrac=NULL;
	//	G.vertices[i].firstarc=NULL;
	}
	for(i=0;i<G.vexnum;i++)
	{
		ArcNode *rear, *p;
		rear=G.vertices[i].firstarc;
		scanf("%d", &G.vertices[i].date);
		for(j=0;j<G.vertices[i].date;j++)
		{
			p=(ArcNode *)malloc(sizeof(ArcNode));
			if(!p) exit(0);
			scanf("%d", &p->adjvex); 	 
			rear->nextrac=p;
			rear=p;
		}
		rear->nextrac=NULL;
	}
	for(i=0;i<G.vexnum;i++)
	{
		ArcNode *rear;
		rear=G.vertices[i].firstarc->nextrac;
		
		while(rear)
		{
			printf("%d  ", rear->adjvex);
			rear=rear->nextrac;
		}
		putchar(10);
	}
		
	
	
	
	return 0;
}
