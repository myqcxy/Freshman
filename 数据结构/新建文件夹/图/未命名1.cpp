#include<stdio.h>
typedef struct ArcCell
{
	int adj;
	char *info;
} ArcCell,AdjMatrix[20][20];
typedef struct
{
	int vexs[20];
	AdjMatrix arcs;
	int vexnum,arcnum;
	int kind;
}MGraph;
int CreatUDN(MGraph *G);
int LocateVex(MGraph *G,int u);
int main()
{
	MGraph G;
	printf("%d", CreatUDN(&G));
	
	
	
	
	return 0;
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
	for(j=0;j<G->vexnum;++j) {
		G->arcs[i][j].adj=0;
		G->arcs[i][j].info=NULL;
	}
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













