#include<stdio.h> 
#include<math.h>
int main()
{
	int m, i, a, b, c;
	scanf("%d", &m);
	while(m--)
	{
		c=0; 
		scanf("%d%d", &a, &b);
		for(i=1;i<=a/2;i++)
		{
			if(a%i==0)
			c+=i;
		}
		if(c==b)
		printf("YES\n");
		else printf("NO\n");
	}
	
	
	return 0;
}
