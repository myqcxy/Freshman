#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, a, find=0;
	scanf("%d", &n);
	a=(int)sqrt(n);
	for(i=2;i<=a;i++)
	{
		if(n%i==0)
		{
			find=1;
			break;
		}
	} 
	if(find==1||n==1)
	{
		printf("No\n");
	}
	else
	printf("Yes\n");
	return 0;
}
