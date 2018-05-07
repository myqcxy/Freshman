#include<stdio.h>
int main()
{
	int n, i, f[44],a;
	f[0]=f[1]=1;
	scanf("%d", &n);

	for(i=2;i<n;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	printf("%d", f[n-1]);
	
	return 0;
}
