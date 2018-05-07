#include<stdio.h>
int main()
{
	int t, i, n, sum, a;
	scanf("%d", &t);
	while(t>0)
	{
		scanf("%d", &n);
		for(i=7;i<=n;i++)
		{
			if(i%7==0||i%10==7||i%100/10==7||i%1000/100==7||i%10000/1000==7)
			{
				printf("%d ", i);
			}
		}
		putchar(10);
		t--;
	} 
	
	return 0;
}
