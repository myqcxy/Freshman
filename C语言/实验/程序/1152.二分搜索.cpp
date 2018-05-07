#include<stdio.h>
#include<string.h>
#define N 100000
int main()
{
	int a[N];
	int n, m, x,i, start, end, mid;
	scanf("%d", &n);	
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d", &x);
		start=0;
		end=n-1;
		mid=(start+end)/2;
		while(a[mid]!=x&&start<end)
		{

			if(a[mid]>x) 
				end=mid-1;
		    if(a[mid]<x) 
				start=mid+1;
			mid=(start+end)/2;
		}	
		if(a[mid]==x) printf("%d\n", mid);
		else printf("Not found!\n");
	}
	
	return 0;
}
