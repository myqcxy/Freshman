#include<stdio.h>
int main()
{
    int i, n, a, b=1;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a);
        if(a%2!=0)
        {
        	b*=a;
		}
	}
	printf("%d", b);
	
	return 0;
 } 
