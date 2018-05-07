#include<stdio.h>
int main()
{
	long fact(long n);
	int m, k;
	scanf("%d%d", &m, &k);
	printf("%d\n", fact(m)/(fact(k)*fact(m-k)));
	
	
	return 0;
}
long fact(long n)

{ 
	int i, d=1;
	for(i=1;i<=n;i++)
	{
		d=d*i;
	} 
	return d;
} 
