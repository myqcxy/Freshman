#include<stdio.h>
int main()
{
	int i, n;
	double sum1=0, sum2=0;
	scanf("%d", &n);
	for(i=1;i<=n;i+=2)
	{
		sum1=sum1+1.0/(2*i-1);
	}
	for(i=2;i<=n;i+=2)
	{
		sum2=sum2+1.0/(2*i-1);
	}
	printf("%.2f", sum1-sum2);
	
	return 0;
}
