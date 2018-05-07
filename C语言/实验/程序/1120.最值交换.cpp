#include<stdio.h>
int main()
{
	int MinIndex(int a[], int n);
	int MaxIndex(int a[], int n);
	void PrintArr(int a[], int n);
	int a[10], n, i, c, d;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
        scanf("%d", &a[i]);
	}
	d=MinIndex(a, n);
	c=a[0];
	a[0]=a[d];
	a[d]=c;
	d=MaxIndex(a, n);
    c=a[n-1];
    a[n-1]=a[d];
    a[d]=c;
    PrintArr(a, n);

	return 0;
}
int MinIndex(int a[], int n)
{
	int i, min=0;
	for(i=1;i<n;i++)
	{
		if(a[i]<a[min])
		min=i;
	}
	return min;
	
}
int MaxIndex(int a[], int n)
{
	int i, max=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>a[max])
		{
			max=i;
		}
		
	}
	return max;
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
