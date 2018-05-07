#include<stdio.h>
int main()
{
	void swap(int *pa, int *pb);
	int i, a[4], j;
	for(i=0;i<4;i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=0;i<3;i++)
	{
		for(j=i;j<3;j++)
		{
			if(a[i]<a[j+1])
		    {
			    swap(&a[i], &a[j+1]);
		    } 		
		}
	}
	for(i=0;i<4;i++)
	{
		if(i==3)
		{
			printf("%d\n", a[i]);
		}
		else
		{
	     	printf("%d ", a[i]);
		}
	}

	
	return 0;
}
void swap(int *pa, int *pb) 
{ 
    int t; 
    t=*pa;
    *pa=*pb;
	*pb=t; 
} 
