#include<stdio.h>
int main()
{
	int b=0, i, n, a, t;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		a=1;
		for(t=i;t>=1;t--)
		{
			a*=t;
		}
		b=b+a;
	}
	printf("%d\n", b); 
     
	return 0;
}
