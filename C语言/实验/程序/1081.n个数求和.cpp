#include<stdio.h>
int main()
{
	int t, i, n, sum, a;
	scanf("%d", &t);
	while(t>0)
	{
		sum=0;
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
			scanf("%d", &a);
			sum+=a;
		}
		printf("%d\n", sum);
		t--;	
	} 
	
	return 0;
}
