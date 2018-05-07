#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 10000
clock_t start, stop;

void f1(double a[], int n, double x);
void f2(double a[], int n, double x);
int main()
{
double a[N];
	int i;

	printf("%d\n", CLK_TCK);
	
	for(i = 1; i < N;i++) a[i] = (double)1;
	start = clock();
		for(i = 0;i < N ; i++)
	f1(a,N - 1, 1.1);
	stop = clock();	
	printf("%f\n", (1.0*stop - start) / CLK_TCK);
	
	start = clock();
	for(i = 0;i < N ; i++)
	f2(a,N - 1, 1.1);
	stop = clock();	
	printf("%f\n", (1.0*stop - start) / CLK_TCK);
//	f2(a,N - 1, 10);
	
	return 0;
}
void f2(double a[], int n, double x)
{
	int i;
	double p = a[n];
	for(i = n;i > 0;i--)
	{
		p = a[i-1] + x * p;
	}
}
void f1(double a[], int n, double x) 
{
	int i;
	double p = a[0];
	for(i = 1;i<=n;i++)
	p += a[i] * pow(x, i);
}