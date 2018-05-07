#include<stdio.h>
#include<math.h>

int main()
{
	int year, i;
	double deposit, x;
	scanf("%d%lf", &year, &deposit);
	for(i=1;i<=year;i++)
	{
		deposit=deposit*(1+2.25/100);
	}
	printf("%.6f", deposit);
	
	
	return 0;
}
