#include<stdio.h>
#define N 200
int r[N][N];
double p[N],q[N], c[N][N];
int s[N];
void OBST(int n)
{
	
	int w[N][N];
	int i, j, t, k;
	for(i = 1;i <= n+1;i++)
	{
		c[i][i-1] = 0;
		w[i][i-1] = q[i-1];
	}
	for(t=0;t<n;t++)
		for(i=1;i<=n-t;i++)
		{
			j=i+t;
			w[i][j]=w[i][j-1]+p[i]+q[j];
			c[i][j]=c[i+1][j];
			r[i][j]=i;
			for(k=i+1;k<=j;k++)
				if(c[i][k-1]+c[k+1][j]<c[i][j])
				{
					c[i][j]=c[i][k-1]+c[k+1][j];
					r[i][j]=k;
				}
			c[i][j]+=w[i][j];
		}		
}
void BestSolution(int i,int j)
{
	if(i<=j)
	{
		printf("%d ", s[r[i][j]]);
		BestSolution(i,r[i][j]-1);
		BestSolution(r[i][j]+1,j);
	}
}

int main()
{
	int i;
	for(i=1;i<124;i++) 
	{
		scanf("%d%*c%lf", &s[i],&p[i]);
		q[i] = 0;
	}
	q[0] = 0;
	
	int j;

	 OBST(123);
	BestSolution(1,123);
	putchar(10);
		printf("%5d", c[1][123]);
	printf("\n");


	
	
	
	return 0 ;
}
