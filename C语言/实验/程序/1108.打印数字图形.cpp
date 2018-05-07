#include<stdio.h>
int main()
{
	void PrintLine(int m);
	int n, i, b, m, j;
	scanf("%d", &m);
	n=m,b=1;
	for(i=1;i<=m;i++)
	{
		for(j=n-1;j>=1;j--)
		{
			printf(" ");
		}
		PrintLine(i);
		n--;
	}
	for(i=m-1;i>=1;i--)
	{
		for(j=1;j<=b;j++)
		{
			printf(" ");
		}
		PrintLine(i);
		 b++;
	}
	
	
	return 0;
}
void PrintLine(int m)
{
	int i;
	for(i=1;i<=m;i++)
	{
		printf("%d", i);
	}
	for(i=m-1;i>=1;i--)
	{
		printf("%d", i);
	}
	
	putchar(10);
	
 } 
