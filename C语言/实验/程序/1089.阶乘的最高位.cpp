#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, l;
	double fac=1.0;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		fac*=i;
	l=(int)log10(fac);
	fac=fac/pow(10,l);
	}

	printf("%.0f\n", fac);
	
	
	return 0;
}
