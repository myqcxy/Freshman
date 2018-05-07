#include<stdio.h>
#include<math.h>
int main()
{
	int i, n, t;
	double a;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		a=1;		
		for(t=i;t>=1;t--)
		{
			a=a*t;					
		}
		printf("%-4d%-20.0f\n", i, a);
	}

	
	
	return 0;
}
