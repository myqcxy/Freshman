#include<stdio.h>
int main()
{
	 double n, sum=0, m=1;
	 int i, j;

	scanf("%lf", &n);
	for(i=1;sum<n;i++)
	{
		m=1;
		for(j=i;j>=1;j--)
	    {
		    m=m*j;
	    }
 	    sum+=m;
	}
	printf("m<=%d\n", i-2);
	
	return 0;
}

