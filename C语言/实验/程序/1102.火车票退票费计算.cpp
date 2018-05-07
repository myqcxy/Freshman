#include<stdio.h>
double CancelFee(double price);
int main() 
{
	double price;
	scanf("%lf", &price);
	printf("%.1f\n", CancelFee(price));
	
	return 0;
}
double CancelFee(double price)
{
	int a=price*0.05;
   	double c;
   	c=price*0.05-a;
	if(c<0.25)
	return a;
	if(c>=0.25&&c<0.75)
	return a+0.5;
	if(c>=0.75)
	return a+1.0;
}
