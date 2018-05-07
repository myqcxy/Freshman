#include<stdio.h>
#define N 100
#include<math.h>
int main()
{
	struct point
	{
		int x, y;
	}a[N], t;
	int j, i, n;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);		
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i].x>a[j].x)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			if(a[i].x==a[j].x)
			{
				if(a[i].y>a[j].y)
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	printf("(%d,%d) ", a[i].x, a[i].y);
	putchar(10);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i].x<a[j].x)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			if(a[i].x==a[j].x)
			{
				if(a[i].y<a[j].y)
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	printf("(%d,%d) ", a[i].x, a[i].y);
	putchar(10);
	
	return 0;
}
