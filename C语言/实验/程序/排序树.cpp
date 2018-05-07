/*给定一系列键值和权重，构造最优二叉排序树，使得总的查找次数最少。
要求的输出格式为：第一行为最优的查找次数，第二行为最优二叉排序树的前序遍历得到的序列，
然后一个空行，随后为源代码。算法的输入如下(冒号前为键值，冒号后为权重)：
1:0 2:56 3:19 4:80 5:58 6:47 7:35 8:89 9:82 10:74
 11:17 12:85 13:71 14:51 15:30 16:1 17:9 18:36 19:14 20:16
  21:98 22:44 23:11 24:0 25:0 26:37 27:53 28:57 29:60 30:60
   31:16 32:66 33:45 34:35 35:5 36:60 37:78 38:80 39:51 40:30 
   41:87 42:72 43:95 44:92 45:53 46:14 47:46 48:23 49:86 50:20 
   51:77 52:84 53:99 54:99 55:61 56:39 57:26 58:29 59:84 60:2 
   61:37 62:9 63:67 64:5 65:0 66:91 67:27 68:27 69:58 70:69 
   71:83 72:72 73:48 74:20 75:74 76:46 77:45 78:94 79:74 80:10
    81:59 82:38 83:73 84:60 85:57 86:36 87:15 88:22 89:42 90:80
	 91:51 92:98 93:75 94:34 95:16 96:65 97:49 98:6 99:69 100:50 101:14 102:94 103:14 104:90 105:69 106:30 107:42 108:7 109:96 110:68 111:15 112:87 113:82 114:58 115:19 116:17 117:81 118:47 119:15 120:50 121:73 122:40 123:27 
*/
#include<stdio.h>
#include<stdlib.h> 
struct Node{
	int date;
	struct Node *lchild;
	struct Node *rchild;
};
typedef struct Node node;
void InitTree(node *&T) 
{
	T=NULL;	
}
node* CreatTree()
{
	int s;
	scanf("%d", &s);
	node *T;
	if(s==-1)
	T = NULL;
 	else
	{
		T = (node*)malloc(sizeof(node));
		T->date = s;
		T->lchild = CreatTree();
		T->rchild = CreatTree();
	}
	return T;
	
}
void printT(node* &T)
{
	if(T)
	{
		
		printT(T->lchild);
		printf("%d ", T->date);
		printT(T->rchild);
	}
}
void insert(node *&T,int x)
{
	if(T == NULL)
	{
		T = (node*)malloc(sizeof(node));
		T->date=x;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	if(x < T->date) insert(T->lchild,x);
	if(x > T->date) insert(T->rchild,x);
}
int main()
{
	int a[123], i = 0, b[123], j = 0;
	node *T;
	InitTree(T);
	while(scanf("%d%*c%d", &a[i++], &b[j++]),a[i-1] != -1)
		insert(T,a[i-1]);

	printT(T);
	
	return 0;
}
