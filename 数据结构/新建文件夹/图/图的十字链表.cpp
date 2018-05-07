#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"

#define MAX_INT 1000
#define MAX_VERTEX_NUM 20
#define MAX_QUEUE_NUMBER 20

typedef struct ArcNode
{
	int adjvex;
	double adj;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VexNode
{
	char szName[40];
	ArcNode *firstarc;
}VexNode,AdjList[MAX_VERTEX_NUM];
typedef struct 
{
	AdjList vexs;
	int vexnum,arcnum;
}Net;
//定义队列
typedef struct{
	int *elem;
	int front, rear;
}Queue;
void InitQueue(Queue &Q)
{
	Q.elem = new int[MAX_QUEUE_NUMBER];
	Q.front = Q.rear = 0;
}
int EmptyQueue(Queue Q)
{
	if(Q.front==Q.rear)
		return 0;
	else 
		return 1;
}
void DestroyQueue(Queue &Q){
	delete []Q.elem;
	Q.front = Q.rear = 0;
}

void EnterQueue(Queue &Q, int e)
{
	if((Q.rear + 1)%MAX_QUEUE_NUMBER != Q.front)
		Q.elem[Q.rear ]	= e;
	else
		printf("队列满!\n");
	Q.rear = (Q.rear + 1)%MAX_QUEUE_NUMBER;
}
void LeaveQueue(Queue &Q, int &e)
{
	if(Q.rear != Q.front)
		e = Q.elem[Q.front];
	else
		printf("队列空!\n");
	Q.front = (Q.front+1)%MAX_QUEUE_NUMBER;
}
int LocateVex(Net ga,char *name)
{
	int i;
	for(i=0;i<ga.vexnum;i++)
		if(strcmp(name,ga.vexs[i].szName)==0)
			return i;
	return -1;

}
void crt_net(Net &ga)
{
	ArcNode *p;
	char name1[40],name2[40];
	int i,j,k;
	double w;
	printf("请输入顶点数和弧数：");
	scanf("%d%d",&ga.vexnum,&ga.arcnum);
	printf("请依次输入顶点名：\n");
	for(i=0;i<ga.vexnum;i++)
	{
		scanf("%s",ga.vexs[i].szName);
		ga.vexs[i].firstarc=NULL;
	}
	for(k=0;k<ga.arcnum;k++)
	{
		printf("请输入相邻的两个定点和权值：");
		scanf("%s%s%lf",name1,name2,&w);
		i=LocateVex(ga,name1);
		j=LocateVex(ga,name2);
		p=new ArcNode;
		p->adjvex=j;
		p->adj=w;
		p->nextarc=ga.vexs[i].firstarc;
		ga.vexs[i].firstarc=p;
	}
}

void DFS(Net ga,char *name,int *visited)
{
	int v,w; 
	ArcNode *p;
	v=LocateVex(ga,name);
	visited[v]=1;
	printf("%s ",ga.vexs[v].szName);
	p=ga.vexs[v].firstarc;
	while(p!=NULL)
	{
		w=p->adjvex;
		if(visited[w]==0)
			DFS(ga,ga.vexs[w].szName,visited);
		p=p->nextarc;
	}

}
void DFSTravel(Net ga,char *name)
{
	int v,k=0;
	int visited[20];
	for(v=0;v<ga.vexnum;v++)
		visited[v]=0;
	for(v=LocateVex(ga,name);k!=2;v=(v+1)%(ga.vexnum-1))
	{
		if(v+1==LocateVex(ga,name))
			k++;
		if(visited[v]==0)
			DFS(ga,ga.vexs[v].szName,visited);
		
	}
}

void BFSTravel(Net ga,char *name)
{
	ArcNode *p;
	int v,w,u,k=0;
    Queue Q;
	int visited[20];
	for(v=0;v<ga.vexnum;v++)
		visited[v]=0;
	InitQueue(Q);
	for(v=LocateVex(ga,name);k!=2;v=(v+1)%(ga.vexnum-1))
	{
		if(v+1==LocateVex(ga,name))
			k++;
		if(visited[v]==0)
		{
			visited[v]=1;
			printf("%s ",ga.vexs[v].szName);
			EnterQueue(Q,v);
			while(EmptyQueue(Q)!=0)
			{
				LeaveQueue(Q,u);
				p=ga.vexs[u].firstarc;
				while(p!=NULL)
				{
					w=p->adjvex;
					if(visited[w]==0)
					{
						printf("%s ",ga.vexs[w].szName);
						visited[w]=1;
						EnterQueue(Q,w);
					}
					p=p->nextarc;
				}
			}
		}
	
	}
}

int main()
{
	char name[40];
	Net ga;
	crt_net(ga);
	printf("请输入深度优先遍历开始点的名：");
	scanf("%s",name);
	printf("深度优先遍历：");
	DFSTravel(ga,name);
	printf("\n");
	printf("请输入广度优先遍历开始点的名：");
	scanf("%s",name);
	printf("广度优先遍历：");
	BFSTravel(ga,name);
	printf("\n");
	return 0;
}
