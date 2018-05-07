#include<stdio.h>
int main()
{
	int a, i, n;
	scanf("%d", &n);
	for(i=1;;i++)
	{
		a=n%10;
		n=n/10;
		printf("%d ", a);
		if(n<=0)
		break;
	 } 
	
	return 0;
}
