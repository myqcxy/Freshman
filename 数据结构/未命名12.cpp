#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>  
/****************************************/  
#define MaxVex  255  
#define TRUE    1  
#define FALSE   0  
typedef char    VertexType;     //顶点类型  
//typedef int       EdgeType;   //权值类型  
typedef int     Bool;  
Bool visited[MaxVex];  
  
typedef struct EdgeNode {       //边表结点  
    int             adjvex;     //该邻接点在顶点数组中的下标  
//  EdgeType        weight;     //权值域  
    struct EdgeNode *next;      //链域 指向下一个邻接点  
}EdgeNode;  
  
typedef struct VertexNode {  
    VertexType  data;  
    EdgeNode    *firstedge;     //边表头指针  
}VertexNode, AdjList[MaxVex];  
  
typedef struct {  
    AdjList     adjList;  
    int numVertexes, numEdges;      //图中当前的结点数以及边数  
}GraphAdjList;  
/****************************************/  
//广度优先遍历需要的循环队列  
typedef struct {  
    int data[MaxVex];  
    int front, rear;  
}Queue;  
/****************************************/  
//队列的相关操作  
  
//初始化  
void InitQueue(Queue *Q)  
{  
    Q->front = Q->rear = 0;  
}  
  
//入队  
void EnQueue(Queue *Q, int e)  
{  
    if ((Q->rear+1)%MaxVex == Q->front)  
        return ;  
  
    Q->data[Q->rear] = e;  
    Q->rear = (Q->rear+1)%MaxVex;  
}  
  
//判空  
Bool QueueEmpty(Queue *Q)  
{  
    if (Q->front == Q->rear)  
        return TRUE;  
    else  
        return FALSE;  
}  
  
//出队  
void DeQueue(Queue *Q, int *e)  
{  
    if (Q->front == Q->rear)  
        return ;  
      
    *e = Q->data[Q->front];  
    Q->front = (Q->front+1)%MaxVex;  
}  
/****************************************/  
//建立图的邻接表结构  
void CreateALGraph(GraphAdjList *G)  
{  
    int i, j, k;  
//  EdgType w;  
    EdgeNode *p;  
    printf("输入图的结点数以及边数：");  
    scanf("%d%d", &G->numVertexes, &G->numEdges);  
    fflush(stdin);  
      
    printf("输入各个顶点：");  
    for (i=0; i<G->numVertexes; ++i)  
    {  
        scanf("%c", &G->adjList[i].data);  
        G->adjList[i].firstedge = NULL;  
        fflush(stdin);  
    }  
  
    for (k=0; k<G->numEdges; ++k)  
    {  
        printf("输入(vi, vj)上的顶点序号：");  
        scanf("%d%d", &i, &j);  
        p = (EdgeNode *)malloc(sizeof(EdgeNode));  
        p->adjvex = j;  
        p->next = G->adjList[i].firstedge;  
        G->adjList[i].firstedge = p;  
  
        p = (EdgeNode *)malloc(sizeof(EdgeNode));  
        p->adjvex = i;  
        p->next = G->adjList[j].firstedge;  
        G->adjList[j].firstedge = p;  
    }  
}  
/****************************************/  
//深度优先遍历  
void DFS(GraphAdjList G, int i)  
{  
    EdgeNode *p;  
    visited[i] = TRUE;  
    printf("%c ", G.adjList[i].data);  
    p = G.adjList[i].firstedge;  
  
    while (p)  
    {  
        if (!visited[p->adjvex])  
            DFS(G, p->adjvex);  
        p = p->next;  
    }  
}  
  
  
void DFSTraverse(GraphAdjList G)  
{  
    int i;  
    for (i=0; i<G.numVertexes; ++i)  
        visited[i] = FALSE;  
  
    for (i=0; i<G.numVertexes; ++i)  
        if (!visited[i])  
            DFS(G, i);  
}  
/****************************************/  
//图的广度优先遍历  
void BFSTraverse(GraphAdjList *GL)  
{  
    int i;  
    Queue Q;  
    EdgeNode *p;  
  
    for (i=0; i<GL->numVertexes; ++i)  
        visited[i] = FALSE;  
    InitQueue(&Q);  
  
    for (i=0; i<GL->numVertexes; ++i)  
    {  
        if (!visited[i])  
        {  
            visited[i] = TRUE;  
            printf("%c ", GL->adjList[i].data);  
            EnQueue(&Q, i);  
  
            while (!QueueEmpty(&Q))  
            {  
                DeQueue(&Q, &i);  
                p = GL->adjList[i].firstedge;  
                while (p)  
                {  
                    if (!visited[p->adjvex])  
                    {  
                        visited[p->adjvex] = TRUE;  
                        printf("%c ", GL->adjList[p->adjvex].data);  
                        EnQueue(&Q, p->adjvex);  
                    }  
                    p = p->next;  
                }  
            }  
        }  
    }  
}  
/****************************************/  
int main(void)  
{  
    GraphAdjList G;  
    CreateALGraph(&G);  
    BFSTraverse(&G);  
    return 0;  
}  
