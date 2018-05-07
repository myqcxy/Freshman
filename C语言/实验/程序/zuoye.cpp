#include<stdio.h>
#include<math.h>
int main()
{
	double area(double a, double b, double c);
    double x, y, z, s;
    scanf("%lf%lf%lf", &x, &y, &z);
	s=area(x, y, z);
	printf("%f", s);
	return 0;
}

double area(double a, double b, double c)
{
	double  s, area;
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	return area;
}
