#include<stdio.h>
#include<math.h>
int main()
{
	int hui(int n);
	int m, n, i;
	scanf("%d%d", &m, &n);
	for(i=m;i<=n;i++) 
	{
		if(hui(i))
		printf("%d ", i);
	}

	return 0;
}
int hui(int n)
{
	int a=0;
	int f=n, l;
	l=(int)log10(n)+1;
	while(l--)
	{
		a+=(n%10)*pow(10,l);
		n=n/10;
	}
	if(a==f)
	return 1;
	else
    return 0;
}
