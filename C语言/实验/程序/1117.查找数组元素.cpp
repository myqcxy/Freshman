#include<stdio.h>

int main()
{
	int find(int a[], int n, int x);
	void del(int a[], int n, int i);
	void PrintArr(int a[], int n);
	int i, c[10], n, x;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &c[i]);
	}
	scanf("%d", &x);
	if(find(c, n, x)==-1)
	{
		printf("Not Found\n");
	}
	else
	{
		del(c, n, find(c, n, x));
		PrintArr(c, n);
	}
	
	
	return 0;
}
int find(int a[], int n, int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		break;
	}
	if(i<n)
	{
		return i;
	}
	else
	{
		return -1;
	}
	
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
 	for(i=0;i<n-1;i++)
 	{
 		
		printf("%4d", a[i]);
 		
	 }
 	
 }
