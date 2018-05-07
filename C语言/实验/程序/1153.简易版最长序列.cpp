#include<stdio.h>

double a[10000];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, i, d=1, j, c=0;
		double s;
		scanf("%d", &n);
		for(i=0;i<n;i++)
			scanf("%lf", &a[i]);
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(a[i]>a[j])
				{
					s=a[i];
					a[i]=a[j];
					a[j]=s;
				}
			}
//			printf("%f,", a[i]);
		}

		for(i=1,j=0;i<=n;i++)
		{
			if(a[i]==a[j]) d++;
			else 
			{
				j=i;
				if(d>c) c=d;
//				printf("%d,", d);								
				d=1;
			}
			
		}
		printf("%d\n", c);
	}
	
	return 0;
}
