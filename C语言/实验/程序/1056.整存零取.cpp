#include<stdio.h>
int main()
{
	double x,m=0.0;
	int  i, j;
	scanf("%lf", &x);
	for(j=1;j<=5;j++)
	{
	    m+=1000;
		m=m/(1.0+x*12);
	}
	printf("%.2f\n", m);
	
	return 0;
}
