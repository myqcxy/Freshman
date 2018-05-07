#include<stdio.h>
#include<math.h>
int main()
{
	int prime(int a);
	int i, m, n, x=0;
	scanf("%d%d", &m, &n);
	for(i=m;i<=n;i++)
	{
		if(prime(i)==1)
		{
			printf("%d ", i);
			x++;
		}
		
	}
	if(x==0)
	{
		printf("No Answer\n");
	}	
	return 0;
 } 
 int prime(int a)
 {
 	int t, c;
 	
 	if(a==1)
 	{
 		return 0;
	 }
	 c=(int)sqrt(a);
    for(t=2;t<=c;t++)
	{
	 	if(a%t==0)
		{
 			return 0;
		 }	 
	 }
	 return 1;
 }
