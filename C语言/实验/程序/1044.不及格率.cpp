#include<stdio.h>
int main()
{
    int i, n, sum1=0, sum2=0;
    double a;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
    	scanf("%lf", &a);
    	if(a>=60)
    	{
    		sum1++;
		}
		else
		{
			sum2++;
		}
	}
	
	printf("%.2f", 1.0*sum2/n); 
	
	return 0;
 } 
