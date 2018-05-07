#include<stdio.h>
int main()
{
	int a[6][6], n, i, j, sum=0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{ 
		    scanf("%d", &a[i][j]);
		} 
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j!=i&&j!=n-i-1)
			{
			   sum+=a[i][j]; 
			} 
		} 
	}   
	printf("%d", sum); 

    return 0; 
}
