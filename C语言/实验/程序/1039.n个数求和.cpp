#include<stdio.h>
int main()
{
	int n,sum=0, m, i;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%d", &m);
		sum=sum+m;
	}
	printf("%d", sum);
	
	return 0;
}
