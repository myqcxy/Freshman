#include<stdio.h>
int main()
{
	struct xing
	{
		int x, y; 
	}a[300], b;
	int j, i, n, c=0;
	scanf("%d", &n); 
	for(i=0;i<n;i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	c=n;
	for(i=0;i<n;i++) 
	{
		for(j=i+1;j<n;j++)
		if(a[i].x==a[j].x&&a[i].y==a[j].y)
		{
			c--;
			a[j].x=-11111*j;
		}
	}
	printf("%d\n", c); 

	return 0; 
} 
