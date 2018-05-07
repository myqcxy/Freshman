#include<stdio.h>
int main()
{
	int FacSum(int n);
	int m, n, i, j, f=0;
	scanf("%d%d", &m, &n);
	for(i=m;i<=n;i++)
	{
		j=FacSum(i);
		if(FacSum(j)==i&&i<j)
		{
			printf("%d %d\n", i, j);
			f=1;
		}
	}
	if(f==0)
	{
		printf("No answer\n");
	}
	
	return 0;
}
int FacSum(int n) 
{ 
	int i, sum=0;
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		{
			sum+=i;
		}
	} 
	return sum;
} 
