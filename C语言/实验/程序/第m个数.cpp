#include<stdio.h>
int main()
{
	int t, m, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		if(m<=n/2)
		printf("%d\n",m*2);
		else
		printf("%d\n",(m-n/2)*2-1);
		
	}
	
	return 0;
}
