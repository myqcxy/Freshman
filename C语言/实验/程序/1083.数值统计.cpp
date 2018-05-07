#include<stdio.h>
int main()
{
	int n, b=0, c=0, d=0, i;
	double a;
	while(scanf("%d", &n),n!=0)
	{
		b=0,c=0,d=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf", &a);
			if(a>0) b++;
			if(a==0) d++;
			if(a<0) c++;
		}

		 printf("%d %d %d\n", c, d, b);
	}
	
	return 0;
}
