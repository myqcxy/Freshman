#include<stdio.h>
int main()
{
	int BalanceMatrix(int a[], int n);
	int n, a[100][100], i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	
	return 0;
}
int BalanceMatrix(int a[][100], int n)
{
	int i, j, b[100][100], t;
	for(i=0;i<n;i++)
	{
		t=0;
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
			t++;
		}
		b[i][0]=t;
	}
	for(j=0;j<n;i++)
	{
		t=0;
		for(i=0;i<n;i++)
		{
			if(a[i][j]==1)
			t++;
		}
		b[0][j]=t;
	}
	
}
