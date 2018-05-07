#include<stdio.h>
int main()
{
	int gcd(int m, int n);
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d", gcd(m,n));
	
	return 0;
}
int gcd(int m, int n)
{
	if(m%n==0)
	return n;
	else
	return gcd(n,m%n);
}
