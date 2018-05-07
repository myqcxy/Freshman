#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>  
/****************************************/  
#define MaxVex  255  
#define TRUE    1  
#define FALSE   0  
typedef char    VertexType;     //��������  
//typedef int       EdgeType;   //Ȩֵ����  
typedef int     Bool;  
Bool visited[MaxVex];  
  
typedef struct EdgeNode {       //�߱���  
    int             adjvex;     //���ڽӵ��ڶ��������е��±�  
//  EdgeType        weight;     //Ȩֵ��  
    struct EdgeNode *next;      //���� ָ����һ���ڽӵ�  
}EdgeNode;  
  
typedef struct VertexNode {  
    VertexType  data;  
    EdgeNode    *firstedge;     //�߱�ͷָ��  
}VertexNode, AdjList[MaxVex];  
  
typedef struct {  
    AdjList     adjList;  
    int numVertexes, numEdges;      //ͼ�е�ǰ�Ľ�����Լ�����  
}GraphAdjList;  
/****************************************/  
//������ȱ�����Ҫ��ѭ������  
typedef struct {  
    int data[MaxVex];  
    int front, rear;  
}Queue;  
/****************************************/  
//���е���ز���  
  
//��ʼ��  
void InitQueue(Queue *Q)  
{  
    Q->front = Q->rear = 0;  
}  
  
//���  
void EnQueue(Queue *Q, int e)  
{  
    if ((Q->rear+1)%MaxVex == Q->front)  
        return ;  
  
    Q->data[Q->rear] = e;  
    Q->rear = (Q->rear+1)%MaxVex;  
}  
  
//�п�  
Bool QueueEmpty(Queue *Q)  
{  
    if (Q->front == Q->rear)  
        return TRUE;  
    else  
        return FALSE;  
}  
  
//����  
void DeQueue(Queue *Q, int *e)  
{  
    if (Q->front == Q->rear)  
        return ;  
      
    *e = Q->data[Q->front];  
    Q->front = (Q->front+1)%MaxVex;  
}  
/****************************************/  
//����ͼ���ڽӱ�ṹ  
void CreateALGraph(GraphAdjList *G)  
{  
    int i, j, k;  
//  EdgType w;  
    EdgeNode *p;  
    printf("����ͼ�Ľ�����Լ�������");  
    scanf("%d%d", &G->numVertexes, &G->numEdges);  
    fflush(stdin);  
      
    printf("����������㣺");  
    for (i=0; i<G->numVertexes; ++i)  
    {  
        scanf("%c", &G->adjList[i].data);  
        G->adjList[i].firstedge = NULL;  
        fflush(stdin);  
    }  
  
    for (k=0; k<G->numEdges; ++k)  
    {  
        printf("����(vi, vj)�ϵĶ�����ţ�");  
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
//������ȱ���  
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
//ͼ�Ĺ�����ȱ���  
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
