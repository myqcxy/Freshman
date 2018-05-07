#include<stdio.h>
int main()
{
	int IsUpperTriMatrix(int a[][10], int n);
	int a[10][10], n, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	if(IsUpperTriMatrix(a, n)==1)
	printf("YES\n");
	if(IsUpperTriMatrix(a, n)==0)
	printf("NO\n");
	
	return 0;
}
int IsUpperTriMatrix(int a[][10], int n)
{
	int i, j, t=0;
	for(i=1;i<n-1;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i][j]!=0)
			t=1;
		}
	}
	if(t==0)
	return 1;
	else
	return 0;
}

