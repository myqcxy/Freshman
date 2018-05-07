#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define MaxNum 100
int visited[MaxNum];

typedef struct node
{
	int adjvex;
	struct node *next;
}EdgeNode;
typedef struct vnode
{
	int date;
	EdgeNode *firstarc;
}VertexNode,AdjList[MaxNum];
typedef struct
{
	AdjList adjlist;
	int n,e;
}ALGraph;
void initGraph(ALGraph *G)
{
	int i;
	G->n=0;
	G->e=0;
	for(i=0;i<MaxNum;i++)
	{
		G->adjlist[i].firstarc=NULL;
	}
}
int main()
{
	int i,j;
	ALGraph G;
	initGraph(&G);
	scanf("%d%d", &G.n,&G.e);
	for(i=0;i<G.n;i++)
	{
		scanf("%d", &G.adjlist[i].date);
	}
	
	
	return 0;
}











