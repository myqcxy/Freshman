#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 100000
clock_t start, stop;

double f1(double a[], int n, double x);
double f2(double a[], int n, double x);
int main()
{
	printf("%d\n", CLK_TCK)	;
	double a[N];
	for(int i = 1; i < N;i++) a[i] = (double)i;
	start = clock();
	f1(a,N - 1, 1.1);
	stop = clock();	
	printf("%f", (1.0*stop - start) / CLK_TCK);
	
	start = clock();
	f2(a,N - 1, 1.1);
	stop = clock();	
	printf("%f", (1.0*stop - start) / CLK_TCK);
//	f2(a,N - 1, 10);
	
	return 0;
}
double f2(double a[], int n, double x)
{
	int i;
	double p = a[n];
	for(i = n;i > 0;i--)
	{
		p = a[i-1] + x * p;
	}
	return p;
}
double f1(double a[], int n, double x) 
{
	int i;
	double p = a[0];
	for(i = 1;i<=n;i++)
	p += a[i] * pow(x, i);
	return p;
}
