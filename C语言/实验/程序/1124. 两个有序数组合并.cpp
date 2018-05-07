#include<stdio.h>

int a[1000000], b[1000000], c[2000000];
int main()
{

	int m, i, n, j, t=0;

	scanf("%d", &m);
	for(i=0;i<m;i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &b[i]);
	}
	for(i=m-1,j=0;t<m+n;t++)
	{
		if(a[i]==b[j])
		{
			c[t]=a[i];
			i--;
		}
		else if(a[i]>b[j])
		{
			c[t]=a[i];
			i--;
		}
		else
		{
			c[t]=b[j];
			j++;
		}
			
	}
	printf("%d", c[0]);
	for(i=1;i<m+n;i++)
	printf(" %d", c[i]);

	return 0;
}

