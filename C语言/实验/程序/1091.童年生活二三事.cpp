#include<stdio.h>
int main()
{
	int n, i, j=0, t, a[40];
	while(scanf("%d", &n),n!=0)
	{
		t=0;
		a[0]=1,a[1]=2;
		for(i=2;i<n;i++)
		{
			a[i]=a[i-1]+a[i-2];
		}
		printf("%d\n", a[n-1]);
		
	} 
	
	
	return 0;
}
