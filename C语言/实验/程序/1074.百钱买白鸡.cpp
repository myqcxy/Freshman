#include<stdio.h>
int main()
{
	int i, j, k, n, anwser=0;
	scanf("%d", &n);
	for(i=0;i<=n/5;i++)
	{
		for(j=0;j<=n/3;j++)
		{
			k=n-j-i;
			if(i*15+j*9+k==3*n)
			{
				printf("%4d%4d%4d\n", i, j, k);
				anwser=1;
			}
		}
	}
	if(anwser==0)
	{
		printf("No Answer\n");
	}
	
	
	return 0;
}
