#include<stdio.h>

int main()
{
	double a;
	scanf("%lf", &a);
	if(a<500)
	{
    	printf("%.2f", a);
    }
	else if(a>=500&&a<1000)
	{
		a=a*0.95;
	    printf("%.2f", a);
    }
	else if(a>=1000&&a<3000)
	{
		a=a*0.9;
	    printf("%.2f", a);
    }
    else if(a>=3000&&a<5000)
	{
		a=a*0.85;
	    printf("%.2f", a);
    }
	else
	{
		a=a*0.8;
	    printf("%.2f", a);
    }
	
	return 0;
}

