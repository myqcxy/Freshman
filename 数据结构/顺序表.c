#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define init 10 

typedef struct
{
	int *date;
	int length;
	int lestsize;
}SQList;
void InitSqList(SQList *L);
void TraverseSqList(SQList *L);
int SqListInsert(SQList *L);
void Input(SQList *L);
void addsize(SQList *L);
int main()
{
	
	SQList L;
	InitSqList(&L);	
	Input(&L);
	
	TraverseSqList(&L);

	printf("\n顺序表插入...\n");
	SqListInsert(&L);

	printf("\n遍历顺序表...\n");
	TraverseSqList(&L);

	printf("\n\n");
}
void InitSqList(SQList *L)
{
	L->date=(int *)malloc(MAXSIZE*sizeof(int));
	if(!L->date) exit(0);
	L->length=0;
	L->lestsize=MAXSIZE;
}
void addsize(SQList *L)
{
	int *newsize;
	newsize=(int *)realloc(L->date,(L->lestsize+init)*sizeof(int));
	if(!newsize) exit(0);
	L->date=newsize;
	L->lestsize=L->lestsize+init;
}
void Input(SQList *L)
{
    int n;
    printf("请输入需要输入的若干整数：(输入-1时结束)\n");
    scanf("%d", &n);
	for(L->length=0;n!=-1;L->length++)
	{
		if(L->length==MAXSIZE-1)
		addsize(L);
		L->date[L->length]=n;
		scanf("%d", &n);
	}
}

void TraverseSqList(SQList *L)
{
	int i;
	for(i=0; i<L->length; i++)
		printf("%d,", L->date[i]);
	printf("\n");
}

int SqListInsert(SQList *L)
{
	int j, i;
	int ch;
	scanf("%d",&i); 
	i--;     /*i为下标*/
	scanf("%d",&ch);
    //在线性表L的第i个元素前插入元素x
	if (i<0 || i>L->length-1)
		return(0); //位置错误
	if(L->length==MAXSIZE-1)
		addsize(L);//溢出错误
	for(j=L->length-1;j>=i;j--)
		L->date[j+1]=L->date[j];
        L->date[i]=ch;
	    L->length++;
	return(1);
} 

