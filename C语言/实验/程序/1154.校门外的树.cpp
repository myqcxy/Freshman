#include<stdio.h>
#define T 10001
int main()
{
	int N;
	scanf("%d", &N);
	while(N--)
	{
		int i, l, m, a, b, c[T], d=0, j;
		scanf("%d%d", &l, &m);
		for(i=0;i<=l;i++)
		 c[i]=1;
		for(i=0;i<m;i++)
		{
			scanf("%d%d", &a, &b);
			for(j=a;j<=b;j++)
			c[j]=0;
		}
		for(i=0;i<l;i++)
		if(c[i]) d++;
		printf("%d\n", d+1);
	} 
		
	return 0;
}
