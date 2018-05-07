#include<stdio.h>
#include<stdlib.h>
typedef struct ArcCell//边定义
{
	int adj;//边的权值
} ArcCell,AdjMatrix[20][20];
typedef struct//图的定义
{
	int vexs[20];//图的顶点
	AdjMatrix arcs;//边
	int vexnum,arcnum;//顶点和边的个数
}MGraph;
int visit[20]={0};//深度优先遍历时已经访问过的节点
int CreatUDN(MGraph *G);/*初始化图，参数为需要初始化的图的地址返回值为1时成功，*/
int LocateVex(MGraph *G,int u);//查找节点u在图G中的位置并返回位置
void DFSM(MGraph *G, int vex);//从节点vex深度优先遍历
void printG(MGraph *G);
int main()
{
	MGraph G; 
	if(CreatUDN(&G)) printf("创建成功！\n");
	printG(&G);
	int u;
	printf("请输入需要从哪个节点开始！\n");
	scanf("%d", &u);
	DFSM(&G,u);
	return 0;
}
void DFSM(MGraph *G, int vex)
{
	int i,j;
	i=LocateVex(G,vex);
	printf("%d,",vex);
	visit[i]=1;
	for(j=0;j<G->vexnum;j++)
	if(G->arcs[i][j].adj&&!visit[j])
	DFSM(G,G->vexs[j]);
}
void printG(MGraph *G)
{
	int i,j;
	printf("  ");
	for(i=0;i<G->vexnum;i++)
	printf("%d ", G->vexs[i]);
	putchar(10);
	for(i=0;i<G->vexnum;i++)
	{
		printf("%d ", G->vexs[i]);		
		for(j=0;j<G->vexnum;j++)
		printf("%d ", G->arcs[i][j].adj);
		putchar(10);
	}
	
}
int LocateVex(MGraph *G,int u)
{
	int i=-1;
	for(i=0;i<G->vexnum;i++)
	if(G->vexs[i]==u)
	return i;
	return -1;
}
int CreatUDN(MGraph *G)
{
	int i,x,y,u,j;
	scanf("%d%d", &G->vexnum,&G->arcnum);
	for(i=0;i<G->vexnum;i++)
	for(j=0;j<G->vexnum;j++)
	G->arcs[i][j].adj=0;
	for(i=0;i<G->vexnum;i++)
	scanf("%d", &G->vexs[i]);
	for(i=0;i<G->arcnum;i++)	
	{
		scanf("%d", &u);
		x=LocateVex(G,u);
		if(x==-1){
			printf("输入错误\n");
			exit(0);
		}
		scanf("%d", &u);
		y=LocateVex(G,u);
		if(y==-1){
			printf("输入错误\n");
			exit(0);
		}
		scanf("%d", &u);
		G->arcs[x][y].adj=u;
		G->arcs[y][x].adj=u;
	}						
}
