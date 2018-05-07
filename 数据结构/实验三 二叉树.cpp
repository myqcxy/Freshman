#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	struct node *lch,*rch;
}BinNode,*BinTree;
void creatbitree(BinTree *T);
void travelbitree(BinTree T);
int main()
{
	BinTree T;
	creatbitree(&T);
	travelbitree(T);
	
	
	
	return 0;
}
void travelbitree(BinTree T)
{

	if(T)
	{
			
		printf("%d", T->date); 
		travelbitree(T->lch);
		travelbitree(T->rch);
	}
} 
void creatbitree(BinTree *T)
{
	int n;
	scanf("%d", &n);
	
	if(n==-1) *T=NULL;
	
	else{
		*T=(BinTree)malloc(sizeof(BinNode));
		(*T)->date=n;
		creatbitree(&(*T)->lch);
		creatbitree(&(*T)->rch);
	}
}






