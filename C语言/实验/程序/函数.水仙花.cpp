#include<stdio.h>

int main()
{
	int  flower(int  num);
	int m, n, i;
	scanf("%d%d", &m, &n);
	for(i=m;i<=n;i++)
	{
		
		if(flower(i)==1)
	    {
		    printf("%d ", i);
	    }
	    
	}
	
	return 0;
}
int  flower(int  num)
{
	int a, b, c;
	a=num/100;
	b=num/10%10;
	c=num%100%10;
	if(num==a*a*a+b*b*b+c*c*c)
	{
		return 1;
	}
	else
	{
		return 2;
	}
	
}
