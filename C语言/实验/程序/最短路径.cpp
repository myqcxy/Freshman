#include<stdio.h>
#define N 100
#define flase 0
#define ture 1
#define max  10000
void Dijkstra(int n,int u,int dist[], int p[],int c[N][N]);

int main()
{
	int v = 0, e = 0;
	printf("请输入节点个数和边的个数：\n");
	scanf("%d%d", &v, &e);
	int c[N][N];
	for(int i = 0;i < N;i++)
	for(int j = 0;j < N;j++)
	c[i][j] = max;
	int start, end;
	for(int i = 0;i < e; i++) 
	{
		printf("请输入第%d个边以及权值:",i+1);
		scanf("%d%d", &start, &end);
		scanf("%d", &c[start][end]);
	}
	int j, i;
	for(i = 0;i < v;i++)
	{
		for(j = 0; j <v;j++)
		printf("%6d ", c[i][j]);
		putchar(10);
	}
	putchar(10);
	int p[N];
	int u = 0;
	int dist[N];
	Dijkstra(v,u,dist,p, c);
	for(int i =1;i < v;i++)
	{
		printf("距离为%d ：%d ", dist[i], i);
		for(int j = i; p[j] != u;j = p[j])
		printf("%d ", p[j]);
		printf("%d\n", u);
	}
//	printf("%d ", p[i]);
	
	return 0;
}
void Dijkstra(int n,int u,int dist[],int p[], int c[N][N])
{
	bool s[n];
	for(int i = 0;i < n;i++)
	{
		dist[i] = c[u][i];
		s[i] = flase;
		if(dist[i] == max)
			p[i] = -1;
		else  p[i] = u;
	}
	dist[u] = 0;
	s[u] = ture;
	for(int i = 0;i <n;i++)
	{
		int temp = max;
		int t = u;
		for(int j = 0;j < n;j++)
		{
			if((!s[j])&&dist[j] < temp)
			{
				t = j ;
				temp = dist[j];
			}
		}
		if(t==u) break;
		s[t] = ture;
		for(int j =0; j <n ; j++)
		{
			if((!s[j])&&(c[t][j] < max))
				if(dist[j]>(dist[t] + c[t][j]))
				{
					dist[j] = dist[t] + c[t][j];
					p[j] = t;
				}
		}
	}
}
