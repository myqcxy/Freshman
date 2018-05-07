#include<stdio.h>
#include<math.h>
int main()
{
	int inverse(int n); 
	int n;
	scanf("%d", &n);
	printf("%d\n", n+inverse(n));
	
	return 0;
}
int inverse(int n) 
{ 
	int a, i, b=0;
	a=(int)log10(n)+1;
	for(i=1;i<=a;i++)
	{
		b+=n%10*pow(10,a-i);
		n=n/10;
	}

	return b;
	
	
} 
