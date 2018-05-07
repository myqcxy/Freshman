#include<stdio.h>
#include<math.h>
int main()
{
	double area(double x, double y, double z);
    double x, y, z, s;
    scanf("%lf%lf%lf", &x, &y, &z);
	s=area(x, y, z);
	printf("%f", s);
	return 0;
}
double area(double a, double b, double c)
{
	double  s, area1;
	s=(a+b+c)/2.0;
	area1=sqrt(s*(s-a)*(s-b)*(s-c));
	return area1;
}



