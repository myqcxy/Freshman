#include<stdio.h>
int main()
{
	double w, p, sum=0;
	while(scanf("%*s%lf%lf", &w, &p)!=EOF)
	{
		sum+=w*p;
	}
	printf("%.1f\n", sum);
	
	
	
	return 0;
}
