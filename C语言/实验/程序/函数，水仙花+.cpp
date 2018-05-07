#include<stdio.h>
int main()
{
	int  even(int  a);
	int n, sum=0;

	scanf("%d", &n);
	while(n>0)
	{
		if(even(n)==0)
		{
		sum=sum+n;
		}
		scanf("%d", &n);
	   
	}
	printf("%d", sum);
	return 0;
 } 
int  even(int  a)
{
	if(a%2==0)
	{
	   return 1;
    }
	else
	{
	   putchar('\n');
    }
}

