#include<stdio.h>
int main()
{
	int k, n=1;
	double sum=0;
	scanf("%d", &k);
	while(sum<=k)
	{
		sum=sum+1.0/n;
		n++; 
	}
	printf("%d", n-1);
	
	return 0;
}
