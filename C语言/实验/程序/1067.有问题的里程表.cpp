#include<stdio.h>
int main()
{
	int num, j=0, i;
	scanf("%d", &num);
	for(i=1;i<=num;i++)
	{
		if(i%10==4||i%100/10==4||i/100==4)
		{
			continue;
		}
		
		j++;
	}
	printf("%d\n", j);
	
	return 0;
}
