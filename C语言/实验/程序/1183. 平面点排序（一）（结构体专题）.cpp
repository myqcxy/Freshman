#include<stdio.h>
#define N 100
#include<math.h>
int main()
{
	struct point
	{
		int x, y;
		double dis;
	}a[N], t;
	int j, i, n;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].dis=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);		
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i].dis>a[j].dis)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	printf("(%d,%d) ", a[i].x, a[i].y);
	
	
	return 0;
}
