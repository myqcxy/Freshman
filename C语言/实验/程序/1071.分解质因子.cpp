#include<stdio.h>
#include<math.h>
int main()
{
	int prim(int n); 
	int n, i, t=0,a[100];
	scanf("%d", &n);
	for(i=2;i<=n;i++)
	{
		if(n%i==0&&prim(i)==1)
		{
			while(n%i==0)
			{
				n=n/i;
				if(n/i==0)
				printf("%d", i);
				else
				printf("%d ", i);
			}
		}
	}
	
	
	return 0;
}
int prim(int n)
{
	int i, k;
	k=(int)sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
		break;
	}
	if(i<=k)
	return 0;
	else
	return 1;
}
