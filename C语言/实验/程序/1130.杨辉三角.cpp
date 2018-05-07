#include<stdio.h>
int main()
{
	int n, i, j, a[30][30];
	while(scanf("%d", &n)!=EOF)
	{
		a[0][0]=a[1][0]=a[1][1]=1;
	for(i=2;i<n;i++)
	{
		a[i][0]=a[i][i]=1;
	}
	for(i=2;i<n;i++)
	{
		for(j=1;j<i;j++)
		{
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}
	for(i=0;i<n;i++)
	{
		j=0;
		printf("%d", a[i][j]);
		for(j=1;j<=i;j++)
		printf(" %d", a[i][j]);
		putchar(10);
	}
	}
	a[0][0]=a[1][0]=a[1][1]=1;
	for(i=2;i<n;i++)
	{
		a[i][0]=a[i][i]=1;
	}
	for(i=2;i<n;i++)
	{
		for(j=1;j<i;j++)
		{
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}
	for(i=0;i<n;i++)
	{
		j=0;
		printf("%d", a[i][j]);
		for(j=1;j<=i;j++)
		printf(" %d", a[i][j]);
		putchar(10);
	}
	
	
	return 0;
}
