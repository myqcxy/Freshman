/*#define MAX_VEX_NUM 50
typedef char VertexType;
typedef enum {
    DG, UDG
} GraphType;
typedef struct {
    VertexType vexs[MAX_VEX_NUM];
    int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} MGraph;
void create_MG(MGraph *MG) {
    int i, j, k;
    int v1, v2, type;
    char c1, c2;
    printf("Please input graph type DG(0) or UDG(1) :\n");
    scanf("%d", &type);
    if (type == 0)
        MG->type = DG;
    else if (type == 1)
        MG->type = UDG;
    else {
        printf("Please input correct graph type DG(0) or UDG(1)!\n");
        return;
    }
 
    printf(Please input vexmun : );
    scanf(%d, &MG->vexnum);
    printf(Please input arcnum : );
    scanf(%d, &MG->arcnum);
    getchar();
    for (i = 1; i <= MG->vexnum; i++) {
        printf(Please input %dth vex(char):, i);
        scanf(%c, &MG->vexs[i]);
        getchar();
    }
 
    //��ʼ���ڽӾ���
    for (i = 1; i <= MG->vexnum; i++) {
        for (j = 1; j <= MG->vexnum; j++) {
            MG->arcs[i][j] = 0;
        }
    }
 
    //����ߵ���Ϣ�������ڽӾ���
    for (k = 1; k <= MG->arcnum; k++) {
        printf(Please input %dth arc v1(char) v2(char) : , k);
 
        scanf(%c %c, &c1, &c2);
        v1 = getIndexOfVexs(c1, MG);
        v2 = getIndexOfVexs(c2, MG);
        if (MG->type == 1)
            MG->arcs[v1][v2] = MG->arcs[v2][v1] = 1;
        else
            MG->arcs[v1][v2] = 1;
        getchar();
    }
}*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VEX_NUM 50
typedef char VertexType;
typedef enum {
    DG, UDG
} GraphType;
typedef struct {
    VertexType vexs[MAX_VEX_NUM];
    int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} MGraph;
 
/**
 * �������Ƶõ�ָ�������ڶ��㼯���е��±�
 * vex  ����
 * return ����ҵ����򷵻��±꣬���򣬷��أ�
 */
int getIndexOfVexs(char vex, MGraph *MG) {
    int i;
    for (i = 1; i <= MG->vexnum; i++) {
        if (MG->vexs[i] == vex) {
            return i;
        }
    }
    return 0;
}
 
/**
 * �����ڽӾ���
 */
void create_MG(MGraph *MG) {
    int i, j, k;
    int v1, v2, type;
    char c1, c2;
    printf("Please input graph type DG(0) or UDG(1) :");
    scanf("%d", &type);
    if (type == 0)
        MG->type = DG;
    else if (type == 1)
        MG->type = UDG;
    else {
        printf("Please input correct graph type DG(0) or UDG(1)!");
        return;
    }
 
    printf("Please input vexmun : ");
    scanf("%d", &MG->vexnum);
    printf("Please input arcnum : ");
    scanf("%d", &MG->arcnum);
    getchar();
    for (i = 1; i <= MG->vexnum; i++) {
        printf("Please input %dth vex(char):", i);
        scanf("%c", &MG->vexs[i]);
        getchar();
    }
 
    //��ʼ���ڽӾ���
    for (i = 1; i <= MG->vexnum; i++) {
        for (j = 1; j <= MG->vexnum; j++) {
            MG->arcs[i][j] = 0;
        }
    }
 
    //����ߵ���Ϣ�������ڽӾ���
    for (k = 1; k <= MG->arcnum; k++) {
        printf("Please input %dth arc v1(char) v2(char) : ", k);
 
        scanf("%c %c", &c1, &c2);
        v1 = getIndexOfVexs(c1, MG);
        v2 = getIndexOfVexs(c2, MG);
        if (MG->type == 1)
            MG->arcs[v1][v2] = MG->arcs[v2][v1] = 1;
        else
            MG->arcs[v1][v2] = 1;
        getchar();
    }
}
/**
 * ��ӡ�ڽӾ���Ͷ�����Ϣ
 */
void print_MG(MGraph MG) {
    int i, j;
    if(MG.type == DG){
        printf("Graph type: Direct graph\n");
    }
    else{
        printf("Graph type: Undirect graph\n");
    }
 
    printf("Graph vertex number: %d\n",MG.vexnum);
    printf("Graph arc number: %d\n",MG.arcnum);
 
    printf("Vertex set:");
    for (i = 1; i <= MG.vexnum; i++)
        printf("%c   ", MG.vexs[i]);
    printf("Adjacency Matrix:");
 
    for (i = 1; i <= MG.vexnum; i++) {
        j = 1;
        for (; j < MG.vexnum; j++) {
            printf("%d   ", MG.arcs[i][j]);
        }
        printf("%d", MG.arcs[i][j]);
    }
}
 
/**
 * ������
 */
int main(void) {
    MGraph MG;
    create_MG(&MG);
    print_MG(MG);
    return EXIT_SUCCESS;
}
