/*
  顺序表操作。
  在线性表L的第i个元素前插入元素x
*/
#include <stdio.h>

#define MAXSIZE 30

typedef struct
{
	int date[MAXSIZE];
	int length;
}SQList;
void InitSqList(SQList *L);
void TraverseSqList(SQList *L);
int SqListInsert(SQList *L);
void Input(SQList *L);
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
	L->length=0;
}
void Input(SQList *L)
{
    int n;
    printf("请输入需要输入的若干整数：(输入-1时结束)\n");
    scanf("%d", &n);
	for(L->length=0;n!=-1&&L->length<MAXSIZE;L->length++) 
	{
		L->date[L->length]=n;
		scanf("%d", &n);
	}
}

void TraverseSqList(SQList *L)
{
	for(int i=0; i<L->length; i++)
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
		return(-1); //溢出错误
	for(j=L->length-1;j>=i;j--)
		L->date[j+1]=L->date[j];
        L->date[i]=ch;
	    L->length++;
	return(1);
}

