#include<stdio.h>
#include<math.h>

int prime(int m);

int main()
{
	int m;
	
	for(m=2;m<=100;m++)
	{
		if(prime(m)!=0)
		   printf("%6d", m);
		   
	}
	printf("\n");
	
	return 0;
}
int prime(int m)
{
	int i, k;
	if(m==1)
	  return 0;
	  
	k=(int)sqrt (m);
	
	for(i=2; i<=k;i++)
	{
		if(m%i==0)
		 return 0;
	}
	return 1;
}
