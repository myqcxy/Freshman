#include<stdio.h>
int main()
{
	int a[1000] ;
	int max, t=0, i, n;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<max)
		{
			max=a[i];
			t=i;
		}
	}
	printf("%d %d", a[t], t);
	
	
	return 0;
}
