#include<stdio.h>
int main()
{
	int a[100];
	int i,n,j,t;

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i]<a[j])
			t=a[i],a[i]=a[j],a[j]=t;
		}
	}

	for(i=0;i<n;i++)
	{
		
		printf("%d ",a[i]);
	}

	return 0;

	}
