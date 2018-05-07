#include<stdio.h>

int main()
{
	int  flower(int  num);
	int x;
	scanf("%d", &x);
	if(flower(x)==1)
	{
		printf("yes\n")
	}
	if(flower(x)==1)
	{
		printf("no\n")
	}
	
	return 0;
}
int  flower(int  num)
{
	int a, b, c;
	a=num/100;
	b=num/10%10;
	c=num%100;
	if(num==a*a*a+b*b*b+c*c*c)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
