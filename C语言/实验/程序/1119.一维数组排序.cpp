#include<stdio.h>
int main()
{
	void PrintArr(int a[], int n);
	int sort(int a[], int n);
	int a[10];
	int n, i;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, n);
	PrintArr(a, n);
	
	return 0;
} 
int sort(int a[], int n)
{
	int i, j, min;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(a[j]<a[j-1])
			{
				min=a[j-1];
				a[j-1]=a[j];
				a[j]=min;
			}
		}
	}
}
void PrintArr(int a[], int n)
 {
 	int i;
 	for(i=0;i<n;i++)
 	{
 		if(i==n-1)
 		{
 			printf("%d", a[i]);
		 }
	    else
		 {
		 	printf("%d ", a[i]);
		 }
 		
	 }
 	
 }
