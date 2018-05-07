#include<stdio.h>
int main()
{
	int a, i, j;
	for(j=1;j<=9;j++)
	{
	   for(i=1;i<=j; i++)
	   {
		  a=j*i;
	      printf("%d*%d=%d ",j, i, a);
	   }
	   printf("\n");
    } 
	return 0;
}
