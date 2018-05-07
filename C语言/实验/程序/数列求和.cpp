#include<stdio.h>
int main()
 
{
	
	int i, deno=1, n;
	double sum=0;
	scanf("%d", &n);
	for(i=1 ;i<=n;i++)
	{
		sum+=1.0/deno;
		deno+=2;
	}
	printf("%.3f\n", sum);
	return 0;
}
