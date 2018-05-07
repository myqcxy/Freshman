#include<stdio.h>
int main()
{
	int insert(int a[], int n, int num);
	void PrintArr(int a[], int n);
	int n, i, num,  b[100];
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &b[i]);
	}
	scanf("%d", &num);
	insert(b, n, num);
    PrintArr(b, n);
	return 0;
}
int insert(int a[], int n, int num)
{
	int i, c, t;
	if(a[n-1]<=num)
	{
		a[n]=num;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>num)
		{
			for(t=n;t>i;t--)
			{   
			    a[t]=a[t-1];
			}
			a[i]=num;
			break;
		}
	}
	
	
} 
void PrintArr(int a[], int n)
 {
 	int i;
 	for(i=0;i<n+1;i++)
 	{
 		if(i==n)
 		{
 			printf("%d", a[i]);
		 }
	    else
		 {
		 	printf("%d ", a[i]);
		 }
 		
	 }
 	
 }
