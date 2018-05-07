#include<stdio.h>
int main()
{
	int i=0, m, k;
	scanf("%d%d", &m, &k);
	for(;m>0;m--)
	{
		i++;
		if(i%k==0)
		m++;
	}
	 printf("%d", i);
	
	return 0;
}
