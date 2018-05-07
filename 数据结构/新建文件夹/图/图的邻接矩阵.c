#include<stdio.h>
typedef struct ArcCell
{
	int adj;
} ArcCell,AdjMatrix[20][20];
typedef struct
{
	int vexs[20];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;
int visit[20]={0};
int CreatUDN(MGraph *G);
int LocateVex(MGraph *G,int u);
void DFSM(MGraph *G, int vex);
int main()
{
	int vex;
	MGraph G;
	if(CreatUDN(&G)) printf("图的邻接矩阵创建成功\n");	
	printf("请输入需要遍历的首节点：\n");
	scanf("%d",&vex);
	DFSM(&G,vex);
	return 0;
}
void DFSM(MGraph *G, int vex)
{
	int i, j;		
	printf("%d,",vex);	
	i=LocateVex(G,vex);
	visit[i]=1;
	for(j=0;j<G->vexnum;j++)
	if(G->arcs[i][j].adj&&!visit[j])
	DFSM(G,G->vexs[j]);
}
int LocateVex(MGraph *G,int u)
{
	int i;
	for(i=0;i<G->vexnum;i++)
	{
		if(u==G->vexs[i])
		return i;
	}
}
int CreatUDN(MGraph *G)
{
	scanf("%d%d", &G->vexnum,&G->arcnum);
	int i,k, j,x,y,w;
	int info;
	for(i=0;i<G->vexnum;++i) scanf("%d", &G->vexs[i]);
	for(i=0;i<G->vexnum;++i)
	for(j=0;j<G->vexnum;++j) 
		G->arcs[i][j].adj=0;
	for(k=0;k<G->arcnum;++k)
	{
		scanf("%d%d%d",&x,&y,&w);
		i=LocateVex(G,x);
		j=LocateVex(G,y);
		G->arcs[i][j].adj=w;
		G->arcs[j][i]=G->arcs[i][j];
	}
	printf("   ");
	for(i=0;i<G->vexnum;++i) 
	printf("%d  ", G->vexs[i]);
	putchar(10);
	for(i=0;i<G->vexnum;++i)
	{
		printf("%d  ",G->vexs[i]);
		for(j=0;j<G->vexnum;j++)
		printf("%d  ", G->arcs[i][j].adj);
		putchar(10);
	}
	return 1;
}













