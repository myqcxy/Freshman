#include<stdio.h>
int main()
{
	int gcn(int m, int n);
	int m, n;
	double a, b;
	scanf("%d%d", &m, &n);
	a=gcn(m, n);
	b=1.0*m*n/a;
	printf("%.0f %.0f", a, b);
	
	return 0;
}
int gcn(int m, int n)
{
	if(m%n==0)
	return n;
	else
	return gcn(n,m%n);
}
