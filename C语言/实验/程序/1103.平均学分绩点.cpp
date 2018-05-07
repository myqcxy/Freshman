#include<stdio.h>
int GP(int n);
int main()
{
	
	int n, s, i;
	double x; 
	double sumx=0, sums=0;
	scanf("%d", &n);
	for(i=0;i<n;i++) 
	{
		scanf("%lf%d", &x, &s);
		sumx+=x*GP(s);
		sums+=x;				
	}
	printf("%.1f\n", 1.0*sumx/sums);
	scanf("%d", &n);
	return 0;
}
int GP(int n)
{
	if(n<60)
	return 0;
	else
	return (n-50)/10;
}
