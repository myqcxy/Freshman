#include<stdio.h>
int main() 
{
	int m, n, i, j;
	double a[1000][10];
	double sum=0.0, aver;
	scanf("%d%d", &m, &n);
	for(i=0;i<m;i++) 
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	for(j=0;j<m;j++)
	{
		sum+=a[j][0];
		aver=sum/m;
	}
	printf("%.2f", aver);
	for(j=1;j<n;j++) 
	{
		sum=0.0;
		for(i=0;i<m;i++)
		{
			sum+=a[i][j];
		}
		aver=sum/m;
		printf(" %.2f", aver);
	}
	
	
	return 0;
}
