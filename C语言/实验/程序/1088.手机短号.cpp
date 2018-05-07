#include<stdio.h>
int main()
{
	int n, dig;
	scanf("%d", &n);
	while(n>0)
	{
		scanf("%*6d%5d", &dig);
		printf("6%05d\n", dig);		
		n--;
	}
	
	
	
	return 0;
}
