#include<stdio.h>
int main()
{
	int n, x, y, z, i, answer=0;
	scanf("%d", &n);
	for(x=1;x<=9;x++)
	{
		for(y=1;y<=9;y++)
		{
			for(z=0;z<=9;z++)
			{
				if(x*100+y*10+z+y*100+z*10+z==n)
				{
					printf("%4d%4d%4d", x, y, z);
					answer=1;
				}
			}
		}
	}
	if(answer==0)
	{
		printf("No Answer\n");
	}
	
	return 0; 
}
