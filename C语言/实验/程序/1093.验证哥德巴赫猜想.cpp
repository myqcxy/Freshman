#include<stdio.h>
#include<math.h>

int main()
{
	int prime(int a); 
	int m, i;
	scanf("%d", &m);
	for(i=3;i<=m/2;i=i+1)
	{
		if(prime(i)==1&&prime(m-i)==1)
		{
			printf("%d %d\n", i, m-i);
		}
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
