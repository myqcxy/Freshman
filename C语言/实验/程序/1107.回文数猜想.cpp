#include<stdio.h>
#include<math.h>
int main()
{
	int hui(int n);
	int n, m;
	scanf("%d", &n);

	while(m=hui(n),m!=n)
	{
		
		printf("%d ", n);
		n=m+n;
	}
	printf("%d", m);
	
	return 0;
}
int hui(int n)
{
	int a=0;
	int l;
	l=(int)log10(n)+1;
	while(l--)
	{
		a+=(n%10)*pow(10,l);
		n=n/10;
	}
    return a;
}
