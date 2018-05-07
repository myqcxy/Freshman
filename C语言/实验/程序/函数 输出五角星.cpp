#include<stdio.h>
int main()
{
	void outputstar(int n);
	int  m;
	scanf("%d", &m);
    outputstar(m);
	
	return 0;
}
void outputstar(int  n)
{
	int i, j, t, a;
	a=n;
	for(j=1;j<=n;j++)
	{
		for(t=2*a-2;t>=1;t--)
		{
		   printf(" ");
		}
		for(i=1;i<=2*j-1;i++)
	    {
	       printf(" *");
	    }
	    printf("\n");
	    a--;
	}	    
	putchar('\n');

}
