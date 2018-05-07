#include<stdio.h> 
int main()
{
	int i, k;
	double s=0;
	scanf("%d", &k);
	for(i=1;s<=k;i++)
	{
		s+=1.0/i;
	}
	printf("%d\n", i-1);
	
	return 0;
}
