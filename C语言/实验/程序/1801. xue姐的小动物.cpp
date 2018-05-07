#include<stdio.h>
#define N 200
int main()
{
	void input(int *a,int n);
	void paixu(int *a,int n);
	int t, n, i, a[N], b[N];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		input(a,n);
		input(b,n);
		paixu(a,n);
		paixu(b,n);
		for(i=0;i<n;i++)
		{
			if(a[i]>b[i])
			{
				printf("NO\n");
				break;
			}
		}
		if(i==n)
		printf("YES\n");
	}
	
	return 0;
}
void input(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d", (a+i));
	}
}
void paixu(int *a,int n)
{
	int i, j, c;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i]>a[j])
			{
				c=a[i];
				a[i]=a[j];
				a[j]=c;	
			}
		}
	}
}
