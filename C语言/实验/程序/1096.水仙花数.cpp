#include<stdio.h>
int main()
{
	int m, n, i, a, b, c, t;
	while(scanf("%d%d", &m, &n)!=EOF)
	{
		t=0;
		for(i=m;i<=n;i++)
		{
			a=i%10;
			b=i%100/10;
			c=i/100;
			if(i==a*a*a+b*b*b+c*c*c)
			{
				t++;
				if(t==1)
				printf("%d", i);
				else
				printf(" %d", i);	
				
			}
		}
		if(t==0)
		printf("no");
		putchar(10);
     }
	
	return 0;
}
