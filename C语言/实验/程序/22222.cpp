#include<stdio.h>
int main()
{
	int a(int b[], int n);
	int c[5]={1,2,3,4,5};
    a(c, 5);
	int i;
	
	
	return 0;
}
int a(int b[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		b[i]+=1;
	}
	for(i=0;i<5;i++)
	{
		printf("%d ", b[i]);
	}
}
