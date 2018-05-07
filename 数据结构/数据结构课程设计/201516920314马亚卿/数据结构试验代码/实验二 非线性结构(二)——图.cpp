#include<stdio.h>
#include<stdlib.h>
typedef struct ArcCell//�߶���
{
	int adj;//�ߵ�Ȩֵ
} ArcCell,AdjMatrix[20][20];
typedef struct//ͼ�Ķ���
{
	int vexs[20];//ͼ�Ķ���
	AdjMatrix arcs;//��
	int vexnum,arcnum;//����ͱߵĸ���
}MGraph;
int visit[20]={0};//������ȱ���ʱ�Ѿ����ʹ��Ľڵ�
int CreatUDN(MGraph *G);/*��ʼ��ͼ������Ϊ��Ҫ��ʼ����ͼ�ĵ�ַ����ֵΪ1ʱ�ɹ���*/
int LocateVex(MGraph *G,int u);//���ҽڵ�u��ͼG�е�λ�ò�����λ��
void DFSM(MGraph *G, int vex);//�ӽڵ�vex������ȱ���
void printG(MGraph *G);
int main()
{
	MGraph G; 
	if(CreatUDN(&G)) printf("�����ɹ���\n");
	printG(&G);
	int u;
	printf("��������Ҫ���ĸ��ڵ㿪ʼ��\n");
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
			printf("�������\n");
			exit(0);
		}
		scanf("%d", &u);
		y=LocateVex(G,u);
		if(y==-1){
			printf("�������\n");
			exit(0);
		}
		scanf("%d", &u);
		G->arcs[x][y].adj=u;
		G->arcs[y][x].adj=u;
	}						
}
