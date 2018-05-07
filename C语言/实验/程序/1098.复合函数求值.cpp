#include<stdio.h> 
#include<math.h> 
int main()
{
	double funF(double x);
	double funG(double x);
	double x;
	scanf("%lf", &x);
	printf("%.2f\n", funF(funG(x)));
	
	return 0;
}
double funF(double x) 
{
	return fabs(x-3)+fabs(x+1);
	
} 
double funG(double x) 
{ 
	 return x*x-3*x;
}
