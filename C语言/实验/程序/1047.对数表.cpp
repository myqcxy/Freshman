#include<stdio.h>
#include<math.h>
int main()
{
	int m, i, n;
	scanf("%d %d", &m, &n);
	for(i=m;i<=n;i++)
	{
		printf("%4d%8.4f\n", i, log(i));
	}
	
	
	return 0;
}
