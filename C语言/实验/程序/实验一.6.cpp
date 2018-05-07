#include<stdio.h>
#include<math.h>
#include"file1.c"
int main()
{
	int n, t, count=0;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
			if(prime(n)) count++;
	}
	printf("%d\n", count);
	
	
	
	return 0;
}
