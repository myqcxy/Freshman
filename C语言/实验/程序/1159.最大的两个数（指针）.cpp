#include<stdio.h>
void swap(int *pa, int *pb);
void LargestTow(int a[],int n,int *pfirst,int *psecond);
int main()
{
	
	int a[1000], i, n, first, second;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	LargestTow(a, n, &first, &second);
	printf("%d %d", first, second);
	
	return 0;
}
void LargestTow(int a[],int n,int *pfirst,int *psecond)
{
	int i, j;
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n-1;j++)
		{
			if(a[i]<a[j+1])
			{
				swap(&a[i], &a[j+1]);
			}
		}

	}
	*pfirst=a[0];
	*psecond=a[1];
	
} 
void swap(int *pa, int *pb) 
{ 
    int t; 
    t=*pa;
    *pa=*pb;
	*pb=t; 
} 
