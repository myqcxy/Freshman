#include<stdio.h>
#include<stdlib.h>
int main()
{
	void ringShift(int *a, int n, int k); 
	int n, k, i;
	scanf("%d", &n);
	int *a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d", a+i);
	}
	scanf("%d", &k);
	ringShift(a, n, k);
	for(i=0;i<n;i++)
	{
		if(i==n-1)
		{
			printf("%d", a[i]);
		}
		else
		{
			printf("%d ",*(a+i));
		}	
	}
	
	return 0;
}
void ringShift(int *a, int n, int k)
{
	int i, j, *c=(int *)malloc(k*sizeof(int));
	for(i=0,j=0;i<n-k;i++,j++)
	{
		*(c+j)=*(a+i);
	}
	for(i=0,j=n-k;i<k;i++,j++)
	{
		*(a+i)=*(a+j);
	}
	for(i=k,j=0;i<n;i++,j++)
	{
		a[i]=c[j];
	}

}
