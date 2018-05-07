#include<stdio.h>
int main()
{
	void PrintArr(int a[], int n);
	void del(int a[], int n, int i);
	int m[10];
	int i, n, c;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &m[i]);
	}
	scanf("%d", &i);
    del(m, n, i);
    PrintArr(m, n-1);
	return 0;
}
void del(int a[], int n, int i)
{
	int t;
	for(t=i;t<n;t++)
	{
		a[t]=a[t+1];
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
 
