#include<stdio.h>
int main()
{
	int FacSum(int n);
	int n;
	scanf("%d", &n);
	printf("%d\n", FacSum(n));
	
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
