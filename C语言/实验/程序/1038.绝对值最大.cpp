#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c, max, d;
	scanf("%d%d%d", &a, &b, &c);
	max=abs(a);
	d=a;
	if(abs(b)>max)
	{
		max=abs(b);
		d=b;
	}
	if(abs(c)>max)
	{
		max=abs(c);
		d=c;
	}
	printf("%d", d);
	return 0;
 } 
