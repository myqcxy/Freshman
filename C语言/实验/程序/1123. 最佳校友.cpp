#include<stdio.h>
#define N 100
int main()
{
	int a[N]={0}, i, d=0, b, flag=1, c[N];
	while(scanf("%d", &b),b>=0)
	{
		a[b]++;
	}
	for(i=0;i<N;i++)
	{
		if(a[i]>=flag)
		flag=a[i];
	}
	for(i=0;i<N;i++)
	{
		if(a[i]==flag)
		{
			c[d]=i;
			d++;
		}
	}
	printf("%d", c[0]);
	for(i=1;i<d;i++)
	printf(" %d", c[i]);
	return 0;
}
