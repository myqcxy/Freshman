#include<stdio.h>
int main()
{
	int i, j, k, n, anwser=0, cost;
	scanf("%d%d", &n, &cost);
	for(i=0;i<=cost/3;i++)
	{
		for(j=0;j<=cost/2;j++)
		{
			k=n-j-i;
			if(i*3+j*2+k==cost)
			{
				printf("%d %d %d\n", i, j, k);
				anwser=1;
			}
		}
	}
	if(anwser==0)
	{
		printf("No answer\n");
	}
	
	
	return 0;
}
