#include<stdio.h>
#include<math.h> 
int main()
{
	double x, sin=0,n;
	int   j,i;
	scanf("%lf", &x); 
	for(i=1;i<=10;i++)
	{
	    n=1.0;
		for(j=2*i-1;j>=1;j--)
		{
			n=n*j;
		}
		sin+=pow(-1,i-1)*pow(x,2*i-1)/n;
	}
	printf("%.3f\n",sin);

	return 0;
}
