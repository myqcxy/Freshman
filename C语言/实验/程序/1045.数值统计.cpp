#include<stdio.h>
int main()
{
    int i, n, a, b=0, c=0, d=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
    	scanf("%d", &a); 
    	if(a<0)
    	{
    		b++;
		}
		if(a==0)
    	{
    		c++;
		}
		if(a>0)
    	{
    		d++;
		}
	}
	printf("%d %d %d", b, c, d);
	
	return 0;
 } 
