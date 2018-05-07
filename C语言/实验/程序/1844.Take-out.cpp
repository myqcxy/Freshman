#include<stdio.h> 
long int N=2000000;
int main()
{
	int x, y, z;
	double sum;
	scanf("%d%d%d", &x, &y, &z);
	sum=(x+y)*z*0.1;
	if(sum<x)
	printf("%.2f\n", sum);
	else
	printf("%.2f\n", x*1.0);
	
	return 0;
}
