#include<stdio.h>
#define N 1000
int main()
{
	int flag=0, n, j=1, i,t=0, a[N], b[N];
	scanf("%d", &n);
	for(i=0;i<n;i++) 
	{
		scanf("%d", &a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i]>a[j])
			{
				
				flag=a[i];
				a[i]=a[j];
				a[j]=flag;
			}
		}
	}
	b[0]=a[0];
	for(i=1,j=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			b[j]=a[i];
			j++;
		}
	}
	printf("%d\n", j);
	printf("%d", b[0]);
	for(i=1;i<j;i++)
	{
		printf(" %d", b[i]);
	}
	
	
	
	return 0;
}
