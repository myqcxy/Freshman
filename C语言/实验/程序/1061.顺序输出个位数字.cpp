#include<stdio.h>
int main()
{
	int n, i, q, h=1;
	scanf("%d", &n);
	q=n;
	while(n>=10)
	{
		h*=10;
		n=n/10;
	}
	for(;h>0;h=h/10)
	{
		printf("%d ", q/h);
		q=q%h;
	}
	
	return 0;
}
