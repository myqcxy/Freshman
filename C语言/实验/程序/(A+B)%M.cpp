#include<stdio.h>
int main()
{
	long long int a, b, m;
	scanf("%lld%lld%d", &a, &b, &m),
	printf("%d\n", (a+b)%m); 
	return 0;
}

