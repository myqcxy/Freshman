#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,n,i, c;
	scanf("%d",&n);
	while(n--)
    {
    	c=1;
        scanf("%d%d",&a,&b);
		for(i=1;i<=b;i++)
		{
			c=c*a;
			c=c%1000;
		}
		
		
    	
		printf("%d\n",c);
    }
    return 0;
}
