#include<stdio.h>
#include<math.h> 
int main()
{
	int n, a, i, j, sum1=0, sum=0;
	scanf("%d%d", &n, &a);
	for(i=0;i<n;i++)
	{
		for(j=i;j>=0;j--)
		{
			sum1+=pow(10, j)*a;
		}
		sum+=sum1;
		sum1=0;
	} 
	printf("%d\n", sum);
	
	return 0;
}
