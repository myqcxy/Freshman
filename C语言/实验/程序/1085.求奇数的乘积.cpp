#include<stdio.h>
int main()
{
	int n, i, a, pro;
	while(scanf("%d", &n)!=EOF)
	{
		pro=1;
			for(i=0;i<n;i++)
			{
				scanf("%d", &a);
				if(a%2!=0)
				pro*=a;
			}
			printf("%d\n", pro);
	} 
	
	return 0;
}
