#include<stdio.h>
#include<math.h>
int main()
{
	int i, n;
	double a=0, item;
	scanf("%lf%d", &item, &n);
	for(i=1;i<=n;i++)
	{
		
	    a+=item;
	    item=sqrt(item);
	}
	printf("%.2f\n", a); 
     
	return 0;
}
