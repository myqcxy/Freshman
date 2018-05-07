#include<stdio.h>
int main()
{
	int a[10][10], b[10][10],c[10][10]={0}, m, p, n, i, j, sum=0, t, f;
	scanf("%d%d%d", &m, &p, &n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for(i=0;i<p;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(t=0;t<p;t++)
			c[i][j]+=a[i][t]*b[t][j];
		}
		
	}
	for(i=0;i<m;i++)
	{
		printf("%d", c[i][0]);
		for(j=1;j<n;j++)
		{
			printf(" %d", c[i][j]);
		}
		putchar(10);
	}

	return 0;
}
