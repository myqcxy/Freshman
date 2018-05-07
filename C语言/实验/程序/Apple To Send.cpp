#include<stdio.h>
#include<math.h>
int main()
{
	int n, a[101], i;
	double t=0;
	a[0]=0;
	scanf("%d", &n);
	for(i=1;i<n+1;i++)
	{
		scanf("%d", &a[i]);
		t+=fabs(a[i]-a[i-1])+15;
	}
	printf("%.0f\n", t+5+a[n]);

	return 0;
}
