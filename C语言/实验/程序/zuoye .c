#include<stdio.h>
#include<math.h>
int main()
{
	int area(int x, int y, int z);
	double a, b, c, d;
	scanf("%lf%lf%lf", &a, &b, &c);
	d=area(a, b, c);
	printf("%f", d);
	
	
	return 0;
}
int area(int x, int y, int z)
{
	double s, area;
	s=(x+y+z)/2;
	area=sqrt(s*(s-x)*(s-y)*(s-z));
	return area; 
}
