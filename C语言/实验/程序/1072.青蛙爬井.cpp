#include<stdio.h> 
int main()
{
	int high, up, down, t=0;
	scanf("%d%d%d", &high, &up, &down);
	while(high>up)
	{
		high=high-up+down;
		t++;
	} 
	printf("%d\n", t+1);
	
	return 0;
}
